def _2set(src):
    """转为 set

    Args:
        src (Any): 任意类型

    Returns:
        set: 集合
    """
    ret = src
    if not isinstance(src, set):
        ret = set()
        ret.add(src)
    return ret


def _proper_subset(items):
    """输出子集的集合，除了空子集

    Args:
        items (set): 集合

    Returns:
        list: 集合的真子集和自己
    """
    ret = [[]]
    for x in items:
        # 自加之前的子集
        ret.extend([subset + [x] for subset in ret])
    return ret[1:]  # 第一个为空集


def _set2string(items):
    """集合转字符串，带了花括号，元素排序

    Args:
        items (set)): 集合，代表了函数依赖集

    Returns:
        string: set 可视化
    """
    return "{{{}}}".format(", ".join(sorted([str(item) for item in items])))


class FD(object):
    """一个函数依赖。A functional dependency。
    """
    def __init__(self, lhs, rhs):
        """初始化

        Args:
            lhs (set): 箭头左半部属性集，left hand side
            rhs (set): 箭头右半部属性集
        """
        self.lhs = _2set(lhs)
        self.rhs = _2set(rhs)

    def __str__(self):
        """字符串化 FD

        Returns:
            string: FD 可视化
        """
        return "{} -> {}".format(_set2string(self.lhs), _set2string(self.rhs))

    def __eq__(self, other):
        """是否相等

        Args:
            other (FD): 另一个 FD

        Returns:
            bool: 是否相等
        """
        if isinstance(other, FD):
            return self.lhs == other.lhs and self.rhs == other.rhs
        return False

    def __ne__(self, other):
        """是否不等

        Args:
            other (FD): 另一个 FD

        Returns:
            bool: 是否不等
        """
        return not self.__eq__(other)

    def __hash__(self):
        """hash 函数

        Returns:
            int: FD 的可视化的哈希值
        """
        return hash(str(self))

    def attributes(self):
        """该函数依赖的所有属性

        Returns:
            set: 左半部和右半部的所有属性
        """
        return self.lhs.union(self.rhs)

    def issingle_left(self):
        """左处是否只有一个属性

        Returns:
            bool: 只有一个属性
        """
        return len(self.lhs) == 1

    def issingle_right(self):
        """右处是否只有一个属性

        Returns:
            bool: 只有一个属性
        """
        return len(self.rhs) == 1


