#!/bin/bash

######## 启动非创世矿工专用脚本 ######## 
#### 本脚本默认基于 screen 软件集成 ####

home_path="/home/ml"                        # Home 目录的路径
genesis_host_name="ml"                      # 创世节点主机的用户名
# genesis_host_ip="192.168.1.8"             # 创世节点主机的IP
genesis_host_ip="192.168.1.11"              # 创世节点主机的IP
# genesis_host_ip="192.168.100.190"         # 创世节点主机的IP
# genesis_host_ip="192.168.100.163"         # 创世节点主机的IP
# genesis_host_ip="192.168.100.18"          # 创世节点主机的IP
# genesis_host_ip="192.168.88.9"            # 创世节点主机的IP
# genesis_host_ip="192.168.100.23"          # 创世节点主机的IP
genesis_lotus_path="${home_path}/git/lotus" # 创世节点主机 lotus 目录
lotus_path="${home_path}/git2/lotus"        # 本机 lotus 目录
sector_size="2KiB"                          # 默认扇区大小
# sector_size="512MiB"                      # 默认扇区大小

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

# # For the second miner
# export LOTUS_PATH=/home/ml/.lotus2
# export LOTUS_STORAGE_PATH=/home/ml/.lotusminer2

# 获取创世节点监听的网络地址
green_bold_print "Get listen address of genesis daemon..."
sleep 1s
genesis_daemon_listen_addr=$(ssh ${genesis_host_name}@${genesis_host_ip} "${genesis_lotus_path}/lotus net listen" | grep "${genesis_host_ip}")
blue_print "Listen address is : ${genesis_daemon_listen_addr}"
blue_bold_print "Get listen address of genesis daemon finished!"

# 手动连接到创世节点上
green_bold_print "Connect to the genesis daemon..."
sleep 1s
${lotus_path}/lotus net connect $genesis_daemon_listen_addr
blue_bold_print "Connect to the genesis daemon finished!"

# 创建一个新的钱包
green_bold_print "Create a user account..."
sleep 2s
wallet_addr=$(${lotus_path}/lotus wallet new bls)
blue_print "User account is : ${wallet_addr}"
blue_bold_print "Create a user account finished!"

# 让创世节点发送 100 FIL 到当前钱包中
FIL=100
green_bold_print "Sending funds (${FIL} FIL)  to this wallet..."
sleep 1s
ssh ${genesis_host_name}@${genesis_host_ip} "${genesis_lotus_path}/lotus send ${wallet_addr} ${FIL}"
blue_bold_print "Sending funds (${FIL} FIL) to this wallet finished!"

# 等待余额到帐
green_bold_print "Waitting, until we get funds!"
idx=1
while ((idx<=2000))
do
    sleep 2s  # 2 秒钟查询一次账户余额
    wallet_balance=$(${lotus_path}/lotus wallet balance ${wallet_addr} | awk '{print $1}')
    blue_print "[${idx}] Wallet balance is : ${wallet_balance} FIL"
    let idx++
    if [ ${wallet_balance} -gt 0 ]; then
        blue_bold_print "Get funds, break loop process!"
        break
    fi
done
echo -e ""

# 钱包有钱了之后，就可以初始化新矿工了
green_bold_print "Initializing storage miner..."
sleep 2s
${lotus_path}/lotus-miner init --sector-size=${sector_size} 
blue_bold_print "Initializing storage miner finished!"

# 启动新矿工
green_bold_print "Starting storage miner..."
sleep 1s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S miner -t miner_$t ${lotus_path}/lotus-miner run 
blue_bold_print "Starting storage miner finished!"

# 查看新矿工信息
green_bold_print "Showing storage miner info..."
sleep 2s
${lotus_path}/lotus-miner info
blue_bold_print "Showing storage miner info finished!"

# LOTUS_PATH=/home/ml/.lotus2 ~/git2/lotus/lotus net connect
# LOTUS_PATH=/home/ml/.lotus2 LOTUS_STORAGE_PATH=/home/ml/.lotusminer2 ~/git2/lotus/lotus-miner init --sector-size=${sector_size} 
# LOTUS_PATH=/home/ml/.lotus2 LOTUS_STORAGE_PATH=/home/ml/.lotusminer2 ~/git2/lotus/lotus-miner run --miner-api=2346
# LOTUS_PATH=/home/ml/.lotus2 LOTUS_STORAGE_PATH=/home/ml/.lotusminer2 ~/git2/lotus/lotus-miner info
# ~/git2/lotus/lotus-miner auth api-info --perm admin
# grep -ni "swarm" /tmp/screenlog_daemon_*.log
# ~/git2/lotus/lotus-miner sectors batching precommit --publish-now
# ~/git2/lotus/lotus-miner sectors batching commit    --publish-now



