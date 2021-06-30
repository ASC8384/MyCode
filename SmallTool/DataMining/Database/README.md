## NFTool

### Overview

NFTool is a simple tool for functional dependencies (FDs) and normalization of relational database schemata.

### Getting Started

#### Installation

Please download `NFTool.py` and put it anywhere you can import.

And then using `import NFTool` to enjoy it.

#### Usage

```python
import NFTool


if __name__ == '__main__':
    # 属性闭包计算
    fds = FDSet()
    fds.add(FD({"A"}, {"B"}))
    fds.add(FD({"B"}, {"C"}))
    fds.add(FD({"C", "B"}, {"D"}))
    print(fds.closure({"A"}))

    # 判定超码
    fds = FDSet()
    fds.add(FD({"A"}, {"B"}))
    fds.add(FD({"B"}, {"C"}))
    fds.add(FD({"C", "B"}, {"D"}))
    print(fds.issuper_key({"A"}))
    print(fds.issuper_key({"B"}))

    # 判定候选码
    fds = FDSet()
    fds.add(FD({"A"}, {"B"}))
    fds.add(FD({"B"}, {"C"}))
    fds.add(FD({"B"}, {"D"}))
    fds.add(FD({"C", "B"}, {"A"}))
    print(fds.iscandidate_key({"A"}))
    print(fds.iscandidate_key({"B", "C"}))

    # 函数依赖集闭包
    fds = FDSet()
    fds.add(FD({"A"}, {"B"}))
    fds.add(FD({"B"}, {"C"}))
    print(fds.closure_plus())

    # 判定函数依赖是否属于函数依赖集闭包
    fds = FDSet()
    fds.add(FD({"A"}, {"B"}))
    fds.add(FD({"B"}, {"C"}))
    print(fds.isin_fds(FD({"A", "B"}, {"B", "C"})))

    # 函数依赖保持判定
    fds = FDSet()
    fds.add(FD({"B"}, {"A"}))
    fds.add(FD({"D"}, {"A"}))
    fds.add(FD({"A"}, {"E"}))
    fds.add(FD({"A", "C"}, {"B"}))
    rs = RelSchema(fds)
    print(rs.isdependency({"A", "B", "C", "E"}, {"C", "D"}))
    fds = FDSet()
    fds.add(FD({"E"}, {"A"}))
    fds.add(FD({"C"}, {"D"}))
    fds.add(FD({"A"}, {"B", "C"}))
    fds.add(FD({"B", "C"}, {"E"}))
    rs = RelSchema(fds)
    print(rs.isdependency({"A", "B", "C", "E"}, {"C", "D"}))

    # 判断模式是否满足BCNF
    fds = FDSet()
    fds.add(FD({"S", "J"}, {"T"}))
    fds.add(FD({"S", "T"}, {"J"}))
    fds.add(FD({"T"}, {"J"}))
    rs = RelSchema(fds)
    print(rs.isbcnf())

    # 判断分解后的模式是否属于BCNF
    fds = FDSet()
    fds.add(FD({"A"}, {"B", "C"}))
    fds.add(FD({"D", "C"}, {"E"}))
    fds.add(FD({"B"}, {"D"}))
    fds.add(FD({"E"}, {"A"}))
    rs = RelSchema(fds)
    print(rs.isbcnf_decompn({"A", "B", "C", "E"}, {"B", "D"}))

    # 函数依赖集正则覆盖的构造
    fds = FDSet()
    fds.add(FD({"A"}, {"B", "C"}))
    fds.add(FD({"B"}, {"C"}))
    fds.add(FD({"A"}, {"B"}))
    fds.add(FD({"A", "B"}, {"C"}))
    print(fds.canonical_cover())

    # 3NF 分解
    fds = FDSet()
    fds.add(FD({"A"}, {"B", "C"}))
    fds.add(FD({"D", "C"}, {"E"}))
    fds.add(FD({"B"}, {"D"}))
    fds.add(FD({"E"}, {"A"}))
    rs = RelSchema(fds)
    for i in rs.decompn_3NF(True):
        print(i)

    # BCNF 分解
    fds = FDSet()
    fds.add(FD({"A"}, {"B"}))
    fds.add(FD({"A"}, {"C"}))
    fds.add(FD({"C"}, {"D"}))
    fds.add(FD({"C"}, {"E"}))
    fds.add(FD({"E"}, {"F", "G"}))
    rs = RelSchema(fds)
    print(rs.decompn_BCNF())
```



### Changelog

* [0.9] - 2021-06-26

  Initial release.
