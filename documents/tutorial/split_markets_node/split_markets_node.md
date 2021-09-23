# 如何分离存储市场到不同的机器

## 分离存储市场好处

- 保存信息一直是Filecoin的使命，Filecoin总会进入下一个阶段，存储真实的数据，为社会创造更多价值，我们应该为些做好准备。
- 与Filecoin生态保持同步，对于中小SP而言，分离存储市场并不会带来额外的风险，相反与生态同步会带来更多的机会。而当前真实数据的主要参予者国内的SP占比较低，我们可以更积极的参予其中，扮演重要角色。
- 分离业务可以独立运行，互不影响，不管你是不同的机器，还是相同的机器运行两个程序，你可以不影响封装证明的情况下重启markets节点。
- 减少端口暴露，提升安全性，你可以放心的暴露你的libp2p端口，因为来自外部的攻击只会影响在线交易部分，可以把证明、封装功能放在内网，来自外部的网络攻击将不会影响你的证明、封装。

我们关于[分离存储市场文档](https://docs.filecoin.io/mine/lotus/split-markets-miners/#split-the-market-subsystem)已经比较完善。你可以参考现有文档，确保理解分离的过程

## 1. mining/sealing/proving节点操作

请在开始操作前确保所有封装任务已经结束

### step 1. 停止mining/sealing/proving节点，并配置环境变量,这里我们使用备份目录为/backup

```shell
lotus-miner stop
export LOTUS_BACKUP_BASE_PATH=/backup
```

### step 2. 更改mining/sealing/proving节点配置

subsystem区域主要把EnableMarkets改为false.
> [Subsystems]
EnableMining = true  
EnableSealing = true  
EnableSectorStorage = true  
EnableMarkets = false  

注释掉如下区域

```toml
#[Libp2p]  
#Endpoint for libp2p requests (public)  
#ListenAddresses = ["/ip4/0.0.0.0/tcp/24001", "/ip6/::/tcp/24001"]  
```

### step 3. 启动lotus-miner 并执行备份

```shell
nohup lotus-miner run &
lotus-miner backup /backup/backup.cbor
cp ~/.lotusminer/dagstore /backup/ #If you have initialized the dagstore already built up   
cp ~/.lotusminer/config.toml /backup/  
```

### step 4. 输出变量值，以供market节点使用

```shell
echo APISEALER=`lotus-miner auth api-info --perm=admin`  
echo APISECTORINDEX=`lotus-miner auth api-info --perm=admin`  
lotus-miner auth api-info --perm=admin
```  

记录这三个值，导入到markets节点的环境变量中。

### step 5 将/backup文件夹拷贝至markets node 根目录下

## 2. markets node节点操作

### step 1.编辑 /backup/config.toml

```toml
 [Subsystems]
EnableMining = false  
EnableSealing = false 
EnableSectorStorage = false  
EnableMarkets = true 
```

### step2. 导入环境变量

环境变量主要为APISEALER，APISECTORINDEX,MINER_API_INFO(这三个环境变量在1.step4中导出)    
另外一个是FULLNODE_API_INFO，这个你可以在你的lotus daemon节点中执行这个命令来获取  

```shell
lotus auth api-info --perm admin  
```  

APISEALER，APISECTORINDEX用于markets节点接受到订单后，发送封装信息至lotus-miner.  
MINER_API_INFO用于lotus-miner客户端与mining/sealing/proving交互  
FULLNODE_API_INFO用于链上交互  
这是我的例子  

```shell
export FULLNODE_API_INFO=xxx:/ip4/192.168.0.105/tcp/1234/http
export APISECTORINDEX=MINER_API_INFO=XXXX:/ip4/192.168.0.105/tcp/2345/http  
export APISEALER=MINER_API_INFO=xxxx:/ip4/192.168.0.105/tcp/2345/http  
export MINER_API_INFO=XXXX:/ip4/192.168.0.105/tcp/2345/http  
```  

### step3. 初始化节点和修改配置

#### 1 执行初始化命令

```shell
lotus-miner --markets-repo=~/.lotusmarkets init service --type=markets \
                                                        --api-sealer=$APISEALER \
                                                        --api-sector-index=$APISECTORINDEX \
                                                        --config=/backup/config.toml \
                                                        /backup/backup.cbor
```  

这一步骤主要是初始化markets节点，并不会直接运行　　

#### 2 恢复dag存储文件（可选项，如果你初始化了dagstore）

```shell
cp /backup/dagstore ~/.lotusmarkets/ #If you have initialized the dagstore
```  

#### 3 编辑配置文件和导出环境变量

把对应的地址部分改为你当前主机的地址

```toml
 ListenAddresses = ["/ip4/0.0.0.0/tcp/0", "/ip6/::/tcp/0"]  
  AnnounceAddresses = []  
```

导出环境变量：  

```shell
export LOTUS_MINER_PATH=~/.lotusmarkets
```  

### step 4.　启动节点

```shell
nohup lotus-miner run &
```  

### step 5. 如何确认分离成功

执行以下两个命令

```shell
lotus-miner info  
lotus-miner storage-deals list  
```  

如果没有任何报错，基本上可以确定是成功的
最后建议大家给自己的markets节点发起一笔存储订单测试，以确保分离后的各项功能是正常的

### step 6 导出环境变量和其它配置

如果你最终更改了你的接受订单的外网地址，请执行以下命令更新

```shell
lotus-miner actor set-addrs <NEW_MULTIADDR>
```

获取markets节点的API连接信息

```shell
lotus-miner --call-on-markets  auth api-info --perm admin
```  

输出结果类似：
> MARKETS_API_INFO=eyJhXXX:/ip4/192.168.0.105/tcp/2345/http

请把这个变量导入到你的mining/sealing/proving节点中，不然你在执行lotus-miner info的命令时会遇到如下报错
> ERROR: could not get API info for Markets: could not get api endpoint: API not running (no endpoint)

### 提示信息

当前部分配置项，需要子系统全部配置才能生效，为了保证配置的统一，在修改Miner配置的时侯，请确保所有子系统的配置是相同的，例：

```toml
[Addresses]  
    PreCommitControl = ["f00XX1"]  
    CommitControl = ["f00XX2"]  
    TerminateControl = []  
    DealPublishControl = ["f00XX3"] 
    DisableOwnerFallback = false  
    DisableWorkerFallback = false 
```

如果你配置了`DealPublishControl`，在所有子系统都要配置。

### version info

lotus-miner version 1.11.1-rc2+git.40449f1cc.dirty  
Linux nerpa-miner 5.11.0-25-generic #27-Ubuntu SMP Fri Jul 9 23:06:29 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux.

## 　真实数据项目文档

以下是部分文档：
Filplus文档地址：[链接](https://docs.filecoin.io/store/filecoin-plus/)　　
Estuary: [文档](https://docs.estuary.tech/), [网址](https://estuary.tech/)
Filplus: [注册网址](https://plus.fil.org/)
