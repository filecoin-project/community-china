## 如何正确删除扇区
在你删除扇区之前请确保已经采取了必要的抢救措施，例如遇到存储故障，网络故障，调度故障等等，都要经过一系列的调试，故障诊断 ,最后再考虑删除扇区，谨慎删除扇区，别忘了，该命令有个选项--really-do-it
 
## 1:　如何删除packing,PreCommitFailed和SealPreCommit1Failed状态的扇区？

这几种状态因为还没有质押，可通过下面的命令直接删除。所有precommit阶段完成之前的扇区，都可以通过此方法删除。

```sh
 $ lotus-miner sectors remove --really-do-it <sectorId>
```
## 2：如果删除状态为PreCommit1，PreCommit2，并且一直卡顿在这些状态的扇区？
##### 1:首先应尝试如下命令删除
```sh
lotus-miner sealing abort <JobId>
```
```sh
lotus-miner sectors remove <SectorId>
```
如果以上两个命令无法删除，可以执行下面的步骤
##### 2.找一个空闲的Worker（如果所有worker工作满状态，则可以通过执行
```sh
lotus-worker tasks disable [command options] [UNS|C2|PC2|PC1|AP]
```
禁用所有任务，等worker执行完当前任务，就没有任何封装任务了，本操作执行完再通过
```sh
lotus-worker tasks enable [command options] [UNS|C2|PC2|PC1|AP]
```
恢复任务），在该worker的LOTUS_WORKER_PATH的unsealed和seald目录下，分别创建对应扇区ID的空扇区文件，假设扇区的ID为100
，那分别在unsealed和seald目录下执行：
```sh
touch s-t0xxxxxx-100# 其中t0xxxxxx是矿工ID
```
##### 3.重启该Worker，注意观察Worker的日志中，该扇区会不会开始封装，如果没有开始封装，可以再重启一下Miner。
 
##### 4. 待该扇区开始封装，在lotus-miner sealing jobs列表中能看到以后，就可以执行命令先终止掉任务。


```sh 
lotus-miner sealing abort <JobId>
```
 

##### 5：执行


```sh 
lotus-miner sectors remove <SectorId>
```
 

## 3：如果删除状态为Committing，并且一直卡顿在这些状态的扇区？
> 注意删除任何precommit已经完成的扇区将导致prcommit阶段的抵押罚没，[参考文档](https://spec.filecoin.io/#section-systems.filecoin_mining.sector.adding_storage)  
>PreCommitting a Sector: A Miner publishes a Sector’s SealedCID, through miner.PreCommitSector of miner.PreCommitSectorBatch, and makes a deposit. The Sector is now registered to the Miner, and the Miner must ProveCommit the Sector or lose their deposit.
##### 1: 同样执行2.1 2.2 2.3
 
##### 2:创建并重启Worker以后，该扇区并不会出现在lotus-miner sealing jobs列表中，而是直接变为CommitFailed，这个时候，执行以下命令删除扇区即可
```shell 
lotus-miner sectors remove <SectorId>
```

## 4：不建议删除commitfaied. finalizedfailed　以及所有完成precommit或者完成provcommit的扇区
建议把错误扇区恢复成出错之前的状态，重新做出错的这个步骤
- 例：扇区commitfailed.此时precommit已经完成，重置扇区状态至commit1
## 5：如何删除因为存储故障，无法恢复的扇区
删除扇区一定要先链上删除再本地删除，这样能最大程度的减少损失，请记住执行顺序，这个相当重要
 
##### 1：执行

删除扇区一定要先链上删除再本地删除，这样能最大程度的减少损失，请记住执行顺序，这个相当重要
 
```shell 
lotus-miner sectors terminate --really-do-it <sectorNum>
```
这一步的主要作用为清除链上数据，最大限度减少处罚
##### 2: 等到扇区状态变为terminalfinality
 
##### 3：执行

```shell 
lotus-miner sectors remove --really-do-it <sectorNum>
```
这一步的主要作用为清除存储
 

## 6：删除扇区中最常范的错误


很多人会直接执行：lotus-miner sectors remove --really-do-it <sectorNum>,这是错误的。然后找不到扇区编号，也无法terminate. 这样的情况，可以通过
```shell 
lotus-miner sectors list --fast --states Remomved
```
查看到扇区编号，这个时侯再执行
```shell
lotus-miner sectors terminate --really-do-it <sectorNum> 
```
 
感谢@tears和@[bugxzhu](https://github.com/bugxzhu) 提供的帮助
 
 
 
 
 

