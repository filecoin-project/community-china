## [回目录](./README.md)

## 10. 重置本地测试网环境

如果你在使用本地测试网，发现 lotus daemon 启动不了，或者是 miner 启动不了，或者是其它的问题，这时候，如果你没有别的更好的解决方法，你可以尝试完全清理本地环境，然后再启动 daemon 和 miner， 默认情况下，你需要清理如下的文件或文件夹等：
```sh
# 如果 daemon 一直同步不了，也可以试试这个方法，很多情况下可以解决同步问题
# 此外，处理前请检查环境变量，比如，是否修改了默认的 ~/.lotus 目录的位置
rm -rf ~/.lotus/
rm -rf ~/.lotusminer/
rm -rf ~/.lotusworker/
rm -rf ~/.lotus-bench/
rm -rf ~/.genesis-sectors/
rm -rf ~/dev.gen
rm -rf ~/localnet.json
```

如果是同步不了，还建议清空 `FIL_PROOFS_MAXIMIZE_CACHING` 环境变量，最近不少人因为在 `.bashrc` 中加入这个环境变量导致无法同步，原因未知：

```sh
unset FIL_PROOFS_MAXIMIZE_CACHING
```

## [回目录](./README.md)