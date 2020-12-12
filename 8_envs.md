## [回目录](./README.md)

## 8 常用环境变量

```sh
# lotus 路径：
LOTUS_PATH
# 例如： export LOTUS_PATH=/home/user/nvme_disk/lotus

# miner 路径： 
LOTUS_STORAGE_PATH
# 例如： export LOTUS_STORAGE_PATH=/home/user/nvme_disk/lotusminer

# worker 路径： 
WORKER_PATH
# 例如： export WORKER_PATH=/home/user/nvme_disk/lotusworker

# proof 证明参数路径： 
FIL_PROOFS_PARAMETER_CACHE
# 例如： export FIL_PROOFS_PARAMETER_CACHE=/home/user/nvme_disk/filecoin-proof-parameters

# 临时文件夹路径： 
TMPDIR
# 例如： export TMPDIR=/home/user/nvme_disk/tmp

# 最大化内存参数
FIL_PROOFS_MAXIMIZE_CACHING
# 例如： export FIL_PROOFS_MAXIMIZE_CACHING=1

# Rust 日志
RUST_LOG
# 例如： export RUST_LOG=Debug

# GPU计算Precommit2
FIL_PROOFS_USE_GPU_COLUMN_BUILDER
# 例如： export FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1

# 源码编译底层库
FFI_BUILD_FROM_SOURCE
# 例如： export FFI_BUILD_FROM_SOURCE=1

# GOLANG 代理
GOPROXY
# 例如： export GOPROXY=https://goproxy.cn

# 启动小扇区支持
FIL_USE_SMALL_SECTORS
# 例如： export FIL_USE_SMALL_SECTORS=true

# 显卡相关
BELLMAN_CUSTOM_GPU
# 例如： export BELLMAN_CUSTOM_GPU="GeForce RTX 2080 Ti:4352"

# 下载证明参数代理：
IPFS_GATEWAY
# 例如： export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"

# Parent cache 参数
FIL_PROOFS_PARENT_CACHE
# 例如： export FIL_PROOFS_PARENT_CACHE=/disk/parent_cache

# 启用 GPU 计算 Precommit2 中的部分过程
FIL_PROOFS_USE_GPU_TREE_BUILDER
FIL_PROOFS_USE_GPU_COLUMN_BUILDER
# 例如：export FIL_PROOFS_USE_GPU_TREE_BUILDER=1
# 例如：export FIL_PROOFS_USE_GPU_COLUMN_BUILDER=1

# 禁用 GPU 参数
BELLMAN_NO_GPU
# 例如：export BELLMAN_NO_GPU=1
# 如果要启用 GPU，则不能让这个环境变量（BELLMAN_NO_GPU）出现在系统的环境变量中（env）
# 如果它出现在 env 中，则需要使用以下命令取消，
#（因为设置 export BELLMAN_NO_GPU=0 无效）：
unset BELLMAN_NO_GPU

# AMD 3970x 2h10m 跑完 P1 环境变量
FIL_PROOFS_USE_MULTICORE_SDR=1

```

## [回目录](./README.md)