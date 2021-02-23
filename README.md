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
- [Calibration](https://github.com/filecoin-project/lotus/tree/ntwk-calibration-10.22.0) - Calibration 校准网
- [Nerpa](https://github.com/filecoin-project/lotus/tree/ntwk-nerpa) - Nerpa测试网

## Documentation
- Filecoin文档
  - [依赖安装和代码编译](https://docs.filecoin.io/get-started/lotus/installation/#build-and-install-lotus)
  - [挖矿教程](https://docs.filecoin.io/mine/lotus/)
  - []()

- 硬件配置
  - [石榴矿池Filecoin挖矿方案](https://6block.com/files/zh/Filecoin%20mining%20solution%20v8.0.pdf) - 石榴矿池Filecoin挖矿解决方案，包含AMD 3760CPU和EPYC 7542两种方案
  - [社区推荐Filecoin硬件方案]()

- 挖矿集群搭建
  - [Filecoin挖矿入门教程]()
  - [Filecoin挖矿集群搭建]()
  - [推荐硬件配置]()
  - [分布式Miner配置]()

- Daemon操作
  - [节点连接]()
  - [快照导出、导入，快照裁剪]()
  - [转账]()

- Miner操作
  - [扇区操作]()
  - [存储路径操作]()
  - [提现操作]()
  - [Owner、Worker、Control钱包说明]()
  - [Miner重启时机选择]()
  - [新矿工节点上线CheckList]()

- Worker操作
  - [Lotus Worker环境变量说明及配置]()

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
  - [Slack安装包下载]()
- [Twitter]()