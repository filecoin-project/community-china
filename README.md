# Awesome Filecoin

**请注意：本文中的链接并非全部是官方链接，部分链接是第三方链接，有些甚至是收费链接，请大家注意区分。**

## 1. Website

#### 1.1 浏览器
- [FilFox](https://filfox.info/en) - 6Block 团队开发的 Filecoin 浏览器
- [Filscan](https://filscan.io) - IPFS原力团队开发的 Filecoin 浏览器
- [Filscout](https://filscout.io) - 星际联盟团队开发的 Filecoin 浏览器
- [1475ipfs](https://1475ipfs.com/#/blockBrowser) - ~~1475 团队开发 Filecoin 浏览器~~【已关闭】
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

#### 1.4 资源下载
- [证明参数国内镜像](https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/) - 京东云镜像
- [社区证明参数镜像](https://gateway.yeaosound.com/ipns/filecoin-proofs.ipns.network/) - 社区@Ego Lee 分享的证明参数国内镜像

## 2. Network
- [网络概览](https://network.filecoin.io/) - 包括主网和测试网等各个网络的详细信息
- [MainNet](https://github.com/filecoin-project/lotus/tree/master) - Filecoin主网
- [Calibration](https://github.com/filecoin-project/community/discussions/74#discussioncomment-1922550) - Calibration 校准网
- [Spacegap](https://spacegap.github.io/#/) - 实时算力概览
## 3. Documentation
### Filecoin文档
  - [FIPs 文档入口](https://github.com/filecoin-project/FIPs) - FIPs
  - [官方文档](https://docs.filecoin.io/) - Filecoin Documentation, [【New document】](https://lotus.filecoin.io/docs/set-up/about/)
  - [官方文档-中文版](https://filecoin-docs.froghub.io/)
  - [依赖安装和代码编译](https://docs.filecoin.io/get-started/lotus/installation/#build-and-install-lotus) - Filecoin官方依赖安装和代码编译教程
  - [挖矿教程](https://docs.filecoin.io/mine/lotus/) - Filecoin官方的挖矿教程，系统性强、详细完整，建议新手通读
  - [Venus文档](https://venus.filecoin.io/) - Venus Documentation

### Filecoin经济模型
  - [Filecoin经济模型白皮书中文版](https://filecoin.io/zh-cn/2020-engineering-filecoins-economy-zh-cn.pdf)
  - [Filecoin经济模型白皮书英文版](https://filecoin.io/2020-engineering-filecoins-economy-en.pdf)
  - [Filecoin的流通供应机制](https://filecoin.io/zh-cn/blog/posts/%E4%BA%86%E8%A7%A3filecoin%E6%B5%81%E9%80%9A%E4%BE%9B%E5%BA%94%E6%9C%BA%E5%88%B6/)

### 硬件配置
  - [石榴矿池Filecoin挖矿方案](https://6block.com/files/zh/Filecoin%20mining%20solution%20v8.0.pdf) - 石榴矿池Filecoin挖矿解决方案，包含AMD 3960CPU和EPYC 7542两种方案
  - [社区推荐Filecoin硬件方案](https://github.com/filecoin-project/community-china/discussions/18) - 社区推荐的基于AMD EPYC 7542的Filecoin挖矿硬件方案

### 挖矿集群搭建
  - [Filecoin挖矿集群搭建](https://github.com/filecoin-project/community-china/discussions/4) - 如何从零开始搭建一个挖矿集群
  - [分布式Miner集群搭建](https://github.com/minerdao/posts/blob/master/posts/filecoin/distributed-miner-configuration.md) - 社区分布式Miner架构详解

### Daemon操作
  - [节点启动](https://github.com/filecoin-project/community-china/discussions/2) - Lotus代码编译、节点搭建、配置、启动
  - [节点操作](https://github.com/filecoin-project/community-china/discussions/8) - Lotus节点常用操作，快照导出、导入，快照裁剪，公网IP配置
  - [Lotus钱包常用操作及使用场景](https://github.com/filecoin-project/community-china/discussions/15) - Lotus钱包创建、导入导出，多钱包配置

### Miner操作
  - [扇区操作](https://github.com/filecoin-project/community-china/discussions/14) - 扇区生命周期解析、扇区状态更新、扇区删除
  - [存储路径操作](https://github.com/minerdao/posts/blob/master/posts/filecoin/storage-manage.md) - 存储路径操作、存储i/o性能分析、网络分析
  - [Owner、Worker、Control钱包说明](https://github.com/filecoin-project/community-china/discussions/15) - 如何配置时空证明、PreCommit、ProveCommit多钱包地址
  - [Miner重启时机选择](https://docs.filecoin.io/mine/lotus/miner-lifecycle/#ensuring-proofs-for-the-current-deadline-have-been-sent) - 重启Miner前需要检查什么
  - [新矿工节点上线CheckList](https://github.com/minerdao/posts/blob/master/posts/filecoin/new-miner-checklist.md) - 新矿工节点上线操作系统、基础环境、Daemon、Miner、Worker检查列表
  - [如何迁移矿工节点](./documents/tutorial/How_to_migrate_miner_nodes/How_to_migrate_miner_nodes.md) - 如何迁移矿工节点至新的机器上，需要做哪些配置和操作
  - [如何正确删除扇区](./documents/tutorial/How_to_delete_sector_correctly/How_to_delete_sector_correctly.md) - 教你删除扇区的正确姿势，以及残留扇区如何处理

  - [Filecoin：扇区到期续期/过期扇区删除流程详解](https://medium.com/@brf_alpha/filecoin-%E6%89%87%E5%8C%BA%E5%88%B0%E6%9C%9F%E7%BB%AD%E6%9C%9F-%E5%88%A0%E9%99%A4%E6%B5%81%E7%A8%8B%E8%AF%A6%E6%83%85-b0fdb86cf797) - 删除过期扇区或者续期的教程，访问此教程可能需要科学上网

  - [多签地址作为Owner操作教程](https://medium.com/@brf_alpha/%E5%A4%9A%E7%AD%BE%E5%9C%B0%E5%9D%80%E4%BD%9C%E4%B8%BAowner%E6%93%8D%E4%BD%9C%E6%95%99%E7%A8%8B-31fc19a1d433) - 近期 owner 私钥被盗的事情时有发生，就提高安全性来讲，使用多签是最有效的手段之一，访问此教程可能需要科学上网

### Deal 操作
  - [Filecoin 订单配置及订单操作](https://github.com/filecoin-project/community-china/discussions/5) - 存储矿工如何接订单，订单常见操作

### 部署运维
  - [Lotus-ops部署运维工具](https://github.com/minerdao/lotus-ops) - [MinerDAO](https://github.com/minerdao)开源的Lotus部署运维工具和运维操作手册
  - [Ansible部署工具使用](https://github.com/minerdao/posts/blob/master/posts/filecoin/ansible-deploy-tool-usage.md) - 如何使用Ansible批量自动化部署Daemon、Miner、Worker
  - [Prometheus + Grafana监控系统搭建](https://github.com/minerdao/posts/blob/master/posts/filecoin/monitoring-deployment.md) - 基于Prometheus和Grafana搭建Filecoin监控报警系统
  - [Lotus日常运维巡检做什么](https://github.com/filecoin-project/community-china/discussions/10) - 日常硬件检查、错误扇区处理、钱包检查、消息池疏通等
  - [Lotus-alert简单易用的Lotus告警系统](https://github.com/jyma/lotus-alert) - 本项目由技术群群友 @mje 提供，可直接发送告警信息到微信
  - [中国大陆地区FileCoin证明参数的下载](https://ipns.tech/2.FileCoin/%E4%B8%AD%E5%9B%BD%E5%A4%A7%E9%99%86%E5%9C%B0%E5%8C%BAFileCoin%E8%AF%81%E6%98%8E%E5%8F%82%E6%95%B0%E7%9A%84%E4%B8%8B%E8%BD%BD%E4%BC%98%E5%8C%96) - 社区@Ego Lee分享的中国大陆地区FileCoin证明参数的下载优化

### 常用环境变量
  - [Lotus Daemon环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Daemon常用环境变量说明
  - [Lotus Miner环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Miner常用环境变量说明
  - [Lotus Worker环境变量](https://github.com/filecoin-project/community-china/discussions/6) - Lotus Worker如何开启PreCommit1 SDR加速，如何指定显卡型号等

### 常见软件问题
  - [Golang编译环境安装配置](./documents/build/build_env_config.md) - Golang编译环境安装、代理设置
  - [Rust编译环境安装配置](./documents/build/build_env_config.md) - Rust编译环境安装配置，`crate.io` 源国内镜像配置
  - [代码编译常见错误解决](./documents/build/build_env_config.md) - 国内代理配置、Intel机器编译环境变量配置

### 常见硬件问题
  - [CPU开启性能模式](./documents/hardware/cpu_performance.md)

### Benchmarks
  - [AMD EPYC 7542 + RTX 2080Ti](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-epyc%E7%B3%BB%E5%88%97cpu)
  - [AMD EPYC 7542 + RTX 3080](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-epyc%E7%B3%BB%E5%88%97cpu)
  - [AMD EPYC 7302 + RTX 2080Ti](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-epyc%E7%B3%BB%E5%88%97cpu)
  - [AMD 3970X + RTX 2080Ti](https://github.com/filecoin-project/community-china/blob/master/documents/benchmark/bench.md#amd-3970x%E7%B3%BB%E5%88%97cpu)

### 资源消耗统计
  - [磁盘消耗统计](./documents/resource/resource_usage/resource_usage.md)
  - [内存消耗统计](./documents/resource/resource_usage/resource_usage.md)
  - [显卡资源消耗统计]() ： TODO
  - [查看系统资源工具介绍](./documents/resource/resource_usage/resource_usage.md)
    - htop （CPU 性能查看工具）
    - nvtop （GPU 性能查看工具）

### 技术文章分享
  - [星想法公众号Filecoin系列文章](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU5MzMxNTk2Nw==&action=getalbum&album_id=1458647927098130433)
  - [MerkleTree的算法流程](https://github.com/kikakkz/rust-fil-proofs-test/blob/master/apps/data/MerkleTree%E7%9A%84%E7%AE%97%E6%B3%95.txt) - [@kikakkz](https://github.com/kikakkz)分享的MerkleTree算法调用流程
  - Seal密封流程分析
    - AP计算过程简介（TODO）
    - [P1计算过程简介](./documents/tutorial/lotus_seal_process/seal_process.md)
    - [P2计算过程简介](./documents/tutorial/lotus_seal_process/seal_process.md)
    - C1计算过程简介（TODO）
    - C2计算过程简介（TODO）
    - WindowPoST计算过程简介（TODO）
    - WinningPoST计算过程简介（TODO）
### 基础教程
  - [本地搭建 2K 测试网入门教程](./documents/tutorial/local_2k_dev_tutorial/local_2k_dev_tutorial.md) - 强烈推荐的新手入门教程
  - [Calibration 测试网使用教程](./documents/tutorial/use_cali-net_tutorial/use_cali-net_tutorial.md) - 强烈推荐的新手入门教程
  - [链数据导入导出使用教程](./document/../documents/tutorial/lotus_chain_op/lotus_chain_op.md) - 文档内包含官方快照网址
  - [GDB调试Lotus源码](./documents/tutorial/gdb_debug_lotus/gdb_debug.md) - 使用本地编译的 Rust 库
  - [Filecoin 最新挖矿集群硬件配置](https://github.com/filecoin-project/community-china/discussions/18)
  - [Filecoin 挖矿教程集合](https://www.r9it.com/categories.html#Filecoin-ref) - 群友 @Rock-Yang 提供的优质文章教程
  - [Calibration 测试网和 Nerpnet 测试网快照下载地址和使用教程](./documents/tutorial/testnet_snapshot/testnet_snapshot.md) - 有效时间从2021/07/15开始到下次测试网重置
  - [如何正确删除扇区](./documents/tutorial/How_to_delete_sector_correctly/How_to_delete_sector_correctly.md) 
  - [如何迁移矿工节点](./documents/tutorial/How_to_migrate_miner_nodes/How_to_migrate_miner_nodes.md) 
  - [快速切换 Daemon 节点](./documents/tutorial/change_lotus_daemon/change_lotus_daemon.md) - 如何切换矿工的 `Daemon` 节点，同时提供大量关于本地测试网的相关脚本
  - [分离存储市场到不同的节点](./documents/tutorial/split_markets_node/split_markets_node.md)　- 解释分离存储市场到不同节点的必要性和步骤
  - [过低的幸运值的排查方法](./documents/tutorial/low_lucky_value/low_lucky_value.md) - 当你的幸运值一直很低，该如何排查原因
  - [从密封文件生成扇区缓存文件](./documents/tutorial/Generate_cache_files_from_sealed/Generate_cache_files_from_sealed.md) -从密封文件生成扇区缓存文件的中文翻译版本
  - [手动将扇区文件转移至永久存储](./documents/tutorial/finalize_sector_manually/finalize_sector_manually.md) - 当扇区落盘失败时手动转移扇区至永久存储

### 真实数据文档
   
  - [关于公证人](./documents/real_data/fil_plus/about_notary.md) - 翻译自官方文档，解释公证人的作用及运行机制 
  - [Filecoin plus](./documents/real_data/fil_plus/file_coin_plus.md) - 翻译自官方文档，关于filecoin plus的概念及参予方式 
  - [如何获取真实交易订单](./documents/real_data/where_do_find_verified_deal/where_do_find_verified_deal.md) 当下获取真实数据的主要方式
  - [textile存储拍卖系统](./documents/real_data/where_do_find_verified_deal/textileio_bidbot.md) textile存储拍卖系统,离线交易平台，更适合国内矿工接单
  - [~~textile奖励计划~~](./documents/real_data/where_do_find_verified_deal/grabs_with_Filecoin_Auctions.md) ~~textile奖励计划，真实数据+奖励，2021年11月8日开始~~
  - [真实数据专题讨论](https://github.com/filecoin-project/community-china/discussions/166) 这里讨论关于真实数据问题
  
### 高级教程
    - [Poseidon 哈希算法 C 语言实现](./ref_src/poseidon/PoseidonHashOriginal/Readme.md) - 基础版（所使用的参数和 lotus 有所不同）
    - [Poseidon 哈希算法 C 语言实现](./ref_src/poseidon/PoseidonHashNeptune/Readme.md) - 高级版（所使用的参数和 lotus 完全相同）

## 4. Optimized Lotus
- [C2优化版](https://github.com/jackoelv/bellperson) - [@jacklelv](https://github.com/jackoelv)开源的C2优化版
- [调度优化版 & 分布式 Miner 备份: 【lotus-1.10.0-1.10.0.zip】](./ref_src/anonymouse_lotus/lotus-1.10.0-1.10.0.zip) - 某匿名大佬开源的分布式 Miner
- [lotus-bee优化版](https://github.com/beelant/lotus-bee) 由蜂灯科技提供的全方位优化的lotus软件免费使用

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
- [FIL 主网数据统计图表](http://fil8.top/) - 群友 @怪盗Kid 提供的 FIL 主网数据统计图表
- [Filecoin扇区修复工具](https://github.com/froghub-io/filecoin-sealer-recover) - 群友@Chen开源的Filecoin扇区修复工具
- [Filecoin-Storage-Tool](https://github.com/VshareCloud-Project/Filecoin-Storage-Tool) - VshareCloud团队开源的FileCoin交易发起/数据备份组件
- [Lotus-wallet-security](https://github.com/cdcdx/lotus/tree/wallet-security) - 群友@Pangtou开源的Lotus钱包加密方案

## 6. Community
- [微信交流群](./README.md)：**Filecoin 技术交流群** 是目前国内最友好，也是全球最大、最活跃的 Filecoin 技术交流社区，欢迎广大 Filecoin 矿工、开发者和爱好者加入我们的技术交流群。
  - Filecoin 技术交流-1群（目前已满）
  - Filecoin 技术交流-2群（目前已满）
  - Filecoin 技术交流-3群（目前已满）
  - Filecoin 技术交流-4群（目前已满）
  - Filecoin 技术交流-5群（目前已满）
  - Filecoin 技术交流-6群（目前已满）
  - Filecoin 技术交流-7群（目前还有空位）
  - **Filecoin 技术交流群**（唯一与微信群同步的 Telegram 群） 
  - 入群请联系群主【**TEARS**】，并做好备注，否则可能会被拒绝。
  - ![TEARS](./images/tears_wchart.png)


- [Telegram交流群](https://t.me/+TOGYnsZ2itA0NGZl)   
- [Discord交流群](https://discord.gg/Qqn3VtC4)

## 7. 杂项

### 7.1 旧版资源大全

目前，该文档是从早期版本中改造过来的，早期维护的一个资源大全，信息依然非常丰富，有些资料在这个文档中没有的，可以去旧版中找找，或许就能找到很多有用的信息，特别是一些基本操作，环境变量等等。

[【旧版资源入口地址】](./documents/legacy_resource/README.md) -- 已迁移到本项目当中

