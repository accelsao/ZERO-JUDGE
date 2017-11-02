while 1:
    try:
        a=int(input())
    except EOFError:
        break;
    print(a%91)
