s = input()

# size = s.size()

# a = [2**i for i in range(10**180)]

ans = 0

s = s.replace("(", "**(")

print(eval(s))