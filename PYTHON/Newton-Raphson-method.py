#Newton Raphson method 
coeff=[]
dervcoeff=[]
f1=0
f2=0
c=0
lim=[0,0]
degree = int(input("Enter degree of equation:"))
for i in range(degree,-1,-1):
	inp = int(input("Enter coefficient of x^"+str(i)+":"))
	dervcoeff.append(inp*i)
	coeff.append(inp)
n = int(input("Enter number of iterations:"))
while(1):
        for j,k in zip(range(len(coeff)),range(degree,-1,-1)):
            f1=f1+(coeff[j]*(c**k))
        lim[0]=lim[1]
        lim[1]=f1
        #print(f1)
        #print(lim)
        if (lim[0]<0 and lim[1]>0):
                if 0-lim[0] < lim[1]:
                        x0=c-1
                elif lim[1] < 0-lim[0]:
                        x0=c
                        break
        elif (lim[0]>0 and lim[1]<0):
                if 0-lim[1] < lim[0]:
                        x0=c
                elif lim[0] < 0-lim[1]:
                        x0=c-1
                        break
        c=c+1
        f1=0
#print(lim)
f1=0
#x0 = float(input("Enter 1st approximate root:"))
for i in range(0,n+1):
	for j,k in zip(range(len(coeff)),range(degree,-1,-1)):
		f1=f1+(coeff[j]*(x0**k))
	for j,k in zip(range(len(dervcoeff)-1),range(degree-1,-1,-1)):
		f2=f2+(dervcoeff[j]*(x0**k))
	x0 = x0-(f1/f2) 
	f1=0
	f2=0
print(x0)
