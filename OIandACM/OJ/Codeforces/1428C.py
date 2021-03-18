n = int(input())

for i in range(n):
    s = input().replace('AB', '')
    n1 = len(s)
    s = s.replace('AB', '')
    n2 = len(s)
    while (n1 != n2):
        n1 = n2
        s = s.replace('AB', '')
        n2 = len(s)
    print(len(s.replace('BB', '')))
