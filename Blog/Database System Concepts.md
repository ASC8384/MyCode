# Database System Concepts

[TOC]

记录一下数据库学习相关的东西。

使用《Database System Concepts (Sixth Edition) 中文版》。

## 安装

由于教学使用 Oracle，为了避免各种秃头问题，我用 Docker 安装了。

使用的是 `oracleinanutshell/oracle-xe-11g`，只有 2G 多一点，比老师提供的 20G 虚拟机小到不知哪里去了。

用 `docker run -d -p 49161:1521 oracleinanutshell/oracle-xe-11g` 运行。

使用以下默认设定：
```
hostname: localhost
port: 49161
sid: xe
username: system
password: oracle
```

而后在 [Sample Tables](https://www.db-book.com/db6/lab-dir/sample_tables-dir/index.html) 处下载 SQL 文件。

用 `docker cp SRC_PATH CONTAINER:DEST_PATH` 导入进容器里，注意源文件貌似只能用绝对地址。

在 sqlplus 里用 `@ /你存放的目录/×.sql;` 导入数据表。

用 [Online SQL interpreter](https://www.db-book.com/db7/university-lab-dir/sqljs.html) 可以在线使用。

## 问题

### sqlplus 上下左右键乱码

安装 `rlwrap` 后，运行 `rlwrap sqlplus`

### sqlplus 长得太丑，换行问题

```sql
set wrap on #关闭（开启）自动换行
set linesize 100 #设置每行显示100字符 
set pagesize 100 #设置每页显示100行记录
```

修改 `$ORACLE_HOME/sqlplus/admin/glogin.sql`

### sqlplus 自动补全（弱）

sqlplus 真的过于老旧，网上找了个带补全的版本 [rlwrap_ext](http://www.linuxification.at/rlwrap_ext.html.en)

这里使用的是 11 版本。

```bash
apt install curl
curl http://www.linuxification.at/download/rlwrap-extensions-V11-0.05.tar.gz -o 1.tar.gz
tar zxvf 1.tar.gz -C /usr/share/rlwrap/completions
cp /usr/share/rlwrap/completions/ /usr/local/share/rlwrap/ -r
cp /usr/local/share/rlwrap/completions/sql+  /usr/local/bin/
sql+
```

以后用 `sql+` 代替 `sqlplus` 就好了。

### 代替 sqlplus

老师说不建议直接用命令行（观点和我一致，过于丑陋），所以找了个命令行替代品 :smile:。

[okcli](https://github.com/man-group/okcli)

因为宿主机没装 Oracle，所以一些库没有，我就在 docker 里头装了。

```bash
# 安装 pip3，并升级至最新版本
LC_ALL=C.UTF-8 pip3 install okcli
# 修改本地语言
okcli system/oracle@xe # 最好新建一个新用户
# enjoy it
```
