n = 1
for _ in range(3):
    a = int(input())
    n *= a
num = [0] * 10
str = str(n)
for i in str:
    num[int(i)] += 1
for cnt in num:
    print(cnt)