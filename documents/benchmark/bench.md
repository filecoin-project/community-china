# Lotus Benchmarks

## AMD EPYC系列CPU
- CPU： AMD EPYC 7542
- GPU： RTX 2080Ti
- 内存： 1TB (2933MHz)
- 硬盘： NVMe 2TB * 8
- 扇区：32GB扇区
```sh
----
results (v28) SectorSize:(34359738368), SectorNumber:(1)
seal: addPiece: 1m19.721062794s (411 MiB/s)
seal: preCommit phase 1: 2h48m33.29921516s (3.24 MiB/s)
seal: preCommit phase 2: 19m4.271091197s (28.64 MiB/s)
seal: commit phase 1: 338.146345ms (94.63 GiB/s)
seal: commit phase 2: 23m49.235556987s (22.93 MiB/s)
seal: verify: 10.807023ms

generate candidates: 242.985µs (128.6 TiB/s)
compute winning post proof (cold): 2.134456641s
compute winning post proof (hot): 2.071956308s
verify winning post proof (cold): 66.543122ms
verify winning post proof (hot): 3.940808ms

compute window post proof (cold): 4m6.503745505s
compute window post proof (hot): 4m2.118297572s
verify window post proof (cold): 8.268479059s
verify window post proof (hot): 13.094437ms
```

- CPU： AMD EPYC 7542
- GPU： RTX 2080Ti
- 内存： 1TB (2933MHz)
- 硬盘： NVMe 2TB * 8
- 扇区：64GB扇区
```sh
----
results (v28) SectorSize:(68719476736), SectorNumber:(1)
seal: addPiece: 3m1.884041138s (360.3 MiB/s)
seal: preCommit phase 1: 5h44m46.301380435s (3.168 MiB/s)
seal: preCommit phase 2: 42m31.04042763s (25.69 MiB/s)
seal: commit phase 1: 632.040017ms (101.3 GiB/s)
seal: commit phase 2: 23m35.980854963s (46.28 MiB/s)
seal: verify: 11.337595ms

generate candidates: 304.804µs (205 TiB/s)
compute winning post proof (cold): 2.223087524s
compute winning post proof (hot): 2.11883932s
verify winning post proof (cold): 66.813428ms
verify winning post proof (hot): 3.869602ms

compute window post proof (cold): 4m16.894513222s
compute window post proof (hot): 4m0.66296702s
verify window post proof (cold): 8.102050986s
verify window post proof (hot): 17.048318ms
```

## AMD 3970x系列CPU

- CPU： AMD 3970x (32核心64线程)
- GPU： RTX 2080Ti
- 内存： 256GB (2133MHz)
- 硬盘： NVMe 1TB * 2
- 扇区：32GB扇区
- 时间：2020/11/26
- 其它： 多线程 P1 + GPU P2
```sh
----
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