from fractions import gcd

s = list(map(lambda x: int(x), input().split()))

a = s[0]
b = s[1]
c = s[2]
d = s[3]
x = s[4]
y = s[5]
mod = 998244353

ans = 1
xxx = x**a
yy = y**c


def qpow(x, n):
    res = 1
    x %= mod
    while n:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res


for i in range(a, b + 1):
    yyy = yy
    tmp = gcd(xxx, yyy)
    ans *= tmp
    # print(ans % mod)
    j = c
    while (j < d):
        yyy = yyy * y
        now = gcd(xxx, yyy)
        if (now == tmp):
            break
        else:
            ans = now % mod * ans % mod
            tmp = now
            # print(ans % mod)
        j += 1
    ans = ans * qpow(tmp, (d - j)) % mod
    xxx = xxx * x

print(ans % mod)
