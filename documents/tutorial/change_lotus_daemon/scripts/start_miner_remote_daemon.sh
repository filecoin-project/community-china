#########################################################################
# File Name: start_miner.sh
# Author: ml
# mail: ml@ml.com
# Created Time: 2020年03月13日 星期五 20时08分07秒
#########################################################################
#!/bin/bash

home_path="/home/ml"
daemon_host_name="ml"
daemon_host_ip="192.168.1.9"
daemon_lotus_path="${home_path}/git/lotus"
# daemon_host_ip="192.168.1.10"
# daemon_lotus_path="${home_path}/git2/lotus"
lotus_path="${home_path}/git2/lotus"
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

green_print "Reseting data..."
sleep 1s
# rm -rf ~/.lotus/
# rm -rf ~/.lotusstorage/
# rm -rf ~/.lotusworker/
rm -rf ~/.lotusminer/
# rm -rf ~/.lotus-bench/
# rm -rf ~/.genesis-sectors/
# rm -rf ~/devgen.car
# rm -rf ~/localnet.json
blue_print "Reseting data finished!"
echo -e ""

green_print "Get fullnode api info..."
sleep 1s
fullnode_aot_info=$(ssh ${daemon_host_name}@${daemon_host_ip} "${daemon_lotus_path}/lotus auth api-info --perm admin")
blue_print2 "Fullnode api info : ${fullnode_aot_info}"
export ${fullnode_aot_info}
blue_print "Get fullnode api info finished!"
echo -e ""

green_print "Exporting full node api info..."
sleep 1s
export ${fullnode_aot_info}
blue_print2 "export ${fullnode_aot_info}"
blue_print "Exporting full node api info finished!"
echo -e ""

green_print "Initializing storage miner..."
sleep 2s
${lotus_path}/lotus-miner init --sector-size=${sector_size} 
blue_print "Initializing storage miner finished!"
echo -e "\n"

green_print "Starting storage miner..."
sleep 2s
t=$(date +%Y_%m_%d_%H_%M)
RUST_LOG=Trace screen -L -S miner -t miner_$t ${lotus_path}/lotus-miner run 
blue_print "Starting storage miner finished!"
echo -e "\n"

green_print "Showing storage miner info..."
# sleep 2s
${lotus_path}/lotus-miner info
blue_print "Showing storage miner info finished!"
echo -e "\n"


