## [回目录](./README.md)

## 9. 解决拉取代码冲突问题（git pull）

如果你在执行 `git pull` 的时候出现类似如下错误（`CONFLICT xxx`），你可以使用以下方法解决该问题：

```sh
warning: Cannot merge binary files: build/genesis/devnet.car (HEAD vs. 8bea0e02d77a6d36c3fc72746a9b38c7018608e9)
Auto-merging build/genesis/devnet.car
CONFLICT (add/add): Merge conflict in build/genesis/devnet.car
Auto-merging build/bootstrap/bootstrappers.pi
CONFLICT (content): Merge conflict in build/bootstrap/bootstrappers.pi
Automatic merge failed; fix conflicts and then commit the result.
```

上述示例来源于从 `interopnet` 分支的 `799f5e5` 版本执行 `git pull` 的时候出现的问题（2020年5月7日），而这个问题在新版的代码中经常会出现，解决这个问题的方法如下（只是其中一个方法，当然还有别的方法）：

### 9.1 方法一：
```sh
# 先重置代码，恢复代码到原始状态
git reset --hard HEAD
# 再随意的获取一个很久以前的代码版本号： commit ID
git log -111 | tail | grep -ni "commit "
# 假设这里拿到的一个 commit ID 是："8c0f2c1ce06"
# 然后恢复到这个版本
git reset --hard 8c0f2c1ce06
# 最后再重新拉取代码
git pull
# 这时候就完成代码更新了，并解决代码冲突问题
# 此时就可以重新编译代码了：
# 当然，在这之前，你可能需要设置一下 GOLANG 的代理
# 已经挂了代理的用户可忽略
env RUSTFLAGS="-C target-cpu=native -g" FFI_BUILD_FROM_SOURCE=1 make clean all bench
```

### 9.2 方法二：
```sh
# 先重置代码，恢复代码到原始状态
git reset --hard HEAD
# 切换到 master 分支或者其它分支也行
git checkout master
# 删除 interopnet 分支
git branch -D interopnet
# 拉取所有代码
git fetch
# 或者拉取 interopnet 分支的代码：
git fetch origin interopnet:interopnet
# 再切换到 interopnet 分支
git checkout interopnet
```

### 9.3 方法三：
```sh
# 如果你没有修改代码，直接执行以下两条命令
git fetch origin
git reset --hard origin/interopnet
```

## [回目录](./README.md)