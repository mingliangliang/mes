## 基于MFC的手机生产制造执行系统的设计与实现
###摘  要：
制造执行系统(Manufacturing Execution System，MES)是面向企业车间层的管理信息系统，位于计划层与控制层之间，它的主要作用是解决上层计划系统与下层控制系统之间的信息通信。企业可以通过制造执行系统获取生产实时信息、优化产能分配、提高制造效率、优化资源配置。

本文针对手机生产制造服务为主的企业特有的业务需求，详细阐述了适用于手机制造企业的制造执行系统的设计思路和实现过程。实现了用户管理、订单管理、组装生产管理、包装生产管理、品质管理等功能。企业通过导入该系统，可以确保计划层下发的生产计划得到有效的落实，并且精细化手机生产流程管理，从而为生产流程改善，提高手机质量提供保障。还为手机生产引入了条码管理体系，条码管控贯穿了主板、电池仓、彩盒包装、卡通箱包装、栈板包装整个手机生产过程，实现了物料及成品在工厂、供应商、客户、售后服务之间的流转追溯，使整个生产过程实时化、数据化。通过导入本系统，形成产品追溯体系，对产品检测、生产、出货、售后返工等整个手机生产周期中的各个因素、环节进行监控、分析、改进。实现生产过程数据化，填补了公司计划层与控制层之间的空隙，为手机生产智能化打下了夯实的基础。

本系统开发工具采用Microsoft Visual C++ 6.0、生产信息数据库使用SQL Server 2005建立、使用MFC技术进行开发。
###关键词：
制造执行系统；MES；手机生产；MFC；ZPL指令
##Design and implementation of Manufacturing Execution System for mobile phone production based on MFC
###Abstract：
Manufacturing Execution System (MES) is a management information service located between the top program management system and the underlying industrial controlled workshop. MES is committed to solving the communication between the upper planning system and the lower control system. Enterprises are able to produce real-time information to optimize the allocation of production capacity, improving manufacturing efficiency and the disposition of resource by setting up their execution system.

In view of the special business needs, the main part of which is the mobile phone production service. This article elaborates the design ideas and the implementation process of the proper MES in details. With MES, enterprises can make sure the production plan can be realized by guiding layer into execution and the production process management to be refined effectively. Both of these can provide security for the advancement of their production process and the improvement of mobile phones’ quality. In this way, enterprises can realize the functions of user management, order management, assembly management, packaging management and quality management. Moreover, this system can introduce bar-code management system to mobile phone production. Bar-code controls throughout the whole mobile phone production process include the main board, battery, color box packaging, carton packaging and pallet packaging. Thus, material and finished goods can flow fluently among factories, suppliers, customers and after-sales service, which makes the whole production process digital and real-time. By importing the system, a product trace ability system can be informed, which can monitor, analyze and improve the whole production cycle, including product testing, production, delivery and after-sale rework, etc. The digital production process filled with the vacancy between planning layer and control layer, laid a solid foundation for intellectualized production.

The system uses Microsoft Visual C ++ 6.0 as a development tool, which uses SQL Server 2005 to build production information database and MFC technology for development.
###Key words：
Manufacturing Execution System; MES; mobile phone production; MFC; ZPL command
###1 绪论
####1.1 研究背景及意义
制造业是国民经济的主体，是立国之本、兴国之器、强国之基。从十八世纪中叶工业文明开启以来，列强的兴衰史和中华名族的艰苦奋斗史一再证明，没有强大的制造业，就没有国家和名族的强盛[1]。中国要想提升综合国力、保障国家安全、建设成为世界强国就必须打造具有国际竞争力的制造业。
新中国成立尤其是改革开放以来，我国制造业发展迅速，建设了门类齐全、独立完整的产业体系，有力推动工业化和现代化进程，显著增强综合国力，支撑世界大国地位。中国制造走出国门，走向了世界，即便如此，与世界上其它制造业大国相比，中国的制造业仍然仅仅是大，不够强，没有形成强大的竞争力。中国制造在自主创新能力、资源利用率、产业链结构、信息化程度、品质效益等方面与先进水平还有差距，企业的转型升级和跨越发展的任务紧迫而又艰巨。

2015年5月8日，经李克强总理签批，国务院印发《中国制造2015》，部署全面推进实施制造强国战略[2]。这是我国实施制造强国战略的第一个十年的行动纲领。《中国制造2015》包含有五大工程，其中就有智能制造工程，提出要加快推进信息技术和制造技术的融合发展，把智能制造作为两化（工业化和信息化）深度融合的主攻方向。依托优势企业，紧扣关键工序智能化、关键岗位机器人替代、智能优化控制生产过程、优化供应链，重点领域建设数字化车间或智能工厂[3]。

制造执行系统恰好能促进智能制造工程的落实与实现。制造执行系统（Manufacturing Execution System，简称MES）是由美国AMR公司（Advanced Manufacturing Research，Inc）在上世纪九十年代提出的，随后还特地成立了制造执行系统协会（Manufacturing Execution System Association，简称MESA），以宣传制造执行系统的思想和宗旨。在AMR公司提出的企业集成的三层模型中（如图1.1），制造执行系统处于中间层，将上层的生产计划系统与工厂车间底层的设备控制系统联系起来[4]。因此，制造执行系统不只是功能单一的工厂信息管理系统，而是多位一体、横纵穿插的集成系统，填补了计划层与控制层之间的鸿沟，打通了工厂的信息交流通道，起着承上启下的关键作用。


