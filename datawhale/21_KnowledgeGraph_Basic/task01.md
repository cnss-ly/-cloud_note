### Task01：知识图谱介绍（1天）

- 知识图谱简介

  > 知识图谱是由 Google 公司在 2012 年提出来的一个新的概念。从实际应用的角度出发其实可以简单地把知识图谱理解成多关系图（Multi-relational Graph）。

- 怎么构建知识图谱

  > 以图这种数据结构为基础，节点储存数据，节点的连接表示两者关系。节点和关系的设计称为schema。
  >
  > 具体的构建技术有：
  >
  > 1. 实体命名识别（Name Entity Recognition）打标签
  >
  > 2. 关系抽取（Relation Extraction）提取实体间关系
  >
  > 3. 实体统一（Entity Resolution）把表示相同实体的节点合并
  >
  > 4. 指代消解（Coreference Resolution）找出代称所指向的实体并做相同合并
  >
  >    。。。

- 知识图谱的存储

  > 两种储存方式
  >
  > 1.基于RDF：易发布以及共享，储存方式为三元组
  >
  > 2.基于图数据库：高效的图查询和搜索，属性图为基本的表示形式

- Neo4j 介绍与安装（最常用）

  > 一种图数据库，社区版免费
  >
  > linux启动命令：bin/neo4j start
  >
  > 打开web页面：http://127.0.0.1:7474/browser/
  >
  > 使用Cypher语言查询（声明式）														

- Neo4j 实战

  > 删库跑路必备
  >
  > ```cypher
  > MATCH (n) DETACH DELETE n
  > ```
  >
  >  创建节点
  >
  > ```cypher
  > CREATE (n:node_type {attribute:'Data'}) RETURN n
  > ```
  >
  > 创建关系
  >
  > ```cypher
  > MATCH (a:node_type1 {attribute1:'Data1'}), (b:node_type2 {attribute2:'Data2'}) MERGE (a)-[:relation {attribute3:'Data3'}]->(b)
  > ```
  >
  > 查询某关系
  >
  > ```cypher
  > MATCH (a:node_type1)-[:relation]->(b:node_type2 {attribute:'Data'}) RETURN a,b
  > ```
  >
  > 查询所有对外关系的节点
  >
  > ```cypher
  > MATCH (a)--() RETURN a
  > ```
  >
  > 查询所有有关系的节点
  >
  > ```cypher
  > MATCH (a)-[r]->() RETURN a.name, type(r)
  > ```
  >
  > 查询所有对外有关系的节点，以及关系类型
  >
  > ```cypher
  > MATCH (a)-[r]->() RETURN a.name, type(r)
  > ```
  >
  > 增加/修改节点的属性
  >
  > ```cypher
  > MATCH (a:Person {name:'Liz'}) SET a.age=34
  > ```
  >
  > 删除节点的属性
  >
  > ```cypher
  > MATCH (a:Person {name:'Mike'}) SET a.test='test'
  > ```
  >
  > 删除节点
  >
  > ```cypher
  > MATCH (a:Location {city:'Portland'}) DELETE a
  > ```

- 通过 Python 操作 Neo4j

  > neo4j和py2neo

- 通过csv文件批量导入图数据(重要的)

  > 1. csv文件放在neo4j安装绝对路径/import下
  >
  > 2. 导入到图数据库mygraph.db
  >
  > ```
  >   neo4j bin/neo4j-admin import --nodes=/var/lib/neo4j/import/nodes.csv --relationships=/var/lib/neo4j/import/relas.csv   --delimiter=^ --database=xinfang*.db
  > ```
  >
  > delimiter=^ 指的是csv的分隔符
  >
  > 3. 指定neo4j使用哪个数据库
  >
  > ```s
  >   修改 /root/neo4j/conf/neo4j.conf 文件中的 dbms.default_database=mygraph.db
  > ```
  >
  > 4. 重启neo4j

初步了解了知识图谱的概念和用处，操作neo4j创建图，使用csv文件导入数据。