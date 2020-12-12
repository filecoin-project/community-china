## [回目录](./README.md)

## 12. 常用的两个查看系统资源的工具

### 12.1 htop 查看 CPU 和内存等信息

htop 比系统自带的 top 界面更加友好，在 Ubuntu 上安装只需要执行：

```sh
sudo apt install htop
```

效果如下：

![htop效果](./pictures/htop.png)

### 12.2 nvtop 查看显卡信息

nvtop 比 nvidia-msi 好看多了，但是安装稍微麻烦一些：
在 Ubuntu 19.04 之后可以直接使用 `sudo apt install nvtop` 安装，否则，你需要执行以下命令安装：

```sh
sudo apt install cmake libncurses5-dev libncursesw5-dev git
git clone https://github.com/Syllo/nvtop.git
mkdir -p nvtop/build && cd nvtop/build
cmake ..
cmake .. -DNVML_RETRIEVE_HEADER_ONLINE=True  # 如果上一个命令出错就用这个
sudo make install
```

效果如下：

![nbvtop效果](./pictures/nvtop.png)

## [回目录](./README.md)