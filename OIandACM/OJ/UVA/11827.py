def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        a = list(map(int, input().split()))
        ans = 0
        for i, val in enumerate(a):
            for j in range(i+1, len(a)):
                ans = max(ans, gcd(val, a[j]))
        print(ans)
