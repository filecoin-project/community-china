# 过低的幸运值的排查方法

如果你在区块浏览器中发现自己幸运值较低，在当前全网算力12.76ＥＢ的情况下，如果你的storage power不高于１ＰＢ。出现幸运值的波动是比较正常的情况，如果你的幸运值长期低于100%，例如超过一个月，你可以用以下的方法去排查，当然，经过排查如果一切正常，你可能只是运气比较差，不用过份担心，我们的运气是一样的。

## 　不要错过选举

每天有2880轮次的winning block选举。如果因为`lotus damon`网络稳定性不好，有些storage provider可能不会监控网络状态，所以有些时侯不稳定你可能感觉不到，通过过滤日志，你可以查看这些轮次是不是足够的. 可以通过命令：　`cat miner.nohup  | grep <date> | grep 'completed mineOne' | wc -l`,实际例子:

```shell
cat miner.log  | grep 2021-09-29 | grep 'completed mineOne' |wc -l
```

如果你得到的结果是2880就是正常的，过滤日期不要选择当天的，当天的一般不足24小时，无法有效判断轮次是不是正常。

## 　查看winningpost是否超时

winningpost的耗时可以通过如下这条日志查看到：
>storageminer    storage/miner.go:295    GenerateWinningPoSt took 1.863073709s

你可以过滤你的storage provider日志：

```shell
cat miner.log  | grep 'GenerateWinningPoSt took'
```

个人认为，如果时长超过15秒就要注意，可以检查一下计算过慢的原因。一个重要的winning post超时的原因是：winningpost和windowpost计算冲突。假如你的winningpost用时超过10分钟。大概率是因为系统在处理windowpost。处理完以后，才会开始计算winningpost.这个是已知的问题，正在改进中，目前只有通过提升硬件，缩短windowpost的时长来减少发生冲突的概率。

## 　查看是否有孤块产生

如果你前面排查都很正常，没有任何问题,那么可以检查一下是不是产生了孤块，一个赢得区块的日志是这样的：
> 2021-10-09T15:20:38.825+0900    INFO    miner   miner/miner.go:568      mined new block {"cid": "bafy2bzacedjwoq54i54vfouj7oypbtnqrirlpq2afbr5bqrei2xfrb5smidr2", "height": 1181802, "miner": "f0401254", "parents": ["f01138014","f020378"], "parentTipset": "{bafy2bzacebmjsfzhfkbpnt3qgpxx37fqrdmx277jeztqlljppkpnumho4g2q4,bafy2bzacearifujqqvrczbpugkfjnrryv4i7mlusnvab554ogxcovgx634lyy}", "took": 2.819712038}

你可以这样过滤你的日志：

```shell
cat miner.log  | grep 'mined new block'
```

然后针对每次出块的记录，可以在浏览器中查看是不是自己拿到了区块奖励以判断孤块有没有产生。孤块产生一般是因为父块接收不全，可以在日志中查看`parents`字段，跟浏览器的父块做个比较。如果有效避免孤块还没有明确的方法，对于storage provider来说，提高网络稳定性是避免孤块的主要思路。
