x = int(input())
res = 0
while x:
    res += x % 10
    x //= 10
print(res)
