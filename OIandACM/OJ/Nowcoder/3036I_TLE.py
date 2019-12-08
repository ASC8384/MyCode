t = int(input())
 
for i in range(t):
    s = input().split()
    p = int(s[0])
    x = p - 1
    n = int(s[1])
    # n = n % (p - 1)
    res = 1;
    while n > 0:
        if n & 1:
            res = res * x % p
        x = x * x % p;
        n >>= 1
    print(res)