## [回目录](./README.md)

## 5 Storage miner 操作

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

## [回目录](./README.md)