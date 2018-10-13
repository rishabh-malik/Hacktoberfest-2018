#trapeziodal rule
x0 = int(input("Enter first value of x:"))
xn = int(input("Enter last value of x:"))
n = int(input("Enter number of iterations:"))
h = ((xn-x0)/n)
x=[x0]
f=0
m=0
y=[]
while (m+h)!=xn:
	x.append(m+h)
	m=m+h
x.append(xn)
#print(x)
degree = int(input("Enter degree of f(x):"))
coeff=[]
for i in range(degree,-1,-1):
	inp = int(input("Enter coefficient of x^"+str(i)+":"))
	coeff.append(inp)
power = float(input("Enter power of f(x)"))
#print(x)
for i in range(len(x)):
	for j,k in zip(range(len(coeff)),range(degree,-1,-1)):
		f = f+coeff[j]*(x[i]**k)
	f=f**power
	y.append(f)
	f=0
print(y)
for i in range(1,len(y)-1):
	f=f+y[i]
I = (0.5*h)*((y[0]+y[-1])+(2*f))
print(I)
