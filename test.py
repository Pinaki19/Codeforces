
from random import choice
words=[]
s=""
for p in range(10):
    for i in range(90,101):
        w=(chr)(ord('a')+p)*i
        words.append('"'+w+'"')

prev=""
for i in range(1000):
    prev+=choice(['a','b','c','d','e','f','g','h','i','j'])*90
    prev+=" "

prev.rstrip(" ")

f=open("test.txt","w")
f.write(','.join(words));
f.write('\n\n\n')
f.write('"'+prev+'"')
f.close();
    
