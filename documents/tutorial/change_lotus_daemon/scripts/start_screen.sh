#########################################################################
# File Name: start_screen.sh
# Author: ml
# mail: ml@ml.com
# Created Time: Sat 14 Mar 2020 10:46:50 PM CST
#########################################################################
#!/bin/bash



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

green_print "Starting screen..."

t=$(date +%Y_%m_%d_%H_%M)
name="$1"
if [[ "${name}" == "sudo" ]]; then
    name=$2
fi
# green_print $name

if [[ $name == ./* ]]; then
    name=${name:2}
fi
# green_print $name

blue_print2 screen -L -S ${name} -t ${name}_${t} $@
sleep 5s
screen -L -S ${name} -t ${name}_${t} $@

blue_print "Starting screen finished."
echo -e "\n"

