#!/bin/bash

######## 启动非创世节点专用脚本 ######## 
#### 本脚本默认基于 screen 软件集成 ####
##### sudo apt install screen ######

# FFI_BUILD_FROM_SOURCE=1 make clean all lotus-seed lotus-bench


home_path="/home/ml"                         # Home 目录的路径
genesis_host_name="ml"                       # 创世节点主机的用户名
genesis_home_path="${home_path}"             # 创世节点主机的 Home 目录的路径
# genesis_host_ip="192.168.1.8"              # 创世节点主机的IP
genesis_host_ip="192.168.1.11"               # 创世节点主机的IP
# genesis_host_ip="192.168.100.190"          # 创世节点主机的IP
# genesis_host_ip="192.168.100.163"          # 创世节点主机的IP
# genesis_host_ip="192.168.88.9"             # 创世节点主机的IP
# genesis_host_ip="192.168.100.23"           # 创世节点主机的IP
genesis_lotus_path="${genesis_home_path}/git/lotus"  # 创世节点主机 lotus 目录
lotus_path="${home_path}/git2/lotus"         # 本机 lotus 目录

# 

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


# 更新系统时间
sudo ntpdate ntp.aliyun.com


# 复制创世节点生成的 devgen.car 文件
green_bold_print "Copying genesis data..."
sleep 2s
scp ${genesis_host_name}@${genesis_host_ip}:${genesis_home_path}/devgen.car ${home_path}/devgen.car
blue_bold_print "Copy genesis data finished!"

# 启动新节点
green_bold_print "Starting lotus daemon..."
sleep 1s
t=$(date +%Y_%m_%d_%H_%M)
screen -L -S daemon -t daemon_$t ${lotus_path}/lotus daemon --genesis="${home_path}/devgen.car" --bootstrap=false 
blue_bold_print "Start lotus daemon finished!"


# ~/git/lotus/lotus-miner sectors batching precommit --publish-now
# ~/git/lotus/lotus-miner sectors list --show-removed --color --events --seal-time
# ~/git/lotus/lotus-miner sectors batching commit --publish-now

# LOTUS_PATH=/home/ml/.lotus2 ~/git2/lotus/lotus daemon --genesis=./devgen.car --api=1235 --bootstrap=false
# LOTUS_PATH=/home/ml/.lotus2 ~/git2/lotus/lotus wallet new bls
# LOTUS_PATH=/home/ml/.lotus2 ~/git2/lotus/lotus wallet list

# ip=`ifconfig | grep "inet 192.168.1" | awk '{print $2}'`
# sed -i "s/\/ip4\/127.0.0.1\/tcp\/1234\/http/\/ip4\/$ip\/tcp\/1234\/http//g" ~/.lotus/.config.toml
# sed -i "s/\/ip4\/127.0.0.1\/tcp\/1234\/http/\/ip4\/$ip\/tcp\/1234\/http//g" ~/.lotus/config.toml
# sed -i "s/127.0.0.1\/tcp/${ip}\/tcp/g" ~/.lotus/config.toml 
# grep -ni "ListenAddress" ~/.lotus/config.toml
