from fractions import gcd

if __name__ == "__main__":
    n = int(input())
    mod = 10**n
    a = list(map(lambda x: int(x), input().split()))
    P = [0 for i in range(110000)]
    for i in range(n):
        P[i + 1] = int(a[i])
    B = [0 for i in range(110000)]
    C = [0 for i in range(110000)]
    for i in range(1, n + 1):
        if (B[i] == 0):
            C[0] = 1
            C[1] = i
            while (P[C[C[0]]] != C[1]):
                C[C[0] + 1] = P[C[C[0]]]
                C[0] += 1
            k = C[0]
            while (C[0]):
                B[C[C[0]]] = k
                C[0] -= 1
    ans = B[1]
    for i in range(2, n + 1):
        k = gcd(ans, B[i])
        ans = ans * B[i] / k % mod
    print(int(ans % mod))
