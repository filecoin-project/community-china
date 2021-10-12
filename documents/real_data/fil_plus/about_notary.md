
为帮助国内社区成员了解公证人的公证人的作用以及运行机制，本文翻译自<https://github.com/filecoin-project/notary-governance/blob/main/notaries/README.md>

# 概述

公证人被选为 Filecoin 网络的 [受托人](https://www.merriam-webster.com/dictionary/fiduciary)。 公证人受托维护该计划的[原则](https://github.com/filecoin-project/FIPs/blob/fip-0003/FIPS/fip-0003.md/#principles) - 负责任地分配DataCap以帮助在 Filecoin 上培养合法用例。本文件旨在为公证人的角色/责任提供更多的具体内容，定义申请和选择过程，以及进行修改的过程。

## 当前活跃的公证人

| 地区 | 公证人 | 申请链接 | 授权额度 |
| --- | --- | --- | --- |
| 亚太地区 | 12ships Foundation | <https://github.com/filecoin-project/notary-governance/issues/180> | 100TiB |
| 亚太地区 | MathWallet | <https://github.com/filecoin-project/notary-governance/issues/123> | 100TiB |
| 亚太地区 | Masaaki Nawatani, Blotocol Japan | <https://github.com/filecoin-project/notary-governance/issues/131> | 100TiB |
| 欧洲 | Filecoin 基金会 | <https://github.com/filecoin-project/notary-governance/issues/187> | 1PiB |
| 欧洲 | Julien NOEL / Twinquasar | <https://github.com/filecoin-project/notary-governance/issues/136> | 100TiB |
| 欧洲 |Keyko | <https://github.com/filecoin-project/notary-governance/issues/46> | 100TiB |
| 欧洲 | Nicklas Reiersen / TechHedge | <https://github.com/filecoin-project/notary-governance/issues/186> | 10TiB |
| 欧洲 | Speedium | <https://github.com/filecoin-project/notary-governance/issues/122> | 10TiB |
| 中国区 | Fenbushi Capital（分布式资本）| <https://github.com/filecoin-project/notary-governance/issues/138> | 1PiB |
| 中国区 | 1475 - Simon686 (1475) | <https://github.com/filecoin-project/notary-governance/issues/172> | 1PiB |
| 大中华区 | IPFSFORCE - Steven Li（原力区）| <https://github.com/filecoin-project/notary-governance/issues/158> | 500 TiB |
| 大中华区 | IPFSMain - Neo Ge（星际大陆） | <https://github.com/filecoin-project/notary-governance/issues/168> | 1PiB |
| 大中华区 | IPFSUnion - Steve Song（星际联盟） | <https://github.com/filecoin-project/notary-governance/issues/135> | 100TiB |
| 大中华区 | ByteBase（冰塔科技） | <https://github.com/filecoin-project/notary-governance/issues/169> | 100TiB |
| 大中华区 | Wise R&D Center - waynewyang | <https://github.com/filecoin-project/notary-governance/issues/178> | 100TiB |
| 大中华区 | Binghe Distributed Storage Lab（冰河分布式存储实验室)| <https://github.com/filecoin-project/notary-governance/issues/149> | 100TiB |
| NA | XnMatrix | <https://github.com/filecoin-project/notary-governance/issues/150> | 1PiB |
| NA | Performive | <https://github.com/filecoin-project/notary-governance/issues/132> | 100TiB |
| NA | Koda Inc. | <https://github.com/filecoin-project/notary-governance/issues/153> | 100TiB |
| NA | Textile | <https://github.com/filecoin-project/notary-governance/issues/53> | 100TiB |
| NA | Glif | <https://github.com/filecoin-project/notary-governance/issues/48> | 100TiB |
| NA | Filswan NBFS | <https://github.com/filecoin-project/notary-governance/issues/157> | 10TiB |
| NA | SECUREEXPERTS Inc. | <https://github.com/filecoin-project/notary-governance/issues/164> | 10TiB |
| NA | Holon Innovations | <https://github.com/filecoin-project/notary-governance/issues/130> | 100TiB |

## 角色和责任

公证人的基本职责如下：

- 将 DataCap 分配给客户端，以增加网络上可靠且有用的存储。
- 根据提供的信息，验证客户端是否收到与保证的信任级别相称的DataCap。
- 确保在分配 DataCap 时，不会以任何可能危及网络的形式过度信任任何一方。
- 遵循操作指南，记录决策流程，并响应对其分配决策进行审计的任何请求。

