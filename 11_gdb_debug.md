## [回目录](./README.md)

## 11. GDB 调试 lotus 源码

### 11.1 GDB 调试 lotus 源码

使用 GDB 调试 lotus 源码（包括上层的 **go** 语言代码和底层的 **rust** 语言代码），你只需要一个 GDB 工具就可以单步调试了，非常方便：

[链接](./gdb_debug.md)

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

## [回目录](./README.md)