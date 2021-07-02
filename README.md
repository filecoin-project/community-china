# Awesome Filecoin

## 1. Website

#### 1.1 浏览器
- [FilFox](https://filfox.info) - 6Block 团队开发的 Filecoin 浏览器
- [Filscan](https://filscan.io) - IPFS原力团队开发的 Filecoin 浏览器
- [Filscout](https://filscout.io) - 星际联盟团队开发的 Filecoin 浏览器
- [1475ipfs](https://1475ipfs.com/#/blockBrowser) - 1475 团队开发 Filecoin 浏览器
- [Stats](https://stats.testnet.filecoin.io/) - 官方 Filecoin 浏览器（按 `ESC` 可查看不同的网络）
- [Spacegap](https://spacegap.github.io/#/) - 官方 Filecoin 浏览器（总览视图）
- [Atpool](https://explorer.atpool.com/) - 雅典娜浏览器-Filecoin专业矿工数据服务

#### 1.2 代码仓库
- [lotus](https://github.com/filecoin-project/lotus) - Filecoin lotus项目源代码地址
- [filecoin-ffi](https://github.com/filecoin-project/filecoin-ffi)
- [rust-fil-proofs](https://github.com/filecoin-project/rust-fil-proofs)
- [bellperson](https://github.com/filecoin-project/bellperson)
- [neptune](https://github.com/filecoin-project/neptune)

#### 1.3 Filecoin其他实现
- [Venus](https://github.com/filecoin-project/venus) - Filecoin Go语言的实现，基于以前的go-filecoin
- [Fuhon](https://github.com/filecoin-project/cpp-filecoin) - Filecoin C++语言的实现
- [Forest](https://github.com/ChainSafe/forest) - Rust语言的实现

## 2. Network
- [网络概览](https://network.filecoin.io/) - 包括主网和测试网等各个网络的详细信息
- [MainNet](https://github.com/filecoin-project/lotus/tree/master) - Filecoin主网
- [Calibration](https://github.com/filecoin-project/lotus/tree/ntwk-calibration-10.22.0) - Calibration 校准网
- [Nerpa](https://github.com/filecoin-project/lotus/tree/ntwk-nerpa) - Nerpa测试网

## 3. Documentation
- Filecoin文档
  - [FIPs 文档入口](https://github.com/filecoin-project/FIPs) - FIPs
  - [官方文档](https://docs.filecoin.io/) - Filecoin Documentation
  - [依赖安装和代码编译](https://docs.filecoin.io/get-started/lotus/installation/#build-and-install-lotus) - Filecoin官方依赖安装和代码编译教程
  - [挖矿教程](https://docs.filecoin.io/mine/lotus/) - Filecoin官方的挖矿教程，系统性强、详细完整，建议新手通读
  - [Filecoin中文文档](https://filecoin.filgo.info/) - 社区全栈老吕提供的Filecoin官方文档中文版
  - [Venus文档](https://venus.filecoin.io/) - Venus Documentation

- 硬件配置
  - [石榴矿池Filecoin挖矿方案](https://6block.com/files/zh/Filecoin%20mining%20solution%20v8.0.pdf) - 石榴矿池Filecoin挖矿解决方案，包含AMD 3960CPU和EPYC 7542两种方案
  - [社区推荐Filecoin硬件方案](https://github.com/filecoin-project/community-china/discussions/18) - 社区推荐的基于AMD EPYC 7542的Filecoin挖矿硬件方案

- 挖矿集群搭建
  - [Filecoin挖矿集群搭建](https://github.com/filecoin-project/community-china/discussions/4) - 如何从零开始搭建一个挖矿集群
  - [分布式Miner集群搭建](https://github.com/filguard/lotus-ops/blob/master/documents/distributed-miner-configuration.md) - 社区分布式Miner架构详解

- Daemon操作
  - [节点启动](https://github.com/filecoin-project/community-china/discussions/2) - Lotus代码编译、节点搭建、配置、启动
  - [节点操作](https://github.com/filecoin-project/community-china/discussions/8) - Lotus节点常用操作，快照导出、导入，快照裁剪，公网IP配置
  - [Lotus钱包常用操作及使用场景](https://github.com/filecoin-project/community-china/discussions/15) - Lotus钱包创建、导入导出，多钱包配置

- Miner操作
  - [扇区操作](https://github.com/filecoin-project/community-china/discussions/14) - 扇区生命周期解析、扇区状态更新、扇区删除
  - [存储路径操作](https://github.com/filguard/lotus-ops/blob/master/documents/storage-manage.md) - 存储路径操作、存储i/o性能分析、网络分析
  - [Owner、Worker、Control钱包说明](https://github.com/filecoin-project/community-china/discussions/15) - 如何配置时空证明、PreCommit、ProveCommit多钱包地址
  - [Miner重启时机选择](https://docs.filecoin.io/mine/lotus/miner-lifecycle/#ensuring-proofs-for-the-current-deadline-have-been-sent) - 重启Miner前需要检查什么
  - [新矿工节点上线CheckList](https://github.com/filguard/lotus-ops/blob/master/documents/new-miner-checklist.md) - 新矿工节点上线操作系统、基础环境、Daemon、Miner、Worker检查列表

- Deal 操作
  - [Filecoin 订单配置及订单操作](https://github.com/filecoin-project/community-china/discussions/5) - 存储矿工如何接订单，订单常见操作

- 部署运维
  - [Ansible部署工具使用](https://github.com/filguard/lotus-ops/blob/master/documents/ansible-deploy-tool-usage.md) - 如何使用Ansible批量自动化部署Daemon、Miner、Worker
  - [Prometheus + Grafana监控系统搭建](https://github.com/filguard/lotus-ops/blob/master/documents/monitoring-deployment.md) - 基于Prometheus和Grafana搭建Filecoin监控报警系统
  - [Lotus日常运维巡检做什么](https://github.com/filecoin-project/community-china/discussions/10) - 日常硬件检查、错误扇区处理、钱包检查、消息池疏通等
  - [Lotus 运维：简单易用的告警系统](https://github.com/filguard/lotus-alert) - 本项目由技术群群友 @mje 提供，可直接发送告警信息到微信

- 常用环境变量
  - [Lotus Daemon环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Daemon常用环境变量说明
  - [Lotus Miner环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Miner常用环境变量说明
  - [Lotus Worker环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Worker如何开启PreCommit1 SDR加速，如何指定显卡型号等

- 常见软件问题
  - [Golang编译环境安装配置](./documents/build/build_env_config.md) - Golang编译环境安装、代理设置
  - [Rust编译环境安装配置](./documents/build/build_env_config.md) - Rust编译环境安装配置，`crate.io` 源国内镜像配置
  - [代码编译常见错误解决](./documents/build/build_env_config.md) - 国内代理配置、Intel机器编译环境变量配置
  - [解决代码拉取冲突]
  - [Ulimit 问题：`Too many open files`]
  - [Daemon 无法启动时恢复钱包密钥的方法]
  - [链同步错误：`block was from the future`]

- 常见硬件问题
  - [CPU开启性能模式](./documents/hardware/cpu_performance.md)
  - 显卡掉驱动问题解决

- Benchmarks
  - [AMD EPYC 7542 + RTX 2080Ti](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-epyc%E7%B3%BB%E5%88%97cpu)
  - [AMD EPYC 7542 + RTX 3080](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-epyc%E7%B3%BB%E5%88%97cpu)
  - [AMD EPYC 7302 + RTX 2080Ti](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-epyc%E7%B3%BB%E5%88%97cpu)
  - [AMD 3970X + RTX 2080Ti](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-3970x%E7%B3%BB%E5%88%97cpu)

- 资源消耗统计
  - [磁盘消耗统计](./documents/resource/resource_usage/resource_usage.md)
  - [内存消耗统计](./documents/resource/resource_usage/resource_usage.md)
  - [显卡资源消耗统计]() ： TODO
  - [查看系统资源工具介绍](./documents/resource/resource_usage/resource_usage.md)
    - htop （CPU 性能查看工具）
    - nvtop （GPU 性能查看工具）

- 技术文章分享
  - [星想法公众号Filecoin系列文章](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU5MzMxNTk2Nw==&action=getalbum&album_id=1458647927098130433)
    - [Filecoin逻辑梳理及源代码导读](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247484751&idx=1&sn=54c2239d9f59c539a1a3c569362da288)
    - [Snark as a Service数据量分析](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487006&idx=1&sn=5c72648790ea19d4151c750b8ce635d7)
    - [Payment Channel介绍](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487029&idx=1&sn=3770740aeee5317d3e1bba74bf2ba411)
    - [Lotus存储证明了什么？](https://mp.weixin.qq.com/s/LSkuEJl9mYV98jD7bZ8iUQ)
    - [PoREP电路介绍](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247486997&idx=1&sn=f0c024ecb25817040ee89241036f456d)
    - [PoRep和PoSt算法源代码导读](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247484787&idx=1&sn=643fb732f00f786da561c86239069294)
    - [深入理解NSE算法](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487062&idx=1&sn=08ac222dfe3a4120922fa07d569bac98)
    - [winningPoSt逻辑介绍](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487013&idx=1&sn=eb69a171b43ec84e7bcf0eea80e37d50)
    - [深入理解WindowPoSt](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487037&idx=1&sn=70f36cdabd2723112f7784408f6c6d9d)
    - [Sector状态管理逻辑](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487121&idx=1&sn=38ae427ba5613d5608448b1e069ed25c)
    - [Precommit2计算介绍](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487141&idx=1&sn=7b28c4f53d1422ae9e0bbe4526a380e4)
    - [为什么SDR这么慢？](https://mp.weixin.qq.com/s/8V2r1627R6igtvXlV42mJQ)
    - [深入理解存储管理](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487237&idx=1&sn=d0dda542c79858977954b247fdeb654e)
    - [C2性能能优化多少？](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487262&idx=1&sn=e143a5329300f8e2a9ff64535b5ffc7a)
    - [Lotus Gas计算](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487295&idx=1&sn=fc6833df469dfa05fc8f538d05417c88)
    - [SDR性能优化原理分析](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487317&idx=1&sn=ec5df63004c2d8d3b4816feaaa8a95fd)
    - [一个越界Bug引发升级](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247487403&idx=1&sn=26fe5fc2152f3f50e53065d840474b8a)
  - [MerkleTree的算法流程](https://github.com/kikakkz/rust-fil-proofs-test/blob/master/apps/data/MerkleTree%E7%9A%84%E7%AE%97%E6%B3%95.txt) - [@kikakkz](https://github.com/kikakkz)分享的MerkleTree算法调用流程
  - Seal密封流程分析
    - AP计算过程简介（TODO）
    - [P1计算过程简介](./documents/tutorial/lotus_seal_process/seal_process.md)
    - [P2计算过程简介](./documents/tutorial/lotus_seal_process/seal_process.md)
    - C1计算过程简介（TODO）
    - C2计算过程简介（TODO）
    - WindowPoST计算过程简介（TODO）
    - WinningPoST计算过程简介（TODO）
- 基础教程
  - [本地搭建 2K 测试网入门教程](./documents/tutorial/local_2k_dev_tutorial/local_2k_dev_tutorial.md) -- 强烈推荐的新手入门教程
  - [Calibration 测试网使用教程](./documents/tutorial/use_cali-net_tutorial/use_cali-net_tutorial.md) -- 强烈推荐的新手入门教程
  - [链数据导入导出使用教程](./document/../documents/tutorial/lotus_chain_op/lotus_chain_op.md)
  - [GDB调试Lotus源码](./documents/tutorial/gdb_debug_lotus/gdb_debug.md)
  - [Filecoin最新挖矿集群硬件配置](https://github.com/filecoin-project/community-china/discussions/18)
  
- 高级教程
    - [Poseidon 哈希算法 C 语言实现](./ref_src/poseidon/PoseidonHashOriginal/Readme.md) - 基础版（所使用的参数和 lotus 有所不同）
    - [Poseidon 哈希算法 C 语言实现](./ref_src/poseidon/PoseidonHashNeptune/Readme.md) - 高级版（所使用的参数和 lotus 完全相同）



## 4. Optimized Lotus
- [熊鹰myScheduler调度](http://202.74.1.76/myScheduler1.2.2/myScheduler.pdf) - [@熊鹰](https://github.com/KevinXiong2018)提供的lotus自定义调度程序myScheduler，参数使用与实测案例分享
- [P2优化版](https://github.com/filguard/rust-fil-proofs) - [@mje](https://github.com/jyma)开源的P2优化版
- [C2优化版](https://github.com/jackoelv/bellperson) - [@jacklelv](https://github.com/jackoelv)开源的C2优化版
- [分布式Miner](https://github.com/moran666666/lotus-1.5.0) - [@默然](https://github.com/moran666666)开源的分布式Miner
- [调度优化版](https://github.com/moran666666/lotus-1.5.0) - [@默然](https://github.com/moran666666)开源的调度程序

## 5. Ecosystem Tools
- [file.app](https://file.app) - 实时订单，存储费用，存储矿工等查询
- [Fgas](https://fgas.io/index) - 挖矿成本查询，可实时查看抵押币和Gas消耗
- [FileStats](https://filstats.com) - Filecoin挖矿成本查询
- [Spacegap](https://spacegap.github.io/#/) - 主网数据统计概览，显示前50名矿工的算力、账户余额统计
- [Filkeep](https://console.filkeep.com) - Filecoin挖矿监控报警系统
- [收益计算器](https://calculator.atpool.com) - 雅典娜矿池收益计算器
- [订单统计](https://storage.fileco) - Filecoin网络订单统计
- [订单查询工具](https://filecoin.tools/) - Filecoin订单市场查询
- [发单、接单工具](https://github.com/nebulaai/swan) - 技术群成员[@竹风](https://github.com/flyworker)开源的矿工接单、客户发单工具
- [矿机投资收益计算器](http://fil8.top/invest/) - 怪盗FIL收益计算器
- [矿池统计工具](http://fil8.top/pools) - Filecoin矿池统计器
- [Slingshot 数据统计](https://slingshot.filecoin.io/) - Filecoin 有效数据存储排名

## 6. Community
- [Slack](https://filecoinproject.slack.com)
- [Twitter](https://twitter.com/filecoin)
- [微信交流群](./README.md)：**Filecoin 技术交流群** 是目前国内最友好，也是全球最大、最活跃的 Filecoin 技术交流社区，欢迎广大 Filecoin 矿工、开发者和爱好者加入我们的技术交流群。

  - Filecoin 中文交流-1群（目前已满）
  - Filecoin 中文交流-2群（目前已满）
  - Filecoin 中文交流-3群（目前已满）
  - Filecoin 中文交流-4群（目前已满）
  - Filecoin 中文交流-5群（目前已满）
  - Filecoin 中文交流-6群（目前还有空位）

## 7. 杂项

### 7.1 旧版资源大全

目前，该文档是从早期版本中改造过来的，早期维护的一个资源大全，信息依然非常丰富，有些资料在这个文档中没有的，可以去旧版中找找，或许就能找到很多有用的信息，特别是一些基本操作，环境变量等等。

[【旧版资源入口地址】](https://github.com/CoinSummer/filecoin)