**注意：** 公证人在决策过程中享有自主权，并鼓励他们根据自己的最佳判断分配 DataCap。但是，公证人应该在接收未来要分发的 DataCap 之前回答有关先前分配决定的任何问题。本仓库中提供了合理分配策略的指南（包括 [为潜在客户推荐的评分机制](https://github.com/filecoin-project/notary-governance/blob/main/notaries/templates/client-evaluation.md)，以及 [向客户提出的问题样本集](https://github.com/filecoin-project/notary-governance/blob/main/notaries/templates/sample-client-application.md))。虽然不是强制性使用，但这些文件代表了行为良好的公证人的预期基线。

## 操作指南

如上所述，公证人在决策权方面享有高度自主权。为了建立对该机制稳定性的信任，下面概述了一些基本标准，所有公证人都应遵守这些标准。将来，经社区批准（通过标准 PR 流程），这些限制可能会减少或取消。

- **前期披露**：在被确认为公证人之前，公证人应披露其控制、拥有财务利益或通过其他方式与之密切相关的所有相关地址。对于披露，公证人应说明相关地址和关系的性质。

- **推广客户最佳实践**：公证人同意就使用其DataCap的最佳实践（例如，如何向矿工请求额外服务、在多个矿工之间冗余存储数据等）向获得 DataCap 的客户端进行教育。一些参考信息可以在[这里](https://github.com/filecoin-project/notary-governance/issues/9)找到。

- **对有效服务网络的承诺**：公证人同意作为网络的受托人，努力为Filecoin带来有用的数据并改善客户的体验。公证人一般应能在3天内对客户的申请和更新作出回应，并应在申请需要重新定向时与客户和公证人进行沟通。

- **禁止自我交易**：为防止利益冲突，公证人不应将 DataCap 分配给他们控制私钥的客户，或分配给打算将分配的 DataCap 专门用于与公证人关联的地址的客户。如有疑问，公证人应倾向于透明度（即公开披露）或让不同的公证人处理个人请求。

- **诚信操作**：公证人在网络中占有信任的地位，因此希望他们在操作中牢记这一机制的原则。虽然不能详尽地定义每一种形式的滥用，但公证人应偏向于谨慎，并以促进透明度的方式行事。公证人应该预期可能会收到关于分配决定的请求或问题（在合理范围内）--并应在考虑到这一点的情况下做出决定。

- **社区治理参与**：我们期望公证人定期参加预定的治理电话会议。由于这些电话会议是塑造这一进程的论坛，因此必须确保公证人出席，以提供他们的背景、学习和投入。

## 申请/选择过程

对于那些有兴趣向 Filecoin 网络提供此服务的人，他们可以通过在 [此处](https://github.com/filecoin-project/notary-governance/issues/new/choose) 提交问题来申请此角色。申请目前开放至 2021 年 5 月 25 日。

请注意，申请会在 [社区治理电话会议](https://github.com/filecoin-project/notary-governance/blob/main/README.md#governance-and-iteration-process) 期间进行审核 - 并将根据此社区定义的 [标准](https://github.com/filecoin-project/notary-governance/blob/main/notaries/templates#overview) 进行评分。对标准的编辑将遵循与对此存储库进行的任何提议更改相同的过程，在[此处](https://github.com/filecoin-project/notary-governance/blob/main/README.md#process-for-modifications)定义.

首先，根据得分最高的初始申请人，第一波公证人被限制在**每个地区 3 名公证人**。第二轮选举将 EU、GCR 和 NA 的这一限制增加到 5+。有关更多详细信息，请参阅 <https://github.com/filecoin-project/notary-governance/issues/117>。

潜在的公证人将根据用于确定其DataCap分配的四舍五入的分数进行排名

### 当侯选公证人拥有相同的分数

如果同一地区有超过3位公证人拥有相同的资格分数（计算方法为MIN(ROUND(0.5 *Track Record + 0.3* Weighted Notary Leveling + 0.2 *Concreteness of Allocation Plan), Scale of Allocation)），将使用非整数分数（计算方法为（0.5* Track Record + 0.3 *Weighted Notary Leveling + 0.2* Concreteness of Allocation Plan）。在仍然存在平局的情况下，社区可以决定是否批准所有平局的公证人，或者挑选对生态系统贡献最大的公证人（例如，支持不支持的用例，通过开放源码工具，可能有利于未来的公证人，等等）

我们提出这个限制是为了确保在这个过程的早期出现的任何问题都能得到处理，同时带来最小的影响。随着这一进程的稳定，我们设想这一限制将被放宽。

## 删除过程

对其提出一致的实质性问题并被认定为合法滥用权力的公证人将被定为没有资格获得DataCap分配。提出和解决争端的过程可以在[这里](https://github.com/filecoin-project/notary-governance/blob/main/README.md#dispute--audit-framework)找到。
