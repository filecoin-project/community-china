# Filecoin Plus

Filecoin Plus旨在为Filecoin网络增加一层社会信任，并引入一种称为DataCap的新资源，从而实现Filecoin网络的需求端，并最大限度地增加Filecoin上的有用存储。希望将存储载入网络的客户端向社区选择的公证人申请获得DataCap，用来激励存储供应商接受存储交易。

## 概念

Filecoin Plus基于一套指导原则，[详见FIP-0003](https://github.com/filecoin-project/FIPs/blob/master/FIPS/fip-0003.md) , 该计划的重点是提高Filecoin的效率,使其成为人类最重要信息的去中心化存储网络。

根密钥持有者、公证人、客户端和存储提供商通过DataCap的分配和支出进行交互。公证人分批获取DataCap，然后将其分配给值得信赖的客户端，这些客户端使用DataCap资助存储交易。接收DataCap的存储提供商在该交易中提供的存储空间中，其经质量调整后的容量将提高10倍（即有效算力），这增加了他们在网络中的区块奖励份额。这创造了一种机制,以激励所有参与者让Filecoin更有用。

### DataCap

当分配给客户端时，客户端可以在与存储提供商的存储交易中使用DataCap。这些交易带来了更高的交易质量乘数，将存储提供商在网络上的“质量调整能力”提高了10倍，随着时间的推移，存储提供商将获得更好的区块奖励。DataCap被分批授予公证人，公证人可以将其分配给客户端，客户端花费DataCap来资助存储交易，DataCap在用于交易时被使用。

### 公证人

公证人被选为Filecoin网络的受托人，负责将DataCap分配给具有有效存储用例的客户端。公证人的基本职责包括：

- 将 DataCap 分配给客户端，以增加网络上可靠且有用的存储。

- 确保在分配 DataCap 时，不会以任何可能危及网络的形式过度信任任何一方。

- 遵循操作指南，记录决策流程，并响应对其分配决策进行审计的任何请求。

你可以在plus.fil.org上找到当前[活跃公证人](https://plus.fil.org)的列表.

公证人通过[申请流程](https://github.com/filecoin-project/notary-governance/tree/main/notaries#application) 选择。如果获得批准，[根密钥持有者](https://github.com/filecoin-project/notary-governance/tree/main/root-key-holders#overview) (社区所作决定的链上执行人) 授予公证人身份和DataCap分配额度。有意成为公证人的人士应通过在[公证人管理仓库](https://github.com/filecoin-project/notary-governance/) 中提交issue申请担任该职位

### 客户端

客户端可以使用其DataCap来激励存储提供商满足其需求。这可以包括提供满足其特定需求的附加功能和服务级别。通过这样做，Filecoin上与存储相关的商品和服务随着时间的推移变得更有价值和竞争力。公证人对客户端进行审查，以确保客户端收到与其声誉和需求相称的DataCap，并确保客户端负责任的分配该DataCap。

## 使用DataCap

### 获取DataCap

客户需要具有链上Filecoin地址，以便接收DataCap。如果您正在设置一个新地址，请确保通过向该地址发送最低数量的FIL来初始化它，例如，从交易所购买一些FIL。您需要一个地址，才能通过以下任何一种方式继续获取DataCap。

_注意：从网络版本12开始，DataCap分配至Filecoin地址上是一次性的。如果您收到一个分配，并且需要更多，您应该使用一个您已经像上面一样初始化的唯一地址发出一个新请求。[FIP-0012](https://github.com/filecoin-project/FIPs/blob/master/FIPS/fip-0012.md) 已在网络版本13（actor v5）中接受并实现，该版本允许客户端地址多次接收DataCap_

客户端通过向公证人提出请求获得DataCap。对于32GiB的第一个DataCap分配，您可以使用自动验证程序，例如<https://verify.glif.io/>. 自动验证器的存在是为了立即将DataCap授予能够通过特定方法进行自我验证的客户端。例如，verify.glif.io自动公证人向拥有GitHub帐户的客户授予DataCap，该帐户的使用时间超过180天，并且在过去30天内未在此网站上使用。

1.前往<https://verify.glif.io/>

2.连接您的GitHub帐户-单击页面右上角的**Start**按钮

3.如果尚未登录GitHub，请登录

4.在“Request”下的框中粘贴您希望接收DataCap的地址，然后点击**Request**

5.自动公证人现在将尝试向Filecoin网络发送一条消息，您的地址将被授予32GiB的DataCap。这大约需要1分钟

6.完成后，您现在有32GiB开始进行交易！您可以随时返回此站点并使用“check”框查看您在特定地址上剩余多少DataCap

为了更大规模地接收DataCap（用于业务需求和生产用例），根据网络上的数据量，客户端有两个选项：

 - 直接向特定公证人申请-最适合寻求<100TiB DataCap的客户

 - 申请专用于特定项目的大型数据集公证人-最适合寻求>100TiB DataCap（通常在500TiB-5PiB范围内）的客户

直接向特定公证人申请：

1.前往[Filecoin Plus Registry](https://plus.fil.org/) ，然后选择for client点击**Proceed**

2.单击**Get Verified**

3.单击**General Verification**。此链接将带您到公证人注册处，在那里您可以向特定公证人请求DataCap。公证人可以专门处理他们将选择支持的请求类型。建议您在您的业务区域选择一名公证人，该公证人还涵盖您将自己归入的*用例*的一般类别

4.通过选中您要申请的公证人行上的复选框，并单击**Make Request**

5.填写弹出的表格。在授予您所要求的DataCap之前，公证人在进行任何必要的尽职调查时都会用到这一点

6.单击**Sign in with GitHub**，允许应用程序代表您创建GitHub问题

7.登录后，按钮应更改为**Send request**。单击此按钮可代表您创建一个问题并发送给正确的公证人！

每个请求都作为一个GitHub issue在[Fil+ Client Onboarding repo](https://github.com/filecoin-project/filecoin-plus-client-onboarding) 中进行跟踪. 您也可以在那里跟踪应用程序的进度。公证人在为您分配DataCap之前，可能会询问更多信息。

要申请大型数据集公证人，请按照[申请大型DataCap分配](https://github.com/filecoin-project/filecoin-plus-large-datasets#applying) 中的步骤进行操作。

### DataCap使用

一旦您拥有DataCap的地址，您就可以使用DataCap作为支付的一部分进行交易。由于存储提供商在接受Fil+交易时会获得交易质量乘数，因此许多存储提供商提供特殊的定价和服务来吸引使用DataCap进行交易的客户。

默认情况下，当您与分配了DataCap的地址进行交易时，您将在交易时使用DataCap。

如果通过[API](https://github.com/filecoin-project/lotus/blob/master/documentation/en/api-v0-methods.md#ClientStartDeal) 进行交易，请确保在调用'ClientStartDeal'时将'VerifiedDeal'参数设置为'true'。

```json
[
  {
    "Data": {
      "TransferType": "string value",
      "Root": {
        "/": "bafy2bzacea3wsdh6y3a36tb3skempjoxqpuyompjbmfeyf34fi3uy6uue42v4"
      },
      "PieceCid": null,
      "PieceSize": 1024
    },
    "Wallet": "f01234",
    "Miner": "f01234",
    "EpochPrice": "0",
    "MinBlocksDuration": 42,
    "ProviderCollateral": "0",
    "DealStartEpoch": 10101,
    "FastRetrieval": true,
    "VerifiedDeal": true
  }
]

```

如果从命令行进行交易，请确保将标志“---verified deal=true”作为参数传递。

```shell
 lotus client deal --verified-deal=true
```

### 检查剩余的DataCap余额

收到地址的DataCap后，您可以通过访问启用此功能的站点（例如[verify.glif.io](https://verify.glif.io/)) 来检查剩余余额或者通过节点查询地址。

#### 使用LotusV1.10.0

```shell
lotus filplus check-client-datacap f00000
```

#### 使用LotusV1.9.0及以下版本

_注：[Lotus-shed](https://github.com/filecoin-project/lotus/tree/master/cmd/lotus-shed) 是您需要构建和安装的独立软件包（在[lotus](https://github.com/filecoin-project/lotus) 的源码中'make lotus shed'）,虽然这些特性计划合并到Lotus中_

```shell
lotus-shed verifreg check-client f00000
```

### 寻找存储提供商以获得Fil+交易

客户可以通过几种不同的方式找到存储提供商，以获得Fil+存储交易：

1. 在[Filecoin Plus Registry](https://plus.fil.org/) 的**For Clients**部分，有一个[Miner Registry](https://plus.fil.org/miners) 其中列出了一组自愿接受Fil+存储交易的矿工

2. 使用矿工声誉系统，如[Filecoin声誉系统](http://filrep.io/) 或Textile的[矿工指数](https://docs.textile.io/filecoin/miner-index/) 确定能够满足您需求的存储矿工

3. 加入[fil plus](https://filecoinproject.slack.com/archives/C01DLAPKDGX) 通过Filecoin Slack频道讨论存储选项

4. 使用您的节点访问网络，查询存储提供商（使用“query ask”）以查看其已验证的交易价格

## 参与Fil+治理

如果您有兴趣参与治理和规划，以下是您可以参与的方式：

- 加入[fil plus](https://filecoinproject.slack.com/archives/C01DLAPKDGX) Filecoin Slack频道

- 参加每隔周二召开的社区治理电话会议。使用Filecoin社区活动日历加入或观看#fil plus中的更新

- 创建并评论[notary governance repo](https://github.com/filecoin-project/notary-governance/issues) 中的未决问题
