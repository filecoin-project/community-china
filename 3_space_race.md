## [回目录](./README.md)

## 3. SpaceRace 专用【已废弃】

### 3.1 参数下载

使用 JDCloud 下载 32GB 的证明参数：

```
# v28 版本的参数
export IPFS_GATEWAY=https://proof-parameters.s3.cn-south-1.jdcloud-oss.com/ipfs/
./lotus fetch-params 32GiB
```

### 3.2 官方文档

- [SpaceRace 说明](https://docs.filecoin.io/mine/spacerace/#structure-and-rules)
- [SpaceRace 常见问题](https://docs.filecoin.io/mine/spacerace/#frequently-asked-questions)

### 3.3 自己创建矿工

如果水龙头无法创建矿工，可以取一些 FIL 币，那可以自己在本地创建矿工：

```sh
# (1) 生成钱包地址【已有的忽略】
./lotus wallet new bls
# (2) 去水龙头取一次 FIL 币【一次可以取得 100 FIL】
# (3) 本地创建矿工【请把 t3 开头的地址替换成你自己的钱包地址】
./lotus-miner init --owner t3u3fa4z6sxprcm47ufzfiayyg6jnpsulis2xaua5fpyifmuzap2kavw7pefvgu5j3jeb4mtfaqvppzcqwl6gb --sector-size 32GiB
```

注： 创建矿工一般不支持指定 actor 地址，既： t01000, t01001,t1002 等，也就是说，init 命令中的 `--actor t01xxx` 是不可用的。

## [回目录](./README.md)