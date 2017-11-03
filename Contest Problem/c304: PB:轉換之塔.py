while 1:
    try:
        a = input()
    except EOFError:
        break;
    b=int(a)
    a=a[::-1]
    b+=int(a)
    print(b)
