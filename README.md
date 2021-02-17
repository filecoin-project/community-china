# Awesome-filecoin

## Website
#### 浏览器
- [FilFox](https://filfox.info) - 6Block 团队开发的 Filecoin 浏览器
- [Filscan](https://filscan.io) - IPFS原力团队开发的 Filecoin 浏览器
- [Filscout](https://filscout.io) - 星际联盟团队开发的 Filecoin 浏览器
- [1475ipfs](https://1475ipfs.com/#/blockBrowser) - 1475 团队开发 Filecoin 浏览器

#### 代码仓库
- [lotus](https://github.com/filecoin-project/lotus) - Filecoin项目开源代码地址
- [filecoin-ffi](https://github.com/filecoin-project/filecoin-ffi)
- [rust-fil-proofs](https://github.com/filecoin-project/rust-fil-proofs)
- [bellperson](https://github.com/filecoin-project/bellperson)
- [neptune](https://github.com/filecoin-project/neptune)

#### Filecoin其他实现
- [Venus](https://github.com/filecoin-project/venus) - Filecoin Go语言的实现，基于以前的go-filecoin
- [Fuhon](https://github.com/filecoin-project/cpp-filecoin) - Filecoin C++语言的实现
- [Forest](https://github.com/ChainSafe/forest) - Rust语言的实现

## Network
- [MainNet](https://github.com/filecoin-project/lotus/tree/master) - Filecoin主网
- [Butterfly](https://github.com/filecoin-project/lotus/tree/ntwk-butterfly) - Butterfly 测试网
- [Calibration](https://github.com/filecoin-project/lotus/tree/ntwk-calibration-10.22.0) Calibration 校准网
- [Nerpa](https://github.com/filecoin-project/lotus/tree/ntwk-nerpa) - Nerpa测试网

## Documentation
- Filecoin文档
  - [依赖安装和代码编译](https://docs.filecoin.io/get-started/lotus/installation/#build-and-install-lotus)
  - [挖矿教程](https://docs.filecoin.io/mine/lotus/)
  - []()

- 硬件配置
  - [石榴矿池Filecoin挖矿方案]()
  - [社区推荐硬件方案]()

- 挖矿集群搭建
  - [Filecoin挖矿入门教程]()
  - [Filecoin挖矿集群搭建]()
  - [推荐硬件配置]()
  - [分布式Miner配置]()

- Daemon操作 - Lotus daemon相关操作
  - [节点连接]()
  - [快照导出、导入，快照裁剪]()
  - [转账]()

- Miner操作 - Lotus Miner相关操作
  - [扇区操作]()
  - [存储路径操作]()
  - [提现操作]()
  - [Owner、Worker、Control钱包说明]()
  - [Miner重启时机选择]()
  - [新矿工节点上线CheckList]()

- Worker操作 - Lotus Worker 配置及使用说明
  - [Worker环境变量说明及配置]()

- Deal 操作
  - [Filecoin 订单配置]()
  - [Deal常用操作]()
  - [Miner接单流程详解]()

- 部署运维
  - [Ansible部署工具使用]()
  - [Prometheus + Grafana监控系统搭建]()

- 常用环境变量 - Lotus常用环境变量及使用说明
  - [Lotus Daemon环境变量]()
  - [Lotus Miner环境变量]()
  - [Lotus Worker环境变量]()

- 常见软件问题 - 挖矿常见问题及解决方法
  - [golang编译环境配置]()
  - [rust 和 rustup 编译环境配置（Cargo）]()
  - [解决代码拉取冲突]()
  - [代码编译常见错误解决]()
  - [Ulimit 问题：`Too many open files`]()
  - [Daemon 无法启动时恢复钱包密钥的方法]()
  - [链同步错误：`block was from the future`]()

- 常见硬件问题
  - [显卡掉驱动问题解决]()
  - [内存ECC模式开启]()

- Benchmarks
  - [AMD EPYC 7302 + 2080Ti]()
  - [AMD EPYC 7542 + 2080Ti]()
  - [AMD EPYC 7542 + 3090]()

- 资源消耗统计
  - [磁盘消耗统计]()
  - [内存消耗统计]()
  - [显卡资源消耗统计]()
  - [查看系统资源工具介绍]()
    - htop
    - nvtop

- 技术文章分享
  - [为什么SDR这么慢？]()
  - [Lotus存储证明了什么？]()

## Optimized Lotus
- [熊鹰myScheduler调度]() - lotus 自定义调度程序 myScheduler，参数使用与实测案例分享
- [C2优化版]() - @jacklelv开源的C2优化版
- [分布式Miner]() - @默然开源的分布式Miner
- [调度优化版]() - @默然开源的调度程序

## Ecosystem Tools
- [Fgas](https://fgas.io/index) - 挖矿成本查询，可实时查看抵押币和Gas消耗
- [FileStats](https://filstats.com) - Filecoin挖矿成本查询
- [Spacegap](https://spacegap.github.io/#/) - 主网数据统计概览，显示前50名矿工的算力、账户余额统计
- [Filkeep]() - Filecoin挖矿监控报警系统
- [收益计算器](https://calculator.atpool.com) - 雅典娜矿池收益计算器
- [订单统计](https://storage.fileco) - Filecoin网络订单统计
- [订单查询工具](https://filecoin.tools/) - Filecoin订单市场查询

## Tutorial Repositories
- [MerkleTree的算法流程]()
- [GDB调试Lotus源码]()
- [Seal密封流程分析]()
  - P1计算过程简介
  - P2计算过程简介

## Community
- [Slack]()
- [Twitter]()

## 1. 常用链接

- 主网相关
  - [【主网概览：Spacegap】](https://spacegap.github.io/)
  - [【Filecoin 入门：Get Started on Filecoin】](https://docs.filecoin.io/get-started/)
  - [【如何加入主网？】](https://network.filecoin.io/#mainnet)
  - [【2020/10/15 23:00 : 主网正式上线】](https://filecoinproject.slack.com/archives/C019UFEACBT/p1602773642166700)
  - [【Announcing Mainnet Ignition & Liftoff】](https://filecoin.io/blog/mainnet-ignition/), [中文版：【发布主网点火和启动阶段】](https://filecoin.io/zh-cn/blog/mainnet-ignition/)
  - [【Why 宣布 2 小时做完 P1 的 Slack 地址】](https://filecoinproject.slack.com/archives/C0179RNEMU4/p1600281207439900)
  - [【2 小时 P1 代码解读：来自 #星想法#】](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487317&idx=1&sn=ec5df63004c2d8d3b4816feaaa8a95fd&chksm=fe131e45c96497537cfc69533af2ce1d22b9ee971bc1c82f887c158c791b253e53d830a5722e&mpshare=1&scene=1&srcid=0927obVQHNI3ZXwCREJasfsE&sharer_sharetime=1601188872855&sharer_shareid=467d38d146bef855f0bc3f95686dafdd&key=7adf10a6617c63152da1b75a8bd251853b8a8588847b2579cda2a5c0338e2825281bff6df0b42d2b1c388b892936da600bb032d3d3b51fe0d1cbd96543f8b8c6b1d928e15029b791d809fcdc1fca85c81b536f27531b16b881217b642db5f79915626a0fbeaf1e46e18ada2d3157b5d4ff4312ad87d7f36440f27b23f89215d9&ascene=1&uin=Njg4MDE3MzA4&devicetype=Windows+10+x64&version=62090529&lang=zh_CN&exportkey=AUULtqfytNT5kNex6k%2F0Omo%3D&pass_ticket=2b%2FdHSGnuSTk4Ns5v6uDNutMyGCf%2FTw0%2B4oCzXQgEDDVjfHGCJZ8KWSv%2FW0d%2FRkQ&wx_header=0)
  - [【主网出块最低算力要求：10 TiB】](https://filecoinproject.slack.com/archives/C019UFEACBT/p1602584811072400)
  - [【Filecoin Token 经济模型】](https://spec.filecoin.io/#section-systems.filecoin_token.token)
  - [【FIP-0004 Liquidity Improvement for Storage Miners】](https://github.com/filecoin-project/FIPs/blob/master/FIPS/fip-0004.md) - 【25% 奖励立即释放】
  - [【FIP-0009 Exempt Window PoSts from BaseFee burn】](https://github.com/filecoin-project/FIPs/blob/master/FIPS/fip-0009.md) - 【减少 WindowPoST 费用】[【中文解析】](https://mp.weixin.qq.com/s/BE5PYd8-y96rKDZNTXV1Pw)
  - [【Filecoin基线标准调整： 1EB -> 2.5EB （来自原力区的解读）】](https://mp.weixin.qq.com/s?__biz=MzU4Mzk2Mzc3Mg==&mid=2247501447&idx=1&sn=63e2dc271e49f7e435c80a1a28fd79f8&chksm=fda38394cad40a8247ed217e23fc295cd7598d6a0e55e176dba9faf3781c83ab488da0c5d677&mpshare=1&scene=1&srcid=1020nkJFPqgsS7xhEvd4gn46&sharer_sharetime=1603207486701&sharer_shareid=55a0eb6b664d6eb2b20ee28e1fa010cb&key=a151f3f6b92bc94d06c83345b63b7e6505f607e33fda670db6f8dd5d8c571b0e6e620667574018e7afc9e141556434c9c2ca38a8ad6776f31d6ba258aa67ada3414b54f790f0dba8eea4c0fd29b752276604d727dd114e28943c12acc7f45cf4339a3d3a2b0b3f1aad7d1fa844d1de4c8b114e54bd681fd109e2565bf2761e53&ascene=1&uin=Njg4MDE3MzA4&devicetype=Windows+10+x64&version=6300002f&lang=zh_CN&exportkey=AeANr1bcntLaFOvWOyGltl4%3D&pass_ticket=smRz8iUM1C93CVyjEKwSttkqd6J2StzjpprXRW%2B0IyybK2xkzyjf1xdbSJsDsm%2Fu&wx_header=0)
  - [【协议实验室在Filecoin经济中的参与】](https://protocol.ai/blog/pl-participation-in-the-filecoin-economy/)
  - [Filecoin挖矿成本实时查询：FGAS](https://fgas.io/) 【推荐】
  - [Filecoin挖矿成本查询：FileStats](https://filstats.com/) 【推荐】
- [【封装 32GB 扇区所需硬件消耗情况评估】](https://docs.filecoin.io/mine/hardware-requirements/#specific-operation-requirements)
- [Lotus网络(Calibration, Nerpa, Mainnet, Butterfly)](https://network.filecoin.io/)

- 实时币价查看网站、钱包
  - [【Coinlist 地址】](https://coinlist.co/)
  - [【Gate.io 地址】](https://www.gate.io/)
  - [【Gatecn.io 地址】](https://www.gatecn.io/)
  - [【AICoin 地址】](https://www.aicoin.cn/)
  - [【火币】](https://www.huobi.be/zh-cn/)
  - [【ImToken】](https://www.token.im/)

- [Miner 重启的时机的选择](https://docs.filecoin.io/mine/lotus/miner-lifecycle/#ensuring-proofs-for-the-current-deadline-have-been-sent)
- 【群友项目】
  - [【群友 @熊鹰 调度器 myScheduler 】： 《lotus 自定义调度程序 myScheduler，参数使用与实测案例分享》](http://202.74.1.76/myScheduler1.2.2/myScheduler.pdf)
  - [【群友 @ican fly 开源项目】: 矿工监控告警系统](https://github.com/twosson/fil_exporter)
  - [【群友 @Rock-Yang 提供】：Filecoin 挖矿入门系列教程](http://www.r9it.com/20191217/lotus-cluster-mining.html)
- Lotus官方文档
  - [旧版文档](https://docs.lotu.sh/)
  - [新版文档](https://docs.filecoin.io/)
  - [新版文档【中文版】](https://filecoin.io/zh-cn/)
  - [搭建 Testnet本地测试网](https://docs.filecoin.io/build/local-devnet/#devnet-with-vanilla-lotus-binaries)
  - [SpaceRace 文档](https://docs.filecoin.io/mine/spacerace/#structure-and-rules)
  - [SpaceRace 奖励说明](https://filecoin.io/zh-cn/blog/welcome-to-space-race/)
- 代码下载地址
  - [Lotus](https://github.com/filecoin-project/lotus)
  - [Go-filecoin](https://github.com/filecoin-project/go-filecoin)
  - [Rust-fil-proof](https://github.com/filecoin-project/rust-fil-proofs)
  - [Rust-filecoin-proofs-api](https://github.com/filecoin-project/rust-filecoin-proofs-api)
  - [Filecoin-ffi](https://github.com/filecoin-project/filecoin-ffi)
  - [Rust-fil-nse-gpu](https://github.com/filecoin-project/rust-fil-nse-gpu) - NSE 新算法
- 浏览器
  - [官方浏览器 stats](https://stats.testnet.filecoin.io/) - **官方**
  - [Filscout](https://filscout.io/en/) - 星际联盟团队开发
  - [官方 Filscan](https://filscan.io/)
  - [1475ipfs](https://1475ipfs.com/#/blockBrowser) - 1475 团队开发
  - [FilFox](https://filfox.info/zh) - 6Block 团队
  - [Filplorer](https://filplorer.com/) - 未知
  - [雅典娜 FIL 收益计算器](https://calculator.atpool.com/) 冰河实验室 [【视频演示链接】](https://mp.weixin.qq.com/s/zLZ7t1-88DdiM0ud9Y5xCQ)

- [矿工排行榜： Filfox](https://beta.filfox.io/en/ranks)

- [Filecoin官方博客](https://filecoin.io/blog/)
- [Lotus Specification 设计文档](https://filecoin-project.github.io/specs/)
- 水龙头地址
  - [Calibration](https://faucet.calibration.fildev.network/)
- Benchmark 数据
  - [Testnet2(V20)](https://github.com/filecoin-project/lotus/issues/839)
  - [Testnet3(V24)](https://github.com/filecoin-project/lotus/issues/1475)
  - [Testnet3(V25)](https://filecoin-benchmarks.on.fleek.co/)
  - [Testnet3(V25)](https://github.com/CoinSummer/benchmarks/tree/master/benchmarks)
  - [V26/V27 测试结果见文末](./README.md)
- Proof 证明文件国内下载
  - [导出 JDCloud 环境变量](https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/) - `export IPFS_GATEWAY=https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/`
  - [最新版Proofs发布地址](https://proofs.filecoin.io/) - 最新发布 Proof 参数的地方【官方】
- [Filecoin经济模型](https://filecoin.io/blog/filecoin-cryptoeconomic-constructions/)
- [甘特图](https://app.instagantt.com/shared/s/1152992274307505/latest)
- [测试网第二阶段启动](https://filecoin.io/zh-cn/blog/filecoin-testnet-phase-2-is-here/)
  - [400w FIL 奖励细节（中文版）](https://filecoin.io/zh-cn/blog/announcing-testnet-incentives/)
  - [Slack 上消息发布](https://filecoinproject.slack.com/archives/CPFTWMY7N/p1591727244272500)
  - [400w FIL 奖励细则（官方博客）](https://filecoin.io/blog/announcing-testnet-incentives/)
- rust 和 rustup 的安装环境配置（Cargo）
  - [官方文档](https://www.rust-lang.org/tools/install)
  - [社区文档](https://learnku.com/docs/rust-lang/2018/ch01-01-installation/4494)
- 使用 GPU 计算 Precommit2
  - [项目地址](https://github.com/filecoin-project/neptune)
  - [相关链接](https://filecoinproject.slack.com/archives/CEGB67XJ8/p1587776730458900)

- Filecoin Discover
  - [官方博客（中文版）](https://filecoin.io/zh-cn/blog/intro-filecoin-discover/)
  - [常见问题](https://store.filecoin-discover.com/pages/%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98)
  - [硬盘信息（8T 企业级 Seagate 硬盘）](https://www.amazon.com/Seagate-256MB-Cache-3-5-Inch-Enterprise/dp/B07D9625PB/ref=sr_1_3?dchild=1&keywords=exos+seagate+8tb&qid=1588907531&sr=8-3)
  - [Slack 频道：fil-discover-support](fil-discover-support)
  - [Filecoin Discover 商店](https://store.filecoin-discover.com/)

- [本地测试网](https://docs.lotu.sh/en+setup-local-dev-net)

- [IPFS.GUIDE 的地址导航栏（带图标，挺好看的）](http://www.ipfs.guide/)
  
- [官方挖矿参考文档： mining-hardware-config-v6.pdf](./files/mining-hardware-config-v6.pdf)

- Filecoin 经济解读
  - [官方博客](https://filecoin.io/blog/introducing-the-filecoin-economy/)
  - [中文版](https://filecoin.io/zh-cn/2020-engineering-filecoins-economy-zh-cn.pdf)


## 2. 主网


- [【Filecoin基线标准调整，矿工收益影响几何？ --  IPFS原力区】](https://mp.weixin.qq.com/s?__biz=MzU4Mzk2Mzc3Mg==&mid=2247501447&idx=1&sn=63e2dc271e49f7e435c80a1a28fd79f8&chksm=fda38394cad40a8247ed217e23fc295cd7598d6a0e55e176dba9faf3781c83ab488da0c5d677&mpshare=1&scene=1&srcid=1020nkJFPqgsS7xhEvd4gn46&sharer_sharetime=1603207486701&sharer_shareid=55a0eb6b664d6eb2b20ee28e1fa010cb&key=fdd054e9602c88a6238f19a0836803b0fd9b4dfe9d322e7e0c67089549c42aa497a0f216322a0eb1909fab98021658f05dcd056e4b8bff8538f9273139d155495b4452d4456a3f3fda39575cb877bd848651d70a1f9b0e5667b2b77ca16950e01207422f34137395920e0eafbe8ee41e8653e46825bc73e3b5da63fd4d876196&ascene=1&uin=Njg4MDE3MzA4&devicetype=Windows+10+x64&version=6300002f&lang=zh_CN&exportkey=AY%2Fvc21LpsL3R2pes6P4K3o%3D&pass_ticket=TFnj1pD7tykPCIgDGuKYZcdOfaIfb0u%2FvZfbW6ChLakoFcIM9lRZRv3xBvKW0StG&wx_header=0)

### 2.1 活动

- [【上海区块链周 - Filecoin开放日来啦：10月26日上海】](https://mp.weixin.qq.com/s?__biz=Mzg4MTExNjkyOQ==&mid=2247484073&idx=1&sn=f3965a7e4ddf884847f8fe4b3aa09e86&chksm=cf6b90c7f81c19d139058fdb96e96362b62996506a2efccf7f8a482ae112307d82d5f737668e&mpshare=1&scene=1&srcid=1022ogRfHl9qzrhRmT6SnQDn&sharer_sharetime=1603348526756&sharer_shareid=10686d73612a2945faf2b799273d77b1&key=d9259f2335ef3c3ceef032fd0e98ed5ba372a3d3afe0f4c05f70b27863ac4f6a55499bb6578f9e5dff4e9563d9d72020e7ebf0e343dcf94c2e34dbead89448549c11731a916208c430f35d214b9a705b17a74aeb8a037b1718473c0ad4580c6b442c97f18846d3e1aa599fd15a9fa2433d87f03e3d06eff2233f43594e23c3ce&ascene=1&uin=Njg4MDE3MzA4&devicetype=Windows+10+x64&version=6300002f&lang=zh_CN&exportkey=AcHkqaQ32fMX03yUeNe2suc%3D&pass_ticket=TFnj1pD7tykPCIgDGuKYZcdOfaIfb0u%2FvZfbW6ChLakoFcIM9lRZRv3xBvKW0StG&wx_header=0)
- [【Filecoin启动周AMA答疑】](https://filecoin.io/zh-cn/blog/filecoin-liftoff-ama/)

### 2.2 宣称分叉

- [FileStar Project Litepaper 文曲星项目 白皮书初稿](https://github.com/filestar-project/litepaper)
  - [Filestar 浏览器](https://filestar.info/zh)
  - [filestar.net](https://filestar.net/zh)
  - [Filecoin分叉项目FileStar文曲星发布白皮书，拟构建Web3物理基础设施](https://www.panewslab.com/wap/zh/articledetails/1603174008447211.html)
- [filecash](https://github.com/filecash)
  - [FILCASH 上线大会总结](https://www.jianshu.com/p/e3fe823bafdd)
  - [从FIL诞生讲起，为何分叉反成「众望所归」？](https://www.minerbbs.com/37500-1-1.html)
- [Filvision](https://github.com/filecoin-vision/)
  - [Filecoin Vision 宣言](https://github.com/filecoin-vision/manifesto)
  - [github: filecoin-vision](https://github.com/filecoin-vision/lotus)
  - [Filecoin主网未上线分叉已来：《Filecoin Vision 宣言》](https://www.jinse.com/news/blockchain/829082.html)
  - [Filecoin能否真的分叉？](https://www.sohu.com/a/420603504_120635680)

### 2.3 SpaceRace2 专用【已废弃】



### 2.4 主网上线后依然可用的测试网

由于某些需求，主网上线之后，官方依然保留测试网，用于测试：

- [网络列表](https://network.filecoin.io/)
  - [【Butterfly】](https://network.filecoin.io/#butterfly) : 
    For core implementers testing new code. This network suffers frequent resets and is not recommended for most users.
  - [【Calibration】](https://network.filecoin.io/#calibration) : 
    Calibration is the primary live testing network. It is used to evaluate Filecoin at meaningful scale via testing, benchmarking, and optimizations. It is recommended for most prospective miners and app developers.
  - [【Nerpa】](https://network.filecoin.io/#nerpa) :
    For app developers looking to do small-scale testing. Has small sector sizes and reduced proofs parameters, so sealing takes ~25 minutes.

[【主网在这】](https://network.filecoin.io/#mainnet)


## 3. SpaceRace 专用【已废弃】


### 3.1 参数下载

使用 JDCloud 下载 32GB 的证明参数：

```
# v28 版本的参数
export IPFS_GATEWAY=https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/
./lotus fetch-params 32GiB
```

### 3.2 官方文档

- [SpaceRace 说明](https://docs.filecoin.io/mine/spacerace/#structure-and-rules)
- [SpaceRace 常见问题](https://docs.filecoin.io/mine/spacerace/#frequently-asked-questions)

### 3.3 自己创建矿工

如果水龙头无法创建矿工，可以取一些 FIL 币，那可以自己在本地创建矿工：

```sh
# (1) 生成钱包地址【已有的忽略】
./lotus wallet new bls
# (2) 去水龙头取一次 FIL 币【一次可以取得 100 FIL】
# (3) 本地创建矿工【请把 t3 开头的地址替换成你自己的钱包地址】
./lotus-miner init --owner t3u3fa4z6sxprcm47ufzfiayyg6jnpsulis2xaua5fpyifmuzap2kavw7pefvgu5j3jeb4mtfaqvppzcqwl6gb --sector-size 32GiB
```

注： 创建矿工一般不支持指定 actor 地址，既： t01000, t01001,t1002 等，也就是说，init 命令中的 `--actor t01xxx` 是不可用的。


## 4. 节点操作


### 4.1 查看节点信息
```sh
# 查看本节点所监听的地址:
lotus net listen
# 查看连接的节点列表:
lotus net peers
```

### 4.2 手动连接其它节点（命令中的地址为示例地址）
```sh
lotus net connect /ip4/47.240.110.221/tcp/44845/p2p/12D3KooWRgxLL84TSkYSjhvhCy5ZNSuJZZzHWp2FXDY7ufqGBmUW
```
当启动 daemon 后无法正常同步链上的数据，可以试试在启动 daemon 的时候禁用自动连接 peers （即：加上 `--bootstrap=false` 参数），然后手动连接到一个正常节点，例如：
```sh
lotus daemon --bootstrap=false
lotus net connect /ip4/47.240.110.221/tcp/44845/p2p/12D3KooWRgxLL84TSkYSjhvhCy5ZNSuJZZzHWp2FXDY7ufqGBmUW
```
上述的节点是示例节点，当您在使用该命令的时候，您需要自己去找一个可以使用的节点。

### 4.3 手动下载 proof 参数
```sh
# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
./lotus fetch-params --proving-params 2KiB     # 例如下载 2KiB 扇区对应的 Proof 参数
./lotus fetch-params --proving-params 16MiB    # 下载 16MiB 扇区对应的 Proof 参数
./lotus fetch-params --proving-params 32GiB    # 下载 32GiB 扇区对应的 Proof 参数

# v27 版本参数【目前在 next 分支: 2020/06/15】
git fetch
git checkout origin/next
export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
./lotus fetch-params 32GiB
```
[参考](https://github.com/filecoin-project/lotus/blob/master/documentation/en/local-dev-net.md)

### 4.4 编译参数

#### v28 版本代码的编译命令:

源码编译底层 rust 库的命令：

```sh
FFI_BUILD_FROM_SOURCE=1 make clean all lotus-bench
```

对于 Intel 的机器，可能由于兼容性原因（比如，执行过程中出现非法指令： `illegal instruction`），需要添加相应的参数：

```sh
FFI_BUILD_FROM_SOURCE=1 CGO_CFLAGS="-O -D__BLST_PORTABLE__" make clean all lotus-bench
```

#### 启用内存最大化参数：
```sh
export FIL_PROOFS_MAXIMIZE_CACHING=1
```
该参数仅针对 32GB 扇区有效。

#### 启用 Log 日志：
```sh
export RUST_LOG=Debug
```
运行 miner 之前加入该参数可以在 miner 的日志中查看更详细的输出信息（底层 rust 代码的输出信息），Log 登记从低到高分别有： Trace、Debug、Info、Warn、Error，Trace 输出的信息最详细，Error 输出的信息最少，仅输入错误信息。

### 4.5 修改 Proofs 文件路径
```sh
export FIL_PROOFS_PARAMETER_CACHE=/path/to/proof_params/v28/
```

### 4.6 导入导出同步数据：

```sh
# 导出同步数据（去除无用的消息，保证导出的 car 文件很小）
./lotus chain export --recent-stateroots=900 --skip-old-msgs snapshot.car
# 这样导出的话，导出的 car 文件会很大（文件中保存了历史消息）
# ./lotus chain export snapshot.car
# 导入同步数据（在此之前保证 .lotus 目录中的内容是空的）
# 导入数据之后， daemon 默认自动启动，
# 如果不想在导入数据之后启动 daemon，可以加上参数 --halt-after-import
./lotus daemon --import-snapshot snapshot.car
```

[【官方 5GB 左右的快照】](https://fil-chain-snapshots-fallback.s3.amazonaws.com/mainnet/minimal_finality_stateroots_latest.car)，先手动下载好这个 `car` 文件，然后在一个干净的 `.lotus` 目录中导入即可，记得在做任何操作之前先备份数据（**至少需要备份好钱包私钥**：参考 【16.2】 小节）。

参考：[【快速同步数据：Slack】](https://filecoinproject.slack.com/archives/C0179RNEMU4/p1600187096118400)， [【官方文档：Chain sync】](https://github.com/filecoin-project/filecoin-docs/blob/master/docs/get-started/lotus/installation.md#chain-sync)，[【官方文档：create-a-snapshot】](https://docs.filecoin.io/get-started/lotus/chain-snapshots/#create-a-snapshot)


## 5. Storage miner 操作


### 5.1 查看扇区状态
```sh
# 列举所有扇区信息:
lotus-miner sectors list
# 查看某个扇区的历史状态
lotus-miner sectors status --log <SectorID>
```

### 5.2 手动修改扇区状态【谨慎操作】
```sh
lotus-miner sectors update-state --really-do-it <SectorID> <NewSectorStatus>
# 例如：手动修改扇区 1 的状态为 FaultedFinal 状态
lotus-miner sectors update-state --really-do-it 1 FaultedFinal
```

### 5.3 更改默认存储路径
```sh
export LOTUS_STORAGE_PATH="/path/to/.lotusminer"
```
- 默认存储路径是 `~/.lotusminer`，可通过指定 `LOTUS_STORAGE_PATH` 环境变量来更改；
- 每个存储路径下都会有 `sectorstore.json` 配置文件，该文件可以配置该存储路径的用途，比如，是否可以用来存储密封过程中生成的临时文件 `"CanSeal": true`， 是否可以用来存储密封好的数据 `"CanStore": true`，以及该路径的权重 `"Weight": 10` 和一个唯一标识符：`ID`；
```json
{
  "ID": "e59facdc-6a82-418f-a25e-4cbd9165b5de",
  "Weight": 10,
  "CanSeal": true,
  "CanStore": true
}
```
### 5.4 增加存储路径
```sh
# 设置数据存储路径，该路径用来存储最终密封好的数据
# 执行该命令可能需要一点时间等待
lotus-miner storage attach --store --init /path/to/persistent_storage

# 设置密封扇区的存储路径，密封完成之后该路径下的数据会被自动清空，相当于临时目录
# 执行该命令可能需要一点时间等待
lotus-miner storage attach --seal --init /path/to/fast_cache
```
以上两个命令都是在启动了 miner 之后才可以执行，是一种动态添加存储路径的方式，非常灵活。 当然还可以在命令中添加权重 `--weight=10`，默认权重是 `10`。
执行该命令后，可通过以下命令查看存储列表:
```sh
lotus-miner storage list
```

### 5.5 移动存储目录
默认的存储目录 `~/.lotusminer` 可以移动到其他地方。
移动前最好先停掉 daemon 和 miner。
移动后，假设新路径为 `/path/to/.lotusminer`，需要手动更改 `/path/to/.lotusminer` 目录下 `storage.json` 中的 `StoragePaths` 为新路径：
```json
{
  "StoragePaths": [
    {
      "Path": "/path/to/.lotusminer"
    }
  ]
}
```
移动后，重启 daemon 和 miner，miner 会重新读取新路径下的所有 sector 信息。

### 5.6 使用远程 daemon（daemon 在其他机器）
假设daemon在 `192.168.1.100` 机器上，miner在 `192.168.1.101` 机器上：
1. 修改远程 daemon (192.168.1.100)上 `~/.lotus/config.toml` 中的 `ListenAddress` 为：
```toml
# Default config:
[API]
ListenAddress = "/ip4/192.168.1.100/tcp/1234/http"
```
2. 将远程 daemon (192.168.1.100) 上 `~/.lotus` 目录下的 `api` 和 `token` 拷贝到 miner 机器(192.168.1.101)的 `~/.lotus` 目录下；
3. 重启 miner 即可。

### 5.7 启动 miner 参考命令

```sh
# 注意空格不能少【以下命令是使用 screen 进行后台启动的方式】
t=$(date +%Y_%m_%d_%H_%M_%S)
FIL_PROOFS_USE_GPU_TREE_BUILDER=1 FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S miner -t miner_${t} ./lotus-miner run

# 常规方式
FIL_PROOFS_USE_GPU_TREE_BUILDER=1 FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace ./lotus-miner run

```

### 5.8 FIL 余额操作

```sh
# 从 【Available】 中提取 10 个 FIL 到 【Worker Balance】 中
./lotus-miner actor withdraw 10
# 从 【Worker Balance】 中发送 10 个 FIL 到 【Available】 中（假设 minerID 是 t01000 ）
./lotus send t01000 10
```

[参考](https://filecoinproject.slack.com/archives/CEGB67XJ8/p1588805545137700)

### 5.9 更新扇区操作

原来使用 pledge 命令质押的扇区是垃圾扇区，里面的数据都是垃圾数据，为了让这些扇区能够存储有效数据，可以把这些扇区标记为可存储有效数据的扇区：

```sh
./lotus-miner sectors mark-for-upgrade <sector number>
```

[参考](https://docs.filecoin.io/mine/lotus/sector-pledging/#upgrading-pledged-sectors)

### 5.10 移除扇区操作

如何扇区出现问题，或者不想要某个扇区，可以把该扇区删除：

```sh
./lotus-miner sectors remove --really-do-it <sector id>
```

### 5.11 移除时空证明失败的扇区

由于误删、调度错乱等各种原因，导致扇区已提交到了链上，但时空证明失败的问题，可以使用`lotus-shed`，一次性删除链上失败的扇区。

```sh
# 编译 lotus-shed
make lotus-shed

# 删除链上错误的扇区
lotus-shed sectors terminate --really-do-it [sectorNum1 sectorNum2 ...]
```
该命令将会发送一条消息，一次性删除错误扇区(注意：会扣币，目前一个扇区大约扣0.1个FIL)。



## 6. Worker 操作

### 6.1 查看 Worker 列表
```sh
lotus-miner sealing workers
```
### 6.2 集群配置

**6.2.1. 修改 miner**

修改 miner `~/.lotusminer/config.toml` 里面的 `ListenAddress` 和 `RemoteListenAddress` ，把这两个变量中的地址都改为 miner 本机的地址:
```toml
[API]
ListenAddress = "/ip4/192.168.1.100/tcp/2345/http"
RemoteListenAddress = "192.168.1.100:2345"
```
**6.2.2. 配置 worker**

方法一：使用环境变量

```sh
export STORAGE_API_INFO=<TOKEN>:<API>
```
TOKEN 为 `~/.lotusminer` 中的 `token`；
API 为 `~/.lotusminer` 中的 `api`；

注意：启动 miner 之后再查看这两个的值。

**方法二：直接复制文件**

在 **启动了 miner 之后**，复制 miner 的 `~/.lotusminer` 目录中的 `token` 和 `api` 到 worker 中的  `~/.lotusminer` （worker 中没有这个目录就手动创建一个），然后启动 worker 即可。

**6.2.3. 启动 worker**
```sh
lotus-worker run --address=192.168.1.201:2333 --precommit1=false --precommit2=true --commit=true

# 新版改用 --listen=xxx
lotus-worker run --listen=192.168.1.201:2333 --precommit1=false --precommit2=true --commit=true
```
启动worker需要注意以下几点：
- 要给 worker 指定**本机地址**和一个**随机端口（至少四位数）**;
- `precommit1`、`precommit2` 和 `commit` 默认是启用的，如果想要禁用，可以设置为 `false`，例如：
`--precommit1=false`;
- `commit` 参数是配置 `commit2` 的，`commit1` 无法在 Worker 中启用。


## 7. Deal 操作

### 7.1 Deal配置 - Miner有公网IP
假设Miner的公网IP为`123.123.73.123`，内网IP为`10.4.0.100`。
#### (1) MinerIP配置
修改`$LOTUS_STORAGE_PATH/config.toml`文件中的以下内容：
- 将`ListenAddresses`中的IP改为`123.123.73.123`（即公网IP地址），端口自己指定一个固定端口，例如`1024`；
```sh
[Libp2p]
ListenAddresses = ["/ip4/123.123.73.123/tcp/1024", "/ip6/::/tcp/0"]
```
配置修改以后，重启Miner。
#### (2) 设置multiaddress
这里的multiaddress即为上面第(1)步中配置的`ListenAddresses`的地址。
```sh
lotus-miner actor set-addrs /ip4/123.123.73.123/tcp/1024
```
设置完等待消息确认后，可以通过以下命令查看结果:
```sh
lotus state miner-info [t0xxxx]
```
#### (3) 设置Miner连接的节点
执行以下命令查看Miner连接的节点:
```sh
lotus-miner net peers
```
如果返回的结果很少(只有本地一个节点)，需要手动连接节点：
```sh
lotus-miner net connect /dns4/bootstrap-1.calibration.fildev.network/tcp/1347/p2p/12D3KooWQAKmfoAQBDwyaruE1bfFsuekttD974arrkB4G4ZKWk6r
lotus-miner net connect /dns4/bootstrap-0.calibration.fildev.network/tcp/1347/p2p/12D3KooWCoZZ9gExszHaNLoLXhW7DJa3dDZXjGgHELxwhqxoKJUQ
lotus-miner net connect /dns4/bootstrap-2.calibration.fildev.network/tcp/1347/p2p/12D3KooWKRNgz3a8RyxLFa1gihdFHMG6rPKuEFnSwmzk4GTo2TC1
lotus-miner net connect /dns4/bootstrap-3.calibration.fildev.network/tcp/1347/p2p/12D3KooWJt4zgPL8B2cMoCLDQ6MPpMKH62ZjgvvPmrfDBLWpggKG
```
**注意：上面连接的地址，需要替换成Louts项目`/build/bootstrappers.pi`文件中的地址**
连接成功后会有`connect 12D3KooWQAKmfoAQBDwyaruE1bfFsuekttD974arrkB4G4ZKWk6r: success`这样的返回。
执行上面的操作后，再次执行`lotus-miner net peers`，应该就能看到不少节点了。

#### (4) 太空竞赛订单过滤
太空竞赛可以配置Miner只接收官方机器人的订单[参考官方文档](https://docs.filecoin.io/mine/spacerace/#how-do-i-prioritize-deals-from-competition-bots)，将`$LOTUS_STORAGE_PATH/config.toml`文件中的：
```sh
[Dealmaking]
#  Filter = ""
```
改为：
```sh
Filter = "jq -e '.Proposal.Client == \"t1nslxql4pck5pq7hddlzym3orxlx35wkepzjkm3i\" or .Proposal.Client == \"t1stghxhdp2w53dym2nz2jtbpk6ccd4l2lxgmezlq\" or .Proposal.Client == \"t1mcr5xkgv4jdl3rnz77outn6xbmygb55vdejgbfi\" or .Proposal.Client == \"t1qiqdbbmrdalbntnuapriirduvxu5ltsc5mhy7si\" '"
```

#### (5) 检查配置
- 首先通过官方提供的[Ping工具](https://ping.eu/ping)看看能否ping通自己Miner的公网IP；
- 其次，通过[[Port-chk](https://ping.eu/port-chk/)]查看自己Miner的公网端口是否开放；
- `telnet 123.123.73.123 1024`(注意替换成自己的IP和端口)看看是否返回`/multistream/1.0.0`。

### 7.2 Deal配置 - Miner无公网IP
如果Miner机器没有公网IP，就需要在边缘网络设备(如路由器，或有公网IP和端口转发服务的服务器)上做公网IP和端口向内网IP和端口的转发，假设公网IP为`123.123.73.123`，Miner的内网IP为`10.4.0.100`。
#### (1) MinerIP配置
修改`$LOTUS_STORAGE_PATH/config.toml`文件中的以下内容：
- 将`ListenAddresses`中的端口改为自己指定一个固定端口，例如`1024`；
- 将`AnnounceAddresses`中的IP改为Miner所在网络的公网IP(例子中为：123.123.73.123)，端口改为公网监听端口，例如`10240`。
```sh
[Libp2p]
ListenAddresses = ["/ip4/0.0.0.0/tcp/1024", "/ip6/::/tcp/0"]
AnnounceAddresses = ["/ip4/123.123.73.123/tcp/10240"]
```
配置完以后，重启Miner。
#### (2) 设置端口转发规则
- 如果边缘网络设备为路由器，登录路由器管理控制台，将外网的`10240`转发到内网的`1024`端口；
- 如果边缘网络设备为服务器，按以下方式设置转发规则：
编辑系统的`/etc/sysctl.conf`文件(以Ubuntu为例)，将`net.ipv4.ip_forward=1`前面的#注释去掉，保存文件，然后执行`sudo sysctl -p`使其生效。
在Miner所在网络中，添加以下端口转发规则，将外网的10240端口映射到内网的1024端口。
```sh
sudo iptables -t nat -A PREROUTING -p tcp -m tcp --dport 10240 -j DNAT --to-destination 10.4.0.100:1024
```
其中`10.4.0.100`为Miner的内网IP。

#### (3) 设置multiaddress
参照7.1中的设置multiaddress。
#### (4) 设置Miner连接的节点
参照7.1中的设置Miner连接的节点。

### 7.3 Deal常用操作
```sh
# query ask
lotus client query-ask [t0xxxx]

# 查看本地导入的文件
lotus client local

# 导入文件，需要在daemon所在机器上操作
lotus client import /path/filename

# 发送订单
lotus client deal [CID] [miner_id] 0.0000000005 622080

# 查看deals列表
lotus client list-deals

# Miner查看存储订单列表
lotus-miner storage-deals list

# Miner查看检索订单列表
lotus-miner retrieval-deals list
```


## 8. 常用环境变量


```sh
# lotus 路径：
LOTUS_PATH
# 例如： export LOTUS_PATH=/home/user/nvme_disk/lotus

# miner 路径： 
LOTUS_STORAGE_PATH
# 例如： export LOTUS_STORAGE_PATH=/home/user/nvme_disk/lotusminer

# worker 路径： 
WORKER_PATH
# 例如： export WORKER_PATH=/home/user/nvme_disk/lotusworker

# proof 证明参数路径： 
FIL_PROOFS_PARAMETER_CACHE
# 例如： export FIL_PROOFS_PARAMETER_CACHE=/home/user/nvme_disk/filecoin-proof-parameters

# 临时文件夹路径： 
TMPDIR
# 例如： export TMPDIR=/home/user/nvme_disk/tmp

# 最大化内存参数
FIL_PROOFS_MAXIMIZE_CACHING
# 例如： export FIL_PROOFS_MAXIMIZE_CACHING=1

# Rust 日志
RUST_LOG
# 例如： export RUST_LOG=Debug

# GPU计算Precommit2
FIL_PROOFS_USE_GPU_COLUMN_BUILDER
# 例如： export FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1

# 源码编译底层库
FFI_BUILD_FROM_SOURCE
# 例如： export FFI_BUILD_FROM_SOURCE=1

# GOLANG 代理
GOPROXY
# 例如： export GOPROXY=https://goproxy.cn

# 启动小扇区支持
FIL_USE_SMALL_SECTORS
# 例如： export FIL_USE_SMALL_SECTORS=true

# 显卡相关
BELLMAN_CUSTOM_GPU
# 例如： export BELLMAN_CUSTOM_GPU="GeForce RTX 2080 Ti:4352"

# 下载证明参数代理：
IPFS_GATEWAY
# 例如： export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"

# Parent cache 参数
FIL_PROOFS_PARENT_CACHE
# 例如： export FIL_PROOFS_PARENT_CACHE=/disk/parent_cache

# 启用 GPU 计算 Precommit2 中的部分过程
FIL_PROOFS_USE_GPU_TREE_BUILDER
FIL_PROOFS_USE_GPU_COLUMN_BUILDER
# 例如：export FIL_PROOFS_USE_GPU_TREE_BUILDER=1
# 例如：export FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1

# 禁用 GPU 参数
BELLMAN_NO_GPU
# 例如：export BELLMAN_NO_GPU=1
# 如果要启用 GPU，则不能让这个环境变量（BELLMAN_NO_GPU）出现在系统的环境变量中（env）
# 如果它出现在 env 中，则需要使用以下命令取消，
#（因为设置 export BELLMAN_NO_GPU=0 无效）：
unset BELLMAN_NO_GPU

# AMD 3970x 2h10m 跑完 P1 环境变量
FIL_PROOFS_USE_MULTICORE_SDR=1

```


## 9. 解决拉取代码冲突问题（git pull）


如果你在执行 `git pull` 的时候出现类似如下错误（`CONFLICT xxx`），你可以使用以下方法解决该问题：

```sh
warning: Cannot merge binary files: build/genesis/devnet.car (HEAD vs. 8bea0e02d77a6d36c3fc72746a9b38c7018608e9)
Auto-merging build/genesis/devnet.car
CONFLICT (add/add): Merge conflict in build/genesis/devnet.car
Auto-merging build/bootstrap/bootstrappers.pi
CONFLICT (content): Merge conflict in build/bootstrap/bootstrappers.pi
Automatic merge failed; fix conflicts and then commit the result.
```

上述示例来源于从 `interopnet` 分支的 `799f5e5` 版本执行 `git pull` 的时候出现的问题（2020年5月7日），而这个问题在新版的代码中经常会出现，解决这个问题的方法如下（只是其中一个方法，当然还有别的方法）：

### 9.1 方法一：
```sh
# 先重置代码，恢复代码到原始状态
git reset --hard HEAD
# 再随意的获取一个很久以前的代码版本号： commit ID
git log -111 | tail | grep -ni "commit "
# 假设这里拿到的一个 commit ID 是："8c0f2c1ce06"
# 然后恢复到这个版本
git reset --hard 8c0f2c1ce06
# 最后再重新拉取代码
git pull
# 这时候就完成代码更新了，并解决代码冲突问题
# 此时就可以重新编译代码了：
# 当然，在这之前，你可能需要设置一下 GOLANG 的代理
# 已经挂了代理的用户可忽略
env RUSTFLAGS="-C target-cpu=native -g" FFI_BUILD_FROM_SOURCE=1 make clean all bench
```

### 9.2 方法二：
```sh
# 先重置代码，恢复代码到原始状态
git reset --hard HEAD
# 切换到 master 分支或者其它分支也行
git checkout master
# 删除 interopnet 分支
git branch -D interopnet
# 拉取所有代码
git fetch
# 或者拉取 interopnet 分支的代码：
git fetch origin interopnet:interopnet
# 再切换到 interopnet 分支
git checkout interopnet
```

### 9.3 方法三：
```sh
# 如果你没有修改代码，直接执行以下两条命令
git fetch origin
git reset --hard origin/interopnet
```



## 10. 重置本地测试网环境


如果你在使用本地测试网，发现 lotus daemon 启动不了，或者是 miner 启动不了，或者是其它的问题，这时候，如果你没有别的更好的解决方法，你可以尝试完全清理本地环境，然后再启动 daemon 和 miner， 默认情况下，你需要清理如下的文件或文件夹等：
```sh
# 如果 daemon 一直同步不了，也可以试试这个方法，很多情况下可以解决同步问题
# 此外，处理前请检查环境变量，比如，是否修改了默认的 ~/.lotus 目录的位置
rm -rf ~/.lotus/
rm -rf ~/.lotusminer/
rm -rf ~/.lotusworker/
rm -rf ~/.lotus-bench/
rm -rf ~/.genesis-sectors/
rm -rf ~/dev.gen
rm -rf ~/localnet.json
```

如果是同步不了，还建议清空 `FIL_PROOFS_MAXIMIZE_CACHING` 环境变量，最近不少人因为在 `.bashrc` 中加入这个环境变量导致无法同步，原因未知：

```sh
unset FIL_PROOFS_MAXIMIZE_CACHING
```


## 11. GDB 调试 lotus 源码


### 11.1 GDB 调试 lotus 源码

使用 GDB 调试 lotus 源码（包括上层的 **go** 语言代码和底层的 **rust** 语言代码），你只需要一个 GDB 工具就可以单步调试了，非常方便：

[【GDB 调试 lotus 源码的链接】](./gdb_debug.md)

### 11.2 本地测试网搭建教程

为了方便调试测试网，可以在本地自己搭建一个私有链，搭建教程参考 [【官方教程】](https://docs.filecoin.io/build/local-devnet/)，

多 Miner 本地测试网的搭建教程可参考 [【./scripts】](./scripts/) 中的脚本，目录中有启动 genersis 节点的两个脚本：`start_genesis_daemon.sh` 和 `start_genesis_miner.sh`，以及启动其它节点的两个脚本：`start_daemon.sh` 和 `start_miner.sh`，这四个脚本中有一些默认的设置，如果你需要运行这些脚本，你可以自己进行修改：

- 默认执行脚本的目录为 `home` 目录（即：`~/$`）
- lotus 可执行文件的默认目录在： `/home/tears/filecoin/official/lotus`
- 创世节点所在的主机名称默认是：`tears` （你需要修改为你自己的主机名称）
- 创世节点所在的主机地址默认是：`192.168.1.11` （你需要修改为你自己的主机地址）
- 扇区大小默认是：`2KiB`
- 节点启动 daemon 的时候会删除 `home` 目录下的旧文件，请检查：`start_genesis_daemon.sh` 和 `start_daemon.sh`

脚本文件：

- [start_genesis_daemon.sh](./scripts/start_genesis_daemon.sh)
- [start_genesis_miner.sh](./scripts/start_genesis_miner.sh)
- [start_daemon.sh](./scripts/start_daemon.sh)
- [start_miner.sh](./scripts/start_miner.sh)

### 11.3 本地编译 Bellperson 库

本教程适用于需要修改 bellperson 代码的朋友：

[【本地编译 Bellperson 库代码】](./build_bellperson.md)



## 12. 编译相关问题



### 12.1 crate.io 源的问题

如果因为编译的时候卡住，症状如下图所示：

![更新 crate.io 时卡住](./pictures/stuck_in_comiple_for_crate.io.png)

解决方法：可以试试更改 `crate.io` 的源为国内的源，例如：

```sh
# 上海交通大学（正常使用）
[source.crates-io]
replace-with = 'sjtu'
[source.sjtu]
registry = "https://mirrors.sjtug.sjtu.edu.cn/git/crates.io-index"

# 清华的源（失效）
[source.crates-io]
replace-with = 'tuna'
[source.tuna]
registry = "https://mirrors.tuna.tsinghua.edu.cn/git/crates.io-index.git"

# rustcc社区
[source.crates-io]
replace-with = 'rustcc'
[source.rustcc]
registry = "git://crates.rustcc.cn/crates.io-index"

```
使用方法：`vi ~/.cargo/config`， 然后把以上中的任意一个添加进去，保存好，然后再重新编译一次即可。
[参考](https://blog.csdn.net/xiangxianghehe/article/details/105874880)

### 12.2 GOPROXY 的问题

如果在编译的时候因为下载代码子模块的时候卡住（GO 代码），可能是 GOPROXY 没有设置，此时，设置一下 GOPROXY，然后再重新编译一遍即可：

```sh
export GOPROXY=https://goproxy.cn
```
### 12.3 go 版本太低的问题

lotus 的 interopnet 分支在编译的时候，如果检测到 go 的版本低于 1.14， 则会编译失败，如下图所示：

![go 版本过低](./pictures/upgrade_go_1.14_version.png)

解决方法，安装新版本的 go，并软链接 `/usr/bin/go` 到新版的 go 可执行文件中（或者卸载旧版的 go）：

```sh
# Ubuntu 20.04 示例
sudo apt install golang-1.14
# 删除原来的 go 软链接
sudo rm /usr/bin/go
# 让它链接到新版本的 go 可执行文件中
sudo ln -s /usr/lib/go-1.14/bin/go /usr/bin/go
```

### 12.4 编译提示 Rustup 1.43.1 版本找不到

在编译最新版的 master 分支分支的时候遇到这个问题（2020年6月19号23点，master 的 commit 是： ffa7be86fe6ee738ab4b095469029b9fac51e090），编译的时候提示找不到 `1.43.1-x86_64-unknown-linux-gnu` ，错误信息如下所示：

![rustup 版本未能找到](./pictures/rustup_version_not_found.png)

解决方法是跳过这个版本，直接使用 `nightly` 的版本，即，替换以下这个文件中的 `1.43.1` 为 `nightly`。

```sh
echo "nightly" > ./extern/filecoin-ffi/rust/rust-toolchain
```

然后再重新编译，即可正常编译。

### 12.5 Intel 机器 【SIGILL: illegal instruction】

使用 Intel （老）机器，调试本地测试网测试 2KiB 扇区，执行 `lotus-seed` 命令的时候出现程序崩溃现象：

```sh
./lotus-seed genesis add-miner localnet.json ~/.genesis-sectors/pre-seal-t01000.json
```
错误信息大致如下所示：

```sh
SIGILL: illegal instruction
PC=0xe910af m=4 sigcode=2

goroutine 0 [idle]:
runtime: unknown pc 0xe910af
stack: frame={sp:0x7efc33ec4830, fp:0x0} stack=[0x7efc336c4ec8,0x7efc33ec4ac8)
00007efc33ec4730:  0000000003ed46a0  000000000063e394 <path/filepath.walkSymlinks+660> 
00007efc33ec4740:  0000000000000000  0000000000000000 
00007efc33ec4750:  0000000000000000  0000000000000000 
......
goroutine 1 [syscall]:
runtime.cgocall(0xe7a700, 0xc0009b77c8, 0x6cb501)
	/usr/lib/go-1.14/src/runtime/cgocall.go:133 +0x5b fp=0xc0009b7798 sp=0xc0009b7760 pc=0x51b75b
github.com/supranational/blst/bindings/go._Cfunc_blst_keygen(0xc000156320, 0xc0001562c0, 0x20, 0x0, 0x0)
	_cgo_gotypes.go:298 +0x45 fp=0xc0009b77c8 sp=0xc0009b7798 pc=0xe61505
github.com/supranational/blst/bindings/go.KeyGen(0xc0001562c0, 0x20, 0x20, 0x0, 0x0, 0x0, 0x6882897a)
	/home/ml/filecoin/official/lotus/extern/fil-blst/blst/bindings/go/blst.go:79 +0x96 fp=0xc0009b7808 sp=0xc0009b77c8 pc=0xe63596
github.com/filecoin-project/lotus/lib/sigs/bls.blsSigner.GenPrivate(0xc000542468, 0xc39cc8db33e69201, 0xc300000000000008, 0x0, 0xc000542460)
	/home/ml/filecoin/official/lotus/lib/sigs/bls/init.go:32 +0xeb fp=0xc0009b7868 sp=0xc0009b7808 pc=0xe6c98b
......
```

**解决方法：** 编译的时候加上参数 `CGO_CFLAGS="-D__BLST_PORTABLE__"`：

```sh
FFI_BUILD_FROM_SOURCE=1 CGO_CFLAGS="-D__BLST_PORTABLE__" make clean debug
```

参考：[【lotus/issues/4059】](https://github.com/filecoin-project/lotus/issues/4059)

### 12.6 编译错误：Unable to find libclang

新版的 lotus 需要用到 clang 编译器来编译部分底层的代码，因此，如果系统上没有安装 clang 的话，在编译 lotus 的时候就会报错，错误信息如下所示：

```sh
cargo:rustc-link-lib=stdc++
cargo:warning=couldn't execute `llvm-config --prefix` (error: No such file or directory (os error 2))
cargo:warning=set the LLVM_CONFIG_PATH environment variable to the full path to a valid `llvm-config` executable (including the executable itself)

--- stderr
thread 'main' panicked at 'Unable to find libclang: "couldn\'t find any valid shared libraries matching: [\'libclang.so\', \'libclang-*.so\', \'libclang.so.*\', \'libclang-*.so.*\'], set the `LIBCLANG_PATH` environment variable to a path where one of these files can be found (invalid: [])"', /home/ml/.cargo/registry/src/mirrors.tuna.tsinghua.edu.cn-df7c3c540f42cdbd/bindgen-0.54.0/src/lib.rs:1959:13
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace

warning: build failed, waiting for other jobs to finish...
error: build failed
+ rm -f /tmp/tmp.npUjYGfyHa
Makefile:11: recipe for target '.install-filcrypto' failed
make[1]: *** [.install-filcrypto] Error 101
make[1]: Leaving directory '/home/ml/filecoin/official/lotus/extern/filecoin-ffi'
```

**解决方法：** 编译之前先安装 clang：

```sh
# 安装 clang
sudo apt install clang
# 或者
# sudo apt install clang-10
# 出问题可以试一下（在 Ubuntu 18.04 上安装 clang-10 的时候可能会需要加上【--fix-missing】参数）：
# sudo apt install clang-10 --fix-missing

# 然后再重新编译
FFI_BUILD_FROM_SOURCE=1 make all
```
参考：[【lotus/issues/3826】](https://github.com/filecoin-project/lotus/issues/3826)


### 12.7 Ulimit 问题：Too many open files (os error 24)

miner 在运行过程中可能会出现这个错误 `Too many open files (os error 24)`， 导致程序退出，解决的方法就是设置系统中最大允许的文件打开数量：

`ulimit` 命令分别可以作用于 `soft` 类型和 `hard` 类型，`soft` 表示可以超出，但只是警告
`hard` 表示绝对不能超出，两者的值一般是不一样的:

```sh
# 查看当前值（默认是 soft 值）：
ulimit -a | grep -ni "open"
# 查看当前值 soft 值：
ulimit -Sa | grep -ni "open"
# 查看当前值 hard 值：
ulimit -Ha | grep -ni "open"

# 临时修改（只对当前 Shell 有用，修改立即生效）：
# 修改为 1048576 （默认修改的是 soft 值）：
ulimit -n 1048576  # 等效于 ulimit -Sn 1048576
# 临时修改 hard 值为 1048576
ulimit -Hn 1048576
# 可同时修改 soft 和 hard 的值：
ulimit -SHn 1048576

# 针对正在运行中的miner进程，可以通过以下命令修改：
prlimit --pid <PID> --nofile=1048576:1048576
# 通过以下命令查看修改：
cat /proc/<PID>/limits

# 永久修改（重新登录或重启生效）: 
# 把文件 /etc/systemd/user.conf  和 /etc/systemd/system.conf 中的字段修改如下：
DefaultLimitNOFILE=1048576
# 并修改 /etc/security/limits.conf 文件，添加如下内容：
* hard nofile 1048576
* soft nofile 1048576
```

Ref: [【解决Too many open files问题】](https://blog.csdn.net/zgaoq/article/details/81911860)、[【Too many open files的四种解决办法】](https://www.cnblogs.com/huaweicloud/p/11861475.html)

### 12.8 daemon 无法启动时恢复钱包密钥的方法

由于某种原因，可能由于 `.lotus` 目录下的某些文件损坏导致 `lotus daemon` 无法启动，此时，最关键的还是要先把钱包的密钥导出来备份好（如果之前有备份的话就可以不用往下看了），导出的方法如下所示：

假设出故障的机器叫做 `机器A`，新的机器叫做 `机器B`：

- (1). 在 `机器B` 上启动一个干净的 `daemon` 进程（同一台机器上也行，但是要保证有一个新的 `.lotus` 目录，和旧 `.lotus` 目录不能冲突），启动之后，`daemon` 会自动创建一个新的 `.lotus` 目录
- (2). 关闭 `机器B` 上的 `daemon` 进程，删除 `机器B` 上的 `.lotus` 目录中的 `token` 文件和 `keystore` 文件夹。
- (3). 拷贝 `机器A` 上的 `.lotus` 目录中的 `token` 文件和 `keystore` 文件夹到 `机器B` 的 `.lotus` 目录中
- (4). 再次启动 `机器B` 中的 daemon，此时就可以在 `机器B` 中正常的导出钱包地址了

### 12.9 链同步错误：block was from the future

同步链错误，由于本机的时间与网络时间不同步导致，解决方法如下所示：

```sh
# 同步本机时间
ntpdate ntp.aliyun.com
```

### 12.10 编译错误：/usr/bin/ld: cannot find -lhwloc

hwloc 是获取 CPU 硬件信息的有用工具，lotus 需要使用到这个工具，安装一下就可以：

```sh
# Ubuntu 上的解决方法：
sudo apt install hwloc libhwloc-dev
```
[参考](https://github.com/daschl/hwloc-rs/issues/23) 

### 12.11 编译错误：git@github.com: Permission denied (publickey)

给自己的 github 添加一对公私钥就可以了，生成公私钥对的命令参考如下，生成之后，你还需要把公钥复制到 github 账号的 `SSH Keys` 中（这步需要在网页上操作），默认生成的公钥名称是 `id_rsa.pub`, 私钥名称是 `id_rsa`，私钥放在你的 `~/.ssh` 文件夹中即可，公钥上传到 github 服务器中：

```sh
# 生成公私钥对，带 .pub 后缀的文件是公钥，是需要上传到 github 上面的
# 命令中 【your_email@email.com】 输入你的 github 账号
ssh-keygen -t rsa -C "your_email@email.com"
```

[参考](https://blog.csdn.net/fenghuibian/article/details/73350890)

### 12.12 同步错误：Error: chain contained block marked previously as bad

例如，当前链同步的高度是 6100，但是同步的时候出现某个块是坏块，因此，会导致同步失败，失败信息如下所示：

```sh
Error: chain linked to block marked previously as bad ([bafy2bzacedwp2ciwsjirnxc5gdtehddjurpp7qijzal32su7ob5vh4ons2sm2],
```

解决方法：先把高度往前调一些（比如，当前高度在 6100， 往前调到 6000），然后再手动标记某些坏块：

```sh
lotus chain sethead --epoch 6000
# 重启一下 daemon
lotus sync mark-bad bafy2bzacedwp2ciwsjirnxc5gdtehddjurpp7qijzal32su7ob5vh4ons2sm2
```

[参考](https://filecoinproject.slack.com/archives/CPFTWMY7N/p1593170480169100)

### 12.13 编译 lotus 1.2.1 失败：Update Golang to version to at least 1.15.5

最新版 `lotus-v1.2.1` 需要使用最新版的 `golang` (`golang-1.15.5`) 来编译，否则会如下错误：

```sh
Makefile:10: Your Golang version is go 1.15.2
Makefile:11: *** Update Golang to version to at least 1.15.5.  Stop.
```

目前在 `Ubuntu 20.04` 上可以直接使用 `apt` 安装最新版的 `golang` （安装新版 `golang` 之前最好先卸载旧版的，否则可能会出问题），如果是使用 `Ubuntu 18.04`，则需要手动下载 `golang` 手动安装：

- 下载地址：[【https://golang.org/dl/】](https://golang.org/dl/)， 或者[【go1.15.5.linux-amd64.tar.gz】](https://golang.org/dl/go1.15.5.linux-amd64.tar.gz)，

- 安装方式：[【https://golang.org/doc/install#install】](https://golang.org/doc/install#install)

安装参考命令：

```sh
tar -C /usr/local -xzf go1.15.5.linux-amd64.tar.gz
vi ~/.bashrc
# 在 ~/.bashrc 文件的末尾加上： export PATH=$PATH:/usr/local/go/bin
source ~/.bashrc
```


## 13. Benchmark


### 13.1 v26 版本参数

- CPU： AMD 3970x (32核心64线程)
- GPU： RTX 2080Ti
- 内存： 256GB (2133MHz)
- 硬盘： NVMe 1TB * 2

#### CPU+GPU

```sh
# 命令
t=$(date +%Y_%m_%d_%H_%M_%S)
FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --storage-dir=/home/gossip/disk_nvme1/lotus-bench

# 结果

results (v26) (34359738368)
seal: addPiece: 6m15.3044756s (87.3 MiB/s)
seal: preCommit phase 1: 4h12m45.246321786s (2.16 MiB/s)
seal: preCommit phase 2: 33m25.314284805s (16.3 MiB/s)
seal: commit phase 1: 3.376010315s (9.48 GiB/s)
seal: commit phase 2: 43m46.504108069s (12.5 MiB/s)
seal: verify: 30.908086ms
unseal: 4h10m45.224077903s  (2.18 MiB/s)

generate candidates: 2.716063ms (11.5 TiB/s)
compute winnnig post proof (cold): 4.727151776s
compute winnnig post proof (hot): 2.921746828s
verify winnnig post proof (cold): 72.31729ms
verify winnnig post proof (hot): 15.464289ms

compute window post proof (cold): 17m16.771668516s
compute window post proof (hot): 11m34.142457801s
verify window post proof (cold): 5.157438678s
verify window post proof (hot): 43.763838ms

```

#### CPU

```sh
# 命令
# BELLMAN_NO_GPU 环境变量的使用请参考第 6 节的说明
t=$(date +%Y_%m_%d_%H_%M_%S)
BELLMAN_NO_GPU=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --no-gpu --storage-dir=/home/gossip/disk_nvme1/lotus-bench

# 结果

results (v26) (34359738368)
seal: addPiece: 6m18.045655671s (86.7 MiB/s)
seal: preCommit phase 1: 4h11m2.665760729s (2.18 MiB/s)
seal: preCommit phase 2: 51m35.998398427s (10.6 MiB/s)
seal: commit phase 1: 3.2534009s (9.84 GiB/s)
seal: commit phase 2: 1h19m24.107221673s (6.88 MiB/s)
seal: verify: 27.802053ms
unseal: 4h10m25.648494319s  (2.18 MiB/s)

generate candidates: 2.331868ms (13.4 TiB/s)
compute winnnig post proof (cold): 5.941671756s
compute winnnig post proof (hot): 4.172625272s
verify winnnig post proof (cold): 64.764102ms
verify winnnig post proof (hot): 17.119677ms

compute window post proof (cold): 26m34.328794808s
compute window post proof (hot): 20m47.199004707s
verify window post proof (cold): 5.195517605s
verify window post proof (hot): 46.366221ms

```

### 13.2 v27 版本参数

- CPU： AMD 3970x (32核心64线程)
- GPU： RTX 2080Ti
- 内存： 256GB (2133MHz)
- 硬盘： NVMe 1TB * 2

#### CPU+GPU【next 分支】

```sh
# 命令
t=$(date +%Y_%m_%d_%H_%M_%S)
FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --storage-dir=/home/gossip/disk_nvme1/lotus-bench

# 结果

results (v27) (34359738368)
seal: addPiece: 10m0.840580268s (54.5 MiB/s)
seal: preCommit phase 1: 4h11m42.386256191s (2.17 MiB/s)
seal: preCommit phase 2: 27m5.279700449s (20.2 MiB/s)
seal: commit phase 1: 2.594602083s (12.3 GiB/s)
seal: commit phase 2: 50m31.427904703s (10.8 MiB/s)
seal: verify: 27.388448ms
unseal: 4h12m40.52388773s  (2.16 MiB/s)

generate candidates: 2.714168ms (11.5 TiB/s)
compute winnnig post proof (cold): 6.114939733s
compute winnnig post proof (hot): 5.097337848s
verify winnnig post proof (cold): 50.41631ms
verify winnnig post proof (hot): 15.678623ms

compute window post proof (cold): 18m51.79180394s
compute window post proof (hot): 11m25.783003134s
verify window post proof (cold): 5.36059116s
verify window post proof (hot): 47.596046ms

```


#### CPU【master 分支】

```sh
# 命令
# BELLMAN_NO_GPU 环境变量的使用请参考第 6 节的说明
t=$(date +%Y_%m_%d_%H_%M_%S)
BELLMAN_NO_GPU=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --no-gpu --storage-dir=/home/gossip/disk_nvme1/lotus-bench


# lotus 版本
# lotus version 0.4.1+git.9d56dabb

# 结果

results (v27) (34359738368)
seal: addPiece: 10m10.633126077s (53.7 MiB/s)
seal: preCommit phase 1: 4h14m22.4235947s (2.15 MiB/s)
seal: preCommit phase 2: 51m36.998604335s (10.6 MiB/s)
seal: commit phase 1: 1.151689271s (27.8 GiB/s)
seal: commit phase 2: 1h36m30.270483546s (5.66 MiB/s)
seal: verify: 34.083162ms
unseal: 4h13m10.812170289s  (2.16 MiB/s)

generate candidates: 2.333397ms (13.4 TiB/s)
compute winnnig post proof (cold): 7.327267683s
compute winnnig post proof (hot): 6.318365117s
verify winnnig post proof (cold): 45.298003ms
verify winnnig post proof (hot): 16.806329ms

compute window post proof (cold): 28m6.99008574s
compute window post proof (hot): 20m41.201090515s
verify window post proof (cold): 5.46349285s
verify window post proof (hot): 37.986216ms

```

### 13.3  v28 版本参数

- CPU： AMD 3970x (32核心64线程)
- GPU： RTX 2080Ti
- 内存： 256GB (2133MHz)
- 硬盘： NVMe 1TB * 2
- 时间：2020/11/26
- 其它： 多线程 P1 + GPU P2

```sh
results (v28) SectorSize:(34359738368), SectorNumber:(1)
seal: addPiece: 10m48.240241696s (50.55 MiB/s)
seal: preCommit phase 1: 2h22m21.760639531s (3.836 MiB/s)
seal: preCommit phase 2: 24m51.560433206s (21.97 MiB/s)
seal: commit phase 1: 1.140462976s (28.06 GiB/s)
seal: commit phase 2: 47m29.898859543s (11.5 MiB/s)
seal: verify: 8.01946ms

generate candidates: 853.599µs (36.61 TiB/s)
compute winning post proof (cold): 2.128980727s
compute winning post proof (hot): 1.78541416s
verify winning post proof (cold): 61.022724ms
verify winning post proof (hot): 4.231715ms

compute window post proof (cold): 5m48.192993009s
compute window post proof (hot): 5m28.177627942s
verify window post proof (cold): 6.493587214s
verify window post proof (hot): 10.944523ms
```

### 13.4 磁盘最大消耗

磁盘最大消耗情况，其实不止 `516.64GiB`，因为在每次生成 `tree-r-last` 的时候，都会临时保存中间的 `4.6GB` 数据磁盘中，例如： `[4.6G]  sc-02-data-tree-r-last-6.dat`，因此一次密封过程中的最大磁盘消耗，应该是 `516.64GiB - 9.1MB + 4.6GB`，约等于  `522GiB`。
具体情况如下所示：

```sh
[2020_12_23_04_01]: current size: 554741069840 (516.64GiB)
/home/gossip/disk_nvme1/lotus-bench
└── [4.0K]  bench159597807
    ├── [4.0K]  cache
    │   └── [4.0K]  s-t01000-1
    │       ├── [  64]  p_aux
    │       ├── [ 32G]  sc-02-data-layer-10.dat
    │       ├── [ 32G]  sc-02-data-layer-11.dat
    │       ├── [ 32G]  sc-02-data-layer-1.dat
    │       ├── [ 32G]  sc-02-data-layer-2.dat
    │       ├── [ 32G]  sc-02-data-layer-3.dat
    │       ├── [ 32G]  sc-02-data-layer-4.dat
    │       ├── [ 32G]  sc-02-data-layer-5.dat
    │       ├── [ 32G]  sc-02-data-layer-6.dat
    │       ├── [ 32G]  sc-02-data-layer-7.dat
    │       ├── [ 32G]  sc-02-data-layer-8.dat
    │       ├── [ 32G]  sc-02-data-layer-9.dat
    │       ├── [4.6G]  sc-02-data-tree-c-0.dat
    │       ├── [4.6G]  sc-02-data-tree-c-1.dat
    │       ├── [4.6G]  sc-02-data-tree-c-2.dat
    │       ├── [4.6G]  sc-02-data-tree-c-3.dat
    │       ├── [4.6G]  sc-02-data-tree-c-4.dat
    │       ├── [4.6G]  sc-02-data-tree-c-5.dat
    │       ├── [4.6G]  sc-02-data-tree-c-6.dat
    │       ├── [4.6G]  sc-02-data-tree-c-7.dat
    │       ├── [ 64G]  sc-02-data-tree-d.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-0.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-1.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-2.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-3.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-4.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-5.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-6.dat
    │       ├── [9.1M]  sc-02-data-tree-r-last-7.dat
    │       └── [1.5K]  t_aux
    ├── [4.0K]  sealed
    │   └── [ 32G]  s-t01000-1
    └── [4.0K]  unsealed
        └── [ 32G]  s-t01000-1

5 directories, 32 files
```

### 13.5 内存最大消耗

每过 5 秒统计了一次内存消耗情况，发现 `P1` 最大内存消耗大约是 `73GB`，`C2` 最大内存消耗大约是 `173GB`，如下所示：

```sh

# P1
[2020_12_23_03_18_01:]
              total        used        free      shared  buff/cache   available
Mem:          251Gi        73Gi       1.6Gi       4.0Mi       176Gi       175Gi
Swap:         2.0Gi       1.2Gi       823Mi

# C2
[2020_12_23_04_11_01:]
              total        used        free      shared  buff/cache   available
Mem:          251Gi       173Gi       1.9Gi        20Mi        76Gi        76Gi
Swap:         2.0Gi       1.2Gi       795Mi

```

注： 统计数据可能不是非常准确。


## 14. 一些简单的脚本


### 14.1 Auto pledge sectors script

脚本中默认每 15 分钟添加一个扇区，总共添加 2000 个扇区（你可以自己修改），此外，使用次脚本你需要手动指定 lotus 的路径，即：脚本中的 `lotus_path` 参数。

[auto_pledge_sector.sh](./scripts/auto_pledge_sector.sh)



## 15. Filecoin 中文交流群


**Filecoin 中文交流群** 是目前国内最友好的 Filecoin 技术交流群，
也是全球最大的、最活跃的 Filecoin 技术交流社区，
欢迎广大 Filecoin 爱好者加入我们的技术交流群。
进群请加微信：**max-yu-666** 【微信群管理员】

<img src="https://user-images.githubusercontent.com/1715211/97078045-9c787480-161b-11eb-89ab-54d73fcea9d5.jpg" width="200" height="200" />

Filecoin 中文交流-1群（目前已满）,
Filecoin 中文交流-2群（目前已满）,
Filecoin 中文交流-3群（目前还有空位）,


![Filecoin 中文交流-1群（目前已满）](./pictures/wechat_group_01.png)
![Filecoin 中文交流-2群（目前已满）](./pictures/wechat_group_02.png)
![Filecoin 中文交流-3群（目前还有空位）](./pictures/wechat_group_03.png)



## 16. Seal 密封流程


### 16.1 P1 计算过程简介

对于 `32GB` 的扇区，P1 计算过程是生成 11 层数据，每层数据都是 `32GB` 大小，并且除了第一层之外，剩下的 10 层数据的生成过程是完全一样的。
这里涉及到一个节点的概念，其实就是把一个 32 字节的数据当做一个节点，一层 Layer 由 `1G`（`1G=1024*1024*1024`） 个连续的节点组成，仅此而已。

![P1 运算流程简介](./pictures/P1.png)

### 16.2 P2 计算过程简介

P2 的运算过程其实也很简单，只是使用的哈希算法是 `Poseidon` 哈希算法而已，本质上还是进行哈希运算。
P2 分为两个阶段，一个是 `Building column hash`（也叫做 `Building tree c`），另一个叫做 `Building tree r last`。
只不过，在 `Building column hash` 的时候，会把每层的 `1G` 个节点的划分为大小相等的 `8` 份，每一份都是 `128M` 个节点，最后生成一个 8 个 `tree-c`（`tree-c-0` ~ `tree-c-7`）（下图为了简洁，没有体现划分 8 份的操作）。
`Building tree r last` 和  `Building column hash` 基本一样，只是使用的数据不一样罢了，最后生成 `tree-r-last-0` ~ `tree-r-last-7`。

![P2 运算流程简介](./pictures/P2.png)



## 17. 其它


### 17.1 币单位转换

$ 1 FIL = 10^{9} nanoFIL = 10^{18} attoFIL $

参考：[【go-humanize】](https://github.com/dustin/go-humanize/blob/master/si.go#L10)

### 17.2 钱包密钥导出与导入

```sh
# 查看钱包地址，一般是 t3 开头的一串数字（新版中使用的是 f3 开头）
./lotus wallet list
# 导出钱包的私钥到 mywallet.key 文件中（示例中的钱包地址为： t3w7r6dguggp62nbopehewt4amjh2iq2belz2u73q3k3z7zoarw44k6cra3og7yyvuy3f7gxh4omcmwpnuipaa）
# 你需要把这个钱包地址替换为你自己的钱包地址
wallet_addr="t3w7r6dguggp62nbopehewt4amjh2iq2belz2u73q3k3z7zoarw44k6cra3og7yyvuy3f7gxh4omcmwpnuipaa"
./lotus wallet export ${wallet_addr} > mywallet.key
# 导入钱包私钥
./lotus wallet import ./mywallet.key
# 导入之后，需要把该钱包地址设置为默认地址（当然，如果你有多个钱包地址，你可以自己选择）
./lotus wallet set-default ${wallet_addr}
```

### 17.3 Slack APP

[安卓版本 APK](./app/Slack.7z)

[Windows 版本 EXE](./app/SlackSetup.7z)

### 17.4 参考文档
- [NewMai-CommonLinkForFilecoin](https://github.com/NewMai/CommonLinkForFilecoin)
- [Lotus Docs](https://docs.lotu.sh/)
- [Improving connectivity](https://docs.filecoin.io/mine/connectivity/)


## 18. 常用的两个查看系统资源的工具


### 18.1 htop 查看 CPU 和内存等信息

htop 比系统自带的 top 界面更加友好，在 Ubuntu 上安装只需要执行：

```sh
sudo apt install htop
```

效果如下：

![htop效果](./pictures/htop.png)

### 18.2 nvtop 查看显卡信息

nvtop 比 nvidia-msi 好看多了，但是安装稍微麻烦一些：
在 Ubuntu 19.04 之后可以直接使用 `sudo apt install nvtop` 安装，否则，你需要执行以下命令安装：

```sh
sudo apt install cmake libncurses5-dev libncursesw5-dev git
git clone https://github.com/Syllo/nvtop.git
mkdir -p nvtop/build && cd nvtop/build
cmake ..
cmake .. -DNVML_RETRIEVE_HEADER_ONLINE=True  # 如果上一个命令出错就用这个
sudo make install
```

效果如下：

![nbvtop效果](./pictures/nvtop.png)



## 19. 推荐

### 19.1 技术文章

- **星想法**
	1. [Filecoin - 为什么SDR这么慢？](https://mp.weixin.qq.com/s/8V2r1627R6igtvXlV42mJQ)
	1. [Filecoin - Lotus存储证明了什么？](https://mp.weixin.qq.com/s/LSkuEJl9mYV98jD7bZ8iUQ)

### 19.2 开源

- 1. [【3群 群友 `@呆` 开源的 monitor 】](./files/lotus-worker-monitor.zip)
- 2. [【2群 群友 `@默然` 开源的调度程序 】](https://github.com/moran666666/lotus-1.4.0.git)
- 3. [【开源社区 `@jackoelv` 开源的 C2 优化程序 -- 仅 2080Ti 】](https://github.com/jackoelv/bellperson/tree/2080Ti)、[【优化思路】](https://github.com/jackoelv/bellperson/blob/3090/todo.md)、[【3090 显卡优化版本】](https://github.com/jackoelv/bellperson/tree/3090)


## 20. 打赏

如果您觉得此文档对您有帮助，欢迎打赏哦 ---- **【Filecoin技术交流群-1/2/3群群主：TEARS】**

### 20.1 Filecoin 钱包：

**【FIL 钱包地址】**：`f1vrpuagiiln7qqgfduph2qse7eo5zhriidekp6fq`

**【FIL QRCODE】**：

![TEARS_FILCOIN_QRCODE](./pictures/FIL_QRCODE_OF_TEARS.png)

### 20.2 微信钱包：

![TEARS_WX_QRCODE](./pictures/WX_QRCODE_OF_TEARS.png)

## **参考文档**
- [NewMai-CommonLinkForFilecoin](https://github.com/NewMai/CommonLinkForFilecoin)
- [Lotus Docs](https://docs.lotu.sh/)
- [Improving connectivity](https://docs.filecoin.io/mine/connectivity/)









