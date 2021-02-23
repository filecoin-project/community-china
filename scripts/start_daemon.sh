#########################################################################
# File Name: start_daemon.sh
# Author: tears
# mail: tears@tears.com
# Created Time: 2020年03月13日 星期五 20时02分59秒
#########################################################################
#!/bin/bash

genesis_host_name="tears"
genesis_host_ip="192.168.1.11"
lotus_path="/home/tears/filecoin/official/lotus"

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
# sleep 2s
# ./reset_lotus.sh
rm -rf ~/.lotus
rm -rf ~/.lotusminer/
rm -rf ~/dev.gen
rm -rf ~/.genesis-sectors
rm -rf ~/.lotusworker
rm -rf ~/localnet.json
blue_print "Reseting data finished!"
echo -e ""

green_print "Copying genesis data..."
# sleep 2s
scp ${genesis_host_name}@${genesis_host_ip}:/home/tears/dev.gen /home/tears/dev.gen
blue_print "Copying genesis data finished!"
echo -e ""

green_print "Starting lotus daemon..."
# sleep 1s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S daemon -t daemon_$t ${lotus_path}/lotus daemon --genesis=dev.gen --bootstrap=false 
blue_print "Starting lotus daemon finished!"
echo -e "\n"

