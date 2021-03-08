# 开启CPU性能模式

## 1. 临时开启

### 1.1 安装cpufrequtils
```sh
sudo apt-get install cpufrequtils
```

### 1.2 查看当前cpu的状态：
```sh
cpufreq-info
```

### 1.3 设置为性能模式
```sh
sudo cpufreq-set -g performance
```

## 2. 开机默认启动性能模式
使用上述方式，重启系统后又回到默认方式。修改默认模式:

### 2.1 安装sysfsutils
```sh
sudo apt-get install sysfsutils
```
### 2.2 编辑/etc/sysfs.conf，增加如下语句:
```sh
devices/system/cpu/cpu0/cpufreq/scaling_governor = performance
```