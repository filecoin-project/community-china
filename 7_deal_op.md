## [回目录](./README.md)

## 7 Deal操作
### 7.1 Deal配置 - Miner有公网IP
假设Miner的公网IP为`123.123.73.123`，内网IP为`10.4.0.100`。
#### (1) MinerIP配置
修改`$LOTUS_STORAGE_PATH/config.toml`文件中的以下内容：
- 将`ListenAddresses`中的IP改为`123.123.73.123`（即公网IP地址），端口自己指定一个固定端口，例如`1024`；
```sh
[Libp2p]
ListenAddresses = ["/ip4/123.123.73.123/tcp/1024", "/ip6/::/tcp/0"]
```
配置修改以后，重启Miner。
#### (2) 设置multiaddress
这里的multiaddress即为上面第(1)步中配置的`ListenAddresses`的地址。
```sh
lotus-miner actor set-addrs /ip4/123.123.73.123/tcp/1024
```
设置完等待消息确认后，可以通过以下命令查看结果:
```sh
lotus state miner-info [t0xxxx]
```
#### (3) 设置Miner连接的节点
执行以下命令查看Miner连接的节点:
```sh
lotus-miner net peers
```
如果返回的结果很少(只有本地一个节点)，需要手动连接节点：
```sh
lotus-miner net connect /dns4/bootstrap-1.calibration.fildev.network/tcp/1347/p2p/12D3KooWQAKmfoAQBDwyaruE1bfFsuekttD974arrkB4G4ZKWk6r
lotus-miner net connect /dns4/bootstrap-0.calibration.fildev.network/tcp/1347/p2p/12D3KooWCoZZ9gExszHaNLoLXhW7DJa3dDZXjGgHELxwhqxoKJUQ
lotus-miner net connect /dns4/bootstrap-2.calibration.fildev.network/tcp/1347/p2p/12D3KooWKRNgz3a8RyxLFa1gihdFHMG6rPKuEFnSwmzk4GTo2TC1
lotus-miner net connect /dns4/bootstrap-3.calibration.fildev.network/tcp/1347/p2p/12D3KooWJt4zgPL8B2cMoCLDQ6MPpMKH62ZjgvvPmrfDBLWpggKG
```
**注意：上面连接的地址，需要替换成Louts项目`/build/bootstrappers.pi`文件中的地址**
连接成功后会有`connect 12D3KooWQAKmfoAQBDwyaruE1bfFsuekttD974arrkB4G4ZKWk6r: success`这样的返回。
执行上面的操作后，再次执行`lotus-miner net peers`，应该就能看到不少节点了。

#### (4) 太空竞赛订单过滤
太空竞赛可以配置Miner只接收官方机器人的订单[参考官方文档](https://docs.filecoin.io/mine/spacerace/#how-do-i-prioritize-deals-from-competition-bots)，将`$LOTUS_STORAGE_PATH/config.toml`文件中的：
```sh
[Dealmaking]
#  Filter = ""
```
改为：
```sh
Filter = "jq -e '.Proposal.Client == \"t1nslxql4pck5pq7hddlzym3orxlx35wkepzjkm3i\" or .Proposal.Client == \"t1stghxhdp2w53dym2nz2jtbpk6ccd4l2lxgmezlq\" or .Proposal.Client == \"t1mcr5xkgv4jdl3rnz77outn6xbmygb55vdejgbfi\" or .Proposal.Client == \"t1qiqdbbmrdalbntnuapriirduvxu5ltsc5mhy7si\" '"
```

#### (5) 检查配置
- 首先通过官方提供的[Ping工具](https://ping.eu/ping)看看能否ping通自己Miner的公网IP；
- 其次，通过[[Port-chk](https://ping.eu/port-chk/)]查看自己Miner的公网端口是否开放；
- `telnet 123.123.73.123 1024`(注意替换成自己的IP和端口)看看是否返回`/multistream/1.0.0`。

### 7.2 Deal配置 - Miner无公网IP
如果Miner机器没有公网IP，就需要在边缘网络设备(如路由器，或有公网IP和端口转发服务的服务器)上做公网IP和端口向内网IP和端口的转发，假设公网IP为`123.123.73.123`，Miner的内网IP为`10.4.0.100`。
#### (1) MinerIP配置
修改`$LOTUS_STORAGE_PATH/config.toml`文件中的以下内容：
- 将`ListenAddresses`中的端口改为自己指定一个固定端口，例如`1024`；
- 将`AnnounceAddresses`中的IP改为Miner所在网络的公网IP(例子中为：123.123.73.123)，端口改为公网监听端口，例如`10240`。
```sh
[Libp2p]
ListenAddresses = ["/ip4/0.0.0.0/tcp/1024", "/ip6/::/tcp/0"]
AnnounceAddresses = ["/ip4/123.123.73.123/tcp/10240"]
```
配置完以后，重启Miner。
#### (2) 设置端口转发规则
- 如果边缘网络设备为路由器，登录路由器管理控制台，将外网的`10240`转发到内网的`1024`端口；
- 如果边缘网络设备为服务器，按以下方式设置转发规则：
编辑系统的`/etc/sysctl.conf`文件(以Ubuntu为例)，将`net.ipv4.ip_forward=1`前面的#注释去掉，保存文件，然后执行`sudo sysctl -p`使其生效。
在Miner所在网络中，添加以下端口转发规则，将外网的10240端口映射到内网的1024端口。
```sh
sudo iptables -t nat -A PREROUTING -p tcp -m tcp --dport 10240 -j DNAT --to-destination 10.4.0.100:1024
```
其中`10.4.0.100`为Miner的内网IP。

#### (3) 设置multiaddress
参照7.1中的设置multiaddress。
#### (4) 设置Miner连接的节点
参照7.1中的设置Miner连接的节点。

### 7.3 Deal常用操作
```sh
# query ask
lotus client query-ask [t0xxxx]

# 查看本地导入的文件
lotus client local

# 导入文件，需要在daemon所在机器上操作
lotus client import /path/filename

# 发送订单
lotus client deal [CID] [miner_id] 0.0000000005 622080

# 查看deals列表
lotus client list-deals

# Miner查看存储订单列表
lotus-miner storage-deals list

# Miner查看检索订单列表
lotus-miner retrieval-deals list
```

## [回目录](./README.md)