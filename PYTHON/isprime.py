x = input()
flag =0

for i in range (2,x):
    if (x%i==0):
        flag =1
        break

if (flag == 0):
    print "YES"
else:
    print "NO"
