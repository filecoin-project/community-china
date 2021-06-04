

# Neptune 中的 Poseidon 哈希 C 语言实现

## 1. 项目基础信息

本版本代码是基于 [Rust 语言版本 Neptune](https://github.com/filecoin-project/neptune) 和 [Rust 实现 ff](https://github.com/filecoin-project/ff) 改造而来的，所使用的的参数和 `lotus` 项目中的 `PC2` 算法完全一样。

本文中所使用的的常量数据是动态生成的，但是，对输入数据的长度有一些要求：输入数据以 `Fr` 元素为单位，每一个 `Fr` 的大小是 `32` 字节（`4` 个 `uint64_t` 数据），并且输入数据的长度（以 `Fr` 为单位）只能是 `2`、`4`、`8`、`16`、`24`、`36` 和 `11` 之一。 

本文所使用的开发环境是 `Visual Studion 2015 Enterprise`，并且是基于 `x64` 架构进行开发，若要编译此项目，请在 `Windows` 上使用 `VS2015` 或更高版本的 `VS` 打开本目录下的 `*.sln` 文件（若无法打开，则可以自己使用  `VS` 新建一个基于 `x64` 空项目，然后把这部分代码添加进去就可以编译运行）。

本文涉及一个叫做 `arity` 的概念，也就是 `树(tree)` 这种数据结构的度，通俗的讲就是说，二叉树的 `arity` 是 `2`、八叉树的 `arity` 是 `8`。

本项目中包含两种实现方式：`Naive` 版（本项目对应 `PoseidonHashV2Naive` 函数） 和 `StaticOptimized` 版本（本项目中对应 `PoseidonHashV2Ex` 函数），分别对应 `neptune` 项目中的 `hash_correct` 和 `hash_optimized_static` 的实现，前者比较简单，只需要两部分常量： `RoundConstant` 和 `mds` 矩阵，后者还需要更多的常量，主要是为了加速算法，把部分计算提前，具体内容请看代码。

**注：** 对于 `Fr` 的理解，就姑且认为它是 `Field Representation` 的缩写，其实就是一个大整数。

## 2. benchmark 测试

这里所说的 benchmark 测试只是为了测试代码的正确性，而不是测试代码的性能，目前的代码仅适用于学习，不适合实际适用，因为目前暂时还没有考虑性能问题。

本文目录下已经生成了几组测试数据，在本文同目录下的 `test_case_ref` 文件夹内，对于不同的 `arity` 的对应不同的测试文件，每个测试文件对应一种 `arity`，每个测试文件中包含了 1万个随机测试样例（使用 `neptune` 项目中的代码随机生成的测试样例），可以调用本项目中的 `main.c` 文件中的 `TestBenchPoseidon()` 函数进行测试。

## 3. 本项目用途

本项目仅适用于学习和理解 `lotus` 项目中的 `PC2` 算法的具体底层实现原理。


## 2. 其它

### 2.1 文章来源

本文来自于微信群 `Filecoin技术交流-1/2/3/4/5/6群` 群主（`TEARS`）出品，详细信息请查看 [【Filecoin 中国社区论坛】](https://github.com/filecoin-project/community-china/)。

如有任何问题，请在微信群 `Filecoin技术交流-1/2/3/4/5/6群` 中讨论。


