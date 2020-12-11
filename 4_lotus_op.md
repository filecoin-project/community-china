## [回目录](./README.md)

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

## [回目录](./README.md)