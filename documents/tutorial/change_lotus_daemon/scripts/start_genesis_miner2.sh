#########################################################################
# File Name: start_miner.sh
# Author: ml
# mail: ml@ml.com
# Created Time: 2020年03月13日 星期五 20时08分07秒
#########################################################################
#!/bin/bash

lotus_path="/home/ml/git/lotus"
sector_size="2KiB"  # Default sector size

# Colorefull print
function green_print()
{
    local text=$@

    echo ""
    echo -e "\033[1m\033[32m[$text]\033[0m"   # 绿色加粗, 并复原
    # echo ""
}
function blue_print()
{
    local text=$@

    # echo ""
    echo -e "\033[1m\033[36m[$text]\033[0m"   # 蓝色加粗, 并复原
    # echo ""
}
function blue_print2()
{
    local text=$@

    # echo ""
    echo -e "\033[36m[$text]\033[0m"   # 蓝色, 并复原
    # echo ""
}

# Optional
# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
export RUST_LOG=Trace

green_print "Restarting storage miner..."
sleep 2s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S miner -t miner_$t ${lotus_path}/lotus-miner run --nosync
blue_print "Restarting storage miner finished!"
echo -e "\n"
