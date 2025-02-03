n = int(input())
res = n
cnt = 0
while True:
    cnt += 1
    n = (n // 10 + n % 10) % 10 + (n % 10) * 10
    if n == res:
        break
print(cnt)