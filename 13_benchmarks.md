## [回目录](./README.md)

## 13 Benchmark

### 13.1 v26 版本参数

- CPU： AMD 3970x (32核心64线程)
- GPU： RTX 2080Ti
- 内存： 256GB (2133MHz)
- 硬盘： NVMe 1TB * 2

#### CPU+GPU

```sh
# 命令
t=$(date +%Y_%m_%d_%H_%M_%S)
FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --storage-dir=/home/gossip/disk_nvme1/lotus-bench

# 结果

results (v26) (34359738368)
seal: addPiece: 6m15.3044756s (87.3 MiB/s)
seal: preCommit phase 1: 4h12m45.246321786s (2.16 MiB/s)
seal: preCommit phase 2: 33m25.314284805s (16.3 MiB/s)
seal: commit phase 1: 3.376010315s (9.48 GiB/s)
seal: commit phase 2: 43m46.504108069s (12.5 MiB/s)
seal: verify: 30.908086ms
unseal: 4h10m45.224077903s  (2.18 MiB/s)

generate candidates: 2.716063ms (11.5 TiB/s)
compute winnnig post proof (cold): 4.727151776s
compute winnnig post proof (hot): 2.921746828s
verify winnnig post proof (cold): 72.31729ms
verify winnnig post proof (hot): 15.464289ms

compute window post proof (cold): 17m16.771668516s
compute window post proof (hot): 11m34.142457801s
verify window post proof (cold): 5.157438678s
verify window post proof (hot): 43.763838ms

```

#### CPU

```sh
# 命令
# BELLMAN_NO_GPU 环境变量的使用请参考第 6 节的说明
t=$(date +%Y_%m_%d_%H_%M_%S)
BELLMAN_NO_GPU=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --no-gpu --storage-dir=/home/gossip/disk_nvme1/lotus-bench

# 结果

results (v26) (34359738368)
seal: addPiece: 6m18.045655671s (86.7 MiB/s)
seal: preCommit phase 1: 4h11m2.665760729s (2.18 MiB/s)
seal: preCommit phase 2: 51m35.998398427s (10.6 MiB/s)
seal: commit phase 1: 3.2534009s (9.84 GiB/s)
seal: commit phase 2: 1h19m24.107221673s (6.88 MiB/s)
seal: verify: 27.802053ms
unseal: 4h10m25.648494319s  (2.18 MiB/s)

generate candidates: 2.331868ms (13.4 TiB/s)
compute winnnig post proof (cold): 5.941671756s
compute winnnig post proof (hot): 4.172625272s
verify winnnig post proof (cold): 64.764102ms
verify winnnig post proof (hot): 17.119677ms

compute window post proof (cold): 26m34.328794808s
compute window post proof (hot): 20m47.199004707s
verify window post proof (cold): 5.195517605s
verify window post proof (hot): 46.366221ms

```

### 13.2 v27 版本参数

- CPU： AMD 3970x (32核心64线程)
- GPU： RTX 2080Ti
- 内存： 256GB (2133MHz)
- 硬盘： NVMe 1TB * 2

#### CPU+GPU【next 分支】

```sh
# 命令
t=$(date +%Y_%m_%d_%H_%M_%S)
FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --storage-dir=/home/gossip/disk_nvme1/lotus-bench

# 结果

results (v27) (34359738368)
seal: addPiece: 10m0.840580268s (54.5 MiB/s)
seal: preCommit phase 1: 4h11m42.386256191s (2.17 MiB/s)
seal: preCommit phase 2: 27m5.279700449s (20.2 MiB/s)
seal: commit phase 1: 2.594602083s (12.3 GiB/s)
seal: commit phase 2: 50m31.427904703s (10.8 MiB/s)
seal: verify: 27.388448ms
unseal: 4h12m40.52388773s  (2.16 MiB/s)

generate candidates: 2.714168ms (11.5 TiB/s)
compute winnnig post proof (cold): 6.114939733s
compute winnnig post proof (hot): 5.097337848s
verify winnnig post proof (cold): 50.41631ms
verify winnnig post proof (hot): 15.678623ms

compute window post proof (cold): 18m51.79180394s
compute window post proof (hot): 11m25.783003134s
verify window post proof (cold): 5.36059116s
verify window post proof (hot): 47.596046ms

```


#### CPU【master 分支】

```sh
# 命令
# BELLMAN_NO_GPU 环境变量的使用请参考第 6 节的说明
t=$(date +%Y_%m_%d_%H_%M_%S)
BELLMAN_NO_GPU=1 FIL_PROOFS_MAXIMIZE_CACHING=1 RUST_LOG=Trace screen -L -S bench -t bench_${t} ./bench sealing --sector-size=32GiB --no-gpu --storage-dir=/home/gossip/disk_nvme1/lotus-bench


# lotus 版本
# lotus version 0.4.1+git.9d56dabb

# 结果

results (v27) (34359738368)
seal: addPiece: 10m10.633126077s (53.7 MiB/s)
seal: preCommit phase 1: 4h14m22.4235947s (2.15 MiB/s)
seal: preCommit phase 2: 51m36.998604335s (10.6 MiB/s)
seal: commit phase 1: 1.151689271s (27.8 GiB/s)
seal: commit phase 2: 1h36m30.270483546s (5.66 MiB/s)
seal: verify: 34.083162ms
unseal: 4h13m10.812170289s  (2.16 MiB/s)

generate candidates: 2.333397ms (13.4 TiB/s)
compute winnnig post proof (cold): 7.327267683s
compute winnnig post proof (hot): 6.318365117s
verify winnnig post proof (cold): 45.298003ms
verify winnnig post proof (hot): 16.806329ms

compute window post proof (cold): 28m6.99008574s
compute window post proof (hot): 20m41.201090515s
verify window post proof (cold): 5.46349285s
verify window post proof (hot): 37.986216ms

```

### 13.3  v28 版本参数

- CPU： AMD 3970x (32核心64线程)
- GPU： RTX 2080Ti
- 内存： 256GB (2133MHz)
- 硬盘： NVMe 1TB * 2
- 时间：2020/11/26
- 其它： 多线程 P1 + GPU P2

```sh
results (v28) SectorSize:(34359738368), SectorNumber:(1)
seal: addPiece: 10m48.240241696s (50.55 MiB/s)
seal: preCommit phase 1: 2h22m21.760639531s (3.836 MiB/s)
seal: preCommit phase 2: 24m51.560433206s (21.97 MiB/s)
seal: commit phase 1: 1.140462976s (28.06 GiB/s)
seal: commit phase 2: 47m29.898859543s (11.5 MiB/s)
seal: verify: 8.01946ms

generate candidates: 853.599µs (36.61 TiB/s)
compute winning post proof (cold): 2.128980727s
compute winning post proof (hot): 1.78541416s
verify winning post proof (cold): 61.022724ms
verify winning post proof (hot): 4.231715ms

compute window post proof (cold): 5m48.192993009s
compute window post proof (hot): 5m28.177627942s
verify window post proof (cold): 6.493587214s
verify window post proof (hot): 10.944523ms
```

## [回目录](./README.md)