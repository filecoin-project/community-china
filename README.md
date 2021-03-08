# Awesome-filecoin

## Website
#### 浏览器
- [FilFox](https://filfox.info) - 6Block 团队开发的 Filecoin 浏览器
- [Filscan](https://filscan.io) - IPFS原力团队开发的 Filecoin 浏览器
- [Filscout](https://filscout.io) - 星际联盟团队开发的 Filecoin 浏览器
- [1475ipfs](https://1475ipfs.com/#/blockBrowser) - 1475 团队开发 Filecoin 浏览器

#### 代码仓库
- [lotus](https://github.com/filecoin-project/lotus) - Filecoin lotus项目源代码地址
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
- [Calibration](https://github.com/filecoin-project/lotus/tree/ntwk-calibration-10.22.0) - Calibration 校准网
- [Nerpa](https://github.com/filecoin-project/lotus/tree/ntwk-nerpa) - Nerpa测试网

## Documentation
- Filecoin文档
  - [依赖安装和代码编译](https://docs.filecoin.io/get-started/lotus/installation/#build-and-install-lotus) - Filecoin官方依赖安装和代码编译教程
  - [挖矿教程](https://docs.filecoin.io/mine/lotus/) - Filecoin官方的挖矿教程，系统性强、详细完整，建议新手通读
  - [Filecoin中文文档](https://filecoin.filgo.info/) - 社区全栈老吕提供的Filecoin官方文档中文版

- 硬件配置
  - [石榴矿池Filecoin挖矿方案](https://6block.com/files/zh/Filecoin%20mining%20solution%20v8.0.pdf) - 石榴矿池Filecoin挖矿解决方案，包含AMD 3760CPU和EPYC 7542两种方案
  - [社区推荐Filecoin硬件方案]()

- 挖矿集群搭建
  - [Filecoin挖矿集群搭建](https://github.com/filecoin-project/community-china/discussions/4) - 如何从零开始搭建一个挖矿集群
  - [分布式Miner集群搭建](https://github.com/filguard/lotus-ops/blob/master/documents/distributed-miner-configuration.md) - 社区分布式Miner架构详解

- Daemon操作
  - [节点启动](https://github.com/filecoin-project/community-china/discussions/2) - Lotus代码编译、节点搭建、配置、启动
  - [节点操作](https://github.com/filecoin-project/community-china/discussions/8) - Lotus节点常用操作，快照导出、导入，快照裁剪，公网IP配置
  - [Lotus钱包常用操作及使用场景](https://github.com/filecoin-project/community-china/discussions/15) - Lotus钱包创建、导入导出，多钱包配置

- Miner操作
  - [扇区操作](https://github.com/filecoin-project/community-china/discussions/14) - 扇区生命周期解析、扇区状态更新、扇区删除
  - [存储路径操作]()
  - [Owner、Worker、Control钱包说明](https://github.com/filecoin-project/community-china/discussions/15) - 如何配置时空证明、PreCommit、ProveCommit多钱包地址
  - [Miner重启时机选择](https://docs.filecoin.io/mine/lotus/miner-lifecycle/#ensuring-proofs-for-the-current-deadline-have-been-sent) - 重启Miner前需要检查什么
  - [新矿工节点上线CheckList](https://github.com/filguard/lotus-ops/blob/master/documents/new-miner-checklist.md) - 新矿工节点上线操作系统、基础环境、Daemon、Miner、Worker检查列表

- Deal 操作
  - [Filecoin 订单配置及订单操作](https://github.com/filecoin-project/community-china/discussions/5) - 存储矿工如何接订单，订单常见操作

- 部署运维
  - [Ansible部署工具使用](https://github.com/filguard/lotus-ops/blob/master/documents/ansible-deploy-tool-usage.md) - 如何使用Ansible批量自动化部署Daemon、Miner、Worker
  - [Prometheus + Grafana监控系统搭建](https://github.com/filguard/lotus-ops/blob/master/documents/monitoring-deployment.md) - 基于Prometheus和Grafana搭建Filecoin监控报警系统
  - [Lotus日常运维巡检做什么](https://github.com/filecoin-project/community-china/discussions/10) - 日常硬件检查、错误扇区处理、钱包检查、消息池疏通...

- 常用环境变量
  - [Lotus Daemon环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Daemon常用环境变量说明
  - [Lotus Miner环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Miner常用环境变量说明
  - [Lotus Worker环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Worker如何开启PreCommit1 SDR加速，如何指定显卡型号等

- 常见软件问题 - 挖矿常见问题及解决方法
  - [golang编译环境配置]
  - [rust 和 rustup 编译环境配置（Cargo）]
  - [解决代码拉取冲突]
  - [代码编译常见错误解决]
  - [Ulimit 问题：`Too many open files`]
  - [Daemon 无法启动时恢复钱包密钥的方法]
  - [链同步错误：`block was from the future`]

- 常见硬件问题
  - [显卡掉驱动问题解决]
  - [内存ECC模式开启]

- Benchmarks
  - [AMD EPYC 7302 + 2080Ti]
  - [AMD EPYC 7542 + 2080Ti]
  - [AMD EPYC 7542 + 3090]

- 资源消耗统计
  - [磁盘消耗统计]
  - [内存消耗统计]
  - [显卡资源消耗统计]
  - [查看系统资源工具介绍]
    - htop
    - nvtop

- 技术文章分享
  - [星想法公众号Filecoin系列文章](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU5MzMxNTk2Nw==&action=getalbum&album_id=1458647927098130433)
    - [Filecoin逻辑梳理及源代码导读](https://mp.weixin.qq.com/s?__biz=MzU5MzMxNTk2Nw==&mid=2247484751&idx=1&sn=54c2239d9f59c539a1a3c569362da288)
    - [Snark as a Service数据量分析]()
    - [Payment Channel介绍]()
    - [Lotus存储证明了什么？](https://mp.weixin.qq.com/s/LSkuEJl9mYV98jD7bZ8iUQ)
    - [PoREP电路介绍]()
    - [PoRep和PoSt算法源代码导读]()
    - [深入理解NSE算法]()
    - [winningPoSt逻辑介绍]()
    - [深入理解WindowPoSt]()
    - [Sector状态管理逻辑]()
    - [Precommit2计算介绍]()
    - [为什么SDR这么慢？](https://mp.weixin.qq.com/s/8V2r1627R6igtvXlV42mJQ)
    - [深入理解存储管理]()
    - [C2性能能优化多少？]()
    - [Lotus Gas计算]()
    - [SDR性能优化原理分析]()
    - [一个越界Bug引发升级]()

## Optimized Lotus
- [熊鹰myScheduler调度]() - [@熊鹰](https://github.com/KevinXiong2018)提供的lotus自定义调度程序myScheduler，参数使用与实测案例分享
- [P2优化版](https://github.com/filguard/rust-fil-proofs) - [@mje](https://github.com/jyma)开源的P2优化版
- [C2优化版]() - @jacklelv开源的C2优化版
- [分布式Miner](https://github.com/moran666666/lotus-1.5.0) - [@默然](https://github.com/moran666666)开源的分布式Miner
- [调度优化版](https://github.com/moran666666/lotus-1.5.0) - [@默然](https://github.com/moran666666)开源的调度程序

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