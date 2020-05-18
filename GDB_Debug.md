
# GDB 调试 lotus 源码教程

## 1. 环境配置

### (1). 下载源代码

这里所说的源代码不仅包括 lotus 的源代码： [lotus](https://github.com/filecoin-project/lotus)，还包括底层 rust 库实现的代码： [rust-fil-proofs](https://github.com/filecoin-project/rust-fil-proofs)，以及中间一层 封装接口调用的代码： [rust-filecoin-proofs-api](https://github.com/filecoin-project/rust-filecoin-proofs-api)，这里的三份代码的关系是这样的：`lotus` 调用 `rust-filecoin-proofs-api` 的 `api` 接口，而  `rust-filecoin-proofs-api` 是对底层 `rust-fil-proofs` 的一个简单封装,所以我们需要把这三个项目的代码都下载下来。

假设我们现在所在目录是 `~/git/`，然后在该目录中把所有代码都下载下来：

```sh
cd ~/git/
git clone https://github.com/filecoin-project/lotus.git
git clone https://github.com/filecoin-project/rust-fil-proofs.git
git clone https://github.com/filecoin-project/rust-filecoin-proofs-api.git
```

下载之后就可以看到这三个项目的代码了：

![三个项目的代码目录](./pictures/project.png)


### (2). 配置源代码

下载下来之后， `~/git/` 目录中就有这三个项目的代码，而 `lotus` 本身默认使用的底层库代码不是我们放在 `~/git/` 目录下的代码，为了让它使用我们 `~/git/` 目录下底层库代码（方便后续修改代码，然后重新编译），我们需要对这项目中的配置文件做一些修改（改它们的 **Cargo.toml** 配置文件）。

**注意：**
待修改配置文件的项目有两个：`lotus` 和  `rust-filecoin-proofs-api` ，而 `rust-fil-proofs` **无需做任何修改**。

#### A. 修改 lotus 中的配置文件

首先修改 `lotus` 目录中的 **Cargo.toml** 配置文件，让它直接使用本地的 `rust-filecoin-proofs-api` 代码，这个配置文件的路径在：`lotus/extern/filecoin-ffi/rust/` 目录下，但是由于第一次使用这份代码，这个目录还不存在，因此，可以先编译一遍这个 `lotus` 的源码，让它先生成这个对应的目录，以及其中的相关代码，编译命令如下（**FFI_BUILD_FROM_SOURCE=1** 这个环境变量是必须的）：

```sh
FFI_BUILD_FROM_SOURCE=1 make clean debug
```

这里只是预编译，就是为了获取 `lotus/extern/filecoin-ffi/` 目录下的源码就可以了，如下图所示（当然你也可以直接从已有的项目中拷贝对应的代码过来）：

![预编译下载对应代码](./pictures/precompile.png)

有了对应的代码，就可以修改对应的 **Cargo.toml** 文件了：

![待修改的配置文件](./pictures/change_lotus.png)

**修改前：**

![修改前](./pictures/before_change_lotus.png)

**修改后：**

![修改后](./pictures/after_change_lotus.png)

注意，上述修改中，原来用 **git** 关键字的，现在用的是 **path** 关键字，以及把下一行的 `branch="master"` 删除。


#### B. 修改 rust-filecoin-proofs-api 中的配置文件

`rust-filecoin-proofs-api` 中也需要修改对应的 **Cargo.toml** 文件，让它使用本地的 `rust-filecoin-proofs` 库中的代码：

![待修改的配置文件](./pictures/chang_api.png)

**修改前：**

![修改前](./pictures/before_change_api.png)

**修改后：**

![修改后](./pictures/after_change_api.png)

**这里要特别注意那个尾巴，是必须要加上去的，否则无法编译。**



## (2). 编译前的准备

