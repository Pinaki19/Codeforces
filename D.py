t=int(input())
def diff(s1,s2):
    c=0
    for i in range(len(s1)):
        if(s1[i]!=s2[i]):
            c+=1
        if(c>1):
            return False
    return True if c<=1 else False
for _ in range(t):
    n=int(input())
    s=input()
    mid= n//2
    for x in range(1,mid+1):
        if(n%x!=0):
            continue
        t=n//x
        p=s[:x]
        q=s[x:2*x]
        if(diff(s,p*t) or diff(s,q*t)):
            print(x)
            break
    else:
        print(n)