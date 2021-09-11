#########################################################################
# File Name: start_daemon.sh
# Author: ml
# mail: ml@ml.com
# Created Time: 2020年03月13日 星期五 20时02分59秒
#########################################################################
#!/bin/bash

home_path="/home/ml"                        # Home 目录的路径
genesis_host_name="ml"                      # 创世节点主机的用户名
# genesis_host_ip="192.168.1.8"             # 创世节点主机的IP
genesis_host_ip="192.168.1.11"              # 创世节点主机的IP
# genesis_host_ip="192.168.100.190"         # 创世节点主机的IP
# genesis_host_ip="192.168.100.20"          # 创世节点主机的IP
# genesis_host_ip="192.168.88.9"             # 创世节点主机的IP
# genesis_host_ip="192.168.100.23"          # 创世节点主机的IP
genesis_lotus_path="${home_path}/git/lotus" # 创世节点主机 lotus 目录
lotus_path="${home_path}/git2/lotus"        # 本机 lotus 目录
sector_size="2KiB"                          # 默认扇区大小

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

# For the second lotus
# export LOTUS_PATH=/home/ml/.lotus2

green_print "Starting lotus daemon..."
# sleep 1s
# --repo=${home_path}/.lotus/
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S daemon -t daemon_$t ${lotus_path}/lotus daemon --genesis=devgen.car --bootstrap=false 
blue_print "Starting lotus daemon finished!"
echo -e "\n"

green_print "Get listen address of genesis daemon..."
# sleep 1s
genesis_daemon_listen_addr=$(ssh ${genesis_host_name}@${genesis_host_ip} "${genesis_lotus_path}/lotus net listen" | grep "${genesis_host_ip}")
blue_print2 "Listen address is : ${genesis_daemon_listen_addr}"
blue_print "Get listen address of genesis daemon finished!"
echo -e ""

green_print "Connect to the genesis daemon node..."
sleep 1s
${lotus_path}/lotus net connect ${genesis_daemon_listen_addr}
blue_print "Connect to the genesis daemon node finished!"
echo -e ""

# screen -r daemon
