#########################################################################
# File Name: start_worker.sh
# Author: ml
# mail: ml@ml.com
# Created Time: Sat 14 Mar 2020 11:23:04 AM CST
#########################################################################
#!/bin/bash


home_path="/home/ml"                        # Home 目录的路径
miner_host_name="ml"                        # miner 节点主机的主机名
miner_host_ip="192.168.100.18"              # miner 节点主机的IP
# host_ip="192.168.100.190"                 # worker 主机的IP
host_ip="192.168.100.18"                    # worker 主机的IP
host_port="2333"                            # worker 主机的端口
lotus_path="${home_path}/git2/lotus"         # 本机 lotus 目录
sector_size="2KiB"                          # 默认扇区大小
miner_token="eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBbGxvdyI6WyJyZWFkIiwid3JpdGUiLCJzaWduIiwiYWRtaW4iXX0.5cBlvoHxIBbfqTI0G5GuIRZixqz5l7FDxVwfXxb2t-c"
miner_api="/ip4/192.168.100.18/tcp/2345/http"
miner_home_path="/home/ml"                           # miner 主机的 home 目录的路径
miner_storage_path="${miner_home_path}/.lotusminer"  # miner 主机的 lotus 目录
miner_info=${miner_token}:${miner_api}


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

# 更新系统时间
# sudo ntpdate ntp.aliyun.com
sudo date --set="$(ssh ${miner_host_name}@${miner_host_ip} date +"%H:%M:%S")"


# green_print "Copy api and token from miner..."
# rm -rf ~/.lotusminer/
# mkdir ~/.lotusminer
# rm -rf ~/.lotusworker/
# # scp -i /home/ml/.ssh/id_rsa_vbox_18.04 ml@${miner_host_ip}:~/.lotusminer/{api,token} ./.lotusminer/
# scp ml@${miner_host_ip}:~/.lotusminer/{api,token} ./.lotusminer/
# blue_print "Copy api and token from miner finished!"

green_print "Get api and token from miner..."
miner_token=$(ssh ${miner_host_name}@${miner_host_ip} "cat ${miner_storage_path}/token")
blue_print2 "Miner token is: [${miner_token}]"
miner_api=$(ssh ${miner_host_name}@${miner_host_ip} "cat ${miner_storage_path}/api")
blue_print2 "Miner api is: [${miner_api}]"
miner_info=${miner_token}:${miner_api}
blue_print2 "Miner info is: [${miner_info}]"
blue_print "Get api and token from miner finished!"


green_print "Starting storage worker..."
sleep 2s
t=$(date +%Y_%m_%d_%H_%M)
#screen -L -S worker -t worker_2020_03_13_20_08 /home/ml/filecoin/lotus/lotus-seal-worker run 
# BELLMAN_NO_GPU=1 RUST_LOG=Trace screen -L -S worker -t worker_$t ${lotus_path}/lotus-worker run --listen=${host_ip}:${host_port} --precommit1=true --precommit2=true --commit=true --addpiece=true --parallel-fetch-limit=1 --unseal=true
STORAGE_API_INFO=${miner_info} BELLMAN_NO_GPU=1 RUST_LOG=Trace screen -L -S worker -t worker_$t ${lotus_path}/lotus-worker run --listen=${host_ip}:${host_port} --addpiece=true --precommit1=true --precommit2=true --commit=true --parallel-fetch-limit=1 --unseal=true
MINER_API_INFO=${miner_info} BELLMAN_NO_GPU=1 RUST_LOG=Trace screen -L -S worker -t worker_$t ${lotus_path}/lotus-worker run --listen=${host_ip}:${host_port} --addpiece=true --precommit1=true --precommit2=true --commit=true --parallel-fetch-limit=1 --unseal=true

# export STORAGE_API_INFO=${miner_token}:${miner_api}
# export MINER_API_INFO=${miner_token}:${miner_api}
# BELLMAN_NO_GPU=1 RUST_LOG=Trace ~/git2/lotus/lotus-worker run --listen=192.168.100.18:2333 --addpiece=true --precommit1=true --precommit2=true --commit=false --parallel-fetch-limit=1 --unseal=false
# BELLMAN_NO_GPU=1 RUST_LOG=Trace ~/git/lotus/lotus-worker run --listen=192.168.100.190:2333 --addpiece=true --precommit1=true --precommit2=true --commit=true --parallel-fetch-limit=1 --unseal=true
blue_print "Starting storage worker finished!"
echo -e "\n"


