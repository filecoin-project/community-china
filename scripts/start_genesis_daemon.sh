#########################################################################
# File Name: start_daemon.sh
# Author: tears
# mail: tears@tears.com
# Created Time: 2020年03月13日 星期五 20时02分59秒
#########################################################################
#!/bin/bash

lotus_path="/home/tears/filecoin/official/lotus"
sector_size="2KiB"  # Default sector size
sector_num="1"

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
sleep 2s
# ./reset_lotus.sh
rm -rf ~/.lotus/
rm -rf ~/.lotusstorage/
rm -rf ~/.lotusworker/
rm -rf ~/.lotus-bench/
rm -rf ~/.lotusminer/
rm -rf ~/.genesis-sectors/
rm -rf ~/dev.gen
rm -rf ~/localnet.json
blue_print "Reseting data finished!"
echo -e ""

# Testnet3 support 2KiB sector size
# make debug
# ./lotus fetch-params 2KiB

# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
export RUST_LOG=Trace

green_print "Gengerating pre-seal sector..."
sleep 2s
# lotus-seed pre-seal --sector-size=2KiB --num-sectors=2
${lotus_path}/lotus-seed pre-seal --sector-size=${sector_size} --num-sectors=${sector_num}
blue_print "Gengerating pre-seal sector finished!"
echo -e ""

green_print "Preparing for daemon..."
sleep 2s
${lotus_path}/lotus-seed genesis new localnet.json
blue_print "Preparing for daemon finished!"
echo -e ""

green_print "Adding miner..."
sleep 2s
${lotus_path}/lotus-seed genesis add-miner localnet.json ~/.genesis-sectors/pre-seal-t01000.json
blue_print "Adding miner finished!"
echo -e ""

green_print "Generating genesis block and starting daemon..."
sleep 5s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S daemon -t daemon_$t ${lotus_path}/lotus daemon --lotus-make-genesis=dev.gen --genesis-template=localnet.json --bootstrap=false
green_print "Generating genesis block and starting daemon finished!"
echo -e "\n"



