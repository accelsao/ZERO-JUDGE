while 1:
    try:
        a=input()
    except EOFError:
        break;
    for i in range(len(a)):
        print(chr(ord(a[i])-7),end="")
    print()
