#!/bin/bash


home_path="/home/ml"                                        # Home 目录的路径
lotus_path="${home_path}/git/lotus"                         # 本机 lotus 目录

old_deamon_home_path="${home_path}"                         # Home 目录的路径
old_deamon_host_name="ml"                                   # 旧节点主机的用户名
old_deamon_host_ip="192.168.1.9"                            # 旧节点主机的IP
old_deamon_lotus_path="${old_deamon_home_path}/git/lotus"   # 旧节点主机 lotus 目录

new_deamon_home_path="${home_path}"                         # Home 目录的路径
new_deamon_host_name="ml"                                   # 旧节点主机的用户名
new_deamon_host_ip="192.168.1.10"                           # 旧节点主机的IP
new_deamon_lotus_path="${new_deamon_home_path}/git2/lotus"  # 旧节点主机 lotus 目录


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

green_bold_print "Getting the wallet key from old daemon [${old_deamon_host_name}@${old_deamon_host_ip}]..."
sleep 1s
# wallet_addr=`${old_deamon_lotus_path}/lotus wallet default`
wallet_addr=$(ssh ${old_deamon_host_name}@${old_deamon_host_ip} "${old_deamon_lotus_path}/lotus wallet default")
blue_print "Wallet address: [${wallet_addr}]"
# wallet_key=`${old_deamon_lotus_path}/lotus wallet export ${wallet_addr}`
wallet_key=$(ssh ${old_deamon_host_name}@${old_deamon_host_ip} "${old_deamon_lotus_path}/lotus wallet export ${wallet_addr}")
blue_print "Wallet key: [${wallet_key}]"
# Optional: delete wallet from old demon
# ssh ${old_deamon_host_name}@${old_deamon_host_ip} "${old_deamon_lotus_path}/lotus wallet delete ${wallet_addr}"
blue_bold_print "Get the wallet key from old daemon finihsed!"


# ~/git2/lotus/lotus wallet import --as-default
green_bold_print "Importting the wallet key to new daemon [${new_deamon_host_name}@${new_deamon_host_ip}]..."
sleep 1s
ssh ${new_deamon_host_name}@${new_deamon_host_ip} "${new_deamon_lotus_path}/lotus wallet import --as-default <<EOF
${wallet_key}
EOF
"
blue_bold_print "Import the wallet key to new daemon finished!"

green_bold_print "Showing the wallet key in new daemon..."
ssh ${new_deamon_host_name}@${new_deamon_host_ip} "${new_deamon_lotus_path}/lotus wallet list -i"
blue_bold_print "Show the wallet key in new daemon finihsed"


green_bold_print "Getting fullnode api info..."
sleep 1s
fullnode_aot_info=$(ssh ${new_deamon_host_name}@${new_deamon_host_ip} "${new_deamon_lotus_path}/lotus auth api-info --perm admin")
blue_print "Fullnode api info : ${fullnode_aot_info}"
export ${fullnode_aot_info}
blue_bold_print "Get fullnode api info finished!"
# echo -e ""

green_bold_print "Exporting full node api info..."
sleep 1s
export ${fullnode_aot_info}
blue_print "export ${fullnode_aot_info}"
blue_bold_print "Exporting full node api info finished!"
# echo -e ""

green_bold_print "Starting storage miner..."
sleep 2s
t=$(date +%Y_%m_%d_%H_%M)
RUST_LOG=Trace screen -L -S miner -t miner_$t ${lotus_path}/lotus-miner run 
blue_bold_print "Starting storage miner finished!"
# echo -e "\n"



