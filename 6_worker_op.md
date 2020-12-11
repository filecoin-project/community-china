## [回目录](./README.md)

## 6 Worker操作
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

## [回目录](./README.md)