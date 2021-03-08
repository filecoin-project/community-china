# Lotus编译环境搭建

## 1. Golang编译环境安装

### 1.1 下载golang安装包
```sh
# 下载golang安装包
$ wget -c https://golang.org/dl/go1.16.linux-amd64.tar.gz
$ tar -xvf go1.16.linux-amd64.tar.gz
```

### 1.2 安装
```sh
$ sudo chown -R root:root ./go
$ sudo rm -rfv /usr/local/go
$ sudo mv go /usr/local
```

### 1.3 GOPATH写入环境变量
```sh
$ echo "GOPATH=$HOME/go" >> $HOME/.profile
$ echo "export PATH=$PATH:/usr/local/go/bin:$GOPATH/bin" >> $HOME/.profile
```

### 1.4 配置代理
国内网络环境，可以配置goproxy代理，不然编译会非常慢。
```sh
echo "export GOPROXY=https://goproxy.cn" >> $HOME/.profile
```

### 1.5 使环境变量生效
```
$ source $HOME/.profile
```

### 1.6 查看golang版本
```sh
$ go version
```

## 2. Rust编译环境安装
按照以下步骤，安装Rust编译环境。
```sh
$ curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs -o ./rust-setup.sh
$ chmod a+x ./rust-setup.sh
$ ./rust-setup.sh -y 
$ rm ./rust-setup.sh
$ source $HOME/.cargo/env
$ rustup default nightly
```

## 3. Lotus源码编译常见问题

### 3.1 GOPROXY 的问题
编译时如果因为下载代码子模块卡住（GO 代码），可能是 GOPROXY 没有设置，此时，设置一下 GOPROXY，然后再重新编译一遍即可：

```sh
export GOPROXY=https://goproxy.cn
```

### 3.2 Golang 版本太低的问题
目前lotus的代码需要使用Golang 1.5以上进行编译。请按照上面第1步中的，安装最新的Golang版本进行编译。

### 3.3 crate.io 源的问题
如果编译源码的时候卡在`Updating crates.io index`，是因为无法加载crate.io源，可以更换为crate.io的国内镜像源。

`vi ~/.cargo/config`， 然后把下面中的任意一个添加进去，保存好，`source ~/.cargo/env`，然后再重新编译一次即可。

```sh
# rustcc社区
[source.crates-io]
replace-with = 'rustcc'
[source.rustcc]
registry = "git://crates.rustcc.cn/crates.io-index"

# 上海交通大学（正常使用）
[source.crates-io]
replace-with = 'sjtu'
[source.sjtu]
registry = "https://mirrors.sjtug.sjtu.edu.cn/git/crates.io-index"
```

### 3.4  Intel 机器编译`SIGILL: illegal instruction`
在Intel机器上编译lotus时候，会遇到如下类似的错误，提示`SIGILL: illegal instruction`：
```sh
SIGILL: illegal instruction
PC=0xe910af m=4 sigcode=2

goroutine 0 [idle]:
runtime: unknown pc 0xe910af
stack: frame={sp:0x7efc33ec4830, fp:0x0} stack=[0x7efc336c4ec8,0x7efc33ec4ac8)
00007efc33ec4730:  0000000003ed46a0  000000000063e394 <path/filepath.walkSymlinks+660> 
00007efc33ec4740:  0000000000000000  0000000000000000 
00007efc33ec4750:  0000000000000000  0000000000000000 
......
goroutine 1 [syscall]:
runtime.cgocall(0xe7a700, 0xc0009b77c8, 0x6cb501)
	/usr/lib/go-1.14/src/runtime/cgocall.go:133 +0x5b fp=0xc0009b7798 sp=0xc0009b7760 pc=0x51b75b
github.com/supranational/blst/bindings/go._Cfunc_blst_keygen(0xc000156320, 0xc0001562c0, 0x20, 0x0, 0x0)
	_cgo_gotypes.go:298 +0x45 fp=0xc0009b77c8 sp=0xc0009b7798 pc=0xe61505
github.com/supranational/blst/bindings/go.KeyGen(0xc0001562c0, 0x20, 0x20, 0x0, 0x0, 0x0, 0x6882897a)
	/home/ml/filecoin/official/lotus/extern/fil-blst/blst/bindings/go/blst.go:79 +0x96 fp=0xc0009b7808 sp=0xc0009b77c8 pc=0xe63596
github.com/filecoin-project/lotus/lib/sigs/bls.blsSigner.GenPrivate(0xc000542468, 0xc39cc8db33e69201, 0xc300000000000008, 0x0, 0xc000542460)
	/home/ml/filecoin/official/lotus/lib/sigs/bls/init.go:32 +0xeb fp=0xc0009b7868 sp=0xc0009b7808 pc=0xe6c98b
......
```
**解决方法：** 编译的时候加上参数 `CGO_CFLAGS="-D__BLST_PORTABLE__"`：

```sh
FFI_BUILD_FROM_SOURCE=1 CGO_CFLAGS="-D__BLST_PORTABLE__" make clean debug
```