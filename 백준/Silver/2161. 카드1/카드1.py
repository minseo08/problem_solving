n = int(input())
a = []
b = []
for i in range(1, n + 1):
    a.append(i)

while(len(a) != 1):
    b.append(a.pop(0))
    a.append(a.pop(0))
    
for i in b:
    print(i, end = " ")
print(a[0])