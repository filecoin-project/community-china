
```sh

ml@ml:~$ ./git/lotus/lotus-miner run
2021-03-13T10:59:29.029+0800	INFO	main	lotus-storage-miner/run.go:95	Checking full node sync status
Worker: 86; Base: 10559; Target: 10560 (diff: 1)
State: complete; Current Epoch: 10560; Todo: 0

Done!
2021-03-13T10:59:29.060+0800	INFO	modules	modules/core.go:63	memory limits initialized	{"max_mem_heap": 0, "total_system_mem": 8363663360, "effective_mem_limit": 8363663360}
2021-03-13T10:59:29.063+0800	INFO	modules	modules/core.go:94	max heap size not provided; memory watchdog will apply total system memory constraint: 8363663360 bytes
2021-03-13T10:59:29.064+0800	INFO	watchdog	go-watchdog@v0.0.1/watchdog.go:220	watchdog after GC
2021-03-13T10:59:29.064+0800	INFO	watchdog	go-watchdog@v0.0.1/watermarks.go:63	initialized watermark watchdog policy; watermarks: [0.5 0.6 0.7 0.85 0.9 0.925 0.95]; emergency watermark: 0.950000, thresholds: [4181831680 5018198016 5854564352 7109113856 7527297024 7736388608 7945480192]; silence period: 0s
2021-03-13T10:59:29.107+0800	INFO	badger	v2@v2.2007.2/levels.go:183	All 0 tables opened in 0s

2021-03-13T10:59:29.118+0800	INFO	badger	v2@v2.2007.2/value.go:1158	Replaying file id: 0 at offset: 0

2021-03-13T10:59:29.118+0800	INFO	badger	v2@v2.2007.2/value.go:1178	Replay took: 6.556µs

2021-03-13T10:59:29.125+0800	INFO	badger	v2@v2.2007.2/levels.go:183	All 0 tables opened in 0s

2021-03-13T10:59:29.131+0800	INFO	badger	v2@v2.2007.2/value.go:1158	Replaying file id: 0 at offset: 0

2021-03-13T10:59:29.131+0800	INFO	badger	v2@v2.2007.2/value.go:1178	Replay took: 3.88µs

2021-03-13T10:59:29.173+0800	INFO	p2pnode	lp2p/addrs.go:114	Swarm listening at: [/ip6/::1/tcp/42615 /ip4/192.168.100.19/tcp/1024]
2021-03-13T10:59:29.190+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-0170db1f394b35d995252228ee359194b13199d259380541dc529fb0099096b0.vk is ok
2021-03-13T10:59:29.195+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-8-0-0377ded656c6f524f1618760bffe4e0a1c51d5a70c4509eedae8a27555733edc.vk is ok
2021-03-13T10:59:29.195+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-stacked-proof-of-replication-merkletree-poseidon_hasher-8-0-0-sha256_hasher-ecd683648512ab1765faa2a5f14bab48f676e633467f0aa8aad4b55dcb0652bb.vk is ok
2021-03-13T10:59:29.210+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-5294475db5237a2e83c3e52fd6c2b03859a1831d45ed08c4f35dbf9a803165a9.vk is ok
2021-03-13T10:59:29.210+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-8-2-b62098629d07946e9028127e70295ed996fe3ed25b0f9f88eb610a0ab4385a3c.vk is ok
2021-03-13T10:59:29.210+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-stacked-proof-of-replication-merkletree-poseidon_hasher-8-0-0-sha256_hasher-032d3138d22506ec0082ed72b2dcba18df18477904e35bafee82b3793b06832f.vk is ok
2021-03-13T10:59:29.210+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-stacked-proof-of-replication-merkletree-poseidon_hasher-8-8-0-sha256_hasher-82a357d2f2ca81dc61bb45f4a762807aedee1b0a53fd6c4e77b46a01bfef7820.vk is ok
2021-03-13T10:59:29.219+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-50c7368dea9593ed0989e70974d28024efa9d156d585b7eea1be22b2e753f331.vk is ok
2021-03-13T10:59:29.219+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-stacked-proof-of-replication-merkletree-poseidon_hasher-8-0-0-sha256_hasher-6babf46ce344ae495d558e7770a585b2382d54f225af8ed0397b8be7c3fcd472.vk is ok
2021-03-13T10:59:29.219+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-3ea05428c9d11689f23529cde32fd30aabd50f7d2c93657c1d3650bca3e8ea9e.vk is ok
2021-03-13T10:59:29.219+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-8-0-559e581f022bb4e4ec6e719e563bf0e026ad6de42e56c18714a2c692b1b88d7e.vk is ok
2021-03-13T10:59:29.223+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-8-2-2627e4006b67f99cef990c0a47d5426cb7ab0a0ad58fc1061547bf2d28b09def.vk is ok
2021-03-13T10:59:29.223+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-stacked-proof-of-replication-merkletree-poseidon_hasher-8-8-2-sha256_hasher-96f1b4a04c5c51e4759bbf224bbc2ef5a42c7100f16ec0637123f16a845ddfb2.vk is ok
2021-03-13T10:59:29.223+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-0cfb4f178bbb71cf2ecfcd42accce558b27199ab4fb59cb78f2483fe21ef36d9.vk is ok
2021-03-13T10:59:29.223+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-7d739b8cf60f1b0709eeebee7730e297683552e4b69cab6984ec0285663c5781.vk is ok
2021-03-13T10:59:29.234+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-0170db1f394b35d995252228ee359194b13199d259380541dc529fb0099096b0.params is ok
2021-03-13T10:59:29.355+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-proof-of-spacetime-fallback-merkletree-poseidon_hasher-8-0-0-3ea05428c9d11689f23529cde32fd30aabd50f7d2c93657c1d3650bca3e8ea9e.params is ok
2021-03-13T10:59:31.488+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:138	Parameter file /var/tmp/filecoin-proof-parameters/v28-stacked-proof-of-replication-merkletree-poseidon_hasher-8-0-0-sha256_hasher-032d3138d22506ec0082ed72b2dcba18df18477904e35bafee82b3793b06832f.params is ok
2021-03-13T10:59:31.488+0800	INFO	build	go-paramfetch@v0.0.2-0.20200701152213-3e0f0afdc261/paramfetch.go:162	parameter and key-fetching complete
2021-03-13T10:59:31.490+0800	INFO	stores	stores/index.go:138	New sector storage: fc26bf37-21bb-4cde-8912-d5002a3ea2f9
2021-03-13T10:59:31.535+0800	WARN	storageminer	storage/miner.go:234	*****************************************************************************
2021-03-13T10:59:31.535+0800	WARN	storageminer	storage/miner.go:235	 Generating fake PoSt proof! You should only see this while running tests! 
2021-03-13T10:59:31.535+0800	WARN	storageminer	storage/miner.go:236	*****************************************************************************
2021-03-13T10:59:31.551+0800	INFO	storageminer	storage/miner.go:206	starting up miner t01004, worker addr t3vltmdv4r4uuhix5rcegvquhjxsj45auh5lkidqpigasictjp3sllaottjx23hovcojuhsdct2lrk3ghnugeq
2021-03-13T10:59:31.560+0800	INFO	markets	loggers/loggers.go:56	module ready	{"module": "provider data transfer"}
2021-03-13T10:59:31.560+0800	INFO	markets	loggers/loggers.go:56	module ready	{"module": "retrieval provider"}
2021-03-13T10:59:31.560+0800	INFO	markets	loggers/loggers.go:56	module ready	{"module": "storage provider"}
2021-03-13T10:59:31.560+0800	INFO	markets	loggers/loggers.go:56	module ready	{"module": "piecestore"}
2021-03-13T10:59:31.566+0800	INFO	main	lotus-storage-miner/run.go:151	Remote version 1.4.1+debug+git.ebaa721e4+api1.0.0
2021-03-13T10:59:31.653+0800	INFO	miner	miner/warmup.go:49	skipping winning PoSt warmup, no sectors
2021-03-13T10:59:34.492+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows



2021-03-13T11:02:27.703+0800	INFO	storagemarket_impl	impl/provider.go:207	Handling storage deal proposal!
2021-03-13T11:02:27.713+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventOpen", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealValidating", "message": ""}
2021-03-13T11:02:27.762+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDealDeciding", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealAcceptWait", "message": ""}
2021-03-13T11:02:27.776+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDataRequested", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealWaitingForData", "message": ""}
2021-03-13T11:02:27.816+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDataTransferInitiated", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealTransferring", "message": ""}
2021-03-13T11:02:27.848+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDataTransferCompleted", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealVerifyData", "message": ""}
2021-03-13T11:02:27.921+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventVerifiedData", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealReserveProviderFunds", "message": ""}
2021-03-13T11:02:27.926+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventFundsReserved", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealReserveProviderFunds", "message": ""}
2021-03-13T11:02:27.928+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventFunded", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealPublish", "message": ""}
2021-03-13T11:02:27.929+0800	INFO	storageadapter	storageadapter/provider.go:74	publishing deal
2021-03-13T11:02:27.954+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDealPublishInitiated", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealPublishing", "message": ""}
2021-03-13T11:03:15.686+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDealPublished", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealStaged", "message": ""}
2021-03-13T11:03:15.689+0800	INFO	sectors	storage-sealing/sealing.go:182	Adding piece for deal 3 (publish msg: bafy2bzacebxgzrfdnx2vr5cqhq4jrzyfhsdvaj4xtpf7eru6cwgtl6uu5ea72)
2021-03-13T11:03:15.693+0800	WARN	advmgr	sector-storage/manager.go:313	stub NewSector
2021-03-13T11:03:15.693+0800	INFO	sectors	storage-sealing/sealing.go:428	Creating sector 0
2021-03-13T11:03:15.706+0800	INFO	sectors	storage-sealing/fsm.go:298	Waiting for deals 0
2021-03-13T11:03:15.706+0800	INFO	sectors	storage-sealing/sealing.go:240	Adding piece to sector 0
2021-03-13T11:03:15.707+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 1 queued; 2 open windows
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched.go:449	SCHED windows: [{allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]} {allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]}]
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched.go:450	SCHED Acceptable win: [[0 1]]
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched.go:465	SCHED try assign sqi:0 sector 0 to window 0
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched.go:472	SCHED ASSIGNED sqi:0 sector 0 task seal/v0/addpiece to window 0
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched_worker.go:368	assign worker sector 0
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched_worker.go:278	task done	{"workerid": "a9af0036-ffaf-4d76-9d5d-3aa0959e79e3"}
2021-03-13T11:03:15.708+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T11:03:15.712+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:0; a:1): {{0 0} /home/ml/.lotusminer/unsealed/s-t01004-0  }
2021-03-13T11:03:15.715+0800	INFO	sectors	storage-sealing/fsm.go:298	Waiting for deals 0
2021-03-13T11:03:15.718+0800	WARN	storageadapter	storageadapter/provider.go:138	New Deal: deal 3
2021-03-13T11:03:15.735+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDealHandedOff", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealAwaitingPreCommit", "message": ""}


2021-03-13T17:03:32.178+0800	INFO	sectors	storage-sealing/sealing.go:306	Starting packing sector 0
2021-03-13T17:03:32.178+0800	INFO	sectors	storage-sealing/sealing.go:311	send Starting packing event success sector 0
2021-03-13T17:03:32.180+0800	INFO	sectors	storage-sealing/states_sealing.go:28	performing filling up rest of the sector...	{"sector": "0"}
2021-03-13T17:03:32.203+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 1 queued; 2 open windows
2021-03-13T17:03:32.203+0800	DEBUG	advmgr	sector-storage/sched.go:449	SCHED windows: [{allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]} {allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]}]
2021-03-13T17:03:32.203+0800	DEBUG	advmgr	sector-storage/sched.go:450	SCHED Acceptable win: [[0 1]]
2021-03-13T17:03:32.203+0800	DEBUG	advmgr	sector-storage/sched.go:465	SCHED try assign sqi:0 sector 0 to window 0
2021-03-13T17:03:32.203+0800	DEBUG	advmgr	sector-storage/sched.go:472	SCHED ASSIGNED sqi:0 sector 0 task seal/v0/precommit/1 to window 0
2021-03-13T17:03:32.203+0800	DEBUG	advmgr	sector-storage/sched_worker.go:368	assign worker sector 0
2021-03-13T17:03:32.203+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:03:32.204+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:1; a:0): {{0 0} /home/ml/.lotusminer/unsealed/s-t01004-0  }
2021-03-13T17:03:32.204+0800	DEBUG	advmgr	sector-storage/sched_worker.go:278	task done	{"workerid": "a9af0036-ffaf-4d76-9d5d-3aa0959e79e3"}
2021-03-13T17:03:32.204+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:03:32.207+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:1; a:6): {{0 0} /home/ml/.lotusminer/unsealed/s-t01004-0 /home/ml/.lotusminer/sealed/s-t01004-0 /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:03:32.262+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 1 queued; 2 open windows
2021-03-13T17:03:32.262+0800	DEBUG	advmgr	sector-storage/sched.go:449	SCHED windows: [{allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]} {allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]}]
2021-03-13T17:03:32.263+0800	DEBUG	advmgr	sector-storage/sched.go:450	SCHED Acceptable win: [[0 1]]
2021-03-13T17:03:32.263+0800	DEBUG	advmgr	sector-storage/sched.go:465	SCHED try assign sqi:0 sector 0 to window 0
2021-03-13T17:03:32.263+0800	DEBUG	advmgr	sector-storage/sched.go:472	SCHED ASSIGNED sqi:0 sector 0 task seal/v0/precommit/2 to window 0
2021-03-13T17:03:32.263+0800	DEBUG	advmgr	sector-storage/sched_worker.go:368	assign worker sector 0
2021-03-13T17:03:32.263+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:03:32.265+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:6; a:0): {{0 0}  /home/ml/.lotusminer/sealed/s-t01004-0 /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:03:32.265+0800	DEBUG	advmgr	sector-storage/sched_worker.go:278	task done	{"workerid": "a9af0036-ffaf-4d76-9d5d-3aa0959e79e3"}
2021-03-13T17:03:32.265+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:03:32.267+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:6; a:0): {{0 0}  /home/ml/.lotusminer/sealed/s-t01004-0 /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:03:32.387+0800	INFO	sectors	storage-sealing/states_sealing.go:277	submitting precommit for sector 0 (deposit: 0): 
2021-03-13T17:03:32.398+0800	INFO	sectors	storage-sealing/states_sealing.go:295	Sector precommitted: 0
2021-03-13T17:03:59.965+0800	INFO	sectors	storage-sealing/states_sealing.go:315	precommit message landed on chain: 0
2021-03-13T17:04:03.991+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealSealing", "message": ""}
2021-03-13T17:13:35.963+0800	WARN	sectors	storage-sealing/states_sealing.go:362	revert in interactive commit sector step
2021-03-13T17:13:59.972+0800	INFO	sectors	storage-sealing/states_sealing.go:388	scheduling seal proof computation...
2021-03-13T17:13:59.972+0800	INFO	sectors	storage-sealing/states_sealing.go:390	KOMIT 0 823c8ae42b163a9e0376ff100c2c376661656f5c431f90ad76946c3220b3fa0b(15121); 4556c0db0125c2475ae9700a9c86ef196e7f7d268cb20398f9953102c4f2d2d3(16172); [{2048 baga6ea4seaqp6sgyzdec7al3qass6canpicjuzw4td7i72ntymkh6okxzakrwba}]; r:626167626f656134623561626361626e6f6c76666773377a6b6f376b7072646e6c366a627174327a66377071706d646f32677172367036636a756871767434637a; d:62616761366561347365617170367367797a64656337616c33716173733663616e7069636a757a77347464376937326e74796d6b68366f6b787a616b72776261
2021-03-13T17:13:59.974+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 1 queued; 2 open windows
2021-03-13T17:13:59.975+0800	DEBUG	advmgr	sector-storage/sched.go:449	SCHED windows: [{allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]} {allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]}]
2021-03-13T17:13:59.975+0800	DEBUG	advmgr	sector-storage/sched.go:450	SCHED Acceptable win: [[0 1]]
2021-03-13T17:13:59.975+0800	DEBUG	advmgr	sector-storage/sched.go:465	SCHED try assign sqi:0 sector 0 to window 0
2021-03-13T17:13:59.975+0800	DEBUG	advmgr	sector-storage/sched.go:472	SCHED ASSIGNED sqi:0 sector 0 task seal/v0/commit/1 to window 0
2021-03-13T17:13:59.975+0800	DEBUG	advmgr	sector-storage/sched_worker.go:368	assign worker sector 0
2021-03-13T17:13:59.975+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:13:59.988+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:6; a:0): {{0 0}  /home/ml/.lotusminer/sealed/s-t01004-0 /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:13:59.988+0800	DEBUG	advmgr	sector-storage/sched_worker.go:278	task done	{"workerid": "a9af0036-ffaf-4d76-9d5d-3aa0959e79e3"}
2021-03-13T17:13:59.988+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:13:59.990+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:6; a:0): {{0 0}  /home/ml/.lotusminer/sealed/s-t01004-0 /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 1 queued; 2 open windows
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched.go:449	SCHED windows: [{allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]} {allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]}]
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched.go:450	SCHED Acceptable win: [[0 1]]
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched.go:465	SCHED try assign sqi:0 sector 0 to window 0
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched.go:472	SCHED ASSIGNED sqi:0 sector 0 task seal/v0/commit/2 to window 0
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched_worker.go:368	assign worker sector 0
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched_worker.go:278	task done	{"workerid": "a9af0036-ffaf-4d76-9d5d-3aa0959e79e3"}
2021-03-13T17:14:00.021+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:15:39.974+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 1 queued; 2 open windows
2021-03-13T17:15:39.975+0800	DEBUG	advmgr	sector-storage/sched.go:449	SCHED windows: [{allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]} {allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]}]
2021-03-13T17:15:39.975+0800	DEBUG	advmgr	sector-storage/sched.go:450	SCHED Acceptable win: [[0 1]]
2021-03-13T17:15:39.975+0800	DEBUG	advmgr	sector-storage/sched.go:465	SCHED try assign sqi:0 sector 0 to window 0
2021-03-13T17:15:39.975+0800	DEBUG	advmgr	sector-storage/sched.go:472	SCHED ASSIGNED sqi:0 sector 0 task seal/v0/finalize to window 0
2021-03-13T17:15:39.975+0800	DEBUG	advmgr	sector-storage/sched_worker.go:368	assign worker sector 0
2021-03-13T17:15:39.975+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:15:39.976+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:7; a:0): {{0 0} /home/ml/.lotusminer/unsealed/s-t01004-0 /home/ml/.lotusminer/sealed/s-t01004-0 /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:15:39.977+0800	DEBUG	advmgr	sector-storage/sched_worker.go:278	task done	{"workerid": "a9af0036-ffaf-4d76-9d5d-3aa0959e79e3"}
2021-03-13T17:15:39.977+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:15:39.979+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:1; a:0): {{0 0} /home/ml/.lotusminer/unsealed/s-t01004-0  }
2021-03-13T17:15:39.979+0800	WARN	fsutil	fsutil/dealloc_linux.go:22	could not deallocate space, ignoring: operation not supported
2021-03-13T17:15:39.980+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:4; a:0): {{0 0}   /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:15:39.987+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 1 queued; 2 open windows
2021-03-13T17:15:39.987+0800	DEBUG	advmgr	sector-storage/sched.go:449	SCHED windows: [{allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]} {allocated:{memUsedMin:0 memUsedMax:0 gpuUsed:false cpuUse:0 cond:<nil>} todo:[]}]
2021-03-13T17:15:39.987+0800	DEBUG	advmgr	sector-storage/sched.go:450	SCHED Acceptable win: [[0 1]]
2021-03-13T17:15:39.987+0800	DEBUG	advmgr	sector-storage/sched.go:465	SCHED try assign sqi:0 sector 0 to window 0
2021-03-13T17:15:39.988+0800	DEBUG	advmgr	sector-storage/sched.go:472	SCHED ASSIGNED sqi:0 sector 0 task seal/v0/fetch to window 0
2021-03-13T17:15:39.988+0800	DEBUG	advmgr	sector-storage/sched_worker.go:368	assign worker sector 0
2021-03-13T17:15:39.988+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:15:39.991+0800	DEBUG	advmgr	sector-storage/worker_local.go:129	acquired sector {{1004 0} 5} (e:7; a:0): {{0 0} /home/ml/.lotusminer/unsealed/s-t01004-0 /home/ml/.lotusminer/sealed/s-t01004-0 /home/ml/.lotusminer/cache/s-t01004-0}
2021-03-13T17:15:39.991+0800	DEBUG	advmgr	sector-storage/sched_worker.go:278	task done	{"workerid": "a9af0036-ffaf-4d76-9d5d-3aa0959e79e3"}
2021-03-13T17:15:39.991+0800	DEBUG	advmgr	sector-storage/sched.go:354	SCHED 0 queued; 2 open windows
2021-03-13T17:15:39.994+0800	DEBUG	stores	stores/local.go:619	not moving {{1004 0} 5}(1); src and dest are the same
2021-03-13T17:15:39.994+0800	DEBUG	stores	stores/local.go:619	not moving {{1004 0} 5}(2); src and dest are the same
2021-03-13T17:15:39.994+0800	DEBUG	stores	stores/local.go:619	not moving {{1004 0} 5}(4); src and dest are the same
2021-03-13T17:15:39.997+0800	INFO	sectors	storage-sealing/states_sealing.go:524	Proving sector 0
2021-03-13T17:15:39.997+0800	WARN	advmgr	sector-storage/manager.go:597	ReleaseUnsealed todo
2021-03-13T17:15:43.969+0800	INFO	storageadapter	storageadapter/ondealsectorcommitted.go:199	Storage deal 3 activated at epoch 16197
2021-03-13T17:15:43.970+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventDealActivated", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealFinalizing", "message": ""}
2021-03-13T17:15:43.974+0800	INFO	markets	loggers/loggers.go:20	storage event	{"name": "ProviderEventCleanupFinished", "proposal CID": "bafyreihpbj3qkgsva5vou3odu2mh7tvff4b5tb2oozis44tqxoiwd3wbde", "state": "StorageDealActive", "message": ""}
                                                                    
2021-03-13T17:44:52.077+0800	WARN	storageminer	storage/wdpost_run.go:225	Checked sectors	{"checked": 1, "good": 1}
2021-03-13T17:44:52.078+0800	INFO	storageminer	storage/wdpost_run.go:578	running window post	{"chain-random": "0WsD7u/8qcKFwkMne4pJZbSHRWTkj/IDdISdEodO9jI=", "deadline": {"CurrentEpoch":16641,"PeriodStart":16661,"Index":0,"Open":16661,"Close":16721,"Challenge":16641,"FaultCutoff":16591,"WPoStPeriodDeadlines":48,"WPoStProvingPeriod":2880,"WPoStChallengeWindow":60,"WPoStChallengeLookback":20,"FaultDeclarationCutoff":70}, "height": "16641", "skipped": 0}
2021-03-13T17:44:53.839+0800	INFO	storageminer	storage/wdpost_run.go:594	computing window post	{"batch": 0, "elapsed": 1.760728762}
2021-03-13T17:46:28.100+0800	INFO	storageminer	storage/wdpost_run.go:750	Submitted window post: bafy2bzaceafvvwktxiru5u36ot64pz4z4kl33qgnyfhrloylquomt6if7k7be

ml@ml:~$ 

ml@ml:~$ 
ml@ml:~$ ~/git/lotus/lotus-miner sectors list
ID  State      OnChain  Active  Expiration  Deals  
0   WaitDeals  NO       NO      n/a         1      
ml@ml:~$ ~/git/lotus/lotus-miner sectors list
ID  State      OnChain  Active  Expiration  Deals  
0   WaitDeals  NO       NO      n/a         1      
ml@ml:~$ 
ml@ml:~$ ~/git/lotus/lotus-miner sectors status --log 0
SectorID:	0
Status:		WaitDeals
CIDcommD:	<nil>
CIDcommR:	<nil>
Ticket:		
TicketH:	0
Seed:		
SeedH:		0
Precommit:	<nil>
Commit:		<nil>
Proof:		
Deals:		[3]
Retries:	0
--------
Event Log:
0.	2021-03-13 11:03:15 +0800 CST:	[event;sealing.SectorStart]	{"User":{"ID":0,"SectorType":5}}
1.	2021-03-13 11:03:15 +0800 CST:	[event;sealing.SectorAddPiece]	{"User":{"NewPiece":{"Piece":{"Size":2048,"PieceCID":{"/":"baga6ea4seaqp6sgyzdec7al3qass6canpicjuzw4td7i72ntymkh6okxzakrwba"}},"DealInfo":{"PublishCid":{"/":"bafy2bzacebxgzrfdnx2vr5cqhq4jrzyfhsdvaj4xtpf7eru6cwgtl6uu5ea72"},"DealID":3,"DealSchedule":{"StartEpoch":54697,"EndEpoch":575380},"KeepUnsealed":true}}}}
ml@ml:~$ 
ml@ml:~$ ~/git/lotus/lotus-miner sectors list
ID  State      OnChain  Active  Expiration  Deals  
0   WaitDeals  NO       NO      n/a         1      
ml@ml:~$ ~/git/lotus/lotus-miner info
Chain: [sync ok] [basefee 100 aFIL]
Miner: t01004 (2 KiB sectors)
Power: 0  / 46 Ki (0.0000%)
	Raw: 0 B / 10 KiB (0.0000%)
	Committed: 0 B
	Proving: 0 B
Below minimum power threshold, no blocks will be won
Deals: 1, 2 KiB
	Active: 0, 0 B (Verified: 0, 0 B)

Miner Balance:    0
      PreCommit:  0
      Pledge:     0
      Vesting:    0
      Available:  0
Market Balance:   0
       Locked:    0
       Available: 0
Worker Balance:   1000 FIL
Total Spendable:  1000 FIL

Sectors:
	Total: 1
	WaitDeals: 1
ml@ml:~$ ~/git/lotus/lotus-miner sectors list
ID  State      OnChain  Active  Expiration  Deals  
0   WaitDeals  NO       NO      n/a         1      
ml@ml:~$ ~/git/lotus/lotus-miner sectors list
ID  State      OnChain  Active  Expiration  Deals  
0   WaitDeals  NO       NO      n/a         1      
ml@ml:~$ ~/git/lotus/lotus-miner sectors list
ID  State    OnChain  Active  Expiration                  Deals  DealWeight  
0   Proving  YES      NO      578260 (in 3 weeks 5 days)  1      1.853KiB    
ml@ml:~$ 
ml@ml:~$ ~/git/lotus/lotus-miner sectors list
ID  State    OnChain  Active  Expiration                  Deals  DealWeight  
0   Proving  YES      YES     578260 (in 3 weeks 4 days)  1      1.853KiB    
ml@ml:~$ ~/git/lotus/lotus-miner info
Chain: [sync ok] [basefee 100 aFIL]
Miner: t01004 (2 KiB sectors)
Power: 2 Ki / 48 Ki (4.1666%)
	Raw: 2 KiB / 12 KiB (16.6666%)
	Committed: 2 KiB
	Proving: 2 KiB
Expected block win rate: 4499.9280/day (every 19s)

Deals: 1, 2 KiB
	Active: 1, 2 KiB (Verified: 0, 0 B)

Miner Balance:    0
      PreCommit:  0
      Pledge:     0
      Vesting:    0
      Available:  0
Market Balance:   0
       Locked:    0
       Available: 0
Worker Balance:   1000 FIL
Total Spendable:  1000 FIL

Sectors:
	Total: 1
	Proving: 1
ml@ml:~$ 
ml@ml:~$ 



```