class FDSet(set):
    """函数依赖集。A set of functional dependencies.
    """
    def __init__(self, fds=None):
        """初始化

        Args:
            fds (FDSet, optional): 一个函数依赖. Defaults to None.
        """
        set.__init__(self)
        if fds:
            self.update(fds)

    def __str__(self):
        """字符串化

        Returns:
            string: 可视化
        """
        return _set2string(self)

    def __eq__(self, other):
        """是否相等

        Args:
            other (FDSet): 另一个函数依赖集

        Returns:
            bool: 是否相等
        """
        return self.issubset(other) and other.issubset(self)

    def attributes(self):
        """该函数依赖集的所有属性

        Returns:
            set: 该函数依赖集的所有属性
        """
        result = set()
        for i in self:
            result.update(i.attributes())
        return result

    def closure(self, attributes):
        """计算 F 下 alpha 的闭包 alpha+ 的算法。Closure of Attribute Sets.

        Args:
            attributes (set): alpha 属性集

        Returns:
            set: 闭包 alpha+
        """
        ret = set(attributes)
        ismore = True
        while ismore:
            ismore = False
            for fdep in self:
                if fdep.lhs.issubset(ret) and not fdep.rhs.issubset(ret):
                    # 左边的全在，右边的可以更新
                    ismore = True
                    ret.update(fdep.rhs)
        return ret

    def closure_plus(self):
        """计算 F+，函数依赖集的闭包。Closure of a Set of Functional Dependencies.

        Returns:
            FDSet: 一个函数依赖集。
        """
        ret = FDSet()
        for attributes in _proper_subset(self.attributes()):  # 寻找 R 的子集
            for closures in _proper_subset(self.closure(
                    set(attributes))):  # 子集的属性闭包
                ret.add(FD(set(attributes), set(closures)))  # 找到一个函数依赖
        return ret

    def isin_fds(self, fd):
        """判定函数依赖是否属于函数依赖集闭包

        Args:
            fd (FD): 函数依赖

        Returns:
            bool: 函数依赖是否属于函数依赖集闭包
        """
        return fd in self.closure_plus()

    def issuper_key(self, key):
        """判断 alpha 是否是超键

        Args:
            key (set): alpha 属性集

        Returns:
            bool: alpha 是否是超键
        """
        return self.closure(key) == self.attributes()

    def iscandidate_key(self, key):
        """判断是否是候选键

        Args:
            key (set): 属性集

        Returns:
            bool: 是否是候选键
        """
        if self.issuper_key(key):  # 如果是超键
            for i in _proper_subset(key)[:-1]:  # 遍历真子集
                if self.issuper_key(set(i)):
                    return False
            return True
        else:
            return False

    def isimplied(self, lhs, rhs):
        """lhs 是否能推出 rhs

        Args:
            lhs (FD): lhs，左半部
            rhs (FD)): rhs，右半部

        Returns:
            bool: lhs 是否包含 rhs
        """
        return self.closure(lhs).issuperset(_2set(rhs))

    def isextraneous_left(self, fd, a):
        """左半部属性 a 是否是无关的

        Args:
            fd (FD)): 当前使用的函数依赖
            a (any): 属性 a

        Returns:
            bool: 是否是无关属性
        """
        t = fd.lhs.copy()
        t.remove(a)
        return self.isimplied(t, fd.rhs)

    def isextraneous_right(self, fd, a):
        """右半部属性 a 是否是无关的

        Args:
            fd (FD)): 当前使用的函数依赖
            a (any): 属性 a

        Returns:
            bool: 是否是无关属性
        """
        t = FDSet(self.copy())
        tt = fd.rhs.copy()
        tt.remove(a)
        t.add(FD(fd.lhs, tt))
        return t.isimplied(fd.lhs, fd.rhs)

    def union_all(self):
        """使用合并率将 F_c 中所有形如 a->b_1, a->b_2 的依赖替换为 a->b_1b_2

        Returns:
            FDSet: 合并后的 FDSet
        """
        ret = FDSet()
        for i in self:
            t = set()
            for j in self:
                if i.lhs == j.lhs:
                    t.update(j.rhs)
            ret.add(FD(i.lhs, t))
        return ret

    def canonical_cover(self):
        """实现函数依赖集正则覆盖的构造算法

        Returns:
            FDSet: 正则覆盖
        """
        ret = FDSet(self.copy())
        ismore = True
        while ismore:
            ismore = False
            ret = ret.union_all()
            for fd in ret.copy():
                ret.remove(fd)  # 先删除，不删的话会导致 set 失效，具体原因待查
                if not fd.issingle_left():  # alpha
                    for i in fd.lhs.copy():
                        if ret.isextraneous_left(fd, i):
                            fd.lhs.remove(i)
                            ismore = True
                if not fd.issingle_right():  # beta
                    for i in fd.rhs.copy():
                        if ret.isextraneous_right(fd, i):
                            fd.rhs.remove(i)
                            ismore = True
                ret.add(fd)  # 处理完当前 fd
        return ret

    def min_left(self, lhs, rhs):
        """左半部的最小子集

        Args:
            lhs (FD): 函数依赖左半部
            rhs (FD): 函数依赖右半部

        Returns:
            FD: 左半部去除无关属性
        """
        ret = lhs.copy()
        for attr in lhs:
            ret.remove(attr)
            if not self.isimplied(ret, rhs):
                ret.add(attr)
        return ret

    def candidate_key(self):
        """求任意一个候选键。设 U -> U，显然此时左半部去除无关属性后为候选键

        Returns:
            FD: 候选键
        """
        return self.min_left(self.attributes(), self.attributes())


