# Filecoin 资源分享

**CoinSummer实验室** Filecoin 资源分享。

## 1.常用链接

- [Lotus官方文档](https://docs.lotu.sh/)
  - [testnet/3 使用文档](https://github.com/filecoin-project/lotus/blob/testnet/3/documentation/en/join-testnet.md) - 在 Github 项目的 `testnet/3` 分支下
  - [搭建Testnet/3的本地测试网](https://github.com/filecoin-project/lotus/blob/testnet/3/documentation/en/local-dev-net.md)
- 代码下载地址
  - [Lotus](https://github.com/filecoin-project/lotus)
  - [Go-filecoin](https://github.com/filecoin-project/go-filecoin)
  - [Rust-fil-proof](https://github.com/filecoin-project/rust-fil-proofs)
  - [Rust-fil-nse-gpu](https://github.com/filecoin-project/rust-fil-nse-gpu) - NSE新算法
- 浏览器
  - [官方浏览器](https://stats.testnet.filecoin.io/) - 按 ESC 可以选择看 Testnet3 的数据
  - [Filscout](https://filscout.io/en/) - 星际联盟团队开发，可切换 Testnet2 和 Testnet3
  - [Filscan](https://filscan.io/)
  - [1475ipfs](https://1475ipfs.com/#/blockBrowser) - 1475 团队开发【**强烈推荐**】
  - [FilFox](https://interopnet.filfox.io/) - 6Block 团队 （interopnet 6.6 的浏览器）
  - [interopnet.filscan](https://interopnet.filscan.io/#/) - 官方 interopnet 浏览器
- [区块同步数据国内备份](https://filecoin.coinsummer.io/datastore.html) - `interopnet` 分支区块同步数据国内下载地址，CoinSummer实验室提供，[如何使用？](https://github.com/CoinSummer/filecoin#%E6%89%8B%E5%8A%A8%E8%AE%BE%E7%BD%AE%E9%93%BE%E7%9A%84%E9%AB%98%E5%BA%A6)
- [Filecoin官方博客](https://filecoin.io/blog/)
- [Lotus Specification 设计文档](https://filecoin-project.github.io/specs/)
- 水龙头地址
  - [Testnet phase 2](https://faucet.testnet.filecoin.io/)
- Benchmark 数据
  - [Testnet2(V20)](https://github.com/filecoin-project/lotus/issues/839)
  - [Testnet3(V24)](https://github.com/filecoin-project/lotus/issues/1475)
  - [Testnet3(V25)](https://filecoin-benchmarks.on.fleek.co/)
  - [Testnet3(V25)](https://github.com/CoinSummer/benchmarks/tree/master/benchmarks)
- Proof证明文件国内下载
  - [JDCloud(v20)参数下载](https://s3.cn-south-1.jdcloud-oss.com/proof-parameters/filecoin-proof-parameters-v20.tar.gz)
  - [JDCloud(v25)参数下载](https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/) - `env IPFS_GATEWAY=https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/`
  <!-- - [国内专用v26参数下载](https://filecoin.coinsummer.io/v26.html) - CoinSummer实验室提供(暂停访问) -->
  - [国内专用v26参数下载](https://shimo.im/docs/C6ggY9xxhvVG3DX8) - 群友 Daniels 提供，白天效果不错，晚上较慢
  - [国内专用v25参数下载](https://filecoin.coinsummer.io/v25.html) - CoinSummer实验室提供
    - [国内专用v25 URL地址](https://filecoin.coinsummer.io/v25.txt)
  - [最新版Proofs发布地址](https://proofs.filecoin.io/) - 最新发布 Proof 参数的地方【官方】
- [Filecoin经济模型](https://filecoin.io/blog/filecoin-cryptoeconomic-constructions/)
- [甘特图](https://app.instagantt.com/shared/s/1152992274307505/latest)
- [测试网第二阶段启动](https://filecoin.io/zh-cn/blog/filecoin-testnet-phase-2-is-here/)
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

## 2. 新测试网专用（实时更新）

### 2.1 New Interop Deployed 【2020-06-06-9:30AM】

Hey everyone, we have brought back the interopnet for the changes we are working towards deploying during the next testnet reset.

**Branch:** **Deployed code is under branch interopnet (4068c9a); tag interop.6.6**

[**Faucet**](https://t01000.miner.interopnet.kittyhawk.wtf) - https://t01000.miner.interopnet.kittyhawk.wtf

[**Slack Address**](https://filecoinproject.slack.com/archives/CPFTWMY7N/p1591407039139100)

### 2.2 测试网第二阶段启动（重大时刻） 【2020-05-15-6:10AM】

[**Faucet**](https://faucet.testnet.filecoin.io/) - https://faucet.testnet.filecoin.io/

[**Slack Address: 2020-05-15-6:10AM**](https://filecoinproject.slack.com/archives/CPFTWMY7N/p1589494237352300)

Ref:

https://filecoinproject.slack.com/archives/CPFTWMY7N/p1589516324005900
https://filecoinproject.slack.com/archives/CPFTWMY7N/p1589519545018500
https://filecoinproject.slack.com/archives/CPFTWMY7N/p1589494237352300

## 3. 节点操作

### 3.1 查看节点信息
```sh
# 查看本节点所监听的地址:
lotus net listen
# 查看连接的节点列表:
lotus net peers
```

### 3.2 手动连接其它节点（命令中的地址为示例地址）
```sh
lotus net connect /ip4/47.240.110.221/tcp/44845/p2p/12D3KooWRgxLL84TSkYSjhvhCy5ZNSuJZZzHWp2FXDY7ufqGBmUW
```
当启动 daemon 后无法正常同步链上的数据，可以试试在启动 daemon 的时候禁用自动连接 peers （即：加上 `--bootstrap=false` 参数），然后手动连接到一个正常节点，例如：
```sh
lotus daemon --bootstrap=false
lotus net connect /ip4/47.240.110.221/tcp/44845/p2p/12D3KooWRgxLL84TSkYSjhvhCy5ZNSuJZZzHWp2FXDY7ufqGBmUW
```
上述的节点是示例节点，当您在使用该命令的时候，您需要自己去找一个可以使用的节点。

### 3.3 手动设置链的高度
```sh
# 设置高度到9700
lotus chain sethead --epoch=9700
```
节点同步出错时，可下载 **CoinSummer实验室** 提供的 [国内节点备份](https://filecoin.coinsummer.io/datastore.html)，将下载后的文件解压得到的 `datastore` 目录，替换你本机 `~/.lotus` 目录下的 `datastore`，然后执行上面手动设置链高度的命令(需要 daemon 启动的情况下)，即可从指定高度进行同步。

### 3.4 手动下载 proof 参数
```sh
# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
./lotus fetch-params --proving-params 2KiB     # 例如下载 2KiB 扇区对应的 Proof 参数
./lotus fetch-params --proving-params 16MiB    # 下载 16MiB 扇区对应的 Proof 参数
./lotus fetch-params --proving-params 32GiB    # 下载 32GiB 扇区对应的 Proof 参数
```
[参考](https://github.com/filecoin-project/lotus/blob/master/documentation/en/local-dev-net.md)

### 3.5 编译参数
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

### 3.6 修改 Proofs 文件路径
```sh
export FIL_PROOFS_PARAMETER_CACHE=/path/to/proof_params/v26/
```

## 4 Storage miner 操作

### 4.1 查看扇区状态
```sh
# 列举所有扇区信息:
lotus-storage-miner sectors list
# 查看某个扇区的历史状态
lotus-storage-miner sectors status --log <SectorID>
```

### 4.2 手动修改扇区状态【谨慎操作】
```sh
lotus-storage-miner sectors update-state --really-do-it <SectorID> <NewSectorStatus>
# 例如：手动修改扇区 1 的状态为 FaultedFinal 状态
lotus-storage-miner sectors update-state --really-do-it 1 FaultedFinal
```

### 4.3 更改默认存储路径
```sh
export LOTUS_STORAGE_PATH="/path/to/.lotusstorage"
```
- 默认存储路径是 `~/.lotusstorage`，可通过指定 `LOTUS_STORAGE_PATH` 环境变量来更改；
- 每个存储路径下都会有 `sectorstore.json` 配置文件，该文件可以配置该存储路径的用途，比如，是否可以用来存储密封过程中生成的临时文件 `"CanSeal": true`， 是否可以用来存储密封好的数据 `"CanStore": true`，以及该路径的权重 `"Weight": 10` 和一个唯一标识符：`ID`；
```json
{
  "ID": "e59facdc-6a82-418f-a25e-4cbd9165b5de",
  "Weight": 10,
  "CanSeal": true,
  "CanStore": true
}
```
### 4.4 增加存储路径
```sh
# 设置数据存储路径，该路径用来存储最终密封好的数据
# 执行该命令可能需要一点时间等待
lotus-storage-miner storage attach --store --init /path/to/persistent_storage

# 设置密封扇区的存储路径，密封完成之后该路径下的数据会被自动清空，相当于临时目录
# 执行该命令可能需要一点时间等待
lotus-storage-miner storage attach --seal --init /path/to/fast_cache
```
以上两个命令都是在启动了 miner 之后才可以执行，是一种动态添加存储路径的方式，非常灵活。 当然还可以在命令中添加权重 `--weight=10`，默认权重是 `10`。
执行该命令后，可通过以下命令查看存储列表:
```sh
lotus-storage-miner storage list
```

### 4.5 移动存储目录
默认的存储目录 `~/.lotusstorage` 可以移动到其他地方。
移动前最好先停掉 daemon 和 miner。
移动后，假设新路径为 `/path/to/.lotusstorage`，需要手动更改 `/path/to/.lotusstorage` 目录下 `storage.json` 中的 `StoragePaths` 为新路径：
```json
{
  "StoragePaths": [
    {
      "Path": "/path/to/.lotusstorage"
    }
  ]
}
```
移动后，重启 daemon 和 miner，miner 会重新读取新路径下的所有 sector 信息。

### 4.6 使用远程 daemon（daemon 在其他机器）
假设daemon在 `192.168.1.100` 机器上，miner在 `192.168.1.101` 机器上：
1. 修改远程 daemon (192.168.1.100)上 `~/.lotus/config.toml` 中的 `ListenAddress` 为：
```toml
# Default config:
[API]
ListenAddress = "/ip4/192.168.1.100/tcp/1234/http"
```
2. 将远程 daemon (192.168.1.100) 上 `~/.lotus` 目录下的 `api` 和 `token` 拷贝到 miner 机器(192.168.1.101)的 `~/.lotus` 目录下；
3. 重启 miner 即可。

### 4.7 赎回已获得的奖励（Testnet3 才需要手动赎回）
```sh
lotus-storage-miner rewards redeem
lotus-storage-miner rewards list
```
赎回之后，可能需要过一段时间才能看到自己钱包的余额增加。

### 4.8 v26 版本参数中使用 GPU 计算 Precommit2 的方法
运行 miner 之前导出已下环境变量（目前官方还未放出v26参数）：
```sh
export FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1
```
[参考](https://filecoinproject.slack.com/archives/CEGB67XJ8/p1588805545137700)

## 5 Worker操作
### 5.1 Testnet3 查看 Worker 信息
```sh
lotus-storage-miner workers list
```

### 5.2 Testnet3 启动 worker
```sh
lotus-seal-worker run --address=192.168.1.201:2333 --precommit1=false --precommit2=true --commit=true
```
启动worker需要注意以下几点：
- 要给 worker 指定**本机地址**和一个**随机端口（至少四位数）**;
- `precommit1`、`precommit2` 和 `commit` 默认是启用的，如果想要禁用，可以设置为 `false`，例如：
`--precommit1=false`;
- `commit` 参数是配置 `commit2` 的，`commit1` 无法在 Worker 中启用。

### 5.3 Testnet3 集群配置
1. 修改 miner `~/.lotusstorage/config.toml` 里面的 `ListenAddress`:
```toml
[API]
ListenAddress = "/ip4/192.168.1.100/tcp/2345/http"
RemoteListenAddress = "192.168.1.100:2345"
```
2. 配置 worker 的环境变量
```sh
export STORAGE_API_INFO=<TOKEN>:<API>
```
TOKEN 为 `~/.lotusstorage` 中的 token；
API 为 `~/.lotusstorage` 中的 api；

3. 启动 worker
```sh
./lotus-seal-worker run --address=192.168.1.222:3456
```
需要给 worker 指定一个四位数的端口。

## 6 常用环境变量

```sh
# lotus 路径：
LOTUS_PATH
# 例如： export LOTUS_PATH=/home/user/nvme_disk/lotus

# miner 路径： 
LOTUS_STORAGE_PATH
# 例如： export LOTUS_STORAGE_PATH=/home/user/nvme_disk/lotusstorage

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

```

## 7. 解决拉取代码冲突问题（git pull）

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

### 7.1 方法一：
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

### 7.2 方法二：
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

### 7.3 方法三：
```sh
# 如果你没有修改代码，直接执行以下两条命令
git fetch origin
git reset --hard origin/interopnet
```

## 8 重置本地测试网环境

如果你在使用本地测试网，发现 lotus daemon 启动不了，或者是 miner 启动不了，或者是其它的问题，这时候，如果你没有别的更好的解决方法，你可以尝试完全清理本地环境，然后再启动 daemon 和 miner， 默认情况下，你需要清理如下的文件或文件夹等：
```sh
rm -rf ~/.lotus/
rm -rf ~/.lotusstorage/
rm -rf ~/.lotusworker/
rm -rf ~/.lotus-bench/
rm -rf ~/.genesis-sectors/
rm -rf ~/dev.gen
rm -rf ~/localnet.json
```

## 9 GDB 调试 lotus 源码

使用 GDB 调试 lotus 源码（包括上层的 **go** 语言代码和底层的 **rust** 语言代码），你只需要一个 GDB 工具就可以单步调试了，非常方便：

[链接](./GDB_Debug.md)

## 10 常用的两个查看系统资源的工具

### 10.1 htop 查看 CPU 和内存等信息

htop 比系统自带的 top 界面更加友好，在 Ubuntu 上安装只需要执行：

```sh
sudo apt install htop
```

效果如下：

![htop效果](./pictures/htop.png)

### 10.2 nvtop 查看显卡信息

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

## 11 编译相关问题

### 11.1 crate.io 源的问题

如果因为编译的时候卡住，症状如下图所示：

![更新 crate.io 时卡住](./pictures/stuck_in_comiple_for_crate.io.png)

解决方法：可以试试更改 `crate.io` 的源为国内的源，例如：

```sh
# 中科大的源（目前好像出问题了）
[source.crates-io]
registry = "https://github.com/rust-lang/crates.io-index"
replace-with = 'ustc'
[source.ustc]
registry = "git://mirrors.ustc.edu.cn/crates.io-index"

# 清华的源（正常使用）
[source.crates-io]
replace-with = 'tuna'
[source.tuna]
registry = "https://mirrors.tuna.tsinghua.edu.cn/git/crates.io-index.git"
```
使用方法：`vi ~/.cargo/config`， 然后把以上中的一个添加进去，重新编译一次即可。

### 11.2 GOPROXY 的问题

如果在编译的时候因为下载代码子模块的时候卡住（GO 代码），可能是 GOPROXY 没有设置，此时，设置一下 GOPROXY，然后再重新编译一遍即可：

```sh
export GOPROXY=https://goproxy.cn
```
### 11.3 go 版本太低的问题

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



## 12 常见问题(待续)
- Testnet/3 的Actual Power，Byte Power 是什么?
- lotus sync status时的base和target代表什么？
- lotus sync时的worker是如何工作的？

持续更新中，有问题请在Issues中反馈...

> 参考文档
- [NewMai-CommonLinkForFilecoin](https://github.com/NewMai/CommonLinkForFilecoin)
- [Lotus Docs](https://docs.lotu.sh/)
