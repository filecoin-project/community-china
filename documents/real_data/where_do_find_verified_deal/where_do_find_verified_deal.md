# 存储供应商接收真实数据的方式

 Filecoin生态的发展需要越来越多的存储供应商存储服务，逐步形成成熟且商业化的存储市场才能完全体现FileCoin的商业价值，也有利于所有存储供应商的长期发展。

## 提前准备

分离市场节点，参考教程：[链接](https://github.com/filecoin-project/community-china/blob/master/documents/tutorial/split_markets_node/split_markets_node.md)

## 方式介绍和适用场景

### １.　textile

通过运行bidbot去竞争真实数据订单，[仓库地址](https://github.com/textileio/bidbot),存储供应商实时竞拍，为每个真实数据订单提供最佳的存储解决方案。所有交易都是**离线交易**，而不是 在线订单。存储供应商下载数据以创建交易。离线交易更加稳定，让存储供应商可以更快的拿到数据进行封装，为了更快的下载速度，建议科学上网下载交易数据。

### ２.　estuary

estuary跟textile有明显的不同，它的设计主要是面向**在线订单**的，文档地址[链接](https://docs.estuary.tech/) . 对于存储供应商来说，不需要关注客户端的内容，只需要注册成estuary的存储供应商即可，为方便中国的存储供应商参予，有中文的[注册页面](https://docs.estuary.tech/get-provider-added-cn) , 如果你想接收estuary的在线订单，必须注意以下几点：

- 必须保持开放在线订单并暴露公网ip，如果你中途停掉接单功能可能会被从供应商列表中移除。

- 由于中国的网络环境影响，可以尝试采用VPN的方式，通过代理接收在线订单。

- 注册完可以通过[链接](https://estuary.tech/providers/stats/f01264125)查看是不是自己加入了列表，把最后一个字段替换成自己的服务商ID即可。

### ３. slingshot

很多参加slingshot的项目实际上缺少存储供应商存储数据，当然，不是所有slingshot的参予者存储的都是验证数据（Verified deal），对于未验证数据，存储供应商可以根据情况收取一定的费用，很多参予者也拿到了DataCap，可以发送真实数据订单。这个需要存储供应商随时关注[slingshot频道](https://filecoinproject.slack.com/archives/C01AZP8BKRQ)，如果你已经准备好接收在线订单，可以在slingshot频道发布自己的存储供应商信息以吸引潜在的客户端存储数据。

## 疑问解答

- 可以在这个讨论里交流真实数据相关的问题: <https://github.com/filecoin-project/community-china/discussions/166>

- 你可以随时在slack频道里交流相关的问题。

> 2021年9月中旬“公证人治理会议”计划在未来6个月内额度大大扩展500PiB，快速推广有效数据成为协议实验室Filecoin Plus项目接下来半年的重点。引用自[这里](https://mp.weixin.qq.com/s/jtz6MLe3d9aV2ZgxaJbm9A)。
