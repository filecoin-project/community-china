#########################################################################
# File Name: start_miner.sh
# Author: tears
# mail: tears@tears.com
# Created Time: 2020年03月13日 星期五 20时08分07秒
#########################################################################
#!/bin/bash

lotus_path="/home/tears/filecoin/official/lotus"
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

green_print "Importing the genesis miner key..."
sleep 2s
${lotus_path}/lotus wallet import ~/.genesis-sectors/pre-seal-t01000.key
blue_print "Importing the genesis miner key finished!"
echo -e "\n"

# This step just needed in testnet/3 and later
green_print "Setting default wallet..."
sleep 2s
wallet_addr=$(${lotus_path}/lotus wallet list | grep 't3' | awk '{print $1}')
blue_print2 "Wallet address is: ${wallet_addr}"
${lotus_path}/lotus wallet set-default ${wallet_addr}
blue_print "Setting default wallet finished!"
echo -e "\n"

# Optional
# export IPFS_GATEWAY="https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/"
export RUST_LOG=Trace

green_print "Initializing storage miner..."
sleep 5s
${lotus_path}/lotus-miner init --genesis-miner --actor=t01000 --sector-size=${sector_size} --pre-sealed-sectors=~/.genesis-sectors --pre-sealed-metadata=~/.genesis-sectors/pre-seal-t01000.json --nosync
blue_print "Initializing storage miner finished!"
echo -e "\n"

green_print "Starting storage miner..."
sleep 5s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S miner -t miner_$t ${lotus_path}/lotus-miner run --nosync
blue_print "Starting storage miner finished!"
echo -e "\n"

green_print "Showing wallet balance..."
sleep 2s
wallet_balance=$(${lotus_path}/lotus wallet  balance)
blue_print2 "Wallet balance is : ${wallet_balance}"
blue_print "Showing wallet balance finished!"
echo -e ""

green_print "Showing storage miner info..."
sleep 2s
${lotus_path}/lotus-miner info
blue_print "Showing storage miner info finished!"
echo -e ""


