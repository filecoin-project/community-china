
```sh
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ FFI_BUILD_FROM_SOURCE=1 make clean debug 
rm -rf  build/.filecoin-install build/.update-modules  lotus lotus-miner lotus-worker lotus-shed lotus-gateway lotus-seed lotus-pond lotus-townhall lotus-fountain lotus-chainwatch lotus-bench lotus-stats lotus-pcr lotus-health lotus-wallet lotus-keygen testground
make -C extern/filecoin-ffi/ clean
make[1]: Entering directory '/home/ml/git/lotus/extern/filecoin-ffi'
make[1]: *** No rule to make target 'clean'.  Stop.
make[1]: Leaving directory '/home/ml/git/lotus/extern/filecoin-ffi'
Makefile:297: recipe for target 'clean' failed
make: [clean] Error 2 (ignored)
git submodule update --init --recursive
Submodule 'extern/filecoin-ffi' (https://github.com/filecoin-project/filecoin-ffi.git) registered for path 'extern/filecoin-ffi'
Submodule 'extern/serialization-vectors' (https://github.com/filecoin-project/serialization-vectors.git) registered for path 'extern/serialization-vectors'
Submodule 'extern/test-vectors' (https://github.com/filecoin-project/test-vectors.git) registered for path 'extern/test-vectors'
Submodule path 'extern/filecoin-ffi': checked out '62f89f108a6a8fe9ad6ed52fb7ffbf8594d7ae5c'
Submodule path 'extern/serialization-vectors': checked out '5bfb928910b01ac8b940a693af2884f7f8276211'
Submodule path 'extern/test-vectors': checked out 'd9a75a7873aee0db28b87e3970d2ea16a2f37c6a'
Submodule path 'extern/test-vectors/gen/extern/fil-blst': checked out '5f93488fc0dbfb450f2355269f18fc67010d59bb'
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
++ x86_64_uname='Linux ml 4.15.0-88-generic #88-Ubuntu SMP Tue Feb 11 20:11:34 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux'
++ '[' -n 'Linux ml 4.15.0-88-generic #88-Ubuntu SMP Tue Feb 11 20:11:34 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux' ']'
+++ cat /proc/cpuinfo
+++ head -n 1
+++ grep flags
++ __features='flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
++ feature_map=("adx:+adx" "sha_ni:+sha" "sha2:+sha2" "sse2:+sse2" "avx2:+avx2" "avx:+avx" "sse4_2:+sse4.2" "sse4_1:+sse4.1")
++ target_features=
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c adx
++ current_feature=0
++ '[' 1 = 0 ']'
++ for x in ${cpu_features_required_for_optimized_release[@]}
+++ grep -c sha_ni
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
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
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
+++ grep -c avx2
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
+++ grep -c sse4_1
+++ echo 'flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase avx2 invpcid rdseed clflushopt md_clear flush_l1d'
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
+ local __repo_sha1=62f89f108a6a8fe9ad6ed52fb7ffbf8594d7ae5c
+ local __repo_sha1_truncated=62f89f108a6a8fe9
+ echo 'building from source @ 62f89f108a6a8fe9'
building from source @ 62f89f108a6a8fe9
++ command -v cargo
+ '[' -x /home/ml/.cargo/bin/cargo ']'
++ command -v rustup
+ '[' -x /home/ml/.cargo/bin/rustup ']'
+ pushd rust
~/git/lotus/extern/filecoin-ffi/rust ~/git/lotus/extern/filecoin-ffi
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
+ __build_output_log_tmp=/tmp/tmp.mBN3OT1WGI
+ trap '{ rm -f $__build_output_log_tmp; }' EXIT
+ local '__rust_flags=--print native-static-libs -C target-feature=+sse2,+avx2,+avx,+sse4.2,+sse4.1'
+ RUSTFLAGS='--print native-static-libs -C target-feature=+sse2,+avx2,+avx,+sse4.2,+sse4.1'
+ cargo +nightly-2020-10-05 build --release --no-default-features --features pairing
+ tee /tmp/tmp.mBN3OT1WGI
   Compiling autocfg v1.0.1
   Compiling libc v0.2.82
   Compiling cfg-if v1.0.0
   Compiling proc-macro2 v1.0.24
   Compiling unicode-xid v0.2.1
   Compiling lazy_static v1.4.0
   Compiling syn v1.0.60
   Compiling version_check v0.9.2
   Compiling cc v1.0.66
   Compiling log v0.4.14
   Compiling cfg-if v0.1.10
   Compiling typenum v1.12.0
   Compiling bitflags v1.2.1
   Compiling memchr v2.3.4
   Compiling serde_derive v1.0.123
   Compiling serde v1.0.123
   Compiling getrandom v0.2.2
   Compiling scopeguard v1.1.0
   Compiling getrandom v0.1.16
   Compiling byteorder v1.4.2
   Compiling ppv-lite86 v0.2.10
   Compiling maybe-uninit v2.0.0
   Compiling ryu v1.0.5
   Compiling rustc-serialize v0.3.24
   Compiling const_fn v0.4.5
   Compiling adler v0.2.3
   Compiling pkg-config v0.3.19
   Compiling semver v0.1.20
   Compiling failure_derive v0.1.8
   Compiling either v1.6.1
   Compiling once_cell v1.5.2
   Compiling gimli v0.23.0
   Compiling rustc-demangle v0.1.18
   Compiling object v0.23.0
   Compiling byte-tools v0.3.1
   Compiling arrayvec v0.5.2
   Compiling rayon-core v1.9.0
   Compiling cl-sys v0.4.2
   Compiling itoa v0.4.7
   Compiling opaque-debug v0.2.3
   Compiling fake-simd v0.1.2
   Compiling futures v0.1.30
   Compiling subtle v2.4.0
   Compiling serde_json v1.0.61
   Compiling arrayref v0.3.6
   Compiling nodrop v0.1.14
   Compiling constant_time_eq v0.1.5
   Compiling futures-core v0.3.12
   Compiling slab v0.4.2
   Compiling fnv v1.0.7
   Compiling bytes v0.5.6
   Compiling pin-project-internal v0.4.27
   Compiling remove_dir_all v0.5.3
   Compiling lexical-core v0.7.4
   Compiling regex-syntax v0.6.22
   Compiling static_assertions v1.1.0
   Compiling bit-vec v0.6.3
   Compiling pin-project-lite v0.1.11
   Compiling opaque-debug v0.3.0
   Compiling unicode-width v0.1.8
   Compiling anyhow v1.0.38
   Compiling pin-project-lite v0.2.4
   Compiling matches v0.1.8
   Compiling rustc-hash v1.1.0
   Compiling cpuid-bool v0.1.2
   Compiling bytes v1.0.1
   Compiling byteorder v0.5.3
   Compiling openssl v0.10.32
   Compiling tinyvec_macros v0.1.0
   Compiling foreign-types-shared v0.1.1
   Compiling futures-io v0.3.12
   Compiling ansi_term v0.11.0
   Compiling percent-encoding v2.1.0
   Compiling httparse v1.3.4
   Compiling native-tls v0.2.7
   Compiling futures-sink v0.3.12
   Compiling hashbrown v0.9.1
   Compiling block-padding v0.2.1
   Compiling pin-utils v0.1.0
   Compiling try-lock v0.2.3
   Compiling proc-macro2 v0.4.30
   Compiling openssl-probe v0.1.2
   Compiling hex v0.4.2
   Compiling httpdate v0.3.2
   Compiling glob v0.3.0
   Compiling unicode-xid v0.1.0
   Compiling bitflags v0.4.0
   Compiling difference v2.0.0
   Compiling tower-service v0.3.1
   Compiling crc32fast v1.2.1
   Compiling encoding_rs v0.8.26
   Compiling unicode-segmentation v1.7.1
   Compiling yansi v0.5.0
   Compiling syn v0.15.44
   Compiling strsim v0.8.0
   Compiling vec_map v0.8.2
   Compiling bitintr v0.3.0
   Compiling byte-slice-cast v1.0.0
   Compiling storage-proofs v5.4.0
   Compiling cbindgen v0.14.0
   Compiling mime v0.3.16
   Compiling number_prefix v0.3.0
   Compiling radium v0.3.0
   Compiling zeroize v0.9.3
   Compiling ipnet v2.3.0
   Compiling base64 v0.13.0
   Compiling termcolor v1.1.2
   Compiling humansize v1.1.0
   Compiling tracing-core v0.1.17
   Compiling num-traits v0.2.14
   Compiling num-integer v0.1.44
   Compiling crossbeam-utils v0.8.1
   Compiling num-bigint v0.2.6
   Compiling crossbeam-utils v0.7.2
   Compiling miniz_oxide v0.4.3
   Compiling memoffset v0.6.1
   Compiling num-iter v0.1.42
   Compiling memoffset v0.5.6
   Compiling crossbeam-epoch v0.8.2
   Compiling rayon v1.5.0
   Compiling indexmap v1.6.1
   Compiling generic-array v0.14.4
   Compiling unicase v2.6.0
   Compiling nom v5.1.2
   Compiling proc-macro-error-attr v1.0.4
   Compiling proc-macro-error v1.0.4
   Compiling openssl-src v111.13.0+1.1.1i
   Compiling fff v0.2.3
   Compiling neptune-triton v2.1.0
   Compiling sha2-asm v0.5.5
   Compiling rustc_version v0.1.7
   Compiling itertools v0.8.2
   Compiling itertools v0.9.0
   Compiling thread_local v1.1.2
   Compiling futures-task v0.3.12
   Compiling hwloc v0.3.0
   Compiling block-padding v0.1.5
   Compiling addr2line v0.14.1
   Compiling blake2b_simd v0.5.11
   Compiling blake2s_simd v0.5.11
   Compiling futures-channel v0.3.12
   Compiling textwrap v0.11.0
   Compiling unicode-bidi v0.3.4
   Compiling http v0.2.3
   Compiling tinyvec v1.1.1
   Compiling foreign-types v0.3.2
   Compiling form_urlencoded v1.0.0
   Compiling blst v0.2.0
   Compiling pretty_assertions v0.6.1
   Compiling heck v0.3.2
   Compiling bitvec v0.17.4
   Compiling openssl-sys v0.9.60
   Compiling fil-ocl-core v0.11.3
   Compiling http-body v0.3.1
   Compiling unicode-normalization v0.1.16
   Compiling quote v1.0.8
   Compiling num_cpus v1.13.0
   Compiling rand v0.4.6
   Compiling dirs-sys v0.3.5
   Compiling net2 v0.2.37
   Compiling memmap v0.7.0
   Compiling iovec v0.1.4
   Compiling fs2 v0.4.3
   Compiling time v0.1.43
   Compiling positioned-io v0.2.2
   Compiling terminal_size v0.1.16
   Compiling errno v0.1.8
   Compiling socket2 v0.3.19
   Compiling atty v0.2.14
   Compiling mapr v0.8.0
   Compiling filetime v0.2.14
   Compiling xattr v0.2.2
   Compiling tracing v0.1.22
   Compiling want v0.3.0
   Compiling aho-corasick v0.7.15
   Compiling futures-util v0.3.12
   Compiling generic-array v0.12.3
   Compiling quote v0.6.13
   Compiling idna v0.2.0
   Compiling threadpool v1.8.1
   Compiling tempdir v0.3.7
   Compiling rand_core v0.5.1
   Compiling dirs v2.0.2
   Compiling rand_core v0.6.1
   Compiling mio v0.6.23
   Compiling clap v2.33.3
   Compiling tar v0.4.32
   Compiling num-complex v0.1.43
   Compiling num-traits v0.1.43
   Compiling crossbeam-channel v0.5.0
   Compiling crossbeam-queue v0.3.1
   Compiling crossbeam-epoch v0.9.1
   Compiling crossbeam-channel v0.4.4
   Compiling crossbeam-queue v0.2.3
   Compiling backtrace v0.3.56
   Compiling flate2 v1.0.19
   Compiling mime_guess v2.0.3
   Compiling regex v1.4.3
   Compiling digest v0.9.0
   Compiling crypto-mac v0.10.0
   Compiling cipher v0.2.5
   Compiling block-buffer v0.9.0
   Compiling block-buffer v0.7.3
   Compiling digest v0.8.1
   Compiling url v2.2.0
   Compiling rand_chacha v0.2.2
   Compiling rand_xorshift v0.2.0
   Compiling rand_chacha v0.3.0
   Compiling tokio v0.2.24
   Compiling synstructure v0.12.4
   Compiling thiserror-impl v1.0.23
   Compiling pin-project-internal v1.0.4
   Compiling num-bigint v0.1.44
   Compiling chrono v0.4.19
   Compiling enum_primitive v0.1.1
   Compiling pbr v1.0.4
   Compiling crossbeam-deque v0.8.0
   Compiling crossbeam-deque v0.7.3
   Compiling console v0.13.0
   Compiling console v0.14.0
   Compiling hmac v0.10.1
   Compiling aes-soft v0.6.4
   Compiling block-modes v0.7.0
   Compiling sha2 v0.9.2
   Compiling sha2raw v2.0.0
   Compiling sha2 v0.8.2
   Compiling drop_struct_macro_derive v0.4.0
   Compiling env_proxy v0.4.1
   Compiling rand v0.7.3
   Compiling rand v0.8.3
   Compiling structopt-derive v0.4.14
   Compiling tokio-util v0.3.1
   Compiling thiserror v1.0.23
   Compiling pin-project v0.4.27
   Compiling pin-project v1.0.4
   Compiling num-rational v0.1.42
   Compiling flexi_logger v0.14.8
   Compiling simplelog v0.8.0
   Compiling crossbeam v0.8.0
   Compiling fff_derive v0.2.2
   Compiling crossbeam v0.7.3
   Compiling indicatif v0.15.0
   Compiling hkdf v0.10.0
   Compiling aes v0.6.0
   Compiling ffi-toolkit v0.4.0
   Compiling tempfile v3.2.0
   Compiling failure v0.1.8
   Compiling structopt v0.3.21
   Compiling tracing-futures v0.2.4
   Compiling num v0.1.42
   Compiling fil_logger v0.1.2
   Compiling toml v0.5.8
   Compiling bincode v1.3.1
   Compiling serde_urlencoded v0.7.0
   Compiling qutex v0.2.3
   Compiling dialoguer v0.7.1
   Compiling h2 v0.2.7
   Compiling ocl-core-vector v0.1.0
   Compiling config v0.10.1
   Compiling groupy v0.3.1
   Compiling ff-cl-gen v0.2.0
   Compiling merkletree v0.21.0
   Compiling hyper v0.13.9
   Compiling filcrypto v0.7.5 (/home/ml/git/lotus/extern/filecoin-ffi/rust)
   Compiling paired v0.21.0
   Compiling blstrs v0.1.3
   Compiling tokio-tls v0.3.1
   Compiling fil-ocl v0.19.4
   Compiling bls-signatures v0.7.1
   Compiling hyper-tls v0.4.3
   Compiling rust-gpu-tools v0.2.2
   Compiling rust-gpu-tools v0.3.0
   Compiling reqwest v0.10.10
   Compiling bellperson v0.12.3
   Compiling neptune v2.6.0
   Compiling phase21 v0.11.0
   Compiling storage-proofs-core v5.4.0
   Compiling storage-proofs-porep v5.4.0
   Compiling storage-proofs-post v5.4.0
   Compiling filecoin-proofs v5.4.0
   Compiling filecoin-proofs-api v5.4.1
note: Link against the following native artifacts when linking against this static library. The order and any duplication can be significant on some platforms.

note: native-static-libs: -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil

    Finished release [optimized] target(s) in 10m 22s
++ cat /tmp/tmp.mBN3OT1WGI
++ grep native-static-libs:
++ head -n 1
++ cut -d : -f 3
+ local '__linker_flags= -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil'
++ git rev-parse HEAD
+ sed -e 's;@VERSION@;62f89f108a6a8fe9ad6ed52fb7ffbf8594d7ae5c;' -e 's;@PRIVATE_LIBS@; -lhwloc -lOpenCL -lOpenCL -lOpenCL -lgcc_s -lc -lm -lrt -lpthread -lutil -ldl -lutil;' filcrypto.pc.template
+ find -L . -type f -name filcrypto.h
+ read
+ find -L . -type f -name libfilcrypto.a
+ read
+ exit
+ rm -f /tmp/tmp.mBN3OT1WGI
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
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.7e55c44d4" -tags=debug -o lotus ./cmd/lotus
go: downloading github.com/filecoin-project/go-fil-markets v1.1.2
go: downloading github.com/filecoin-project/specs-actors/v3 v3.0.1-0.20210128055125-ab0632b1c8fa
go run github.com/GeertJohan/go.rice/rice append --exec lotus -i ./build
rm -f lotus-miner
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.7e55c44d4" -tags=debug -o lotus-miner ./cmd/lotus-storage-miner
go run github.com/GeertJohan/go.rice/rice append --exec lotus-miner -i ./build
rm -f lotus-worker
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.7e55c44d4" -tags=debug -o lotus-worker ./cmd/lotus-seal-worker
go run github.com/GeertJohan/go.rice/rice append --exec lotus-worker -i ./build
rm -f lotus-seed
go build  -ldflags="-X=github.com/filecoin-project/lotus/build.CurrentCommit=+git.7e55c44d4" -tags=debug -o lotus-seed ./cmd/lotus-seed
go run github.com/GeertJohan/go.rice/rice append --exec lotus-seed -i ./build
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ ls -alh
total 425M
drwxr-xr-x 28 ml ml 4.0K Feb  7 22:11 .
drwxr-xr-x  3 ml ml 4.0K Feb  7 10:56 ..
drwxr-xr-x  7 ml ml 4.0K Feb  7 21:55 api
drwxr-xr-x  5 ml ml 4.0K Feb  7 22:09 build
drwxr-xr-x 19 ml ml 4.0K Feb  7 21:55 chain
-rw-r--r--  1 ml ml  81K Feb  7 11:20 CHANGELOG.md
drwxr-xr-x  2 ml ml 4.0K Feb  7 11:20 .circleci
drwxr-xr-x  4 ml ml 4.0K Feb  7 21:55 cli
drwxr-xr-x 19 ml ml 4.0K Feb  7 11:20 cmd
-rw-r--r--  1 ml ml  373 Feb  7 11:20 .codecov.yml
drwxr-xr-x  3 ml ml 4.0K Feb  7 11:20 conformance
-rw-r--r--  1 ml ml 2.2K Feb  7 11:20 Dockerfile.lotus
lrwxrwxrwx  1 ml ml   10 Feb  7 11:20 .dockerignore -> .gitignore
drwxr-xr-x  4 ml ml 4.0K Feb  7 11:20 documentation
drwxr-xr-x  7 ml ml 4.0K Feb  7 21:59 extern
drwxr-xr-x  2 ml ml 4.0K Feb  7 11:20 gen
drwxr-xr-x  2 ml ml 4.0K Feb  7 11:20 genesis
drwxr-xr-x  9 ml ml 4.0K Feb  7 21:59 .git
drwxr-xr-x  4 ml ml 4.0K Feb  7 11:20 .github
-rw-r--r--  1 ml ml  647 Feb  7 11:20 .gitignore
-rw-r--r--  1 ml ml  393 Feb  7 11:20 .gitmodules
-rw-r--r--  1 ml ml 1.6K Feb  7 11:20 .golangci.yml
-rw-r--r--  1 ml ml 7.3K Feb  7 21:55 go.mod
-rw-r--r--  1 ml ml 192K Feb  7 21:55 go.sum
drwxr-xr-x  2 ml ml 4.0K Feb  7 11:20 journal
drwxr-xr-x 18 ml ml 4.0K Feb  7 11:20 lib
-rw-r--r--  1 ml ml  520 Feb  7 11:20 LICENSE-APACHE
-rw-r--r--  1 ml ml 1.1K Feb  7 11:20 LICENSE-MIT
-rwxr-xr-x  1 ml ml 119M Feb  7 22:10 lotus
-rwxr-xr-x  1 ml ml 119M Feb  7 22:10 lotus-miner
drwxr-xr-x  3 ml ml 4.0K Feb  7 11:20 lotuspond
-rwxr-xr-x  1 ml ml  86M Feb  7 22:11 lotus-seed
-rwxr-xr-x  1 ml ml 102M Feb  7 22:11 lotus-worker
-rw-r--r--  1 ml ml 9.0K Feb  7 21:55 Makefile
drwxr-xr-x  7 ml ml 4.0K Feb  7 11:20 markets
drwxr-xr-x  2 ml ml 4.0K Feb  7 11:20 metrics
drwxr-xr-x  2 ml ml 4.0K Feb  7 21:55 miner
drwxr-xr-x  8 ml ml 4.0K Feb  7 21:55 node
drwxr-xr-x  3 ml ml 4.0K Feb  7 11:20 paychmgr
-rw-r--r--  1 ml ml 4.3K Feb  7 11:20 README.md
drwxr-xr-x  5 ml ml 4.0K Feb  7 11:20 scripts
-rw-r--r--  1 ml ml 1.8K Feb  7 11:20 SECURITY.md
drwxr-xr-x  4 ml ml 4.0K Feb  7 21:55 storage
drwxr-xr-x  2 ml ml 4.0K Feb  7 11:20 system
drwxr-xr-x  8 ml ml 4.0K Feb  7 11:20 testplans
drwxr-xr-x  4 ml ml 4.0K Feb  7 11:20 tools
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ du -h -d 1 ./
88K	./tools
140K	./markets
2.1M	./chain
236K	./lib
712K	./lotuspond
28K	./miner
36K	./.github
356K	./cli
1.2G	./extern
20K	./metrics
28K	./journal
112K	./conformance
3.1M	./build
204K	./paychmgr
1.2M	./cmd
8.0K	./system
8.0K	./gen
640K	./node
260K	./documentation
103M	./.git
348K	./api
28K	./.circleci
8.0K	./genesis
164K	./storage
124K	./scripts
940K	./testplans
1.7G	./
ml@ml:~/git/lotus$ 
ml@ml:~/git/lotus$ 

```