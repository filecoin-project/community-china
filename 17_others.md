## [回目录](./README.md)

## 17 其它

### 17.1 币单位转换

$ 1 FIL = 10^{9} nanoFIL = 10^{18} attoFIL $

参考：[【go-humanize】](https://github.com/dustin/go-humanize/blob/master/si.go#L10)

### 17.2 钱包密钥导出与导入

```sh
# 查看钱包地址，一般是 t3 开头的一串数字（新版中使用的是 f3 开头）
./lotus wallet list
# 导出钱包的私钥到 mywallet.key 文件中（示例中的钱包地址为： t3w7r6dguggp62nbopehewt4amjh2iq2belz2u73q3k3z7zoarw44k6cra3og7yyvuy3f7gxh4omcmwpnuipaa）
# 你需要把这个钱包地址替换为你自己的钱包地址
wallet_addr="t3w7r6dguggp62nbopehewt4amjh2iq2belz2u73q3k3z7zoarw44k6cra3og7yyvuy3f7gxh4omcmwpnuipaa"
./lotus wallet export ${wallet_addr} > mywallet.key
# 导入钱包私钥
./lotus wallet import ./mywallet.key
# 导入之后，需要把该钱包地址设置为默认地址（当然，如果你有多个钱包地址，你可以自己选择）
./lotus wallet set-default ${wallet_addr}
```

### 17.3 APP

[安卓版本 APK](./app/Slack.7z)

[Windows 版本 EXE](./app/SlackSetup.7z)

### 17.4 参考文档
- [NewMai-CommonLinkForFilecoin](https://github.com/NewMai/CommonLinkForFilecoin)
- [Lotus Docs](https://docs.lotu.sh/)
- [Improving connectivity](https://docs.filecoin.io/mine/connectivity/)

## [回目录](./README.md)