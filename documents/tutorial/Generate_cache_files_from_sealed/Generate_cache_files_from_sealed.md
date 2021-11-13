# 本文翻译自https://github.com/filecoin-project/lotus/discussions/7314，如有问题，可查看原文，正文如下

# 从密封文件生成扇区缓存文件

## 声明

本教程介绍如何从密封的扇区文件中重新生成缓存文件，以防它们被删除或损坏。
这些文件对于wdPoST是必需的。

/!\ 如果您还丢失了位于同一文件夹中的“p_aux”文件。你不太可能让这个部门重新运转起来。

- 不需要任何特殊权限

- 可以在任何服务器上执行

- 100%CPU（无需GPU）

- 确保从Rustup.rs安装rustup

## 安装

```shell
git clone https://github.com/filecoin-project/rust-fil-proofs
cd rust-fil-proofs
cargo build --release --bin update_tree_r_cache
```

## 运行

1. 执行

```shell
./target/release/update_tree_r_cache  rebuild --cache <target_output_folder> --replica <sealed_sector_file> --size <size> # [default: 34359738368]
```

2. 将生成的缓存文件夹复制到正确的缓存文件夹

3. 重新启动矿工

4. 检查该扇区的截止日期以进行验证

```shell
lotus-miner proving check --slow  0
```

32GiB扇区miner示例

AMD EPYC 7282 16核处理器上的执行时间：8分钟

```shell
./rust fil-proof/target/release/update_-tree_r_-r_-cache rebuild--cache/tmp/cache/s-t010479-2733--replica sealed/s-t010479-2733
```

非常感谢PL的@dignifiedquire和@cryptonemo
