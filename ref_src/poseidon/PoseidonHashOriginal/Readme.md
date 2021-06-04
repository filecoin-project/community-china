

# 原始版 Poseidon 哈希的 C 语言实现

## 1. 项目基础信息

本版本代码是基于 [Rust 语言版本 Poseidon](https://github.com/arnaucube/poseidon-rs) 改造而来的，所使用的的参数和 `lotus` 项目中的 `PC2` 算法中有所不同（主要是所使用的素数和一些常量不一样）。

本文中所使用的的 `RoundConstant` 是提前生成好，并固定到代码中的，因此，对输入数据的长度有一些要求：输入数据以 `Fr` 元素为单位，每一个 `Fr` 的大小是 `32` 字节（`4` 个 `uint64_t` 数据），并且输入范围只能是在 `1` 到 `6` 个 `Fr` 之间。 

本文所使用的开发环境是 `Visual Studion 2015 Enterprise`，并且是基于 `x64` 架构进行开发，若要编译此项目，请在 `Windows` 上使用 `VS2015` 或更高版本的 `VS` 打开本目录下的 `*.sln` 文件（若无法打开，则可以自己使用  `VS` 新建一个基于 `x64` 空项目，然后把这部分代码添加进去就可以编译运行）。

**注：** 对于 `Fr` 的理解，就姑且认为它是 `Field Representation` 的缩写，其实就是一个大整数。


## 2. 本项目用途

本项目仅适用于学习和理解 `lotus` 项目中的 `PC2` 算法的具体底层实现原理。



## 2. 其它

### 2.1 文章来源

本文来自于微信群 `Filecoin技术交流-1/2/3/4/5/6群` 群主（`TEARS`）出品，详细信息请查看 [【Filecoin 中国社区论坛】](https://github.com/filecoin-project/community-china/)。

如有任何问题，请在微信群 `Filecoin技术交流-1/2/3/4/5/6群` 中讨论。


