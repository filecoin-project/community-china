#########################################################################
# File Name: start_daemon.sh
# Author: ml
# mail: ml@ml.com
# Created Time: 2020年03月13日 星期五 20时02分59秒
#########################################################################
#!/bin/bash

lotus_path="/home/ml/git/lotus"
sector_size="2KiB"  # Default sector size
sector_num="2"

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

# Testnet3 support 2KiB sector size
# make debug
# ./lotus fetch-params 2KiB

# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
export RUST_LOG=Trace

green_print "Restarting daemon..."
sleep 2s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S daemon -t daemon_$t ${lotus_path}/lotus daemon --genesis=devgen.car --genesis-template=localnet.json --bootstrap=false
green_print "Restarting daemon finished!"
echo -e "\n"



