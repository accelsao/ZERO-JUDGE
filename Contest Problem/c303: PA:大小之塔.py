while 1:
    try:
        a = int(input())
    except EOFError:
        break;
    b=input()
    for i in b:
        print(chr(ord(i)+32) if ord(i)<97 else chr(ord(i)-32),end="")
    print()
