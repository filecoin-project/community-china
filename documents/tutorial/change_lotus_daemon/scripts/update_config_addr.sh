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


