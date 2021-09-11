#########################################################################
# File Name: update_config_addr.sh
# Author: ml
# mail: ml@ml.com
# Created Time: 2021年09月02日 星期四 22时59分28秒
#########################################################################
#!/bin/bash


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

    echo ""
    echo -e "\033[1m\033[36m[$text]\033[0m"   # 蓝色加粗, 并复原
    # echo ""
}
function blue_print()
{
    local text=$@

    echo ""
    echo -e "\033[36m[$text]\033[0m"   # 蓝色, 并复原
    # echo ""
}


home_path="/home/ml"
lotus_config_file="${home_path}/.lotus/config.toml"
miner_config_file="${home_path}/.lotusminer/config.toml"
ip_addr_patten="inet 192.168.1"


green_bold_print "Before replacement, the [ListenAddress] of [${lotus_config_file}]:"
grep -ni "ListenAddress" ${lotus_config_file}
ip=`ifconfig | grep "${ip_addr_patten}" | awk '{print $2}'`

blue_print "The ip address is: [${ip}]"
# echo -e ""

sed -i "s/127.0.0.1\/tcp/${ip}\/tcp/g" ${lotus_config_file}
sed -i "s/#ListenAddress =/ListenAddress =/g" ${lotus_config_file}
# echo -e ""

blue_bold_print "After replacement, the [ListenAddress] of [${lotus_config_file}]:"
grep -ni "ListenAddress" ${lotus_config_file}
echo -e ""



green_bold_print "Before replacement, the [ListenAddress] of [${miner_config_file}]:"
grep -ni "ListenAddress" ${miner_config_file}
ip=`ifconfig | grep "inet 192.168.1" | awk '{print $2}'`

blue_print "The ip address is: [${ip}]"
# echo -e ""

sed -i "s/127.0.0.1\/tcp/${ip}\/tcp/g" ${miner_config_file}
sed -i "s/#ListenAddress =/ListenAddress =/g" ${miner_config_file}
# echo -e ""

blue_bold_print "After replacement, the [ListenAddress] of [${miner_config_file}]:"
grep -ni "ListenAddress" ${miner_config_file}
echo -e ""



a1="#MaxPreCommitBatch = 256"
a2="MaxPreCommitBatch = 4"
a3="MaxPreCommitBatch ="
sed -n "/${a3}/p" ${miner_config_file}
sed -i "s/${a1}/${a2}/g" ${miner_config_file}
sed -n "/${a3}/p" ${miner_config_file}

b1="#PreCommitBatchWait = \"24h0m0s\""
b2="PreCommitBatchWait = \"0h4m0s\""
b3="PreCommitBatchWait ="
sed -n "/${b3}/p" ${miner_config_file}
sed -i "s/${b1}/${b2}/g" ${miner_config_file}
sed -n "/${b3}/p" ${miner_config_file}

c1="#PreCommitBatchSlack = \"3h0m0s\""
c2="PreCommitBatchSlack = \"0h8m0s\""
c3="PreCommitBatchSlack ="
sed -n "/${c3}/p" ${miner_config_file}
sed -i "s/${c1}/${c2}/g" ${miner_config_file}
sed -n "/${c3}/p" ${miner_config_file}

d1="#MaxCommitBatch = 819"
d2="MaxCommitBatch = 5"
d3="MaxCommitBatch ="
sed -n "/${d3}/p" ${miner_config_file}
sed -i "s/${d1}/${d2}/g" ${miner_config_file}
sed -n "/${d3}/p" ${miner_config_file}

f1="#CommitBatchWait = \"24h0m0s\""
f2="CommitBatchWait = \"0h4m0s\""
f3="#CommitBatchWait ="
f4=" CommitBatchWait ="
sed -n "/${f3}/p" ${miner_config_file}
sed -i "s/${f1}/${f2}/g" ${miner_config_file}
sed -n "/${f4}/p" ${miner_config_file}

e1="#CommitBatchSlack = \"1h0m0s\""
e2="CommitBatchSlack = \"0h9m0s\""
e3="#CommitBatchSlack ="
e4=" CommitBatchSlack ="
sed -n "/${e3}/p" ${miner_config_file}
sed -i "s/${e1}/${e2}/g" ${miner_config_file}
sed -n "/${e4}/p" ${miner_config_file}


