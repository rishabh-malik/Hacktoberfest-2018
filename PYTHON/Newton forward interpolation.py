#Newton's forward Interpolation 
def fact(n):
	for i in range(1,n):
		n=n*i
	return n
x=[0,5,10,15,20]
gap = int(input("Enter value of interval gap:"))
ran = int(input("Enter range:"))
fx = []
f=[]
for i in range(0,ran+1):
	t=i*gap
	inp = float(input("Enter value of f(x) for x="+str(t)))
	inp=round(inp,2)
	fx.append(inp)
f.append(fx)
fx=[]
k=len(f)-1
c=0
while 1:
	for j in range(len(f[c])-1):
		t=f[c][j+1]-f[c][j]
		t=round(t,2)
		fx.append(t)
	f.append(fx)
	fx=[]
	c=c+1
	if len(f[c])==1:
		break
chf = int(input("Enter value of x for which f(x) is to be found:"))
for i in range(len(x)):
	if x[i]<chf and x[i+1]>chf:
		t=i
		break
p=(chf-0)/gap
y=f[0][t]
for i in range(1,len(f)):
	if len(f[i])>=t and i>1:
		p=p*(p-(i-1))
		y=y+((p/fact(i))*f[i][t])
	else:
		y=y+(p*f[i][t])
print(y)














