a=[0 for i in range(201)]
a[0]=1
for i in range(1,201):
    for j in range(i,201):
        a[j]+=a[j-i]
while 1:
    try:
        n=int(input())
    except EOFError:
        break;
    print(a[n])
