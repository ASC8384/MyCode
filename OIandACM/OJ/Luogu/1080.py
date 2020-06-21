n = int(input())
ss = input().split()
s = int(ss[0])
a = []

for i in range(n):
    ss = input().split()
    a.append((int(ss[0]), int(ss[1])))

a.sort(key=lambda x: x[0] * x[1])
ans = 0

for i in range(n):
    if (s // (a[i])[1] > ans):
        ans = s // (a[i])[1]
    s *= (a[i])[0]
print(ans)