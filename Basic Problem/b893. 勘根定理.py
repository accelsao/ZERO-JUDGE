def df(n):
    return a*(n*n*n*n*n)+b*(n*n*n*n)+c*(n*n*n)+d*(n*n)+e*n+f
while 1:
    try:
        a,b,c,d,e,f=map(int,input().split())
    except EOFError:
        break
    if(not a and b==0 and c==0 and d==0 and e==0 and f==0):
        print ('Too many... = ="')
        continue;
    s=0
    for i in range(-40,41,1):
        if(df(i)==0):
            print('{0} {1}'.format(i,i))
            s=1
            continue;
        elif(df(i)*df(i+1)<0):
            print('{0} {1}'.format(i,i+1))
            s=1
    if(not s):
        print("N0THING! >\\\\\\<")
