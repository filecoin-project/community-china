# Filecoin资源分享
CoinSummer实验室Filecoin资源分享。

## 常用链接
- [Lotus官方文档](https://docs.lotu.sh/)
  - [testnet/3 使用文档](https://github.com/filecoin-project/lotus/blob/testnet/3/documentation/en/join-testnet.md) - 在Github项目的`testnet/3`分支下
  - [搭建Testnet/3的本地测试网](https://github.com/filecoin-project/lotus/blob/testnet/3/documentation/en/local-dev-net.md)
- 代码下载地址
  - [Lotus](https://github.com/filecoin-project/lotus)
  - [Go-filecoin](https://github.com/filecoin-project/go-filecoin)
  - [Rust-fil-proof](https://github.com/filecoin-project/rust-fil-proofs)
- 浏览器
  - [官方浏览器](https://stats.testnet.filecoin.io/) - 按ESC可以选择看Testnet3的数据
  - [Filscout](https://filscout.io/en/) - 星际联盟团队开发，可切换Testnet2和Testnet3
  - [Filscan](https://filscan.io/)
  - [1475ipfs](http://testnet3.1475ipfs.com:10300/d/z6FtI92Zz/testnet3?orgId=1&refresh=25s) - 1475团队开发，仅Testnet3
- [区块同步数据国内备份](https://filecoin.coinsummer.io/datastore.html) - `interopnet`分支区块同步数据国内下载地址，CoinSummer实验室提供，[如何使用？](https://github.com/CoinSummer/filecoin#%E6%89%8B%E5%8A%A8%E8%AE%BE%E7%BD%AE%E9%93%BE%E7%9A%84%E9%AB%98%E5%BA%A6)
- [Filecoin官方博客](https://filecoin.io/blog/)
- [Lotus Specification 设计文档](https://filecoin-project.github.io/specs/)
- 水龙头地址
  - [Testnet2(旧版)](https://faucet.testnet.filecoin.io/)
  - [Testnet3(新版)](http://t01000.miner.interopnet.kittyhawk.wtf)
- Benchmark数据
  - [Testnet2(V20)](https://github.com/filecoin-project/lotus/issues/839)
  - [Testnet3(V24)](https://github.com/filecoin-project/lotus/issues/1475)
  - [Testnet3(V25)](https://filecoin-benchmarks.on.fleek.co/)
- Proof证明文件国内下载
  - [JDCloud(v20)参数下载](https://s3.cn-south-1.jdcloud-oss.com/proof-parameters/filecoin-proof-parameters-v20.tar.gz)
  - [JDCloud(v25)参数下载](https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/) - `env IPFS_GATEWAY=https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/`
  - [中国专用v25参数下载](https://filecoin.coinsummer.io/v25.html) - CoinSummer实验室提供
  - [中国专用v25 URL地址](https://filecoin.coinsummer.io/v25.txt)
  - [中国专用v24参数下载](https://filecoin.coinsummer.io/v24.html) - CoinSummer实验室提供
  - [最新版Proofs发布地址](https://proofs.filecoin.io/) - 最新发布 Proof 参数的地方【官方】
- [Filecoin经济模型](https://filecoin.io/blog/filecoin-cryptoeconomic-constructions/)
- [甘特图](https://app.instagantt.com/shared/s/1152992274307505/latest
)
- rust 和 rustup 的安装环境配置（Cargo）
  - [官方文档](https://www.rust-lang.org/tools/install)
  - [社区文档](https://learnku.com/docs/rust-lang/2018/ch01-01-installation/4494)
  - [国内免翻墙文档](https://www.cnblogs.com/honyer/p/11877145.html)
- 使用GPU计算Precommit2
  - [项目地址](https://github.com/filecoin-project/neptune)
  - [相关链接](https://filecoinproject.slack.com/archives/CEGB67XJ8/p1587776730458900)

## 节点操作
### 查看节点信息
```sh
# 查看本节点所监听的地址:
lotus net listen
# 查看连接的节点列表:
lotus net peers
```

### 手动连接其它节点（命令中的地址为示例地址）
```sh
lotus net connect /ip4/47.240.110.221/tcp/44845/p2p/12D3KooWRgxLL84TSkYSjhvhCy5ZNSuJZZzHWp2FXDY7ufqGBmUW
```
当启动 daemon 后无法正常同步链上的数据，可以试试在启动 daemon 的时候禁用自动连接 peers （即：加上 `--bootstrap=false` 参数），然后手动连接到一个正常节点，例如：
```sh
lotus daemon --bootstrap=false
lotus net connect /ip4/47.240.110.221/tcp/44845/p2p/12D3KooWRgxLL84TSkYSjhvhCy5ZNSuJZZzHWp2FXDY7ufqGBmUW
```
上述的节点是示例节点，当您在使用该命令的时候，您需要自己去找一个可以使用的节点。

### 手动设置链的高度
```sh
# 设置高度到9700
lotus chain sethead --epoch=9700
```

### 编译参数
#### v25 版本代码的编译命令:
```sh
env RUSTFLAGS="-C target-cpu=native -g" FFI_BUILD_FROM_SOURCE=1 make clean all
```
特别是针对 AMD 处理器，使用该命令自己编译出来的代码更适合自己的机器。

#### 启用内存最大化参数：
```sh
export FIL_PROOFS_MAXIMIZE_CACHING=1
```
该参数仅针对Testnet3的 32GB 扇区有效。

#### 启用 Log 日志：
```sh
export RUST_LOG=Debug
```
运行 miner 之前加入该参数可以在 miner 的日志中查看更详细的输出信息（底层 rust 代码的输出信息），Log 登记从低到高分别有： Trace、Debug、Info、Warn、Error，Trace 输出的信息最详细，Error 输出的信息最少，仅输入错误信息。

### 修改proof文件路径
```sh
export FIL_PROOFS_PARAMETER_CACHE=/path/to/proof_params/v25/
```

## Storage miner操作
### 查看扇区状态
```sh
# 列举所有扇区信息:
lotus-storage-miner sectors list
# 查看某个扇区的历史状态
lotus-storage-miner sectors status --log <SectorID>
```

### 手动修改扇区状态
```sh
lotus-storage-miner sectors update-state --really-do-it <SectorID> <NewSectorStatus>
# 例如：手动修改扇区 1 的状态为 FaultedFinal 状态
lotus-storage-miner sectors update-state --really-do-it 1 FaultedFinal
```

### 更改默认存储路径
```sh
export LOTUS_STORAGE_PATH="/path/to/.lotusstorage"
```
- 默认存储路径是`~/.lotusstorage`，可通过指定`LOTUS_STORAGE_PATH`环境变量来更改；
- 每个存储路径下都会有`sectorstore.json`配置文件，该文件可以配置该存储路径的用途，比如，是否可以用来存储密封过程中生成的临时文件`"CanSeal": true`， 是否可以用来存储密封好的数据`"CanStore": true`，以及该路径的权重`"Weight": 10`和一唯一标识符：`ID`；
```json
{
  "ID": "e59facdc-6a82-418f-a25e-4cbd9165b5de",
  "Weight": 10,
  "CanSeal": true,
  "CanStore": true
}
```
### 增加存储路径
```sh
# 设置数据存储路径，该路径用来存储最终密封好的数据
# 执行该命令可能需要一点时间等待
lotus-storage-miner storage attach --store --init /path/to/persistent_storage

# 设置密封扇区的存储路径，密封完成之后该路径下的数据会被自动清空，相当于临时目录
# 执行该命令可能需要一点时间等待
lotus-storage-miner storage attach --seal --init /path/to/fast_cache
```
以上两个命令都是在启动了 miner 之后才可以执行，是一种动态添加存储路径的方式，非常灵活。 当然还可以在命令中添加权重 --weight=10，默认权重是 10。
执行该命令后，可通过以下命令查看存储列表:
```sh
lotus-storage-miner storage list
```

### 赎回已获得的奖励（Testnet3 才需要手动赎回）
```sh
lotus-storage-miner rewards redeem
lotus-storage-miner rewards list
```
赎回之后，可能需要过一段时间才能看到自己钱包的余额增加。

## Worker操作
### Testnet3 查看 Worker 信息
```sh
lotus-storage-miner workers list
```

### Testnet3 启动 worker
```sh
lotus-seal-worker run --address=192.168.1.201:2333 --precommit1=false --precommit2=true --commit=true
```
启动worker需要注意以下几点：
- 要给 worker 指定**本机地址**和一个**随机端口（四位数以上）**;
- `precommit1`、`precommit2` 和`commit`默认是启用的，如果想要禁用，可以设置为 false，例如：
`--precommit1=false`;
- `commit` 参数是配置 `commit2` 的，`commit1` 无法在 Worker 中启用。

## 常见问题(待续)
- Testnet/3 的Actual Power，Byte Power 是什么?
- lotus sync status时的base和target代表什么？
- lotus sync时的worker是如何工作的？

持续更新中，有问题请在Issues中反馈...

> 参考文档
- [NewMai-CommonLinkForFilecoin](https://github.com/NewMai/CommonLinkForFilecoin)
- [Lotus Docs](https://docs.lotu.sh/)
