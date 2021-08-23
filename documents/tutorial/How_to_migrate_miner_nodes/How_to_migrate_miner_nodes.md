## 如何迁移矿工节点
### 1：准备工作
#### 1.如果扇区较少，建议选择没有window post的deadline进行矿工迁移，具体查看命令为：
```shell
lotus-miner proving deadlines
```

#### 2.停止所有封装任务

#### 3.设置环境变量
> export LOTUS_BACKUP_BASE_PATH=</lotus/backup/basepath>

此项必须设置，如果不设置，报错信息为：
> ERROR: LOTUS_BACKUP_BASE_PATH env var not set

设置完以后需要重新启动lotus-miner进程才能导出备份，并且备份文件所在的文件夹必须是该变量指向的文件夹。这里假设设置BACKUP_BASE_PATH为~/.lotusminer/backup/
### 2：备份矿工数据和配置文件
#### 1. 执行备份
```shell 
lotus-miner backup  ~/.lotusminer/backup/backup.cbor
```
Miner程序如果已经停止,执行：
```shell script
lotus-miner backup --offline ~/.lotusminer/backup/backup.cbor
```


#### 2. 备份配置文件
```shell script
cp ~/.lotusminer/config.toml ~/.lotusminer/storage.json ~/.lotusminer/sectorstore.json                                                       
~/.lotusminer/backup/
```


### 3：导入矿工数据
#### 1.复制backup文件夹至新的矿工节点
```shell script
lotus-miner init restore backup/backup.cbor
```

#### 2. 恢复配置文件
```shell script
cp backup/config.toml backup/storage.json backup/sectorstore.json  ~/.lotusminer
```


### 4：迁移文件（如果矿工节点本机存储了扇区文件）
#### 1.那么把.lotusminer/cache   .lotusminer/sealed  .lotusminer/unsealed 这三个文件夹的文件迁移至新节点，直接覆盖相应的文件夹即可.
#### 2.如果有网络文件存储，可以将存储挂载至新的矿工节点，要挂载同样的目录名

### 5：修改配置
#### 1.修改config.toml, 
如果内网地址发生变化：
> ListenAddress = "/ip4/<local_ip_address>/tcp/2345/http"

修改<local_ip_address>为新的矿工节点内网地址
如果外网地址发生变化：
> RemoteListenAddress = "<remote_ip_address>:2345"

修改<remote_ip_address>为新的矿工节点外网地

#### 2.修改storage.json
如果运行用户发生变化,
> "Path": "/home/\<user\>/.lotusminer"

修改<user>为新用户的名字

### 6：启动节点
```shell script
lotus-miner run
```


### 7：检查扇区状态
```shell script
lotus-miner proving check [command options] <deadlineIdx>
```
逐个deadline检查扇区状态，确保所扇区被miner识别并能找到对应的文件

### 8：重新导出api
```shell script
lotus-miner auth api-info --perm admin
```

发生迁移后，对应的授权信息会更新，LotusWorkers将需要此令牌来连接到LotusMiner
所有worker更新完以后，执行
```shell script
lotus-miner sealing workers
```
如果没有问题，迁移完成

注意：
由于我们的运行环境多种多样，所以教程无法覆盖所有情形，存储提供者应该根据具体情况调整操作
测试版本信息如下：
> lotus version: lotus-miner version 1.11.1-dev+git.19048e6a9. 
> os version: Linux Ubuntu 20.04. 
> network: nerpa