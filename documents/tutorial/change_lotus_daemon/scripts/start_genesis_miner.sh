#!/bin/bash

######## 启动创世矿工专用脚本 ######## 
### 本脚本默认基于 screen 软件集成 ###

# set -ex  # 启用这个选项可以详细看到各个命令的执行情况

# lotus 目录所在的路径
home_path="/home/ml"
lotus_path="${home_path}/git/lotus"
sector_size="2KiB"  # 默认扇区大小
sector_num="2"      # 默认创世扇区数量
# sector_size="512MiB"  # 默认扇区大小
# sector_num="1"        # 默认创世扇区数量

# 目前代码是 v1.4.1
# Debug 版本的代码和 Release 版本的代码生产的数据有一些差别，注意切换
pre_seal_metadata="${home_path}/.genesis-sectors/pre-seal-t01000.json"   # For debug version
key_file="${home_path}/.genesis-sectors/pre-seal-t01000.key"             # For debug version
# pre_seal_metadata="${home_path}/.genesis-sectors/pre-seal-f01000.json"     # For release version
# key_file="${home_path}/.genesis-sectors/pre-seal-f01000.key"               # For release version

# 更新系统时间
# sudo ntpdate ntp.aliyun.com

# 打印输出函数
function green_bold_print()
{
    local text=$@

    echo ""
    echo -e "\033[1m\033[32m[$text]\033[0m"   # 绿色加粗, 并复原
    # echo ""
}
function blue_bold_print()
{
    local text=$@

    # echo ""
    echo -e "\033[1m\033[36m[$text]\033[0m"   # 蓝色加粗, 并复原
    echo ""
}
function blue_print()
{
    local text=$@

    # echo ""
    echo -e "\033[36m[$text]\033[0m"   # 蓝色, 并复原
    # echo ""
}

# 导入创世钱包信息
green_bold_print "Importing the genesis miner key..."
sleep 2s
${lotus_path}/lotus wallet import "${key_file}"
blue_bold_print "Importing the genesis miner key finished!"

# 设置默认钱包地址
green_bold_print "Setting default wallet..."
sleep 2s
wallet_addr=$(${lotus_path}/lotus wallet list | grep 't3' | awk '{print $1}')
blue_print "Wallet address is: ${wallet_addr}"
${lotus_path}/lotus wallet set-default ${wallet_addr}
blue_bold_print "Setting default wallet finished!"

# [可选] 设置 log 等级为 Trace，还可以设置为 Debug/Info/Warn/Error
# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
export RUST_LOG=Trace

# 初始化创世矿工
green_bold_print "Initializing storage miner..."
sleep 5s
${lotus_path}/lotus-miner init --genesis-miner --actor=t01000 --sector-size=${sector_size} --pre-sealed-sectors="${home_path}/.genesis-sectors" --pre-sealed-metadata="${pre_seal_metadata}" --nosync
blue_bold_print "Initializing storage miner finished!"

# 启动创世矿工
green_bold_print "Starting storage miner..."
sleep 5s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S miner -t miner_$t ${lotus_path}/lotus-miner run --nosync
blue_bold_print "Starting storage miner finished!"

# 查看钱包余额
green_bold_print "Showing wallet balance..."
sleep 2s
wallet_balance=$(${lotus_path}/lotus wallet  balance)
blue_print "Wallet balance is : ${wallet_balance}"
blue_bold_print "Showing wallet balance finished!"

# 查看矿工信息
green_bold_print "Showing storage miner info..."
sleep 2s
${lotus_path}/lotus-miner info
blue_bold_print "Showing storage miner info finished!"

# Ctrl+A+D
# screen -r daemon

# Restart genesis miner
# ${lotus_path}/lotus-miner run --nosync
