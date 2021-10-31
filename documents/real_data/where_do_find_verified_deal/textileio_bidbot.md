# 本文档翻译自[textileio_bidbot](https://github.com/textileio/bidbot/blob/main/README.md)

建议参考原文理解

# bidbot

Bidbot是一个Filecoin Network的挎斗工具（挎斗工具的定义参考这个[链接](https://www.cnblogs.com/kevin1988/p/8244730.html)），用于存储供应商在存储交易拍卖中投标。
加入我们的[公共Slack频道](https://slack.textile.io/)，了解新闻、讨论和状态更新。[查看我们的博客](https://blog.textile.io/)了解最新的帖子和公告。

## 目录

- [安装](#installation)
- [什么是存储拍卖系统](#what-is-an-auctioneer)
- [我如何与存储拍卖系统连接](#How-do-i-connect-the-system)
- [CID gravity 集成](#CID-gravity-integration)
- [有用的`bidbot`命令](#useful-bidbot-operational-commands)
- [故障排除](#troubleshooting)
- [贡献](#contributing)
- [更新日志](#changelog)
- [许可证](#license)

## 安装

- **预构建包**: See [release assets](https://github.com/textileio/bidbot/releases/latest)
- **Docker 镜像**: See the `latest` tag on [Docker Hub](https://hub.docker.com/r/textile/bidbot/tags)
- **从源码构建** ([Go 1.15 or newer](https://golang.org/doc/install)):

```shell
git clone https://github.com/textileio/bidbot.git
cd bidbot
make install
```

## 什么是存储拍卖系统？

首先，我们必须明白，`bidbot`是一个更大的体系的一部分，这个系统就是：存储拍卖系统。
存储拍卖系统（Auctioneer）是一个从多个客户端接收数据的系统，将它们聚合起来，并提供给存储供应商进行存储。存储拍卖系统有几个独特的属性，使其与典型的Filecoin客户端不同。

1. 存储供应商连接到存储拍卖系统，以发现等待交易的可用数据。
2. 存储供应商实时竞价，为每个数据提供最佳的存储解决方案。
3. 所有交易都是离线交易，而不是在线交易。存储供应商下载数据以创建交易。

目前，存储拍卖系统正在创建一个缓慢的拍卖流，所以当运行 "bidbot"时，你可能会看到没有任何事情发生,这会持续一段时间，所以除非你在日志中看到错误，否则你可以让守护程序继续运行。

### 它是如何工作的

每当存储拍卖系统汇聚的数据超过了最小的阈值，它就会尝试与存储供应商进行交易。等待存储的数据是由你在Filecoin中熟悉的常用属性描述的。

- PayloadCid (cid)
- PieceCid (cid)
- DealSize (int64 in bytes)
- VerifiedDeal (bool)

为了启动新的数据的存储，存储拍卖系统创建一个*拍卖*。该*拍卖*被发布到所有连接的存储供应商，以通知他们有一个新的数据正在等待在Filecoin上存储。

为了更好地理解这一点，请考虑下面的聊天。

- [存储拍卖系统]。"嘿，存储供应商，有一个新的数据集拍卖，大小为X，PayloadCid为X，PieceCid为X，PieceSize为X，这个数据将通过验证的交易创建。谁有兴趣？"
- [提供者-A]。"我！这是我的出价：price-per-epoch=0.0001FIL，我承诺接受*DealStartEpoch=XXXX的交易建议 "*。
- [提供者-B]：嘿，我也是！我的价格是0.00000001。我的价格是0.00000001FIL，我承诺接受DealStartepoch=YYYYY的交易提议"。
- [提供者-C]。呃，我现在太忙了...... 我不会在这里出价，就让它过去吧。下次拍卖再看!

存储供应商将发送*出价*，以显示他们对参与拍卖的兴趣。出价为存储拍卖系统提供了关于供应商的存储意向的多个信息（即价格、起始区块等）。与基于聊天的拍卖不同，连接到存储拍卖系统的存储提供商可以将出价配置为自动进行，只要
其存储集群能够处理就可以.

存储拍卖系统从连接的存储供应商那里收集所有的出价，并选择一个或多个赢家。中标算法的目的是最大限度地提高存储客户的交易成功率，同时对所有存储供应商，无论大小，无论新旧，都是公平的。它是开放的，并根据社区反馈不断发展。任何人都可以参加每两周一次的[拍卖管理会议](https://textile.notion.site/Auction-Governance-2eb1acae8a204b6e8dbf72752255a008)，做出贡献。作为一个经验法则，你可以期望以下事实有助于赢得拍卖。

- 为交易提供低的报价price/epoch。经过验证的交易当前需要免费。
- 提供一个低的DealStartEpoch，并尽快确认链上的获胜交易。
- 在过去的拍卖中保持较高的交易成功率。

如果你赢得了拍卖，你会得到相关的通知! 否则，你在下一次拍卖中很可能会有更好的运气!

存储拍卖系统依靠线下交易与存储供应商进行交易。在你赢得一场拍卖后，你的投标机器人将从客户那里拉出交易数据。你可以把这个流程看作是一个*自动*的离线交易设置，在这里，你不会收到硬盘，而是从某个地方提取数据，然后收到离线交易提议。

## 我如何与系统连接？

上一节中的假设情景显然没有解释你如何真正发送竞价或与存储拍卖系统互动。下面的图表将有助于更好地了解情况。

![auctioneer + bidbots](https://user-images.githubusercontent.com/1369696/135887323-6b31cc1c-81e6-422e-9169-f09326680b69.png)

为了连接到系统，你将安装`bidbot`，一个在你的主机上运行的守护程序。

`bidbot`通过libp2p pubsub主题与存储拍卖系统对话。这与许多`libp2p`应用程序，如`lotus`,使用的技术相同。通过这些主题，你的`bidbot`守护程序将收到新的*拍卖*，并可以发送*出价*来参与。

每当你赢得一个拍卖，你的`lotus-miner`将收到相应数据的交易建议，这样你就可以接受它，并产生一个*ProposalCid*。接受后，你的`bidbot`将通过客户端给出的URL或IPFS multiaddrs自动下载*PayloadCid*数据，并像一般离线交易那样进行导入，类似你可能知道的以下命令。`lotus-miner storage-deals import-data <dealCid> <carFilePath>`。

carFilePath "是 "bidbot "下载交易数据后生成的CAR文件。*dealCid*是你之前从拍卖商那里接受的建议的*ProposalCid*。

从那一刻起，除了常规的交易执行步骤外，不需要其它动作。重要的是，在你出价时承诺的*StartDealEpoch*之前，该交易在链上变成激活状态!

### 我如何运行`bidbot`？

以下是运行的步骤。

0. [安装Go 1.15或更新版本](https://golang.org/doc/install)
1. 确保`$GOPATH/bin`在你的`$PATH`中，即`export PATH=$GOPATH/bin:$PATH`。
2. `bidbot init`.
3. 终端输出将要求你用你的矿工的所有者地址签署一个令牌。
4. 配置你的_ask price_，其他出价设置，和拍卖过滤器。详见`bidbot help daemon`。你可以编辑`bidbot init`生成的配置文件（`~/.bidbot/config`），或者对任何给定的选项使用相应的标志。
5. 如步骤2输出所示，使用你上面生成的签名来启动守护进程。
6. 祝你好运! 你的`bidbot`将在公开交易的拍卖中自动投标。如果它赢得了拍卖，存储拍卖系统将自动开始与步骤4中使用的`lotus`矿工地址进行交易。

**第四步的重要配置注意事项：**

- Bidbot默认将下载的CAR文件存储在`~/.bidbot/deal_data`中。这个目录应该是你的Lotus-miner可以访问的，这样CAR导入步骤才能正常进行。如果你在Lotus节点的同一主机上运行`bidbot`，默认的下载文件夹可能会起作用。如果你想在不同的主机上运行`bidbot`和Lotus节点，你应该建立一个共享卷，并在`bidbot`主机上设置BIDBOT_DEAL_DATA_DIRECTORY环境变量来改变下载文件夹目标。共享卷应该被挂载到Lotus节点主机上，与`bidbot`主机的全路径相同。
- 你的`--ask-price`和`--verified-ask-price`值应该与你的市场节点配置相匹配。
- 你应该正确设置你的`--deal-start-window`值，使其比你的矿工节点配置大一些，以涵盖下载和导入数据所需的时间。如果这个值设置不正确，你的矿工节点将拒绝提议，因为 "DealStartEpoch"值太早，你无法接受。
- `--lotus-miner-api-token`应该有`write`权限。
- 考虑使用`--sealing-sectors-limit`标志来允许`bidbot`在你有超过指定数量的封装扇区时暂停竞价。

## 这在我目前的矿工基础设施中如何体现？

下图显示了bidbot、 auctioneer和你的lotus-miner如何互动。

![auctioneer, bidbot, and lotus-miner](https://user-images.githubusercontent.com/1369696/135889226-19cf7830-8ed9-495f-a685-76e6f63c8b47.png)

**注意**：你可以把`bidbot`安装在与你的矿工守护程序相同的主机上，但出于安全考虑，你有可能想避免这样做。

### OK，我已经运行了，我应该看到什么？

首先，祝贺你已经连接上了! 当启动你的`bidbot'守护程序时，你应该看到控制台中出现以下几行。

```go
2021-05-28T17:33:30.814-0300    INFO    mpeer   marketpeer/marketpeer.go:148    marketpeer 12D3KooWPX8uutGrghEYLt1i9EPmLmwSUYtYD3BN1tvARK5YXDXV is online
2021-05-28T17:33:30.814-0300    DEBUG   mpeer   marketpeer/marketpeer.go:149    marketpeer addresses: [/ip4/192.168.1.27/udp/4002/quic /ip4/127.0.0.1/udp/4002/quic /ip4/192.168.1.27/tcp/4002 /ip4/127.0.0.1/tcp/4002]
2021-05-28T17:33:30.814-0300    INFO    mpeer   marketpeer/marketpeer.go:164    mdns was enabled (interval=1s)
2021-05-28T17:33:30.814-0300    INFO    bidbot/service  service/service.go:143  service started
2021-05-28T17:33:31.875-0300    INFO    mpeer   marketpeer/marketpeer.go:184    peer was bootstapped
2021-05-28T17:33:31.876-0300    INFO    bidbot/service  service/service.go:191  subscribed to the deal auction feed
```

检查你是否在日志输出中看到最后一行（"subscribed to the deal auction feed"）很重要。这意味着你已经成功连接到Auctioneer。

一段时间后，你会在日志输出中看到一些活动，例如。

```go
2021-05-28T17:34:26.467-0300    DEBUG   bidbot/service  service/service.go:202  /textile/auction/0.0.1 received auction from 12D3KooWRhbmhcWGB84qPehvZvtVyzW8qNkdbcX2gGidhAmJBzhi                                                                                                         
2021-05-28T17:34:26.467-0300    DEBUG   mpeer/pubsub    pubsub/pubsub.go:245    /textile/auction/0.0.1/12D3KooWRhbmhcWGB84qPehvZvtVyzW8qNkdbcX2gGidhAmJBzhi/acks ack peer event: 12D3KooWRhbmhcWGB84qPehvZvtVyzW8qNkdbcX2gGidhAmJBzhi JOINED                                              
2021-05-28T17:34:26.467-0300    INFO    bidbot/service  service/service.go:215  received auction 01f6taxy1v33a8pmdttas03de3 from 12D3KooWRhbmhcWGB84qPehvZvtVyzW8qNkdbcX2gGidhAmJBzhi:                                                                                                    
{                                                                                                                                                                                                                                                                                         
  "id": "01f6taxy1v33a8pmdttas03de3",                                                                                                                                                                                                                                                     
  "deal_size": 524288,                                                                                                                                                                                                                                                                    
  "deal_duration": 1051200,                                                                                                                                                                                                                                                               
  "ends_at": {                                                                                                                                                                                                                                                                        
    "seconds": 1622234076,                                                                                                                                                                                                                                                                
    "nanos": 311991847                                                                                                                                                                                                                                                                   
  }                                                                                                                                                                                                                                                                                     
}
```

在这里，你可以看到你的`bidbot`被通知有一个新的拍卖。

你还会看到拍卖中提出的竞价

```go
2021-05-28T17:53:03.925-0300 INFO bidbot/service/service.go:269 bidding in auction 01f6tc0ygw6bpyj00e0k17secb from 12D3KooWRhbmhcWGB84qPehvZvtVyzW8qNkdbcX2gGidhAmJBzhi: 
{                                                                     
  "auction_id": "01f6tc0ygw6bpyj00e0k17secb",                                                                                                
  "storage_provider_id": "f02222",                                             
  "wallet_addr_sig": "***",
  "ask_price": 10,                                                    
  "verified_ask_price": 10,                                           
  "start_epoch": 800506,                                              
  "fast_retrieval": true                                              
}

```

如果你赢得了拍卖，你应该看到一个类似的日志行。

```go
2021-05-28T17:53:13.790-0300    DEBUG   bidbot/service  service/service.go:225  /textile/auction/0.0.1/12D3KooWPX8uutGrghEYLt1i9EPmLmwSUYtYD3BN1tvARK5YXDXV/wins received win from 12D3KooWRhbmhcWGB84qPehvZvtVyzW8qNkdbcX2gGidhAmJBzhi
```

## CID gravity 集成

[CID gravity](https://www.cidgravity.com)是存储供应商管理客户和价格层级的工具。如果集成了，bidbot可以根据那里的配置出价，而不是本地配置的`--ask-price`和`--verified-ask-price`。这里只涉及两个参数。

- `--cid-gravity-key`。你应该能够通过点击CID引力控制台的 "Integrations"菜单项来生成一个。
- `--cid-gravity-strict`。默认情况下，如果bidbot由于某种原因不能到达CID gravity的API，它会根据本地配置的价格出价。如果你想让它在这种情况下停止出价，请将此设置为 "true"。

Bidbot的交易来自Textile的地址，`f144zep4gitj73rrujd3jw6iprljicx6vl4wbeavi`，或者拍卖客户的地址。当你`bidbot deals list`或`bidbot deals show`时，该地址会显示出来。如果你想对bidbot交易有特定的定价模式，在CID引力控制台创建一个有定价模式的客户，然后添加你关心的客户地址。

## 有用的`bidbot`操作命令

如果你有`bidbot`守护程序在运行，我们建议你探索以下可用的命令。

- `bidbot download <payload-cid> <data-uri>`: 该命令允许你下载一个CAR文件到`bidbot`下载文件夹。这对测试下载或从拍卖会上手动重新下载一个特定的CAR很有帮助（如果有必要的话）。
- `bidbot deals list`。这个命令显示了你所赢得的拍卖的列表，以及你在这个过程中的某个阶段的一些总结。
- `bidbot deals show <bid-id>`: 该命令显示关于已赢得的拍卖的详细信息。
- `bidbot pause`和`bidbot resume`: 当你使用脚本来管理你的矿工负载时很有用。
- `bidbot install-service`: 将bidbot安装为一个systemd服务。需要用 "sudo "运行。

你认为`bidbot`可以有其他命令，使你的生活更轻松吗？我们很想知道!

## 故障排除

问题可能会出现，特别是当你是bidbot的新手时。下面是一些你可能遇到的常见问题。

1. 当你 "bidbot交易列表 "中，有很多交易处于 "awaiting_proposal"状态。很可能是
    - 你的矿工不能被联系到。做以下检查（感谢@TippyFlitsUK)
        - 获取你的矿工同行的ID - `lotus-miner net id`。
        - 尝试找到你自己的ID - `lotus net findpeer YOUR_MINER_PEER_ID`。
        - 用Bidbot使用的Glif节点尝试几次 - `FULLNODE_API_INFO="https://api.node.glif.io" lotus net findpeer YOUR_MINER_PEER_ID`。
    - 或者你设置的`--deal-start-window'太小。你会在你的矿工日志中看到类似 "deal rejected: cannot seal a sector before ..."的内容。将你的 "deal-start-window"设置为比你的矿工配置中的 "ExpectedSealDuration"长几个小时。

2. 交易太多，超过了你的密封能力。有两种方法可以节制。
    - `--running-bytes-limit`，限制bidbot在一段时间内处理的总字节数。
    - `--sealing-sectors-limit`，如果矿工节点的封印区超过所需区段，则暂停竞价。

3. 我们看到过这样一种情况，当bidbot在中标后很久才导入数据时，会出现 "normal shutdown of state machine"或 "given data does not match expected commP ..."这样的错误，尽管真正的问题是超过了交易开始时间。如果有疑问，请检查你的 "lotus-miner"日志，了解真正的原因。

我们也建议设置`--log-debug=true`，并在你想向Textile或社区寻求帮助时保留这些日志。

## 贡献

我们非常欢迎拉动请求和错误报告❤️。

这个仓库属于 Textile [行为准则](./CODE_OF_CONDUCT.md)的范围。

欢迎通过以下方式与我们联系。

- [打开一个问题](https://github.com/textileio/bidbot/issues/new)
- 加入[公共Slack频道](https://slack.textile.io/)
- 发送电子邮件到 contact@textile.io

## 更新日志

更新日志与每个[发行版本](https://github.com/textileio/bidbot/releases)一起发布。

## 许可证

[MIT](LICENSE)
