```sh
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ git status 
On branch master
Your branch is up to date with 'origin/master'.

nothing to commit, working tree clean
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ du -h -d 1 ./
260K	./documentation
20K	./metrics
236K	./lib
112K	./conformance
28K	./.circleci
28K	./miner
1.2M	./cmd
348K	./api
640K	./node
8.0K	./system
8.0K	./genesis
8.0K	./gen
36K	./.github
28K	./journal
936K	./testplans
2.1M	./chain
5.6M	./build
356K	./cli
168K	./storage
88K	./tools
190M	./.git
45M	./extern
124K	./scripts
204K	./paychmgr
716K	./lotuspond
140K	./markets
247M	./
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ du -h -d 1 ./extern/
43M	./extern/test-vectors
44K	./extern/serialization-vectors
780K	./extern/filecoin-ffi
572K	./extern/sector-storage
268K	./extern/storage-sealing
45M	./extern/
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ git checkout v1.4.1
M	extern/filecoin-ffi
Note: switching to 'v1.4.1'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD is now at ebaa721e4 Merge pull request #5390 from filecoin-project/asr/changelog
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ git status 
HEAD detached at v1.4.1
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   extern/filecoin-ffi (new commits)

no changes added to commit (use "git add" and/or "git commit -a")
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ FFI_BUILD_FROM_SOURCE=1 CGO_CFLAGS="-D__BLST_PORTABLE__" make clean all lotus-seed 
rm -rf  build/.filecoin-install build/.update-modules  lotus lotus-miner lotus-worker lotus-shed lotus-gateway lotus-seed lotus-pond lotus-townhall lotus-fountain lotus-chainwatch lotus-bench lotus-stats lotus-pcr lotus-health lotus-wallet lotus-keygen testground
make -C extern/filecoin-ffi/ clean
make[1]: Entering directory '/home/ml/git/lotus/extern/filecoin-ffi'
rm -rf filcrypto.h filcrypto.pc libfilcrypto.a .install-filcrypto
rm -f ./runner
cd rust && cargo clean && cd ..
make[1]: Leaving directory '/home/ml/git/lotus/extern/filecoin-ffi'
git submodule update --init --recursive
Submodule path 'extern/blst': checked out '1cbb16ed9580dcd3e9593b71221fcf2a048faaef'
Submodule path 'extern/filecoin-ffi': checked out '1d9cb3e8ff53f51f9318fc57e5d00bc79bdc0128'
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
++ x86_64_uname='Linux ml 5.8.0-41-generic #46~20.04.1-Ubuntu SMP Mon Jan 18 17:52:23 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux'
++ '[' -n 'Linux ml 5.8.0-41-generic #46~20.04.1-Ubuntu SMP Mon Jan 18 17:52:23 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux' ']'
+++ cat /proc/cpuinfo
+++ grep flags
+++ head -n 1
++ __features='flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
++ feature_map=("adx:+adx" "sha_ni:+sha" "sha2:+sha2" "sse2:+sse2" "avx2:+avx2" "avx:+avx" "sse4_2:+sse4.2" "sse4_1:+sse4.1")
++ target_features=
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
+++ grep -c adx
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
+++ grep -c sha_ni
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
+++ grep -c sha2
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
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
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
+++ grep -c avx2
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
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
++ '[' -z +sse2 ']'
++ target_features=+sse2,+avx
++ for feature in "${feature_map[@]}"
++ key=sse4_2
++ '[' sse4_2 == avx ']'
++ for feature in "${feature_map[@]}"
++ key=sse4_1
++ '[' sse4_1 == avx ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
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
++ '[' -z +sse2,+avx ']'
++ target_features=+sse2,+avx,+sse4.2
++ for feature in "${feature_map[@]}"
++ key=sse4_1
++ '[' sse4_1 == sse4_2 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic popcnt aes xsave avx rdrand hypervisor lahf_lm pti fsgsbase flush_l1d'
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
++ '[' -z +sse2,+avx,+sse4.2 ']'
++ target_features=+sse2,+avx,+sse4.2,+sse4.1
++ echo +sse2,+avx,+sse4.2,+sse4.1
+ local __release_flags=+sse2,+avx,+sse4.2,+sse4.1
+ '[' 1 '!=' 1 ']'
+ echo '[install-filcrypto/main] building libfilcrypto from local sources (dir = rust)'
[install-filcrypto/main] building libfilcrypto from local sources (dir = rust)
+ build_from_source filcrypto rust +sse2,+avx,+sse4.2,+sse4.1
+ local __library_name=filcrypto
+ local __rust_sources_path=rust
+ local __release_flags=+sse2,+avx,+sse4.2,+sse4.1
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
cargo 1.48.0-nightly (75615f8e6 2020-09-29)
+ '[' '' == 1 ']'
+ additional_flags='--no-default-features --features pairing'
+ '[' -n +sse2,+avx,+sse4.2,+sse4.1 ']'
++ cat rust-toolchain
+ RUSTFLAGS='-C target-feature=+sse2,+avx,+sse4.2,+sse4.1'
+ ./scripts/build-release.sh filcrypto 'nightly-2020-10-05 ' '--no-default-features --features pairing'
+ main filcrypto 'nightly-2020-10-05 ' '--no-default-features --features pairing'
+ [[ -z filcrypto ]]
+ [[ -z nightly-2020-10-05  ]]
++ mktemp
+ __build_output_log_tmp=/tmp/tmp.R0AGfrXa1r
+ trap '{ rm -f $__build_output_log_tmp; }' EXIT
+ local '__rust_flags=--print native-static-libs -C target-feature=+sse2,+avx,+sse4.2,+sse4.1'
+ RUSTFLAGS='--print native-static-libs -C target-feature=+sse2,+avx,+sse4.2,+sse4.1'
+ cargo +nightly-2020-10-05 build --release --no-default-features --features pairing
+ tee /tmp/tmp.R0AGfrXa1r
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
   Compiling rustc-serialize v0.3.24
   Compiling ryu v1.0.5
   Compiling pkg-config v0.3.19
   Compiling arrayvec v0.5.2
   Compiling either v1.6.1
   Compiling adler v0.2.3
   Compiling byte-tools v0.3.1
   Compiling semver v0.1.20
   Compiling arrayref v0.3.6
   Compiling rayon-core v1.9.0
   Compiling gimli v0.23.0
   Compiling failure_derive v0.1.8
   Compiling fake-simd v0.1.2
   Compiling cl-sys v0.4.2
   Compiling rustc-demangle v0.1.18
   Compiling constant_time_eq v0.1.5
   Compiling itoa v0.4.6
   Compiling opaque-debug v0.2.3
   Compiling object v0.22.0
   Compiling subtle v2.3.0
   Compiling serde_json v1.0.59
   Compiling futures v0.1.30
   Compiling getrandom v0.2.0
   Compiling nodrop v0.1.14
   Compiling futures-core v0.3.7
   Compiling fnv v1.0.7
   Compiling bytes v0.5.6
   Compiling slab v0.4.2
   Compiling pin-project-lite v0.1.11
   Compiling pin-project-internal v0.4.27
   Compiling remove_dir_all v0.5.3
   Compiling lexical-core v0.7.4
   Compiling matches v0.1.8
   Compiling bit-vec v0.6.2
   Compiling anyhow v1.0.34
   Compiling opaque-debug v0.3.0
   Compiling static_assertions v1.1.0
   Compiling openssl v0.10.30
   Compiling regex-syntax v0.6.21
   Compiling tinyvec v0.3.4
   Compiling once_cell v1.4.1
   Compiling byteorder v0.5.3
   Compiling unicode-width v0.1.8
   Compiling foreign-types-shared v0.1.1
   Compiling cpuid-bool v0.1.2
   Compiling native-tls v0.2.5
   Compiling semver-parser v0.7.0
   Compiling hashbrown v0.9.1
   Compiling futures-sink v0.3.7
   Compiling ansi_term v0.11.0
   Compiling block-padding v0.2.1
   Compiling futures-io v0.3.7
   Compiling httparse v1.3.4
   Compiling pin-utils v0.1.0
   Compiling percent-encoding v2.1.0
   Compiling hex v0.4.2
   Compiling openssl-probe v0.1.2
   Compiling try-lock v0.2.3
   Compiling proc-macro2 v0.4.30
   Compiling difference v2.0.0
   Compiling tower-service v0.3.0
   Compiling encoding_rs v0.8.26
   Compiling httpdate v0.3.2
   Compiling subtle v1.0.0
   Compiling unicode-xid v0.1.0
   Compiling bitflags v0.4.0
   Compiling crc32fast v1.2.1
   Compiling unicode-segmentation v1.6.0
   Compiling cbindgen v0.14.0
   Compiling vec_map v0.8.2
   Compiling yansi v0.5.0
   Compiling strsim v0.8.0
   Compiling storage-proofs v5.4.0
   Compiling mime v0.3.16
   Compiling bitintr v0.3.0
   Compiling dtoa v0.4.6
   Compiling glob v0.3.0
   Compiling syn v0.15.44
   Compiling byte-slice-cast v1.0.0
   Compiling number_prefix v0.3.0
   Compiling ipnet v2.3.0
   Compiling termcolor v1.1.0
   Compiling radium v0.3.0
   Compiling zeroize v0.9.3
   Compiling base64 v0.12.3
   Compiling humansize v1.1.0
   Compiling lazy_static v1.4.0
   Compiling num-traits v0.2.14
   Compiling num-integer v0.1.44
   Compiling memoffset v0.5.6
   Compiling crossbeam-utils v0.8.0
   Compiling num-bigint v0.2.6
   Compiling crossbeam-utils v0.7.2
   Compiling miniz_oxide v0.4.3
   Compiling num-iter v0.1.42
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
   Compiling unicode-bidi v0.3.4
   Compiling http v0.2.1
   Compiling unicode-normalization v0.1.13
   Compiling futures-task v0.3.7
   Compiling textwrap v0.11.0
   Compiling foreign-types v0.3.2
   Compiling semver v0.9.0
   Compiling form_urlencoded v1.0.0
   Compiling pretty_assertions v0.6.1
   Compiling heck v0.3.1
   Compiling bitvec v0.17.4
   Compiling thread_local v1.0.1
   Compiling tracing-core v0.1.17
   Compiling openssl-sys v0.9.58
   Compiling fil-ocl-core v0.11.3
   Compiling idna v0.2.0
   Compiling http-body v0.3.1
   Compiling rustc_version v0.2.3
   Compiling quote v1.0.7
   Compiling num_cpus v1.13.0
   Compiling rand v0.4.6
   Compiling dirs-sys v0.3.5
   Compiling iovec v0.1.4
   Compiling net2 v0.2.35
   Compiling memmap v0.7.0
   Compiling fs2 v0.4.3
   Compiling time v0.1.44
   Compiling positioned-io v0.2.2
   Compiling errno v0.1.8
   Compiling atty v0.2.14
   Compiling socket2 v0.3.15
   Compiling terminal_size v0.1.13
   Compiling mapr v0.8.0
   Compiling filetime v0.2.13
   Compiling xattr v0.2.2
   Compiling tracing v0.1.21
   Compiling want v0.3.0
   Compiling aho-corasick v0.7.15
   Compiling generic-array v0.12.3
   Compiling raw-cpuid v7.0.3
   Compiling url v2.2.0
   Compiling quote v0.6.13
   Compiling num-complex v0.1.43
   Compiling num-traits v0.1.43
   Compiling rand_core v0.5.1
   Compiling tempdir v0.3.7
   Compiling dirs v2.0.2
   Compiling mio v0.6.22
   Compiling ahash v0.5.8
   Compiling clap v2.33.3
   Compiling tar v0.4.30
   Compiling crossbeam-channel v0.4.4
   Compiling crossbeam-queue v0.2.3
   Compiling backtrace v0.3.54
   Compiling flate2 v1.0.19
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
   Compiling env_proxy v0.4.1
   Compiling num-bigint v0.1.44
   Compiling chrono v0.4.19
   Compiling enum_primitive v0.1.1
   Compiling rand_chacha v0.2.2
   Compiling rand_xorshift v0.2.0
   Compiling synstructure v0.12.4
   Compiling tokio v0.2.22
   Compiling thiserror-impl v1.0.22
   Compiling pin-project-internal v1.0.1
   Compiling pbr v1.0.3
   Compiling crossbeam-deque v0.7.3
   Compiling hmac v0.10.1
   Compiling aes-soft v0.6.3
   Compiling block-modes v0.7.0
   Compiling sha2 v0.9.2
   Compiling console v0.13.0
   Compiling sha2 v0.8.2
   Compiling sha2raw v2.0.0
   Compiling hmac v0.7.1
   Compiling crossbeam-deque v0.8.0
   Compiling drop_struct_macro_derive v0.4.0
   Compiling num-rational v0.1.42
   Compiling flexi_logger v0.14.8
   Compiling simplelog v0.8.0
   Compiling fff_derive v0.2.2
   Compiling rand v0.7.3
   Compiling structopt-derive v0.4.13
   Compiling tokio-util v0.3.1
   Compiling thiserror v1.0.22
   Compiling pin-project v0.4.27
   Compiling pin-project v1.0.1
   Compiling crossbeam v0.7.3
   Compiling hkdf v0.10.0
   Compiling aes v0.6.0
   Compiling indicatif v0.15.0
   Compiling hkdf v0.8.0
   Compiling crossbeam v0.8.0
   Compiling num v0.1.42
   Compiling sha2ni v0.8.5
   Compiling ffi-toolkit v0.4.0
   Compiling fil_logger v0.1.2
   Compiling tempfile v3.1.0
   Compiling structopt v0.3.20
   Compiling failure v0.1.8
   Compiling tracing-futures v0.2.4
   Compiling futures-util v0.3.7
   Compiling qutex v0.2.3
   Compiling toml v0.5.7
   Compiling bincode v1.3.1
   Compiling serde_urlencoded v0.6.1
   Compiling ocl-core-vector v0.1.0
   Compiling groupy v0.3.1
   Compiling ff-cl-gen v0.2.0
   Compiling dialoguer v0.7.1
   Compiling config v0.10.1
   Compiling h2 v0.2.7
   Compiling paired v0.21.0
   Compiling paired v0.20.1
   Compiling merkletree v0.21.0
   Compiling hyper v0.13.9
   Compiling bls-signatures v0.6.1
   Compiling filcrypto v0.7.5 (/home/ml/git/lotus/extern/filecoin-ffi/rust)
   Compiling fil-ocl v0.19.4
   Compiling tokio-tls v0.3.1
   Compiling hyper-tls v0.4.3
   Compiling reqwest v0.10.8
   Compiling rust-gpu-tools v0.2.1
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

    Finished release [optimized] target(s) in 29m 06s
++ cat /tmp/tmp.R0AGfrXa1r
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
+ rm -f /tmp/tmp.R0AGfrXa1r
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
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721e4.dirty" -o lotus ./cmd/lotus
go: downloading github.com/filecoin-project/go-data-transfer v1.2.3
go: downloading github.com/filecoin-project/specs-actors/v2 v2.3.3
go: downloading github.com/filecoin-project/go-fil-markets v1.0.10
go: downloading github.com/ipfs/go-graphsync v0.5.1
go: downloading github.com/raulk/go-watchdog v0.0.1
go run github.com/GeertJohan/go.rice/rice append --exec lotus -i ./build
rm -f lotus-miner
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721e4.dirty" -o lotus-miner ./cmd/lotus-storage-miner
go run github.com/GeertJohan/go.rice/rice append --exec lotus-miner -i ./build
rm -f lotus-worker
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721e4.dirty" -o lotus-worker ./cmd/lotus-seal-worker
go run github.com/GeertJohan/go.rice/rice append --exec lotus-worker -i ./build
Caution: you have an existing lotus binary in your PATH. This may cause problems if you don't run 'sudo make install'
rm -f lotus-seed
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.ebaa721e4.dirty" -o lotus-seed ./cmd/lotus-seed
go run github.com/GeertJohan/go.rice/rice append --exec lotus-seed -i ./build
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ ls -al
total 420452
drwxrwxr-x 28 ml ml      4096 2月  20 21:31 .
drwxrwxr-x  3 ml ml      4096 2月   3 23:23 ..
drwxrwxr-x  7 ml ml      4096 2月  20 20:58 api
drwxrwxr-x  5 ml ml      4096 2月  20 21:28 build
drwxrwxr-x 19 ml ml      4096 2月  20 20:58 chain
-rw-rw-r--  1 ml ml     82505 2月   3 23:30 CHANGELOG.md
drwxrwxr-x  2 ml ml      4096 2月  20 20:58 .circleci
drwxrwxr-x  4 ml ml      4096 2月  20 20:58 cli
drwxrwxr-x 19 ml ml      4096 2月   3 23:24 cmd
-rw-rw-r--  1 ml ml       373 2月   3 23:30 .codecov.yml
drwxrwxr-x  3 ml ml      4096 2月   3 23:30 conformance
lrwxrwxrwx  1 ml ml        10 2月   3 23:24 .dockerignore -> .gitignore
drwxrwxr-x  4 ml ml      4096 2月   3 23:24 documentation
drwxrwxr-x  8 ml ml      4096 2月  20 20:58 extern
drwxrwxr-x  2 ml ml      4096 2月   3 23:24 gen
drwxrwxr-x  2 ml ml      4096 2月   3 23:24 genesis
drwxrwxr-x  9 ml ml      4096 2月  20 20:59 .git
drwxrwxr-x  4 ml ml      4096 2月   3 23:24 .github
-rw-rw-r--  1 ml ml       647 2月   3 23:30 .gitignore
-rw-rw-r--  1 ml ml       488 2月  20 20:58 .gitmodules
-rw-rw-r--  1 ml ml      1626 2月   3 23:24 .golangci.yml
-rw-rw-r--  1 ml ml      7498 2月  20 20:58 go.mod
-rw-rw-r--  1 ml ml    194024 2月  20 20:58 go.sum
drwxrwxr-x  2 ml ml      4096 2月   3 23:24 journal
drwxrwxr-x 18 ml ml      4096 2月   3 23:30 lib
-rw-rw-r--  1 ml ml       520 2月   3 23:24 LICENSE-APACHE
-rw-rw-r--  1 ml ml      1046 2月   3 23:24 LICENSE-MIT
-rwxrwxr-x  1 ml ml 120088044 2月  20 21:29 lotus
-rwxrwxr-x  1 ml ml 119776508 2月  20 21:30 lotus-miner
drwxrwxr-x  3 ml ml      4096 2月   3 23:24 lotuspond
-rwxrwxr-x  1 ml ml  86962244 2月  20 21:31 lotus-seed
-rwxrwxr-x  1 ml ml 103250988 2月  20 21:30 lotus-worker
-rw-rw-r--  1 ml ml      9216 2月  20 20:58 Makefile
drwxrwxr-x  7 ml ml      4096 2月   3 23:24 markets
drwxrwxr-x  2 ml ml      4096 2月   3 23:30 metrics
drwxrwxr-x  2 ml ml      4096 2月   3 23:30 miner
drwxrwxr-x  8 ml ml      4096 2月  20 20:58 node
drwxrwxr-x  3 ml ml      4096 2月   3 23:24 paychmgr
-rw-rw-r--  1 ml ml      4317 2月   3 23:30 README.md
drwxrwxr-x  5 ml ml      4096 2月   3 23:30 scripts
-rw-rw-r--  1 ml ml      1814 2月   3 23:30 SECURITY.md
drwxrwxr-x  4 ml ml      4096 2月  20 20:58 storage
drwxrwxr-x  2 ml ml      4096 2月   3 23:30 system
drwxrwxr-x  8 ml ml      4096 2月   3 23:30 testplans
drwxrwxr-x  4 ml ml      4096 2月   3 23:24 tools
ml@ml:~/git/lotus$ ls
api    CHANGELOG.md  conformance    gen      go.sum   LICENSE-APACHE  lotus-miner  lotus-worker  metrics  paychmgr   SECURITY.md  testplans
build  cli           documentation  genesis  journal  LICENSE-MIT     lotuspond    Makefile      miner    README.md  storage      tools
chain  cmd           extern         go.mod   lib      lotus           lotus-seed   markets       node     scripts    system
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 

```
