
```sh

ml@ml:~/git2/lotus_latest$ git pull origin master 
remote: Enumerating objects: 41, done.
remote: Counting objects: 100% (41/41), done.
remote: Total 71 (delta 41), reused 41 (delta 41), pack-reused 30
Unpacking objects: 100% (71/71), 32.76 KiB | 77.00 KiB/s, done.
From https://github.com/filecoin-project/lotus
 * branch                master     -> FETCH_HEAD
   d1abc3cb5..9f721bfde  master     -> origin/master
Updating d1abc3cb5..9f721bfde
Fast-forward
 CHANGELOG.md                                |  20 +++++++++++++++++++-
 api/cbor_gen.go                             |  19 ++++++++++++++-----
 build/bootstrap/butterflynet.pi             |   4 ++--
 build/genesis/butterflynet.car              | Bin 2519779 -> 2519783 bytes
 build/params_mainnet.go                     |   7 ++++++-
 build/tools.go                              |   1 +
 build/version.go                            |   2 +-
 chain/exchange/cbor_gen.go                  |   3 +++
 chain/market/cbor_gen.go                    |   4 ++++
 chain/types/cbor_gen.go                     |   3 +++
 cli/disputer.go                             |   2 +-
 cli/state.go                                |  80 +++++++++++++++++++++++++++++++++++++++++++++++---------------------------------
 cmd/lotus-storage-miner/sectors.go          |  31 +++++++++++++++++++++++++++++--
 conformance/chaos/cbor_gen.go               |   3 +++
 documentation/en/api-methods-miner.md       |   3 ++-
 documentation/en/api-methods.md             |   9 ++++++---
 extern/sector-storage/cbor_gen.go           |  13 ++++++++++---
 extern/sector-storage/storiface/cbor_gen.go |   7 ++++++-
 extern/storage-sealing/cbor_gen.go          |  19 ++++++++++++++-----
 go.mod                                      |   4 ++--
 go.sum                                      |  13 ++++++++++---
 node/hello/cbor_gen.go                      |   3 +++
 paychmgr/cbor_gen.go                        |  13 ++++++++++---
 23 files changed, 196 insertions(+), 67 deletions(-)
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ git branch 
* master
ml@ml:~/git2/lotus_latest$ git checkout v1.5.0-
v1.5.0-pre1   v1.5.0-pre2   v1.5.0-pre3   v1.5.0-rc1    v1.5.0-rc2    
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ git pull --tags
remote: Enumerating objects: 1532, done.
remote: Counting objects: 100% (1532/1532), done.
remote: Compressing objects: 100% (34/34), done.
remote: Total 2767 (delta 1502), reused 1518 (delta 1497), pack-reused 1235
Receiving objects: 100% (2767/2767), 415.88 KiB | 1.64 MiB/s, done.
Resolving deltas: 100% (2075/2075), completed with 341 local objects.
From https://github.com/filecoin-project/lotus
 * [new branch]          asr/genesis-rootkey                       -> origin/asr/genesis-rootkey
 * [new branch]          digitalocean-generate                     -> origin/digitalocean-generate
 * [new branch]          exp/lotus-soup-diff-client-miner-versions -> origin/exp/lotus-soup-diff-client-miner-versions
 * [new branch]          feat/api-no-dep-build                     -> origin/feat/api-no-dep-build
 * [new branch]          feat/api-versioning-scaffolding           -> origin/feat/api-versioning-scaffolding
 * [new branch]          feat/cli-show-deals                       -> origin/feat/cli-show-deals
 * [new branch]          feat/cliutil-pkg                          -> origin/feat/cliutil-pkg
 * [new branch]          feat/deals-version-test                   -> origin/feat/deals-version-test
 * [new branch]          feat/disable-pre-migration                -> origin/feat/disable-pre-migration
 * [new branch]          feat/extend-sectors-cmd                   -> origin/feat/extend-sectors-cmd
 * [new branch]          feat/net-peers-extended                   -> origin/feat/net-peers-extended
 * [new branch]          feat/optim-gas-premium                    -> origin/feat/optim-gas-premium
 * [new branch]          feat/pubsub-ip-colocatio-whitelist        -> origin/feat/pubsub-ip-colocatio-whitelist
 + 6d416b997...e85391b46 feat/splitstore                           -> origin/feat/splitstore  (forced update)
 * [new branch]          feat/splitstore-bench-import              -> origin/feat/splitstore-bench-import
 * [new branch]          feat/splitstore-lmdb                      -> origin/feat/splitstore-lmdb
 * [new branch]          feat/statecompute-script                  -> origin/feat/statecompute-script
 * [new branch]          feat/v1-api                               -> origin/feat/v1-api
 * [new branch]          fix/digitalocean-pass-test                -> origin/fix/digitalocean-pass-test
 * [new branch]          frrist/fx-hello-world                     -> origin/frrist/fx-hello-world
   a03506cf8..81fcffcf3  jen/issue-templates                       -> origin/jen/issue-templates
 * [new branch]          next                                      -> origin/next
   607d1bc6f..7148a5558  refac/send                                -> origin/refac/send
 * [new branch]          sentinel/binary                           -> origin/sentinel/binary
 * [new branch]          sentinel/module-scaffold                  -> origin/sentinel/module-scaffold
 * [new branch]          steb/read-cache-migration                 -> origin/steb/read-cache-migration
 * [new branch]          test/early-upgrade-test                   -> origin/test/early-upgrade-test
 * [new tag]             v1.5.0                                    -> v1.5.0
Already up to date.
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ git checkout v1.5.0
v1.5.0        v1.5.0-pre1   v1.5.0-pre2   v1.5.0-pre3   v1.5.0-rc1    v1.5.0-rc2    
ml@ml:~/git2/lotus_latest$ git checkout v1.5.0
Note: switching to 'v1.5.0'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD is now at 55b85f314 Merge pull request #5670 from filecoin-project/asr/changelog
ml@ml:~/git2/lotus_latest$
ml@ml:~/git2/lotus_latest$ git branch 
* (HEAD detached at v1.5.0)
  master
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ FFI_BUILD_FROM_SOURCE=1 make clean calibnet
rm -rf  build/.filecoin-install build/.update-modules  lotus lotus-miner lotus-worker lotus-shed lotus-gateway lotus-seed lotus-pond lotus-townhall lotus-fountain lotus-chainwatch lotus-bench lotus-stats lotus-pcr lotus-health lotus-wallet lotus-keygen testground
make -C extern/filecoin-ffi/ clean
make[1]: Entering directory '/home/ml/git2/lotus_latest/extern/filecoin-ffi'
make[1]: *** No rule to make target 'clean'.  Stop.
make[1]: Leaving directory '/home/ml/git2/lotus_latest/extern/filecoin-ffi'
make: [Makefile:310: clean] Error 2 (ignored)
git submodule update --init --recursive
Submodule path 'extern/filecoin-ffi': checked out 'b6e0b35fb49ed0fedb6a6a473b222e3b8a7d7f17'
Submodule path 'extern/serialization-vectors': checked out '5bfb928910b01ac8b940a693af2884f7f8276211'
Submodule path 'extern/test-vectors': checked out 'd9a75a7873aee0db28b87e3970d2ea16a2f37c6a'
Submodule path 'extern/test-vectors/gen/extern/fil-blst': checked out '5f93488fc0dbfb450f2355269f18fc67010d59bb'
Submodule path 'extern/test-vectors/gen/extern/filecoin-ffi': checked out 'f640612a1a1f7a2dd8b3a49e1531db0aa0f63447'
touch build/.update-modules
make -C extern/filecoin-ffi/ .install-filcrypto
make[1]: Entering directory '/home/ml/git2/lotus_latest/extern/filecoin-ffi'
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
++ x86_64_uname='Linux ml 5.4.0-29-generic #33-Ubuntu SMP Wed Apr 29 14:32:27 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux'
++ '[' -n 'Linux ml 5.4.0-29-generic #33-Ubuntu SMP Wed Apr 29 14:32:27 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux' ']'
+++ cat /proc/cpuinfo
+++ grep flags
+++ head -n 1
++ __features='flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
++ feature_map=("adx:+adx" "sha_ni:+sha" "sha2:+sha2" "sse2:+sse2" "avx2:+avx2" "avx:+avx" "sse4_2:+sse4.2" "sse4_1:+sse4.1")
++ target_features=
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c adx
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c sha_ni
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c sha2
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c sse2
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in "${feature_map[@]}"
++ key=adx
++ '[' adx == sse2 ']'
++ for feature in "${feature_map[@]}"
++ key=sha_ni
++ '[' sha_ni == sse2 ']'
++ for feature in "${feature_map[@]}"
++ key=sha2
++ '[' sha2 == sse2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse2
++ '[' sse2 == sse2 ']'
++ val=+sse2
++ '[' -z '' ']'
++ target_features=+sse2
++ for feature in "${feature_map[@]}"
++ key=avx2
++ '[' avx2 == sse2 ']'
++ for feature in "${feature_map[@]}"
++ key=avx
++ '[' avx == sse2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_2
++ '[' sse4_2 == sse2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_1
++ '[' sse4_1 == sse2 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ grep -c avx2
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in "${feature_map[@]}"
++ key=adx
++ '[' adx == avx2 ']'
++ for feature in "${feature_map[@]}"
++ key=sha_ni
++ '[' sha_ni == avx2 ']'
++ for feature in "${feature_map[@]}"
++ key=sha2
++ '[' sha2 == avx2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse2
++ '[' sse2 == avx2 ']'
++ for feature in "${feature_map[@]}"
++ key=avx2
++ '[' avx2 == avx2 ']'
++ val=+avx2
++ '[' -z +sse2 ']'
++ target_features=+sse2,+avx2
++ for feature in "${feature_map[@]}"
++ key=avx
++ '[' avx == avx2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_2
++ '[' sse4_2 == avx2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_1
++ '[' sse4_1 == avx2 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c avx
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in "${feature_map[@]}"
++ key=adx
++ '[' adx == avx ']'
++ for feature in "${feature_map[@]}"
++ key=sha_ni
++ '[' sha_ni == avx ']'
++ for feature in "${feature_map[@]}"
++ key=sha2
++ '[' sha2 == avx ']'
++ for feature in "${feature_map[@]}"
++ key=sse2
++ '[' sse2 == avx ']'
++ for feature in "${feature_map[@]}"
++ key=avx2
++ '[' avx2 == avx ']'
++ for feature in "${feature_map[@]}"
++ key=avx
++ '[' avx == avx ']'
++ val=+avx
++ '[' -z +sse2,+avx2 ']'
++ target_features=+sse2,+avx2,+avx
++ for feature in "${feature_map[@]}"
++ key=sse4_2
++ '[' sse4_2 == avx ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_1
++ '[' sse4_1 == avx ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c sse4_2
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in "${feature_map[@]}"
++ key=adx
++ '[' adx == sse4_2 ']'
++ for feature in "${feature_map[@]}"
++ key=sha_ni
++ '[' sha_ni == sse4_2 ']'
++ for feature in "${feature_map[@]}"
++ key=sha2
++ '[' sha2 == sse4_2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse2
++ '[' sse2 == sse4_2 ']'
++ for feature in "${feature_map[@]}"
++ key=avx2
++ '[' avx2 == sse4_2 ']'
++ for feature in "${feature_map[@]}"
++ key=avx
++ '[' avx == sse4_2 ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_2
++ '[' sse4_2 == sse4_2 ']'
++ val=+sse4.2
++ '[' -z +sse2,+avx2,+avx ']'
++ target_features=+sse2,+avx2,+avx,+sse4.2
++ for feature in "${feature_map[@]}"
++ key=sse4_1
++ '[' sse4_1 == sse4_2 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c sse4_1
++ current_feature=1
++ '[' 1 = 1 ']'
++ for feature in "${feature_map[@]}"
++ key=adx
++ '[' adx == sse4_1 ']'
++ for feature in "${feature_map[@]}"
++ key=sha_ni
++ '[' sha_ni == sse4_1 ']'
++ for feature in "${feature_map[@]}"
++ key=sha2
++ '[' sha2 == sse4_1 ']'
++ for feature in "${feature_map[@]}"
++ key=sse2
++ '[' sse2 == sse4_1 ']'
++ for feature in "${feature_map[@]}"
++ key=avx2
++ '[' avx2 == sse4_1 ']'
++ for feature in "${feature_map[@]}"
++ key=avx
++ '[' avx == sse4_1 ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_2
++ '[' sse4_2 == sse4_1 ']'
++ for feature in "${feature_map[@]}"
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
+ local __repo_sha1=b6e0b35fb49ed0fedb6a6a473b222e3b8a7d7f17
+ local __repo_sha1_truncated=b6e0b35fb49ed0fe
+ echo 'building from source @ b6e0b35fb49ed0fe'
building from source @ b6e0b35fb49ed0fe
++ command -v cargo
+ '[' -x /home/ml/.cargo/bin/cargo ']'
++ command -v rustup
+ '[' -x /home/ml/.cargo/bin/rustup ']'
+ pushd rust
~/git2/lotus_latest/extern/filecoin-ffi/rust ~/git2/lotus_latest/extern/filecoin-ffi
+ cargo --version
cargo 1.48.0-nightly (75615f8e6 2020-09-29)
+ '[' '' == 1 ']'
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
+ __build_output_log_tmp=/tmp/tmp.brINtLWm1Q
+ trap '{ rm -f $__build_output_log_tmp; }' EXIT
+ local '__rust_flags=--print native-static-libs -C target-feature=+sse2,+avx2,+avx,+sse4.2,+sse4.1'
+ RUSTFLAGS='--print native-static-libs -C target-feature=+sse2,+avx2,+avx,+sse4.2,+sse4.1'
+ cargo +nightly-2020-10-05 build --release --no-default-features --features pairing
+ tee /tmp/tmp.brINtLWm1Q
   Compiling autocfg v1.0.1
   Compiling libc v0.2.86
   Compiling cfg-if v1.0.0
   Compiling proc-macro2 v1.0.24
   Compiling unicode-xid v0.2.1
   Compiling lazy_static v1.4.0
   Compiling syn v1.0.60
   Compiling version_check v0.9.2
   Compiling cc v1.0.66
   Compiling log v0.4.14
   Compiling bitflags v1.2.1
   Compiling typenum v1.12.0
   Compiling cfg-if v0.1.10
   Compiling serde_derive v1.0.123
   Compiling serde v1.0.123
   Compiling memchr v2.3.4
   Compiling scopeguard v1.1.0
   Compiling getrandom v0.2.2
   Compiling getrandom v0.1.16
   Compiling byteorder v1.4.2
   Compiling ppv-lite86 v0.2.10
   Compiling maybe-uninit v2.0.0
   Compiling ryu v1.0.5
   Compiling rustc-serialize v0.3.24
   Compiling const_fn v0.4.5
   Compiling adler v0.2.3
   Compiling pkg-config v0.3.19
   Compiling gimli v0.23.0
   Compiling semver v0.1.20
   Compiling either v1.6.1
   Compiling once_cell v1.5.2
   Compiling failure_derive v0.1.8
   Compiling rayon-core v1.9.0
   Compiling byte-tools v0.3.1
   Compiling arrayvec v0.5.2
   Compiling rustc-demangle v0.1.18
   Compiling cl-sys v0.4.2
   Compiling object v0.23.0
   Compiling itoa v0.4.7
   Compiling opaque-debug v0.2.3
   Compiling subtle v2.4.0
   Compiling arrayref v0.3.6
   Compiling futures v0.1.30
   Compiling serde_json v1.0.62
   Compiling fake-simd v0.1.2
   Compiling nodrop v0.1.14
   Compiling constant_time_eq v0.1.5
   Compiling slab v0.4.2
   Compiling fnv v1.0.7
   Compiling futures-core v0.3.12
   Compiling remove_dir_all v0.5.3
   Compiling bytes v0.5.6
   Compiling lexical-core v0.7.5
   Compiling pin-project-internal v0.4.27
   Compiling anyhow v1.0.38
   Compiling pin-project-lite v0.1.11
   Compiling static_assertions v1.1.0
   Compiling matches v0.1.8
   Compiling regex-syntax v0.6.22
   Compiling bit-vec v0.6.3
   Compiling rustc-hash v1.1.0
   Compiling pin-project-lite v0.2.4
   Compiling unicode-width v0.1.8
   Compiling opaque-debug v0.3.0
   Compiling tinyvec_macros v0.1.0
   Compiling openssl v0.10.32
   Compiling cpuid-bool v0.1.2
   Compiling foreign-types-shared v0.1.1
   Compiling byteorder v0.5.3
   Compiling bytes v1.0.1
   Compiling ansi_term v0.11.0
   Compiling pin-utils v0.1.0
   Compiling percent-encoding v2.1.0
   Compiling futures-io v0.3.12
   Compiling block-padding v0.2.1
   Compiling futures-sink v0.3.12
   Compiling httparse v1.3.5
   Compiling native-tls v0.2.7
   Compiling hashbrown v0.9.1
   Compiling proc-macro2 v0.4.30
   Compiling try-lock v0.2.3
   Compiling hex v0.4.2
   Compiling openssl-probe v0.1.2
   Compiling glob v0.3.0
   Compiling tower-service v0.3.1
   Compiling unicode-xid v0.1.0
   Compiling bitflags v0.4.0
   Compiling crc32fast v1.2.1
   Compiling unicode-segmentation v1.7.1
   Compiling difference v2.0.0
   Compiling httpdate v0.3.2
   Compiling encoding_rs v0.8.28
   Compiling vec_map v0.8.2
   Compiling strsim v0.8.0
   Compiling yansi v0.5.0
   Compiling storage-proofs v5.4.0
   Compiling mime v0.3.16
   Compiling bitintr v0.3.0
   Compiling syn v0.15.44
   Compiling cbindgen v0.14.0
   Compiling byte-slice-cast v1.0.0
   Compiling zeroize v0.9.3
   Compiling radium v0.3.0
   Compiling base64 v0.13.0
   Compiling number_prefix v0.3.0
   Compiling ipnet v2.3.0
   Compiling termcolor v1.1.2
   Compiling humansize v1.1.0
   Compiling tracing-core v0.1.17
   Compiling generic-array v0.14.4
   Compiling unicase v2.6.0
   Compiling nom v5.1.2
   Compiling proc-macro-error-attr v1.0.4
   Compiling proc-macro-error v1.0.4
   Compiling num-traits v0.2.14
   Compiling num-integer v0.1.44
   Compiling crossbeam-utils v0.8.1
   Compiling crossbeam-utils v0.7.2
   Compiling num-bigint v0.2.6
   Compiling memoffset v0.6.1
   Compiling memoffset v0.5.6
   Compiling miniz_oxide v0.4.3
   Compiling num-iter v0.1.42
   Compiling crossbeam-epoch v0.8.2
   Compiling rayon v1.5.0
   Compiling indexmap v1.6.1
   Compiling openssl-src v111.13.0+1.1.1i
   Compiling itertools v0.8.2
   Compiling itertools v0.9.0
   Compiling rustc_version v0.1.7
   Compiling thread_local v1.1.3
   Compiling futures-task v0.3.12
   Compiling fff v0.2.3
   Compiling neptune-triton v2.1.0
   Compiling sha2-asm v0.5.5
   Compiling hwloc v0.3.0
   Compiling block-padding v0.1.5
   Compiling blake2b_simd v0.5.11
   Compiling blake2s_simd v0.5.11
   Compiling futures-channel v0.3.12
   Compiling unicode-bidi v0.3.4
   Compiling tinyvec v1.1.1
   Compiling textwrap v0.11.0
   Compiling foreign-types v0.3.2
   Compiling addr2line v0.14.1
   Compiling http v0.2.3
   Compiling form_urlencoded v1.0.0
   Compiling pretty_assertions v0.6.1
   Compiling blst v0.2.0
   Compiling heck v0.3.2
   Compiling bitvec v0.17.4
   Compiling openssl-sys v0.9.60
   Compiling fil-ocl-core v0.11.3
   Compiling unicode-normalization v0.1.17
   Compiling tracing v0.1.23
   Compiling want v0.3.0
   Compiling quote v1.0.9
   Compiling http-body v0.3.1
   Compiling num_cpus v1.13.0
   Compiling rand v0.4.6
   Compiling dirs-sys v0.3.5
   Compiling memmap v0.7.0
   Compiling iovec v0.1.4
   Compiling net2 v0.2.37
   Compiling fs2 v0.4.3
   Compiling time v0.1.43
   Compiling positioned-io v0.2.2
   Compiling terminal_size v0.1.16
   Compiling atty v0.2.14
   Compiling socket2 v0.3.19
   Compiling errno v0.1.8
   Compiling mapr v0.8.0
   Compiling xattr v0.2.2
   Compiling filetime v0.2.14
   Compiling aho-corasick v0.7.15
   Compiling futures-util v0.3.12
   Compiling generic-array v0.12.3
   Compiling quote v0.6.13
   Compiling idna v0.2.1
   Compiling mime_guess v2.0.3
   Compiling crossbeam-channel v0.5.0
   Compiling crossbeam-queue v0.3.1
   Compiling threadpool v1.8.1
   Compiling num-complex v0.1.43
   Compiling num-traits v0.1.43
   Compiling tempdir v0.3.7
   Compiling rand_core v0.5.1
   Compiling dirs v2.0.2
   Compiling rand_core v0.6.2
   Compiling mio v0.6.23
   Compiling clap v2.33.3
   Compiling tar v0.4.32
   Compiling crossbeam-epoch v0.9.1
   Compiling crossbeam-queue v0.2.3
   Compiling crossbeam-channel v0.4.4
   Compiling backtrace v0.3.56
   Compiling flate2 v1.0.20
   Compiling regex v1.4.3
   Compiling block-buffer v0.7.3
   Compiling digest v0.8.1
   Compiling digest v0.9.0
   Compiling crypto-mac v0.10.0
   Compiling cipher v0.2.5
   Compiling block-buffer v0.9.0
   Compiling url v2.2.0
   Compiling pbr v1.0.4
   Compiling num-bigint v0.1.44
   Compiling chrono v0.4.19
   Compiling enum_primitive v0.1.1
   Compiling rand_chacha v0.2.2
   Compiling rand_xorshift v0.2.0
   Compiling rand_chacha v0.3.0
   Compiling crossbeam-deque v0.8.0
   Compiling tokio v0.2.25
   Compiling synstructure v0.12.4
   Compiling crossbeam-deque v0.7.3
   Compiling thiserror-impl v1.0.23
   Compiling pin-project-internal v1.0.5
   Compiling console v0.14.0
   Compiling console v0.13.0
   Compiling sha2 v0.8.2
   Compiling sha2raw v2.0.0
   Compiling hmac v0.10.1
   Compiling aes-soft v0.6.4
   Compiling block-modes v0.7.0
   Compiling sha2 v0.9.3
   Compiling env_proxy v0.4.1
   Compiling num-rational v0.1.42
   Compiling drop_struct_macro_derive v0.4.0
   Compiling flexi_logger v0.14.8
   Compiling simplelog v0.8.0
   Compiling fff_derive v0.2.2
   Compiling rand v0.7.3
   Compiling rand v0.8.3
   Compiling crossbeam v0.8.0
   Compiling structopt-derive v0.4.14
   Compiling crossbeam v0.7.3
   Compiling tokio-util v0.3.1
   Compiling thiserror v1.0.23
   Compiling indicatif v0.15.0
   Compiling pin-project v1.0.5
   Compiling pin-project v0.4.27
   Compiling hkdf v0.10.0
   Compiling aes v0.6.0
   Compiling num v0.1.42
   Compiling ffi-toolkit v0.4.0
   Compiling fil_logger v0.1.2
   Compiling tempfile v3.2.0
   Compiling qutex v0.2.3
   Compiling failure v0.1.8
   Compiling tracing-futures v0.2.4
   Compiling structopt v0.3.21
   Compiling ocl-core-vector v0.1.0
   Compiling groupy v0.3.1
   Compiling ff-cl-gen v0.2.0
   Compiling dialoguer v0.7.1
   Compiling h2 v0.2.7
   Compiling toml v0.5.8
   Compiling merkletree v0.21.0
   Compiling bincode v1.3.1
   Compiling serde_urlencoded v0.7.0
   Compiling paired v0.21.0
   Compiling blstrs v0.1.3
   Compiling config v0.10.1
   Compiling hyper v0.13.10
   Compiling bls-signatures v0.7.1
   Compiling fil-ocl v0.19.4
   Compiling rust-gpu-tools v0.2.2
   Compiling rust-gpu-tools v0.3.0
   Compiling filcrypto v0.7.5 (/home/ml/git2/lotus_latest/extern/filecoin-ffi/rust)
   Compiling bellperson v0.12.5
   Compiling phase21 v0.11.0
   Compiling tokio-tls v0.3.1
   Compiling hyper-tls v0.4.3
   Compiling reqwest v0.10.10
   Compiling neptune v2.6.0
   Compiling storage-proofs-core v5.4.0
   Compiling storage-proofs-post v5.4.0
   Compiling storage-proofs-porep v5.4.0
   Compiling filecoin-proofs v5.4.0
   Compiling filecoin-proofs-api v5.4.1
note: Link against the following native artifacts when linking against this static library. The order and any duplication can be significant on some platforms.

note: native-static-libs: -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil

    Finished release [optimized] target(s) in 7m 25s
++ cat /tmp/tmp.brINtLWm1Q
++ grep native-static-libs:
++ head -n 1
++ cut -d : -f 3
+ local '__linker_flags= -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil'
++ git rev-parse HEAD
+ sed -e 's;@VERSION@;b6e0b35fb49ed0fedb6a6a473b222e3b8a7d7f17;' -e 's;@PRIVATE_LIBS@; -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil;' filcrypto.pc.template
+ find -L . -type f -name filcrypto.h
+ read
+ find -L . -type f -name libfilcrypto.a
+ read
+ exit
+ rm -f /tmp/tmp.brINtLWm1Q
+ popd
~/git2/lotus_latest/extern/filecoin-ffi
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
make[1]: Leaving directory '/home/ml/git2/lotus_latest/extern/filecoin-ffi'
rm -f lotus
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.55b85f314" -tags=calibnet -o lotus ./cmd/lotus
go: downloading github.com/filecoin-project/go-fil-markets v1.1.9
go: downloading github.com/whyrusleeping/cbor-gen v0.0.0-20210219115102-f37d292932f2
go run github.com/GeertJohan/go.rice/rice append --exec lotus -i ./build
rm -f lotus-miner
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.55b85f314" -tags=calibnet -o lotus-miner ./cmd/lotus-storage-miner
go run github.com/GeertJohan/go.rice/rice append --exec lotus-miner -i ./build
rm -f lotus-worker
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.55b85f314" -tags=calibnet -o lotus-worker ./cmd/lotus-seal-worker
go run github.com/GeertJohan/go.rice/rice append --exec lotus-worker -i ./build
rm -f lotus-seed
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.55b85f314" -tags=calibnet -o lotus-seed ./cmd/lotus-seed
go run github.com/GeertJohan/go.rice/rice append --exec lotus-seed -i ./build
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ ./lotus --version
lotus version 1.5.0+calibnet+git.55b85f314
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ ls
api    CHANGELOG.md  conformance       extern   go.mod   lib             lotus        lotus-seed    markets  node       scripts      system
build  cli           Dockerfile.lotus  gen      go.sum   LICENSE-APACHE  lotus-miner  lotus-worker  metrics  paychmgr   SECURITY.md  testplans
chain  cmd           documentation     genesis  journal  LICENSE-MIT     lotuspond    Makefile      miner    README.md  storage      tools
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ ls -alh
total 460M
drwxrwxr-x 28 ml ml 4.0K 3月   8 11:17 .
drwxrwxr-x  5 ml ml 4.0K 3月   8 11:01 ..
drwxrwxr-x  7 ml ml 4.0K 3月   8 11:03 api
drwxrwxr-x  5 ml ml 4.0K 3月   8 11:15 build
drwxrwxr-x 19 ml ml 4.0K 3月   8 11:02 chain
-rw-rw-r--  1 ml ml  93K 3月   8 11:03 CHANGELOG.md
drwxrwxr-x  2 ml ml 4.0K 3月   8 11:02 .circleci
drwxrwxr-x  4 ml ml 4.0K 3月   8 11:04 cli
drwxrwxr-x 19 ml ml 4.0K 3月   8 11:02 cmd
-rw-rw-r--  1 ml ml  373 3月   8 11:02 .codecov.yml
drwxrwxr-x  3 ml ml 4.0K 3月   8 11:02 conformance
-rw-rw-r--  1 ml ml 2.2K 3月   8 11:02 Dockerfile.lotus
lrwxrwxrwx  1 ml ml   10 3月   8 11:02 .dockerignore -> .gitignore
drwxrwxr-x  4 ml ml 4.0K 3月   8 11:02 documentation
drwxrwxr-x  7 ml ml 4.0K 3月   8 11:02 extern
drwxrwxr-x  2 ml ml 4.0K 3月   8 11:02 gen
drwxrwxr-x  2 ml ml 4.0K 3月   8 11:02 genesis
drwxrwxr-x  9 ml ml 4.0K 3月   8 11:08 .git
drwxrwxr-x  4 ml ml 4.0K 3月   8 11:02 .github
-rw-rw-r--  1 ml ml  647 3月   8 11:02 .gitignore
-rw-rw-r--  1 ml ml  393 3月   8 11:02 .gitmodules
-rw-rw-r--  1 ml ml 1.6K 3月   8 11:02 .golangci.yml
-rw-rw-r--  1 ml ml 7.3K 3月   8 11:03 go.mod
-rw-rw-r--  1 ml ml 190K 3月   8 11:16 go.sum
drwxrwxr-x  2 ml ml 4.0K 3月   8 11:02 journal
drwxrwxr-x 18 ml ml 4.0K 3月   8 11:02 lib
-rw-rw-r--  1 ml ml  520 3月   8 11:02 LICENSE-APACHE
-rw-rw-r--  1 ml ml 1.1K 3月   8 11:02 LICENSE-MIT
-rwxrwxr-x  1 ml ml 124M 3月   8 11:16 lotus
-rwxrwxr-x  1 ml ml 124M 3月   8 11:16 lotus-miner
drwxrwxr-x  3 ml ml 4.0K 3月   8 11:02 lotuspond
-rwxrwxr-x  1 ml ml 105M 3月   8 11:17 lotus-seed
-rwxrwxr-x  1 ml ml 108M 3月   8 11:17 lotus-worker
-rw-rw-r--  1 ml ml 9.4K 3月   8 11:02 Makefile
drwxrwxr-x  7 ml ml 4.0K 3月   8 11:02 markets
drwxrwxr-x  2 ml ml 4.0K 3月   8 11:02 metrics
drwxrwxr-x  2 ml ml 4.0K 3月   8 11:02 miner
drwxrwxr-x  8 ml ml 4.0K 3月   8 11:02 node
drwxrwxr-x  3 ml ml 4.0K 3月   8 11:03 paychmgr
-rw-rw-r--  1 ml ml 4.3K 3月   8 11:02 README.md
drwxrwxr-x  5 ml ml 4.0K 3月   8 11:02 scripts
-rw-rw-r--  1 ml ml 1.8K 3月   8 11:02 SECURITY.md
drwxrwxr-x  4 ml ml 4.0K 3月   8 11:02 storage
drwxrwxr-x  2 ml ml 4.0K 3月   8 11:02 system
drwxrwxr-x  8 ml ml 4.0K 3月   8 11:02 testplans
drwxrwxr-x  4 ml ml 4.0K 3月   8 11:02 tools
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$ du -h -d 1 ./
264K	./documentation
20K	./metrics
236K	./lib
112K	./conformance
28K	./.circleci
28K	./miner
1.2M	./cmd
360K	./api
644K	./node
8.0K	./system
8.0K	./genesis
8.0K	./gen
36K	./.github
28K	./journal
952K	./testplans
2.1M	./chain
7.2M	./build
356K	./cli
168K	./storage
88K	./tools
122M	./.git
1.2G	./extern
124K	./scripts
204K	./paychmgr
716K	./lotuspond
156K	./markets
1.8G	./
ml@ml:~/git2/lotus_latest$ 
ml@ml:~/git2/lotus_latest$

```
