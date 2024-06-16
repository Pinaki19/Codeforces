import sys

def generate():
    val=sys.argv[1]
    print(1)
    m=95000
    print(m)
    s=''
    for i in range(m):
        s+=val
        if(i!=m-1):
            s+=' '
    print(s)
    print(s)
    print(m)
    print(s)
generate()


        