# 手动将扇区文件转移至永久存储

## 需要手动转移扇区文件的情形

- 同时太多扇区进入finalize状态，由于存储或者`lotus-miner`带宽限制，把扇区文件存入永久存储耗时太久
- `lotus-worker`任务中断，已经提交过provecommit信息上链，在finalize的过程中程序中断。

## 找到扇区文件

可以用如下命令尝试找到扇区文件

```shell
lotus-miner storage find [command options] [sector number]
```

另外一种方法是过滤`lotus-miner`的任务分配日志，查看对应的扇区分配给了哪个`lotus-worker`. 找到扇区文件才能进行下一步工作

## 需要转移的文件

1: `lotus-worker`的sealed文件下对应的扇区文件，例如`~/.lotusworker/sealed/s-t01000-10` 

2: `lotus-worker`的cache文件夹下的文件，例如`~/.lotusworker/cache/s-t01000-10` 32G扇区转移如下文件:

```file
p_aux  
sc-02-data-tree-r-last-0.dat  
sc-02-data-tree-r-last-1.dat  
sc-02-data-tree-r-last-2.dat  
sc-02-data-tree-r-last-3.dat  
sc-02-data-tree-r-last-4.dat  
sc-02-data-tree-r-last-5.dat  
sc-02-data-tree-r-last-6.dat  
sc-02-data-tree-r-last-7.dat  
t_aux
```

64G扇区转移文件如下

```file
p_aux  
sc-02-data-tree-r-last-0.dat  
sc-02-data-tree-r-last-1.dat  
sc-02-data-tree-r-last-2.dat  
sc-02-data-tree-r-last-3.dat  
sc-02-data-tree-r-last-4.dat  
sc-02-data-tree-r-last-5.dat  
sc-02-data-tree-r-last-6.dat  
sc-02-data-tree-r-last-7.dat  
sc-02-data-tree-r-last-8.dat  
sc-02-data-tree-r-last-9.dat  
sc-02-data-tree-r-last-10.dat  
sc-02-data-tree-r-last-11.dat  
sc-02-data-tree-r-last-12.dat  
sc-02-data-tree-r-last-13.dat  
sc-02-data-tree-r-last-14.dat  
sc-02-data-tree-r-last-15.dat 
t_aux
```

把这些扇区文件转移至你的永久存储对应的文件夹下即可

