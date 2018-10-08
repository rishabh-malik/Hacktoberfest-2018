#iteration method
coeff=[]
funcfi=[]
s=0
c=0
lim=[0,0]
degree=int(input("Enter degree of eqn:"))
for i in range(degree,-1,-1):
	inp = int(input("Enter coefficient of x^"+str(i)+":"))
	coeff.append(inp)
degreefi = int(input("Enter degree of fi function:"))
for i in range(degreefi,-1,-1):
	inp = float(input("Enter coefficient of x^"+str(i)+" in fi function:"))
	funcfi.append(inp)
p = float(input("Enter power of fi functon:"))
while 1:
	for k,j in zip(range(degree,-1,-1),range(0,degree+1)):
		s=s+(coeff[j]*(c**k))
	lim[0]=lim[1]
	lim[1]=s
	s=0
	if (lim[0]<0 and lim[1]>0) or (lim[0]>0 and lim[1]<0):
		break
	c=c+1
while 1:
	for i,j in zip(range(degreefi,-1,-1),range(0,degreefi+1)):
		s=s+(funcfi[j]*(lim[0]**i))
	s=s**p
	lim[1]=lim[0]
	lim[0]=s
	s=0
	if round(lim[0],3)==round(lim[1],3):
		break
print("Approximate root of eqn is:",round(lim[0],3))
