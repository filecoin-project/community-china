#########################################################################
# File Name: start_miner.sh
# Author: tears
# mail: tears@tears.com
# Created Time: 2020年03月13日 星期五 20时08分07秒
#########################################################################
#!/bin/bash

genesis_host_name="tears"
genesis_host_ip="192.168.1.11"
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

green_print "Get listen address of genesis miner..."
# sleep 1s
genesis_miner_listen_addr=$(ssh ${genesis_host_name}@${genesis_host_ip} "lotus net listen" | grep "${genesis_host_ip}")
blue_print2 "Listen address is : ${genesis_miner_listen_addr}"
blue_print "Get listen address of genesis miner finished!"
echo -e ""

green_print "Connect to the genesis miner..."
# sleep 1s
${lotus_path}/lotus net connect $genesis_miner_listen_addr
blue_print "Connect to the genesis miner finished!"
echo -e ""

green_print "Create a user account..."
# sleep 1s
wallet_addr=$(${lotus_path}/lotus wallet new bls)
blue_print2 "User account is : ${wallet_addr}"
blue_print "Create a user account finished!"
echo -e ""

green_print "Sending funds (1000 FIL)  to this wallet..."
# sleep 1s
ssh ${genesis_host_name}@${genesis_host_ip} "${lotus_path}/lotus send ${wallet_addr} 10"
blue_print "Sending funds (1000 FIL) to this wallet finished!"
echo -e ""

green_print "Waitting, until we get funds!"
idx=1
while ((idx<=2000))
do
    sleep 2s
    wallet_balance=$(${lotus_path}/lotus wallet balance ${wallet_addr} | awk '{print $1}')
    blue_print2 "[${idx}] Wallet balance is : ${wallet_balance} FIL"
    let idx++
    if [ ${wallet_balance} -gt 0 ]; then
        blue_print "Get funds, break loop process!"
        break
    fi
done
echo -e ""

green_print "Initializing storage miner..."
sleep 2s
${lotus_path}/lotus-miner init --sector-size=${sector_size} 
blue_print "Initializing storage miner finished!"
echo -e "\n"

green_print "Starting storage miner..."
sleep 2s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S miner -t miner_$t ${lotus_path}/lotus-miner run 
blue_print "Starting storage miner finished!"
echo -e "\n"

green_print "Showing storage miner info..."
# sleep 2s
${lotus_path}/lotus-miner info
blue_print "Showing storage miner info finished!"
echo -e "\n"


