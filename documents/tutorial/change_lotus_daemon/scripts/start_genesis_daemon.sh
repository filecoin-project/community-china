#!/bin/bash

######## 启动创世节点专用脚本 ########
### 本脚本默认基于 screen 软件集成 ###
##### sudo apt install screen #####

# set -ex  # 启用这个选项可以详细看到各个命令的执行情况
# FFI_BUILD_FROM_SOURCE=1 make clean all lotus-seed lotus-bench

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
# pre_seal_metadata="${home_path}/.genesis-sectors/pre-seal-f01000.json"     # For release version

# 更新系统时间
sudo ntpdate ntp.aliyun.com

# export LOTUS_SKIP_GENESIS_CHECK=_yes_

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

# 删除旧数据
green_bold_print "Reseting data..."
sleep 2s
rm -rf ${home_path}/.lotus/
rm -rf ${home_path}/.lotusminer/
rm -rf ${home_path}/.lotusworker/
rm -rf ${home_path}/.genesis-sectors/
rm -rf ${home_path}/devgen.car
rm -rf ${home_path}/localnet.json
blue_bold_print "Reseting data finished!"

# FFI_BUILD_FROM_SOURCE=1 make clean debug
# FFI_BUILD_FROM_SOURCE=1 CGO_CFLAGS="-D__BLST_PORTABLE__" make clean all lotus-seed
# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
# ./lotus fetch-params 2KiB

# [可选] 设置 log 等级为 Trace，还可以设置为 Debug/Info/Warn/Error
export RUST_LOG=Trace

# 预密封两个扇区
green_bold_print "Gengerating pre-seal sector..."
sleep 2s
# lotus-seed pre-seal --sector-size=2KiB --num-sectors=2
${lotus_path}/lotus-seed pre-seal --sector-size=${sector_size} --num-sectors=${sector_num}
blue_bold_print "Gengerating pre-seal sector finished!"

green_bold_print "Preparing for daemon..."
sleep 2s
${lotus_path}/lotus-seed genesis new "${home_path}/localnet.json"
blue_bold_print "Preparing for daemon finished!"

green_bold_print "Adding miner..."
sleep 2s
${lotus_path}/lotus-seed genesis add-miner "${home_path}/localnet.json" "${pre_seal_metadata}"
blue_bold_print "Adding miner finished!"

green_bold_print "Generating genesis block and starting daemon..."
sleep 5s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S daemon -t daemon_$t ${lotus_path}/lotus daemon --lotus-make-genesis="${home_path}/devgen.car" --genesis-template="${home_path}/localnet.json" --bootstrap=false
green_bold_print "Generating genesis block and starting daemon finished!"
echo -e "\n"

# Ctrl+A+D
# screen -r daemon

# Restart genesis daemon
# ${lotus_path}/lotus daemon --genesis="${home_path}/devgen.car" --profile=bootstrapper