class RelSchema(object):
    """关系模式
    """
    def __init__(self, fds, attributes=None):
        """初始化

        Args:
            fds (FDSet): 函数依赖集
            attributes (set, optional): 属性集. Defaults to None.
        """
        if attributes is None:
            self.attributes = fds.attributes()
        else:
            self.attributes = attributes
        self.fds = fds

    def __str__(self):
        """可视化

        Returns:
            string: 可视化
        """
        return "({}, {})".format(_set2string(self.attributes),
                                 _set2string(self.fds))

    def isdependency(self, *attrs):
        """函数依赖保持判定算法

        Args:
            attrs (set): 属性集 R，不定参数

        Returns:
            bool: 是否保持函数依赖
        """
        for fd in self.fds:
            result = fd.lhs
            ismore = True
            while ismore:
                ismore = False
                for attr in attrs:
                    t = self.fds.closure(
                        result.intersection(attr)).intersection(attr)
                    if not t.issubset(result):  # result 有变化
                        ismore = True
                        result = result.union(t)
            if not fd.rhs.issubset(result):
                return False
        return True

    def isbcnf(self):
        """实现BCNF的判定算法，用于判断模式是否满足BCNF

        Returns:
            bool: 模式是否满足BCNF
        """
        for fd in self.fds:
            if not self.fds.issuper_key(fd.lhs):
                return False
        return True

    def isbcnf_decompn(self, *attrs):
        """实现分解后模式的BCNF判定算法，用于判断分解后的模式是否属于BCNF

        Returns:
            bool: 分解后的模式是否属于BCNF
        """
        for attr in attrs:
            for a in _proper_subset(attr):
                t = self.fds.closure(a)
                if not attr.issubset(t) and not t.isdisjoint(attr - set(a)):
                    # 德摩根定律，手抖写成 or 了，查到自闭
                    return False
        return True

    def decompn_3NF(self, minimize=False):
        """3NF 分解

        Args:
            minimize (bool, optional): 是否需要移除冗余关系. Defaults to False.

        Returns:
            RelSchema: 3NF 模式
        """
        f_c = self.fds.canonical_cover()
        bcopy = FDSet(f_c.copy())
        ret = set()
        for fd in f_c:
            fds = FDSet()
            fds.add(fd)
            ret.add(RelSchema(fds))

        havekey = False
        for i in ret:
            if bcopy.issuper_key(i.attributes):
                havekey = True
                break
        if not havekey:
            key = bcopy.candidate_key()
            ret.add(RelSchema(FDSet(), key))

        if minimize:  # 移除冗余关系
            rcopy = ret.copy()
            for i in rcopy:
                for j in rcopy:
                    if i.attributes != j.attributes:
                        if i.attributes.issubset(j.attributes):
                            ret.remove(i)
        return ret

    def decompn_BCNF(self):
        """BCNF 分解

        Args:
            minimize (bool, optional): 是否需要移除冗余关系. Defaults to False.

        Returns:
            RelSchema: BCNF 模式
        """
        ans = self.decompn_3NF()
        ret = []
        for i in ans:
            ret.append(i.attributes)

        ans = []
        for attr in ret.copy():
            t = []
            t.append(attr)
            while t:  # 用循环代替回溯
                if self.isbcnf_decompn(t[0]):
                    ans.append(t[0])
                else:
                    for a in _proper_subset(t[0]):
                        flg = False
                        for b in _proper_subset(t[0]):
                            if not self.fds.issuper_key(
                                    a) and self.fds.isin_fds(FD(
                                        a, b)) and a not in b:
                                # 找到 a -> b, a 不是超键，a 不属于 b
                                s1 = set(a) + set(b)
                                s2 = t[0] - set(a)
                                t.append(s1)  # 继续计算
                                t.append(s2)
                                flg = True
                                break
                        if flg:
                            break
                t.pop(0)

        for i in ans.copy():
            for j in ans.copy():
                if i.issubset(j) and i != j:
                    if (i in ans):
                        ans.remove(i)
        return ans


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
