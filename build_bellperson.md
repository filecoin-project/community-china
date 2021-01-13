
# 编译本地的 Bellperson 库

## 1. 背景

由于需要对 bellperson 库的代码进行一些修改和定制，因此，需要把 bellperson 库拿出来放到本地指定的路径下，方便修改和编译。
以前由于没有解决依赖问题，修改 bellperson 的代码的时候都需要在 ~/.cargo/registry/src/mirrors.sjtug.sjtu.edu.cn-7a04d2510079875b/bellperson-0.9.2/ 这样的路径下修改，编译的时候也很不方便。

## 2. 环境配置

配置环境和 [【使用 GDB 调试 lotus 代码】](./gdb_debug.md) 这篇文章差不多，不过比那篇文章要多配置两个库，一个是 `neptune`， 另一个是 `neptune-triton`。

配置方法如下：
总共要修改 6 个库的内容：
- `lotus`
- `rust-filecoin-proofs-api`
- `rust-fil-proofs`
- `neptune`
- `neptune-triton`
- `bellperson`

### 2.0 下载代码

第一步就是下载代码，并把每个项目的代码版本切换到对应的版本：

```sh
cd ~/git/
cd ./lotus
git clone https://github.com/filecoin-project/lotus.git
git checkout v1.4.0
FFI_BUILD_FROM_SOURCE=1 make clean debug  # 预编译一轮

cd ~/git/
git clone https://github.com/filecoin-project/rust-fil-proofs.git
cd ./rust-fil-proofs
git checkout v5.4.1

cd ~/git/
git clone https://github.com/filecoin-project/rust-filecoin-proofs-api.git
cd ./rust-filecoin-proofs-api
git checkout filecoin-proofs-v5.4.0

cd ~/git/
git clone https://github.com/filecoin-project/neptune.git
cd ./neptune
git checkout v2.2.0

cd ~/git/
git clone https://github.com/filecoin-project/neptune-triton.git
cd ./neptune-triton
git checkout neptune-triton-v2.0.0

cd ~/git/
git clone https://github.com/filecoin-project/bellperson.git
cd ./bellperson
git checkout v0.12.1

```

### 2.1 修改 lotus 项目：

### 2.2 修改 rust-filecoin-proofs-api 项目：

### 2.3 修改 rust-fil-proofs 项目：

### 2.4 修改 neptune 项目：

### 2.5 修改 neptune-triton 项目：

### 2.6 修改 bellperson 项目：




