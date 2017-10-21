while 1:
    try:
        a=int(input())
    except EOFError:
        break;
    c=0
    while(a):
        a>>=1
        c+=1
    print(c)
