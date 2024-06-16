f=open('hack.txt','w')
    f.write('1\n')
    m=80000
    f.write(str(m)+'\n')
    s=''
    s2=''
    for i in range(m):
        s2+='1'
        s+=val
    f.write(s2+'\n')
    f.write(s+'\n')
    f.write(str(m)+'\n')
    f.write(s2)
    f.close()
