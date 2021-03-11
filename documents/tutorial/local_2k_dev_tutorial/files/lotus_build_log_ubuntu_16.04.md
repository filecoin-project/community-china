

```sh

ml@ml:~$ go version
go version go1.15.5 linux/amd64
ml@ml:~$ 
ml@ml:~$ rustc --version
rustc 1.50.0 (cb75ad5db 2021-02-10)
ml@ml:~$ 
ml@ml:~$ cargo --version
cargo 1.50.0 (f04e7fab7 2021-02-04)
ml@ml:~$ 
ml@ml:~$ 
ml@ml:~$ cd git/
ml@ml:~/git$ 
ml@ml:~/git$ cd lotus
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ git status 
On branch master
Your branch is up-to-date with 'origin/master'.
nothing to commit, working directory clean
ml@ml:~/git/lotus$ git status 
On branch master
Your branch is up-to-date with 'origin/master'.
nothing to commit, working directory clean
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ git pull  --all 
Fetching origin
Already up-to-date.
ml@ml:~/git/lotus$ git checkout v1.
v1.0.0        v1.1.1        v1.1.3        v1.1.3-rc1    v1.2.2        v1.2.3-rc1    v1.4.0        v1.4.2        v1.5.0-pre1   v1.5.0-rc1    
v1.1.0        v1.1.1-pre1   v1.1.3-pre1   v1.2.0        v1.2.2-rc1    v1.3.0        v1.4.1        v1.4.2-rc1    v1.5.0-pre2   v1.5.0-rc2    
v1.1.0-pre1   v1.1.2        v1.1.3-pre2   v1.2.1        v1.2.3        v1.3.0-rc1    v1.4.1-pre1   v1.5.0        v1.5.0-pre3   
ml@ml:~/git/lotus$ git checkout v1.4.1
Note: checking out 'v1.4.1'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by performing another checkout.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -b with the checkout command again. Example:

  git checkout -b <new-branch-name>

HEAD is now at ebaa721... Merge pull request #5390 from filecoin-project/asr/changelog
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ git branch 
* (HEAD detached at v1.4.1)
  master
  testnet/3
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ ls
api    CHANGELOG.md  conformance    gen      go.sum   LICENSE-APACHE  Makefile  miner     README.md    storage    tools
build  cli           documentation  genesis  journal  LICENSE-MIT     markets   node      scripts      system
chain  cmd           extern         go.mod   lib      lotuspond       metrics   paychmgr  SECURITY.md  testplans
ml@ml:~/git/lotus$ git branch 
* (HEAD detached at v1.4.1)
  master
  testnet/3
ml@ml:~/git/lotus$ git status 
HEAD detached at v1.4.1
nothing to commit, working directory clean
ml@ml:~/git/lotus$ git reset --hard HEAD
HEAD is now at ebaa721 Merge pull request #5390 from filecoin-project/asr/changelog
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ FFI_BUILD_FROM_SOURCE=1  make clean debug
rm -rf  build/.filecoin-install build/.update-modules  lotus lotus-miner lotus-worker lotus-shed lotus-gateway lotus-seed lotus-pond lotus-townhall lotus-fountain lotus-chainwatch lotus-bench lotus-stats lotus-pcr lotus-health lotus-wallet lotus-keygen testground
make -C extern/filecoin-ffi/ clean
make[1]: Entering directory '/home/ml/git/lotus/extern/filecoin-ffi'
make[1]: *** No rule to make target 'clean'.  Stop.
make[1]: Leaving directory '/home/ml/git/lotus/extern/filecoin-ffi'
Makefile:297: recipe for target 'clean' failed
make: [clean] Error 2 (ignored)
git submodule update --init --recursive
Submodule 'extern/blst' (https://github.com/supranational/blst.git) registered for path 'extern/blst'
Submodule 'extern/test-vectors' (https://github.com/filecoin-project/test-vectors.git) registered for path 'extern/test-vectors'
Cloning into 'extern/blst'...
remote: Enumerating objects: 26, done.
remote: Counting objects: 100% (26/26), done.
remote: Compressing objects: 100% (18/18), done.
remote: Total 2512 (delta 11), reused 18 (delta 8), pack-reused 2486
Receiving objects: 100% (2512/2512), 926.94 KiB | 320.00 KiB/s, done.
Resolving deltas: 100% (1740/1740), done.
Checking connectivity... done.
Submodule path 'extern/blst': checked out '1cbb16ed9580dcd3e9593b71221fcf2a048faaef'
remote: Enumerating objects: 409, done.
remote: Counting objects: 100% (409/409), done.
remote: Compressing objects: 100% (11/11), done.
remote: Total 1062 (delta 398), reused 405 (delta 398), pack-reused 653
Receiving objects: 100% (1062/1062), 454.88 KiB | 216.00 KiB/s, done.
Resolving deltas: 100% (715/715), completed with 54 local objects.
From https://github.com/filecoin-project/filecoin-ffi
 * [new branch]      expose-dpost-old -> origin/expose-dpost-old
 * [new branch]      faulty-sectors-error -> origin/faulty-sectors-error
 * [new branch]      feat-aggregation -> origin/feat-aggregation
 * [new branch]      feat/upd-x-for-go -> origin/feat/upd-x-for-go
 * [new branch]      fix-blst-sigs-zero -> origin/fix-blst-sigs-zero
 * [new branch]      fix-empty-message-verify -> origin/fix-empty-message-verify
 * [new branch]      fix-locking -> origin/fix-locking
 * [new branch]      improve-unseal-ram -> origin/improve-unseal-ram
   eada00e..b6e0b35  master     -> origin/master
 * [new branch]      proofs-upgrade -> origin/proofs-upgrade
 * [new branch]      proofs-upgrade-seal -> origin/proofs-upgrade-seal
 * [new branch]      release/v0.29.0 -> origin/release/v0.29.0
 * [new branch]      release/v0.30.0 -> origin/release/v0.30.0
 * [new branch]      release/v0.30.1 -> origin/release/v0.30.1
 * [new branch]      release/v0.30.3 -> origin/release/v0.30.3
 + 96bcead...74c5df8 update-deps -> origin/update-deps  (forced update)
 * [new branch]      upgrade-bellman -> origin/upgrade-bellman
 * [new branch]      upgrade-ffi -> origin/upgrade-ffi
 * [new tag]         30daa3597a975a79 -> 30daa3597a975a79
 * [new tag]         32d4e459189706e8 -> 32d4e459189706e8
 * [new tag]         6a143e06f923f3a4 -> 6a143e06f923f3a4
 * [new tag]         aaba7295c50aae83 -> aaba7295c50aae83
 * [new tag]         b6e0b35fb49ed0fe -> b6e0b35fb49ed0fe
 * [new tag]         v0.29.0    -> v0.29.0
 * [new tag]         v0.30.0    -> v0.30.0
 * [new tag]         v0.30.1    -> v0.30.1
 * [new tag]         v0.30.3    -> v0.30.3
 * [new tag]         002bbdb58f25f978 -> 002bbdb58f25f978
 * [new tag]         0226d0be6f0ec441 -> 0226d0be6f0ec441
 * [new tag]         0c50dfbaa64c6187 -> 0c50dfbaa64c6187
 * [new tag]         1178e09a57aec2c9 -> 1178e09a57aec2c9
 * [new tag]         1985275547f222e8 -> 1985275547f222e8
 * [new tag]         1d9cb3e8ff53f51f -> 1d9cb3e8ff53f51f
 * [new tag]         2079f20ee59c7eea -> 2079f20ee59c7eea
 * [new tag]         24e6a49c121d893a -> 24e6a49c121d893a
 * [new tag]         360fddf0127b0835 -> 360fddf0127b0835
 * [new tag]         40569104603407c9 -> 40569104603407c9
 * [new tag]         4bec256c4bd4b56d -> 4bec256c4bd4b56d
 * [new tag]         5342c7c97d1a1df4 -> 5342c7c97d1a1df4
 * [new tag]         57e38efe4943f09d -> 57e38efe4943f09d
 * [new tag]         5bb4a309bce9d446 -> 5bb4a309bce9d446
 * [new tag]         61c02f6bea8d69bb -> 61c02f6bea8d69bb
 * [new tag]         62f89f108a6a8fe9 -> 62f89f108a6a8fe9
 * [new tag]         66cf4d07e03bdee4 -> 66cf4d07e03bdee4
 * [new tag]         681b07563208117f -> 681b07563208117f
 * [new tag]         735a55d15f356b33 -> 735a55d15f356b33
 * [new tag]         777a6fbf4446b111 -> 777a6fbf4446b111
 * [new tag]         821e2b25daca14c9 -> 821e2b25daca14c9
 * [new tag]         828a124ce84755e6 -> 828a124ce84755e6
 * [new tag]         951d66ae93f6f4d3 -> 951d66ae93f6f4d3
 * [new tag]         a62d00da59d1b0fb -> a62d00da59d1b0fb
 * [new tag]         af37d8d5a6c4dc1f -> af37d8d5a6c4dc1f
 * [new tag]         b1990cfbe3970e09 -> b1990cfbe3970e09
 * [new tag]         ca281af0b6c00314 -> ca281af0b6c00314
 * [new tag]         cddc56607e1d851e -> cddc56607e1d851e
 * [new tag]         d1686755fe5fdc9e -> d1686755fe5fdc9e
 * [new tag]         d70d49a742cde20b -> d70d49a742cde20b
 * [new tag]         e0f1cde8a8e9cf3c -> e0f1cde8a8e9cf3c
 * [new tag]         ee9d3b718fbba569 -> ee9d3b718fbba569
 * [new tag]         f38ec093ca1f3a1e -> f38ec093ca1f3a1e
 * [new tag]         f5f0f80bd87e742c -> f5f0f80bd87e742c
 * [new tag]         f640612a1a1f7a2d -> f640612a1a1f7a2d
 * [new tag]         v0.30.2    -> v0.30.2
Submodule path 'extern/filecoin-ffi': checked out '1d9cb3e8ff53f51f9318fc57e5d00bc79bdc0128'
remote: Enumerating objects: 10, done.
remote: Counting objects: 100% (10/10), done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 6 (delta 0), reused 5 (delta 0), pack-reused 0
Unpacking objects: 100% (6/6), done.
From https://github.com/filecoin-project/serialization-vectors
   3f46243..5bfb928  master     -> origin/master
Submodule path 'extern/serialization-vectors': checked out '5bfb928910b01ac8b940a693af2884f7f8276211'
Cloning into 'extern/test-vectors'...
remote: Enumerating objects: 291, done.
remote: Counting objects: 100% (291/291), done.
remote: Compressing objects: 100% (184/184), done.
remote: Total 4004 (delta 108), reused 243 (delta 107), pack-reused 3713
Receiving objects: 100% (4004/4004), 34.82 MiB | 687.00 KiB/s, done.
Resolving deltas: 100% (1855/1855), done.
Checking connectivity... done.
Submodule path 'extern/test-vectors': checked out 'd9a75a7873aee0db28b87e3970d2ea16a2f37c6a'
Submodule 'gen/extern/fil-blst' (https://github.com/filecoin-project/fil-blst.git) registered for path 'gen/extern/fil-blst'
Submodule 'gen/extern/filecoin-ffi' (https://github.com/filecoin-project/filecoin-ffi.git) registered for path 'gen/extern/filecoin-ffi'
Cloning into 'gen/extern/fil-blst'...
remote: Enumerating objects: 349, done.
remote: Counting objects: 100% (349/349), done.
remote: Compressing objects: 100% (224/224), done.
remote: Total 349 (delta 140), reused 309 (delta 112), pack-reused 0
Receiving objects: 100% (349/349), 3.02 MiB | 1.28 MiB/s, done.
Resolving deltas: 100% (140/140), done.
Checking connectivity... done.
Submodule path 'extern/test-vectors/gen/extern/fil-blst': checked out '5f93488fc0dbfb450f2355269f18fc67010d59bb'
Cloning into 'gen/extern/filecoin-ffi'...
remote: Enumerating objects: 20, done.
remote: Counting objects: 100% (20/20), done.
remote: Compressing objects: 100% (15/15), done.
remote: Total 3094 (delta 5), reused 12 (delta 5), pack-reused 3074
Receiving objects: 100% (3094/3094), 1.16 MiB | 389.00 KiB/s, done.
Resolving deltas: 100% (1916/1916), done.
Checking connectivity... done.
Submodule path 'extern/test-vectors/gen/extern/filecoin-ffi': checked out 'f640612a1a1f7a2dd8b3a49e1531db0aa0f63447'
touch build/.update-modules
make -C extern/filecoin-ffi/ .install-filcrypto
make[1]: Entering directory '/home/ml/git/lotus/extern/filecoin-ffi'
./install-filcrypto
+ auth_header=()
+ '[' -n '' ']'
++ dirname ./install-filcrypto
+ cd .
+ rust_sources_dir=rust
++ jq -r '.[].check_cpu_for_feature | select(. != null)'
+ cpu_features_required_for_optimized_release='adx
sha_ni
sha2
sse2
avx2
avx
sse4_2
sse4_1'
+ main
++ get_release_flags
++ local __features=
++ [[ ! -f /proc/cpuinfo ]]
+++ uname -a
+++ grep x86_64
++ x86_64_uname='Linux ml 4.10.0-28-generic #32~16.04.2-Ubuntu SMP Thu Jul 20 10:19:48 UTC 2017 x86_64 x86_64 x86_64 GNU/Linux'
++ '[' -n 'Linux ml 4.10.0-28-generic #32~16.04.2-Ubuntu SMP Thu Jul 20 10:19:48 UTC 2017 x86_64 x86_64 x86_64 GNU/Linux' ']'
+++ cat /proc/cpuinfo
+++ grep flags
+++ head -n 1
++ __features='flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
++ feature_map=("adx:+adx" "sha_ni:+sha" "sha2:+sha2" "sse2:+sse2" "avx2:+avx2" "avx:+avx" "sse4_2:+sse4.2" "sse4_1:+sse4.1")
++ target_features=
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c adx
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c sha_ni
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c sha2
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c sse2
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=adx
++ '[' adx == sse2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha_ni
++ '[' sha_ni == sse2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha2
++ '[' sha2 == sse2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse2
++ '[' sse2 == sse2 ']'
++ val=+sse2
++ '[' -z '' ']'
++ target_features=+sse2
++ for feature in '"${feature_map[@]}"'
++ key=avx2
++ '[' avx2 == sse2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx
++ '[' avx == sse2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_2
++ '[' sse4_2 == sse2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_1
++ '[' sse4_1 == sse2 ']'
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c avx2
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=adx
++ '[' adx == avx2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha_ni
++ '[' sha_ni == avx2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha2
++ '[' sha2 == avx2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse2
++ '[' sse2 == avx2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx2
++ '[' avx2 == avx2 ']'
++ val=+avx2
++ '[' -z +sse2 ']'
++ target_features=+sse2,+avx2
++ for feature in '"${feature_map[@]}"'
++ key=avx
++ '[' avx == avx2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_2
++ '[' sse4_2 == avx2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_1
++ '[' sse4_1 == avx2 ']'
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c avx
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=adx
++ '[' adx == avx ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha_ni
++ '[' sha_ni == avx ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha2
++ '[' sha2 == avx ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse2
++ '[' sse2 == avx ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx2
++ '[' avx2 == avx ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx
++ '[' avx == avx ']'
++ val=+avx
++ '[' -z +sse2,+avx2 ']'
++ target_features=+sse2,+avx2,+avx
++ for feature in '"${feature_map[@]}"'
++ key=sse4_2
++ '[' sse4_2 == avx ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_1
++ '[' sse4_1 == avx ']'
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c sse4_2
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=adx
++ '[' adx == sse4_2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha_ni
++ '[' sha_ni == sse4_2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha2
++ '[' sha2 == sse4_2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse2
++ '[' sse2 == sse4_2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx2
++ '[' avx2 == sse4_2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx
++ '[' avx == sse4_2 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_2
++ '[' sse4_2 == sse4_2 ']'
++ val=+sse4.2
++ '[' -z +sse2,+avx2,+avx ']'
++ target_features=+sse2,+avx2,+avx,+sse4.2
++ for feature in '"${feature_map[@]}"'
++ key=sse4_1
++ '[' sse4_1 == sse4_2 ']'
++ for x in '${cpu_features_required_for_optimized_release[@]}'
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch fsgsbase avx2 invpcid rdseed clflushopt'
+++ grep -c sse4_1
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=adx
++ '[' adx == sse4_1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha_ni
++ '[' sha_ni == sse4_1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sha2
++ '[' sha2 == sse4_1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse2
++ '[' sse2 == sse4_1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx2
++ '[' avx2 == sse4_1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=avx
++ '[' avx == sse4_1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_2
++ '[' sse4_2 == sse4_1 ']'
++ for feature in '"${feature_map[@]}"'
++ key=sse4_1
++ '[' sse4_1 == sse4_1 ']'
++ val=+sse4.1
++ '[' -z +sse2,+avx2,+avx,+sse4.2 ']'
++ target_features=+sse2,+avx2,+avx,+sse4.2,+sse4.1
++ echo +sse2,+avx2,+avx,+sse4.2,+sse4.1
+ local __release_flags=+sse2,+avx2,+avx,+sse4.2,+sse4.1
+ '[' 1 '!=' 1 ']'
+ echo '[install-filcrypto/main] building libfilcrypto from local sources (dir = rust)'
[install-filcrypto/main] building libfilcrypto from local sources (dir = rust)
+ build_from_source filcrypto rust +sse2,+avx2,+avx,+sse4.2,+sse4.1
+ local __library_name=filcrypto
+ local __rust_sources_path=rust
+ local __release_flags=+sse2,+avx2,+avx,+sse4.2,+sse4.1
++ git rev-parse HEAD
+ local __repo_sha1=1d9cb3e8ff53f51f9318fc57e5d00bc79bdc0128
+ local __repo_sha1_truncated=1d9cb3e8ff53f51f
+ echo 'building from source @ 1d9cb3e8ff53f51f'
building from source @ 1d9cb3e8ff53f51f
++ command -v cargo
+ '[' -x /home/ml/.cargo/bin/cargo ']'
++ command -v rustup
+ '[' -x /home/ml/.cargo/bin/rustup ']'
+ pushd rust
~/git/lotus/extern/filecoin-ffi/rust ~/git/lotus/extern/filecoin-ffi
+ cargo --version
info: syncing channel updates for 'nightly-2020-10-05-x86_64-unknown-linux-gnu'
info: latest update on 2020-10-05, rust version 1.49.0-nightly (beb5ae474 2020-10-04)
info: downloading component 'cargo'
info: downloading component 'clippy'
info: downloading component 'rust-docs'
info: downloading component 'rust-std'
info: downloading component 'rustc'
info: downloading component 'rustfmt'
info: installing component 'cargo'
info: using up to 500.0 MiB of RAM to unpack components
info: installing component 'clippy'
info: installing component 'rust-docs'
info: installing component 'rust-std'
info: installing component 'rustc'
info: installing component 'rustfmt'
cargo 1.48.0-nightly (75615f8e6 2020-09-29)
+ '[' '' == 1 ']'
+ additional_flags='--no-default-features --features pairing'
+ '[' -n +sse2,+avx2,+avx,+sse4.2,+sse4.1 ']'
++ cat rust-toolchain
+ RUSTFLAGS='-C target-feature=+sse2,+avx2,+avx,+sse4.2,+sse4.1'
+ ./scripts/build-release.sh filcrypto 'nightly-2020-10-05 ' '--no-default-features --features pairing'
+ main filcrypto 'nightly-2020-10-05 ' '--no-default-features --features pairing'
+ [[ -z filcrypto ]]
+ [[ -z nightly-2020-10-05  ]]
++ mktemp
+ __build_output_log_tmp=/tmp/tmp.WQCqjDa053
+ trap '{ rm -f $__build_output_log_tmp; }' EXIT
+ local '__rust_flags=--print native-static-libs -C target-feature=+sse2,+avx2,+avx,+sse4.2,+sse4.1'
+ RUSTFLAGS='--print native-static-libs -C target-feature=+sse2,+avx2,+avx,+sse4.2,+sse4.1'
+ cargo +nightly-2020-10-05 build --release --no-default-features --features pairing
+ tee /tmp/tmp.WQCqjDa053
    Updating crates.io index
 Downloading crates ...
  Downloaded adler v0.2.3
  Downloaded subtle v1.0.0
  Downloaded terminal_size v0.1.13
  Downloaded tinyvec v0.3.4
  Downloaded tar v0.4.30
  Downloaded itoa v0.4.6
  Downloaded tracing v0.1.21
  Downloaded synstructure v0.12.4
  Downloaded time v0.1.44
  Downloaded unicode-segmentation v1.6.0
  Downloaded thiserror v1.0.22
  Downloaded tokio-tls v0.3.1
  Downloaded try-lock v0.2.3
  Downloaded thread_local v1.0.1
  Downloaded aes-soft v0.6.3
  Downloaded thiserror-impl v1.0.22
  Downloaded byteorder v0.5.3
  Downloaded byteorder v1.3.4
  Downloaded structopt v0.3.20
  Downloaded unicode-xid v0.2.1
  Downloaded unicode-width v0.1.8
  Downloaded tower-service v0.3.0
  Downloaded cbindgen v0.14.0
  Downloaded remove_dir_all v0.5.3
  Downloaded filetime v0.2.13
  Downloaded const_fn v0.4.3
  Downloaded cipher v0.2.5
  Downloaded quote v1.0.7
  Downloaded unicase v2.6.0
  Downloaded aes v0.6.0
  Downloaded unicode-bidi v0.3.4
  Downloaded syn v1.0.48
  Downloaded url v2.2.0
  Downloaded spin v0.5.2
  Downloaded scopeguard v1.1.0
  Downloaded arrayvec v0.5.2
  Downloaded static_assertions v1.1.0
  Downloaded vec_map v0.8.2
  Downloaded version_check v0.9.2
  Downloaded yansi v0.5.0
  Downloaded zeroize v0.9.3
  Downloaded unicode-normalization v0.1.13
  Downloaded phase21 v0.11.0
  Downloaded arrayref v0.3.6
  Downloaded bitflags v1.2.1
  Downloaded xattr v0.2.2
  Downloaded anyhow v1.0.34
  Downloaded blake2b_simd v0.5.11
  Downloaded blake2s_simd v0.5.11
  Downloaded ahash v0.5.8
  Downloaded block-modes v0.7.0
  Downloaded proc-macro-error-attr v1.0.4
  Downloaded block-padding v0.1.5
  Downloaded byte-slice-cast v1.0.0
  Downloaded bytes v0.5.6
  Downloaded block-buffer v0.9.0
  Downloaded crossbeam-epoch v0.8.2
  Downloaded backtrace v0.3.54
  Downloaded crossbeam-queue v0.2.3
  Downloaded block-buffer v0.7.3
  Downloaded crypto-mac v0.10.0
  Downloaded crossbeam-deque v0.8.0
  Downloaded dirs v2.0.2
  Downloaded digest v0.9.0
  Downloaded bit-vec v0.6.2
  Downloaded digest v0.8.1
  Downloaded either v1.6.1
  Downloaded crossbeam-queue v0.3.0
  Downloaded dialoguer v0.7.1
  Downloaded drop_struct_macro_derive v0.4.0
  Downloaded crossbeam-epoch v0.9.0
  Downloaded ffi-toolkit v0.4.0
  Downloaded crossbeam-utils v0.8.0
  Downloaded futures-core v0.3.7
  Downloaded futures-io v0.3.7
  Downloaded dtoa v0.4.6
  Downloaded futures-sink v0.3.7
  Downloaded futures-task v0.3.7
  Downloaded fil-ocl-core v0.11.3
  Downloaded foreign-types v0.3.2
  Downloaded filecoin-proofs-api v5.4.1
  Downloaded dirs-sys v0.3.5
  Downloaded itertools v0.9.0
  Downloaded getrandom v0.1.15
  Downloaded hkdf v0.8.0
  Downloaded base64 v0.12.3
  Downloaded futures-util v0.3.7
  Downloaded fil-ocl v0.19.4
  Downloaded lazy_static v1.4.0
  Downloaded matches v0.1.8
  Downloaded http-body v0.3.1
  Downloaded getrandom v0.2.0
  Downloaded cfg-if v1.0.0
  Downloaded ansi_term v0.11.0
  Downloaded autocfg v1.0.1
  Downloaded atty v0.2.14
  Downloaded pbr v1.0.3
  Downloaded structopt-derive v0.4.13
  Downloaded futures v0.1.30
  Downloaded generic-array v0.12.3
  Downloaded generic-array v0.14.4
  Downloaded openssl-sys v0.9.58
  Downloaded cfg-if v0.1.10
  Downloaded fs2 v0.4.3
  Downloaded aho-corasick v0.7.15
  Downloaded hashbrown v0.9.1
  Downloaded hmac v0.10.1
  Downloaded hex v0.4.2
  Downloaded want v0.3.0
  Downloaded block-padding v0.2.1
  Downloaded reqwest v0.10.8
  Downloaded bitvec v0.17.4
  Downloaded crossbeam-utils v0.7.2
  Downloaded fnv v1.0.7
  Downloaded flate2 v1.0.19
  Downloaded httpdate v0.3.2
  Downloaded glob v0.3.0
  Downloaded idna v0.2.0
  Downloaded hyper-tls v0.4.3
  Downloaded hwloc v0.3.0
  Downloaded indicatif v0.15.0
  Downloaded ipnet v2.3.0
  Downloaded cc v1.0.62
  Downloaded http v0.2.1
  Downloaded cpuid-bool v0.1.2
  Downloaded addr2line v0.14.0
  Downloaded maybe-uninit v2.0.0
  Downloaded memmap v0.7.0
  Downloaded memchr v2.3.4
  Downloaded memoffset v0.5.6
  Downloaded merkletree v0.21.0
  Downloaded mime v0.3.16
  Downloaded mapr v0.8.0
  Downloaded chrono v0.4.19
  Downloaded mime_guess v2.0.3
  Downloaded miniz_oxide v0.4.3
  Downloaded nom v5.1.2
  Downloaded num-bigint v0.1.44
  Downloaded clap v2.33.3
  Downloaded num-integer v0.1.44
  Downloaded net2 v0.2.35
  Downloaded rustc-serialize v0.3.24
  Downloaded byte-tools v0.3.1
  Downloaded num-traits v0.2.14
  Downloaded number_prefix v0.3.0
  Downloaded num_cpus v1.13.0
  Downloaded opaque-debug v0.3.0
  Downloaded num-traits v0.1.43
  Downloaded openssl-probe v0.1.2
  Downloaded crypto-mac v0.7.0
  Downloaded opaque-debug v0.2.3
  Downloaded num-bigint v0.2.6
  Downloaded pin-project-internal v0.4.27
  Downloaded pin-project-lite v0.1.11
  Downloaded filecoin-proofs v5.4.0
  Downloaded percent-encoding v2.1.0
  Downloaded mio v0.6.22
  Downloaded hmac v0.7.1
  Downloaded native-tls v0.2.5
  Downloaded pin-project v1.0.1
  Downloaded openssl v0.10.30
  Downloaded rustc_version v0.1.7
  Downloaded crossbeam v0.8.0
  Downloaded crossbeam-deque v0.7.3
  Downloaded difference v2.0.0
  Downloaded constant_time_eq v0.1.5
  Downloaded config v0.10.1
  Downloaded console v0.13.0
  Downloaded log v0.4.11
  Downloaded crossbeam v0.7.3
  Downloaded termcolor v1.1.0
  Downloaded indexmap v1.6.0
  Downloaded rayon-core v1.9.0
  Downloaded toml v0.5.7
  Downloaded cl-sys v0.4.2
  Downloaded rustc-demangle v0.1.18
  Downloaded bitintr v0.3.0
  Downloaded rustc_version v0.2.3
  Downloaded ryu v1.0.5
  Downloaded crc32fast v1.2.1
  Downloaded foreign-types-shared v0.1.1
  Downloaded nodrop v0.1.14
  Downloaded enum_primitive v0.1.1
  Downloaded num-rational v0.1.42
  Downloaded sha2ni v0.8.5
  Downloaded crossbeam-channel v0.4.4
  Downloaded regex v1.4.2
  Downloaded libc v0.2.80
  Downloaded num-iter v0.1.42
  Downloaded typenum v1.12.0
  Downloaded httparse v1.3.4
  Downloaded bls-signatures v0.6.1
  Downloaded subtle v2.3.0
  Downloaded crossbeam-channel v0.5.0
  Downloaded syn v0.15.44
  Downloaded regex-syntax v0.6.21
  Downloaded gimli v0.23.0
  Downloaded tokio-util v0.3.1
  Downloaded tracing-core v0.1.17
  Downloaded tokio v0.2.22
  Downloaded pkg-config v0.3.19
  Downloaded paired v0.20.1
  Downloaded tracing-futures v0.2.4
  Downloaded rand v0.7.3
  Downloaded rust-gpu-tools v0.2.1
  Downloaded bellperson v0.12.1
  Downloaded rayon v1.5.0
  Downloaded neptune v2.2.0
  Downloaded unicode-xid v0.1.0
  Downloaded paired v0.21.0
  Downloaded flexi_logger v0.14.8
  Downloaded heck v0.3.1
  Downloaded pin-utils v0.1.0
  Downloaded proc-macro-error v1.0.4
  Downloaded proc-macro2 v0.4.30
  Downloaded pin-project-internal v1.0.1
  Downloaded encoding_rs v0.8.26
  Downloaded simplelog v0.8.0
  Downloaded once_cell v1.4.1
  Downloaded env_proxy v0.4.1
  Downloaded pin-project v0.4.27
  Downloaded positioned-io v0.2.2
  Downloaded radium v0.3.0
  Downloaded semver v0.1.20
  Downloaded fake-simd v0.1.2
  Downloaded fil_logger v0.1.2
  Downloaded groupy v0.3.1
  Downloaded futures-channel v0.3.7
  Downloaded sha2 v0.9.2
  Downloaded h2 v0.2.7
  Downloaded neptune-triton v2.0.0
  Downloaded serde_urlencoded v0.6.1
  Downloaded semver v0.9.0
  Downloaded bincode v1.3.1
  Downloaded bitflags v0.4.0
  Downloaded ppv-lite86 v0.2.10
  Downloaded pretty_assertions v0.6.1
  Downloaded iovec v0.1.4
  Downloaded failure v0.1.8
  Downloaded hkdf v0.10.0
  Downloaded serde v1.0.117
  Downloaded quote v0.6.13
  Downloaded ff-cl-gen v0.2.0
  Downloaded itertools v0.8.2
  Downloaded socket2 v0.3.15
  Downloaded serde_json v1.0.59
  Downloaded rand_xorshift v0.2.0
  Downloaded num-complex v0.1.43
  Downloaded form_urlencoded v1.0.0
  Downloaded storage-proofs-porep v5.4.0
  Downloaded sha2 v0.8.2
  Downloaded sha2-asm v0.5.4
  Downloaded rand_chacha v0.2.2
  Downloaded strsim v0.8.0
  Downloaded sha2raw v2.0.0
  Downloaded errno v0.1.8
  Downloaded raw-cpuid v7.0.3
  Downloaded fff_derive v0.2.2
  Downloaded proc-macro2 v1.0.24
  Downloaded tempdir v0.3.7
  Downloaded num v0.1.42
  Downloaded failure_derive v0.1.8
  Downloaded semver-parser v0.7.0
  Downloaded storage-proofs v5.4.0
  Downloaded openssl-src v111.12.0+1.1.1h
  Downloaded qutex v0.2.3
  Downloaded fff v0.2.3
  Downloaded object v0.22.0
  Downloaded humansize v1.1.0
  Downloaded serde_derive v1.0.117
  Downloaded slab v0.4.2
  Downloaded ocl-core-vector v0.1.0
  Downloaded rand_core v0.5.1
  Downloaded storage-proofs-core v5.4.0
  Downloaded hyper v0.13.9
  Downloaded rand v0.4.6
  Downloaded storage-proofs-post v5.4.0
  Downloaded lexical-core v0.7.4
  Downloaded textwrap v0.11.0
  Downloaded tempfile v3.1.0
   Compiling autocfg v1.0.1
   Compiling libc v0.2.80
   Compiling cfg-if v0.1.10
   Compiling spin v0.5.2
   Compiling proc-macro2 v1.0.24
   Compiling unicode-xid v0.2.1
   Compiling syn v1.0.48
   Compiling version_check v0.9.2
   Compiling cc v1.0.62
   Compiling typenum v1.12.0
   Compiling bitflags v1.2.1
   Compiling getrandom v0.1.15
   Compiling log v0.4.11
   Compiling cfg-if v1.0.0
   Compiling serde_derive v1.0.117
   Compiling serde v1.0.117
   Compiling memchr v2.3.4
   Compiling byteorder v1.3.4
   Compiling scopeguard v1.1.0
   Compiling const_fn v0.4.3
   Compiling maybe-uninit v2.0.0
   Compiling ppv-lite86 v0.2.10
   Compiling ryu v1.0.5
   Compiling rustc-serialize v0.3.24
   Compiling arrayvec v0.5.2
   Compiling pkg-config v0.3.19
   Compiling either v1.6.1
   Compiling adler v0.2.3
   Compiling byte-tools v0.3.1
   Compiling gimli v0.23.0
   Compiling semver v0.1.20
   Compiling failure_derive v0.1.8
   Compiling rayon-core v1.9.0
   Compiling arrayref v0.3.6
   Compiling constant_time_eq v0.1.5
   Compiling itoa v0.4.6
   Compiling object v0.22.0
   Compiling fake-simd v0.1.2
   Compiling rustc-demangle v0.1.18
   Compiling cl-sys v0.4.2
   Compiling opaque-debug v0.2.3
   Compiling subtle v2.3.0
   Compiling serde_json v1.0.59
   Compiling futures v0.1.30
   Compiling getrandom v0.2.0
   Compiling futures-core v0.3.7
   Compiling nodrop v0.1.14
   Compiling slab v0.4.2
   Compiling bytes v0.5.6
   Compiling pin-project-lite v0.1.11
   Compiling fnv v1.0.7
   Compiling remove_dir_all v0.5.3
   Compiling lexical-core v0.7.4
   Compiling pin-project-internal v0.4.27
   Compiling anyhow v1.0.34
   Compiling opaque-debug v0.3.0
   Compiling matches v0.1.8
   Compiling bit-vec v0.6.2
   Compiling static_assertions v1.1.0
   Compiling byteorder v0.5.3
   Compiling cpuid-bool v0.1.2
   Compiling regex-syntax v0.6.21
   Compiling unicode-width v0.1.8
   Compiling once_cell v1.4.1
   Compiling openssl v0.10.30
   Compiling tinyvec v0.3.4
   Compiling foreign-types-shared v0.1.1
   Compiling pin-utils v0.1.0
   Compiling futures-io v0.3.7
   Compiling hashbrown v0.9.1
   Compiling semver-parser v0.7.0
   Compiling futures-sink v0.3.7
   Compiling httparse v1.3.4
   Compiling ansi_term v0.11.0
   Compiling block-padding v0.2.1
   Compiling native-tls v0.2.5
   Compiling percent-encoding v2.1.0
   Compiling proc-macro2 v0.4.30
   Compiling try-lock v0.2.3
   Compiling hex v0.4.2
   Compiling openssl-probe v0.1.2
   Compiling unicode-xid v0.1.0
   Compiling bitflags v0.4.0
   Compiling httpdate v0.3.2
   Compiling subtle v1.0.0
   Compiling difference v2.0.0
   Compiling unicode-segmentation v1.6.0
   Compiling tower-service v0.3.0
   Compiling crc32fast v1.2.1
   Compiling encoding_rs v0.8.26
   Compiling vec_map v0.8.2
   Compiling strsim v0.8.0
   Compiling byte-slice-cast v1.0.0
   Compiling dtoa v0.4.6
   Compiling cbindgen v0.14.0
   Compiling yansi v0.5.0
   Compiling bitintr v0.3.0
   Compiling syn v0.15.44
   Compiling glob v0.3.0
   Compiling storage-proofs v5.4.0
   Compiling mime v0.3.16
   Compiling zeroize v0.9.3
   Compiling ipnet v2.3.0
   Compiling number_prefix v0.3.0
   Compiling termcolor v1.1.0
   Compiling base64 v0.12.3
   Compiling radium v0.3.0
   Compiling humansize v1.1.0
   Compiling lazy_static v1.4.0
   Compiling num-traits v0.2.14
   Compiling num-integer v0.1.44
   Compiling memoffset v0.5.6
   Compiling num-bigint v0.2.6
   Compiling crossbeam-utils v0.7.2
   Compiling crossbeam-utils v0.8.0
   Compiling num-iter v0.1.42
   Compiling miniz_oxide v0.4.3
   Compiling crossbeam-epoch v0.8.2
   Compiling rayon v1.5.0
   Compiling indexmap v1.6.0
   Compiling generic-array v0.14.4
   Compiling unicase v2.6.0
   Compiling nom v5.1.2
   Compiling proc-macro-error-attr v1.0.4
   Compiling proc-macro-error v1.0.4
   Compiling openssl-src v111.12.0+1.1.1h
   Compiling fff v0.2.3
   Compiling neptune-triton v2.0.0
   Compiling sha2-asm v0.5.4
   Compiling itertools v0.8.2
   Compiling itertools v0.9.0
   Compiling block-padding v0.1.5
   Compiling hwloc v0.3.0
   Compiling rustc_version v0.1.7
   Compiling blake2b_simd v0.5.11
   Compiling blake2s_simd v0.5.11
   Compiling addr2line v0.14.0
   Compiling futures-channel v0.3.7
   Compiling http v0.2.1
   Compiling unicode-bidi v0.3.4
   Compiling textwrap v0.11.0
   Compiling futures-task v0.3.7
   Compiling foreign-types v0.3.2
   Compiling unicode-normalization v0.1.13
   Compiling semver v0.9.0
   Compiling form_urlencoded v1.0.0
   Compiling pretty_assertions v0.6.1
   Compiling heck v0.3.1
   Compiling bitvec v0.17.4
   Compiling thread_local v1.0.1
   Compiling tracing-core v0.1.17
   Compiling openssl-sys v0.9.58
   Compiling fil-ocl-core v0.11.3
   Compiling http-body v0.3.1
   Compiling rustc_version v0.2.3
   Compiling idna v0.2.0
   Compiling num_cpus v1.13.0
   Compiling rand v0.4.6
   Compiling dirs-sys v0.3.5
   Compiling iovec v0.1.4
   Compiling net2 v0.2.35
   Compiling memmap v0.7.0
   Compiling fs2 v0.4.3
   Compiling time v0.1.44
   Compiling positioned-io v0.2.2
   Compiling atty v0.2.14
   Compiling terminal_size v0.1.13
   Compiling errno v0.1.8
   Compiling socket2 v0.3.15
   Compiling mapr v0.8.0
   Compiling xattr v0.2.2
   Compiling filetime v0.2.13
   Compiling quote v1.0.7
   Compiling tracing v0.1.21
   Compiling want v0.3.0
   Compiling aho-corasick v0.7.15
   Compiling generic-array v0.12.3
   Compiling raw-cpuid v7.0.3
   Compiling quote v0.6.13
   Compiling url v2.2.0
   Compiling rand_core v0.5.1
   Compiling dirs v2.0.2
   Compiling tempdir v0.3.7
   Compiling ahash v0.5.8
   Compiling mio v0.6.22
   Compiling clap v2.33.3
   Compiling tar v0.4.30
   Compiling num-complex v0.1.43
   Compiling num-traits v0.1.43
   Compiling backtrace v0.3.54
   Compiling flate2 v1.0.19
   Compiling crossbeam-channel v0.4.4
   Compiling crossbeam-queue v0.2.3
   Compiling mime_guess v2.0.3
   Compiling digest v0.9.0
   Compiling crypto-mac v0.10.0
   Compiling cipher v0.2.5
   Compiling block-buffer v0.9.0
   Compiling regex v1.4.2
   Compiling digest v0.8.1
   Compiling block-buffer v0.7.3
   Compiling crypto-mac v0.7.0
   Compiling crossbeam-epoch v0.9.0
   Compiling crossbeam-channel v0.5.0
   Compiling crossbeam-queue v0.3.0
   Compiling rand_chacha v0.2.2
   Compiling rand_xorshift v0.2.0
   Compiling env_proxy v0.4.1
   Compiling tokio v0.2.22
   Compiling num-bigint v0.1.44
   Compiling chrono v0.4.19
   Compiling enum_primitive v0.1.1
   Compiling synstructure v0.12.4
   Compiling thiserror-impl v1.0.22
   Compiling pin-project-internal v1.0.1
   Compiling pbr v1.0.3
   Compiling crossbeam-deque v0.7.3
   Compiling hmac v0.10.1
   Compiling aes-soft v0.6.3
   Compiling block-modes v0.7.0
   Compiling sha2 v0.9.2
   Compiling sha2raw v2.0.0
   Compiling sha2 v0.8.2
   Compiling hmac v0.7.1
   Compiling crossbeam-deque v0.8.0
   Compiling console v0.13.0
   Compiling rand v0.7.3
   Compiling drop_struct_macro_derive v0.4.0
   Compiling tokio-util v0.3.1
   Compiling num-rational v0.1.42
   Compiling flexi_logger v0.14.8
   Compiling simplelog v0.8.0
   Compiling structopt-derive v0.4.13
   Compiling thiserror v1.0.22
   Compiling pin-project v1.0.1
   Compiling pin-project v0.4.27
   Compiling fff_derive v0.2.2
   Compiling hkdf v0.10.0
   Compiling crossbeam v0.7.3
   Compiling aes v0.6.0
   Compiling hkdf v0.8.0
   Compiling crossbeam v0.8.0
   Compiling indicatif v0.15.0
   Compiling sha2ni v0.8.5
   Compiling ffi-toolkit v0.4.0
   Compiling tempfile v3.1.0
   Compiling num v0.1.42
   Compiling fil_logger v0.1.2
   Compiling structopt v0.3.20
   Compiling failure v0.1.8
   Compiling futures-util v0.3.7
   Compiling tracing-futures v0.2.4
   Compiling qutex v0.2.3
   Compiling toml v0.5.7
   Compiling bincode v1.3.1
   Compiling serde_urlencoded v0.6.1
   Compiling dialoguer v0.7.1
   Compiling ocl-core-vector v0.1.0
   Compiling groupy v0.3.1
   Compiling ff-cl-gen v0.2.0
   Compiling config v0.10.1
   Compiling h2 v0.2.7
   Compiling merkletree v0.21.0
   Compiling paired v0.21.0
   Compiling paired v0.20.1
   Compiling tokio-tls v0.3.1
   Compiling hyper v0.13.9
   Compiling bls-signatures v0.6.1
   Compiling filcrypto v0.7.5 (/home/ml/git/lotus/extern/filecoin-ffi/rust)
   Compiling fil-ocl v0.19.4
   Compiling hyper-tls v0.4.3
   Compiling rust-gpu-tools v0.2.1
   Compiling reqwest v0.10.8
   Compiling bellperson v0.12.1
   Compiling neptune v2.2.0
   Compiling phase21 v0.11.0
   Compiling storage-proofs-core v5.4.0
   Compiling storage-proofs-post v5.4.0
   Compiling storage-proofs-porep v5.4.0
   Compiling filecoin-proofs v5.4.0
   Compiling filecoin-proofs-api v5.4.1
note: Link against the following native artifacts when linking against this static library. The order and any duplication can be significant on some platforms.

note: native-static-libs: -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil

    Finished release [optimized] target(s) in 12m 11s
++ cat /tmp/tmp.WQCqjDa053
++ grep native-static-libs:
++ cut -d : -f 3
++ head -n 1
+ local '__linker_flags= -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil'
++ git rev-parse HEAD
+ sed -e 's;@VERSION@;1d9cb3e8ff53f51f9318fc57e5d00bc79bdc0128;' -e 's;@PRIVATE_LIBS@; -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil;' filcrypto.pc.template
+ find -L . -type f -name filcrypto.h
+ read
+ find -L . -type f -name libfilcrypto.a
+ read
+ exit
+ rm -f /tmp/tmp.WQCqjDa053
+ popd
~/git/lotus/extern/filecoin-ffi
+ find -L rust/target/release -type f -name filcrypto.h -exec cp -- '{}' . ';'
+ find -L rust/target/release -type f -name libfilcrypto.a -exec cp -- '{}' . ';'
+ find -L rust -type f -name filcrypto.pc -exec cp -- '{}' . ';'
+ check_installed_files
+ [[ ! -f ./filcrypto.h ]]
+ [[ ! -f ./libfilcrypto.a ]]
+ [[ ! -f ./filcrypto.pc ]]
+ echo '[install-filcrypto/main] successfully built and installed libfilcrypto from source'
[install-filcrypto/main] successfully built and installed libfilcrypto from source
+ exit
make[1]: Leaving directory '/home/ml/git/lotus/extern/filecoin-ffi'
rm -f lotus
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721" -tags=debug -o lotus ./cmd/lotus
go: downloading github.com/ipfs/go-cid v0.0.7
go: downloading go.opencensus.io v0.22.5
go: downloading github.com/filecoin-project/go-commp-utils v0.0.0-20201119054358-b88f7a96a434
go: downloading github.com/raulk/clock v1.1.0
go: downloading github.com/filecoin-project/go-bitfield v0.2.3-0.20201110211213-fe2c1862e816
go: downloading github.com/whyrusleeping/cbor-gen v0.0.0-20200826160007-0b9f6c5fb163
go: downloading golang.org/x/xerrors v0.0.0-20200804184101-5ec99f83aff1
go: downloading github.com/ipfs/go-log/v2 v2.1.2-0.20200626104915-0016c0b4b3e4
go: downloading github.com/filecoin-project/go-jsonrpc v0.1.2
go: downloading github.com/filecoin-project/specs-actors v0.9.13
go: downloading github.com/filecoin-project/go-state-types v0.0.0-20201102161440-c8033295a1fc
go: downloading github.com/filecoin-project/go-fil-markets v1.0.10
go: downloading github.com/filecoin-project/go-fil-commcid v0.0.0-20201016201715-d41df56b4f6a
go: downloading github.com/libp2p/go-libp2p-core v0.7.0
go: downloading github.com/filecoin-project/go-data-transfer v1.2.3
go: downloading github.com/chzyer/readline v0.0.0-20180603132655-2972be24d48e
go: downloading github.com/ipfs/go-datastore v0.4.5
go: downloading github.com/libp2p/go-libp2p-kad-dht v0.11.0
go: downloading github.com/multiformats/go-multihash v0.0.14
go: downloading github.com/multiformats/go-multiaddr v0.3.1
go: downloading github.com/ipld/go-ipld-prime v0.5.1-0.20201021195245-109253e8a018
go: downloading github.com/filecoin-project/go-ds-versioning v0.1.0
go: downloading go.uber.org/zap v1.16.0
go: downloading github.com/ipfs/go-ipld-cbor v0.0.5
go: downloading github.com/filecoin-project/specs-actors/v2 v2.3.3
go: downloading github.com/ipfs/go-metrics-prometheus v0.0.2
go: downloading github.com/multiformats/go-multibase v0.0.3
go: downloading github.com/ipld/go-car v0.1.1-0.20201119040415-11b6074b6d4d
go: downloading github.com/buger/goterm v0.0.0-20200322175922-2f3e71b85129
go: downloading github.com/google/uuid v1.1.2
go: downloading github.com/multiformats/go-varint v0.0.6
go: downloading github.com/libp2p/go-libp2p-record v0.1.3
go: downloading golang.org/x/crypto v0.0.0-20200820211705-5c72a883971a
go: downloading github.com/detailyang/go-fallocate v0.0.0-20180908115635-432fa640bd2e
go: downloading github.com/filecoin-project/go-address v0.0.5-0.20201103152444-f2023ef3f5bb
go: downloading golang.org/x/sync v0.0.0-20201020160332-67f06af15bc9
go: downloading go.uber.org/multierr v1.6.0
go: downloading github.com/opentracing/opentracing-go v1.2.0
go: downloading github.com/hako/durafmt v0.0.0-20200710122514-c0fb7b4da026
go: downloading github.com/ipfs/go-ds-leveldb v0.4.2
go: downloading github.com/ipfs/go-blockservice v0.1.4
go: downloading github.com/ipfs/go-graphsync v0.5.1
go: downloading github.com/prometheus/client_golang v1.6.0
go: downloading github.com/libp2p/go-libp2p-pubsub v0.4.1
go: downloading github.com/mr-tron/base58 v1.2.0
go: downloading github.com/syndtr/goleveldb v1.0.0
go: downloading github.com/libp2p/go-libp2p-kbucket v0.4.7
go: downloading github.com/filecoin-project/go-hamt-ipld v0.1.5
go: downloading github.com/libp2p/go-netroute v0.1.3
go: downloading github.com/drand/drand v1.2.1
go: downloading github.com/libp2p/go-libp2p v0.12.0
go: downloading github.com/ipfs/go-bitswap v0.3.2
go: downloading github.com/filecoin-project/specs-storage v0.1.1-0.20201105051918-5188d9774506
go: downloading github.com/ipfs/go-ds-badger2 v0.1.1-0.20200708190120-187fc06f714e
go: downloading github.com/filecoin-project/go-amt-ipld/v2 v2.1.1-0.20201006184820-924ee87a1349
go: downloading github.com/multiformats/go-base36 v0.1.0
go: downloading github.com/ipfs/go-ds-measure v0.1.0
go: downloading github.com/google/gopacket v1.1.18
go: downloading github.com/filecoin-project/go-padreader v0.0.0-20200903213702-ed5fae088b20
go: downloading go.uber.org/atomic v1.7.0
go: downloading github.com/urfave/cli v1.22.1
go: downloading github.com/golang/groupcache v0.0.0-20200121045136-8c9f03a8e57e
go: downloading github.com/libp2p/go-msgio v0.0.6
go: downloading github.com/ipfs/go-cidutil v0.0.2
go: downloading github.com/libp2p/go-libp2p-peerstore v0.2.6
go: downloading github.com/multiformats/go-multiaddr-net v0.2.0
go: downloading github.com/drand/kyber v1.1.4
go: downloading github.com/go-kit/kit v0.10.0
go: downloading github.com/stretchr/testify v1.6.1
go: downloading github.com/prometheus/common v0.10.0
go: downloading github.com/jpillora/backoff v1.0.0
go: downloading github.com/urfave/cli/v2 v2.2.0
go: downloading github.com/filecoin-project/go-multistore v0.0.3
go: downloading github.com/ipfs/go-fs-lock v0.0.6
go: downloading github.com/whyrusleeping/ledger-filecoin-go v0.9.1-0.20201010031517-c3dcc1bddce4
go: downloading github.com/filecoin-project/go-paramfetch v0.0.2-0.20200701152213-3e0f0afdc261
go: downloading github.com/filecoin-project/go-statemachine v0.0.0-20200925024713-05bd7c71fbfe
go: downloading golang.org/x/sys v0.0.0-20200930185726-fdedc70b468f
go: downloading google.golang.org/protobuf v1.25.0
go: downloading github.com/filecoin-project/go-hamt-ipld/v2 v2.0.0
go: downloading github.com/ipld/go-ipld-prime-proto v0.1.0
go: downloading github.com/ipfs/go-merkledag v0.3.2
go: downloading github.com/ipfs/go-ipfs-util v0.0.2
go: downloading github.com/multiformats/go-multistream v0.2.0
go: downloading github.com/libp2p/go-cidranger v1.1.0
go: downloading github.com/golang/protobuf v1.4.2
go: downloading gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c
go: downloading github.com/elastic/gosigar v0.12.0
go: downloading github.com/libp2p/go-libp2p-swarm v0.3.1
go: downloading github.com/libp2p/go-libp2p-asn-util v0.0.0-20200825225859-85005c6cf052
go: downloading github.com/ipfs/go-ipfs-blockstore v1.0.3
go: downloading github.com/dgraph-io/badger/v2 v2.2007.2
go: downloading github.com/libp2p/go-libp2p-autonat v0.4.0
go: downloading google.golang.org/api v0.17.0
go: downloading github.com/raulk/go-watchdog v0.0.1
go: downloading github.com/libp2p/go-tcp-transport v0.2.1
go: downloading google.golang.org/grpc v1.31.1
go: downloading github.com/libp2p/go-libp2p-noise v0.1.2
go: downloading github.com/apache/thrift v0.13.0
go: downloading github.com/zondax/ledger-go v0.12.1
go: downloading go4.org v0.0.0-20200411211856-f5505b9728dd
go: downloading github.com/acarl005/stripansi v0.0.0-20180116102854-5a71ef0e047d
go: downloading github.com/dgraph-io/ristretto v0.0.3-0.20200630154024-f66de99634de
go: downloading github.com/libp2p/go-reuseport v0.0.2
go: downloading github.com/libp2p/go-libp2p-blankhost v0.2.0
go: downloading github.com/libp2p/go-libp2p-quic-transport v0.9.0
go: downloading github.com/cpuguy83/go-md2man v1.0.10
go: downloading go.uber.org/dig v1.10.0
go: downloading github.com/libp2p/go-libp2p-circuit v0.4.0
go: downloading google.golang.org/genproto v0.0.0-20200608115520-7c474a2e3482
go: downloading github.com/flynn/noise v0.0.0-20180327030543-2492fe189ae6
go: downloading github.com/fatih/color v1.9.0
go: downloading github.com/zondax/hid v0.9.0
go: downloading github.com/cpuguy83/go-md2man/v2 v2.0.0
go: downloading github.com/libp2p/go-reuseport-transport v0.0.4
go: downloading golang.org/x/net v0.0.0-20201021035429-f5854403a974
go: downloading github.com/libp2p/go-libp2p-mplex v0.3.0
go: downloading github.com/golang/snappy v0.0.2-0.20190904063534-ff6b7dc882cf
go: downloading github.com/benbjohnson/clock v1.0.3
go: downloading github.com/prometheus/procfs v0.1.0
go: downloading github.com/mattn/go-colorable v0.1.6
go: downloading github.com/lucas-clemente/quic-go v0.18.1
go: downloading github.com/libp2p/go-mplex v0.2.0
go: downloading github.com/drand/kyber-bls12381 v0.2.1
go: downloading golang.org/x/text v0.3.3
go: downloading github.com/libp2p/go-libp2p-yamux v0.4.1
go: downloading github.com/libp2p/go-libp2p-discovery v0.5.0
go: downloading github.com/libp2p/go-libp2p-testing v0.3.0
go: downloading github.com/russross/blackfriday v1.5.2
go: downloading github.com/marten-seemann/qtls-go1-15 v0.1.0
go: downloading github.com/kilic/bls12-381 v0.0.0-20200820230200-6b2c19996391
go: downloading github.com/russross/blackfriday/v2 v2.0.1
go: downloading github.com/libp2p/go-yamux v1.4.1
go: downloading github.com/shurcooL/sanitized_anchor_name v1.0.0
# github.com/filecoin-project/filecoin-ffi/generated
/usr/bin/ld: cannot find -lhwloc
collect2: error: ld returned 1 exit status
Makefile:70: recipe for target 'lotus' failed
make: *** [lotus] Error 2
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ sudo apt get install hwloc libhwloc-dev
[sudo] password for ml: 
E: Invalid operation get
ml@ml:~/git/lotus$ sudo apt-get install hwloc libhwloc-dev
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following packages were automatically installed and are no longer required:
  android-libadb android-libbase android-libcutils android-liblog libhttp-parser2.1 libssh2-1 libstd-rust-1.37 libstd-rust-dev
Use 'sudo apt autoremove' to remove them.
The following additional packages will be installed:
  autotools-dev libhwloc-plugins libhwloc5 libltdl-dev libnuma-dev libnuma1 libtool
Suggested packages:
  libhwloc-contrib-plugins libtool-doc autoconf automaken gfortran | fortran95-compiler gcj-jdk
The following NEW packages will be installed:
  autotools-dev hwloc libhwloc-dev libhwloc-plugins libhwloc5 libltdl-dev libnuma-dev libtool
The following packages will be upgraded:
  libnuma1
1 upgraded, 8 newly installed, 0 to remove and 698 not upgraded.
Need to get 881 kB of archives.
After this operation, 3,873 kB of additional disk space will be used.
Do you want to continue? [Y/n] Y
Get:1 http://mirrors.cloud.tencent.com/ubuntu xenial-security/main amd64 libnuma1 amd64 2.0.11-1ubuntu1.1 [21.0 kB]
Get:2 http://mirrors.cloud.tencent.com/ubuntu xenial/main amd64 autotools-dev all 20150820.1 [39.8 kB]                                                           
Get:3 http://mirrors.cloud.tencent.com/ubuntu xenial/main amd64 libltdl-dev amd64 2.4.6-0.1 [162 kB]                                                             
Get:4 http://mirrors.cloud.tencent.com/ubuntu xenial/main amd64 libtool all 2.4.6-0.1 [193 kB]                                                                   
Get:5 http://mirrors.cloud.tencent.com/ubuntu xenial/universe amd64 libhwloc5 amd64 1.11.2-3 [99.5 kB]                                                           
Get:6 http://mirrors.cloud.tencent.com/ubuntu xenial/universe amd64 hwloc amd64 1.11.2-3 [167 kB]                                                                
Get:7 http://mirrors.cloud.tencent.com/ubuntu xenial-security/main amd64 libnuma-dev amd64 2.0.11-1ubuntu1.1 [31.5 kB]                                           
Get:8 http://mirrors.cloud.tencent.com/ubuntu xenial/universe amd64 libhwloc-dev amd64 1.11.2-3 [155 kB]                                                         
Get:9 http://mirrors.cloud.tencent.com/ubuntu xenial/universe amd64 libhwloc-plugins amd64 1.11.2-3 [13.2 kB]                                                    
Fetched 881 kB in 16s (51.9 kB/s)                                                                                                                                
(Reading database ... 232068 files and directories currently installed.)
Preparing to unpack .../libnuma1_2.0.11-1ubuntu1.1_amd64.deb ...
Unpacking libnuma1:amd64 (2.0.11-1ubuntu1.1) over (2.0.11-1ubuntu1) ...
Selecting previously unselected package autotools-dev.
Preparing to unpack .../autotools-dev_20150820.1_all.deb ...
Unpacking autotools-dev (20150820.1) ...
Selecting previously unselected package libltdl-dev:amd64.
Preparing to unpack .../libltdl-dev_2.4.6-0.1_amd64.deb ...
Unpacking libltdl-dev:amd64 (2.4.6-0.1) ...
Selecting previously unselected package libtool.
Preparing to unpack .../libtool_2.4.6-0.1_all.deb ...
Unpacking libtool (2.4.6-0.1) ...
Selecting previously unselected package libhwloc5:amd64.
Preparing to unpack .../libhwloc5_1.11.2-3_amd64.deb ...
Unpacking libhwloc5:amd64 (1.11.2-3) ...
Selecting previously unselected package hwloc.
Preparing to unpack .../hwloc_1.11.2-3_amd64.deb ...
Unpacking hwloc (1.11.2-3) ...
Selecting previously unselected package libnuma-dev:amd64.
Preparing to unpack .../libnuma-dev_2.0.11-1ubuntu1.1_amd64.deb ...
Unpacking libnuma-dev:amd64 (2.0.11-1ubuntu1.1) ...
Selecting previously unselected package libhwloc-dev:amd64.
Preparing to unpack .../libhwloc-dev_1.11.2-3_amd64.deb ...
Unpacking libhwloc-dev:amd64 (1.11.2-3) ...
Selecting previously unselected package libhwloc-plugins.
Preparing to unpack .../libhwloc-plugins_1.11.2-3_amd64.deb ...
Unpacking libhwloc-plugins (1.11.2-3) ...
Processing triggers for libc-bin (2.23-0ubuntu9) ...
Processing triggers for man-db (2.7.5-1) ...
Processing triggers for gnome-menus (3.13.3-6ubuntu3.1) ...
Processing triggers for desktop-file-utils (0.22-1ubuntu5.1) ...
Processing triggers for bamfdaemon (0.5.3~bzr0+16.04.20160824-0ubuntu1) ...
Rebuilding /usr/share/applications/bamf-2.index...
Processing triggers for mime-support (3.59ubuntu1) ...
Setting up libnuma1:amd64 (2.0.11-1ubuntu1.1) ...
Setting up autotools-dev (20150820.1) ...
Setting up libltdl-dev:amd64 (2.4.6-0.1) ...
Setting up libtool (2.4.6-0.1) ...
Setting up libhwloc5:amd64 (1.11.2-3) ...
Setting up hwloc (1.11.2-3) ...
Setting up libnuma-dev:amd64 (2.0.11-1ubuntu1.1) ...
Setting up libhwloc-dev:amd64 (1.11.2-3) ...
Setting up libhwloc-plugins (1.11.2-3) ...
Processing triggers for libc-bin (2.23-0ubuntu9) ...
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ FFI_BUILD_FROM_SOURCE=1 make debug
rm -f lotus
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721" -tags=debug -o lotus ./cmd/lotus
go run github.com/GeertJohan/go.rice/rice append --exec lotus -i ./build
rm -f lotus-miner
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721" -tags=debug -o lotus-miner ./cmd/lotus-storage-miner
go run github.com/GeertJohan/go.rice/rice append --exec lotus-miner -i ./build
rm -f lotus-worker
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721" -tags=debug -o lotus-worker ./cmd/lotus-seal-worker
go run github.com/GeertJohan/go.rice/rice append --exec lotus-worker -i ./build
rm -f lotus-seed
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721" -tags=debug -o lotus-seed ./cmd/lotus-seed
go run github.com/GeertJohan/go.rice/rice append --exec lotus-seed -i ./build
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ ls -al
total 424380
drwxrwxr-x 28 ml ml      4096 3月   1 11:41 .
drwxrwxr-x  3 ml ml      4096 3月   1 11:12 ..
drwxrwxr-x  7 ml ml      4096 3月   1 11:10 api
drwxrwxr-x  5 ml ml      4096 3月   1 11:27 build
drwxrwxr-x 19 ml ml      4096 3月   1 11:10 chain
-rw-rw-r--  1 ml ml     82505 3月   1 11:10 CHANGELOG.md
drwxrwxr-x  2 ml ml      4096 3月   1 11:10 .circleci
drwxrwxr-x  4 ml ml      4096 3月   1 11:10 cli
drwxrwxr-x 19 ml ml      4096 3月   1 10:56 cmd
-rw-rw-r--  1 ml ml       373 3月   1 10:56 .codecov.yml
drwxrwxr-x  3 ml ml      4096 3月   1 10:56 conformance
lrwxrwxrwx  1 ml ml        10 3月   1 10:55 .dockerignore -> .gitignore
drwxrwxr-x  4 ml ml      4096 3月   1 10:55 documentation
drwxrwxr-x  8 ml ml      4096 3月   1 11:10 extern
drwxrwxr-x  2 ml ml      4096 3月   1 10:56 gen
drwxrwxr-x  2 ml ml      4096 3月   1 10:56 genesis
drwxrwxr-x  9 ml ml      4096 3月   1 11:40 .git
drwxrwxr-x  4 ml ml      4096 3月   1 10:56 .github
-rw-rw-r--  1 ml ml       647 3月   1 10:56 .gitignore
-rw-rw-r--  1 ml ml       488 3月   1 11:10 .gitmodules
-rw-rw-r--  1 ml ml      1626 3月   1 10:56 .golangci.yml
-rw-rw-r--  1 ml ml      7498 3月   1 11:10 go.mod
-rw-rw-r--  1 ml ml    194024 3月   1 11:10 go.sum
drwxrwxr-x  2 ml ml      4096 3月   1 10:56 journal
drwxrwxr-x 18 ml ml      4096 3月   1 10:56 lib
-rw-rw-r--  1 ml ml       520 3月   1 10:55 LICENSE-APACHE
-rw-rw-r--  1 ml ml      1046 3月   1 10:55 LICENSE-MIT
-rwxrwxr-x  1 ml ml 121099020 3月   1 11:41 lotus
-rwxrwxr-x  1 ml ml 120780052 3月   1 11:41 lotus-miner
drwxrwxr-x  3 ml ml      4096 3月   1 10:56 lotuspond
-rwxrwxr-x  1 ml ml  87966980 3月   1 11:42 lotus-seed
-rwxrwxr-x  1 ml ml 104255452 3月   1 11:41 lotus-worker
-rw-rw-r--  1 ml ml      9216 3月   1 11:10 Makefile
drwxrwxr-x  7 ml ml      4096 3月   1 10:56 markets
drwxrwxr-x  2 ml ml      4096 3月   1 10:56 metrics
drwxrwxr-x  2 ml ml      4096 3月   1 11:10 miner
drwxrwxr-x  8 ml ml      4096 3月   1 11:10 node
drwxrwxr-x  3 ml ml      4096 3月   1 11:10 paychmgr
-rw-rw-r--  1 ml ml      4317 3月   1 10:56 README.md
drwxrwxr-x  5 ml ml      4096 3月   1 10:56 scripts
-rw-rw-r--  1 ml ml      1814 3月   1 10:56 SECURITY.md
drwxrwxr-x  4 ml ml      4096 3月   1 11:10 storage
drwxrwxr-x  2 ml ml      4096 3月   1 10:56 system
drwxrwxr-x  8 ml ml      4096 3月   1 11:10 testplans
drwxrwxr-x  4 ml ml      4096 3月   1 10:55 tools
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ ls
api    CHANGELOG.md  conformance    gen      go.sum   LICENSE-APACHE  lotus-miner  lotus-worker  metrics  paychmgr   SECURITY.md  testplans
build  cli           documentation  genesis  journal  LICENSE-MIT     lotuspond    Makefile      miner    README.md  storage      tools
chain  cmd           extern         go.mod   lib      lotus           lotus-seed   markets       node     scripts    system
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ du -h -d 1 ./
344K	./cli
36K	./.github
124K	./scripts
112K	./conformance
28K	./journal
2.0M	./chain
88K	./tools
236K	./lib
204K	./paychmgr
1.2G	./extern
20K	./metrics
132K	./markets
8.0K	./gen
1.2M	./cmd
24K	./.circleci
640K	./node
164K	./storage
712K	./lotuspond
159M	./.git
3.1M	./build
8.0K	./genesis
336K	./api
8.0K	./system
940K	./testplans
260K	./documentation
28K	./miner
1.8G	./
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ ./lotus --version
lotus version 1.4.1+debug+git.ebaa721
ml@ml:~/git/lotus$ 


```