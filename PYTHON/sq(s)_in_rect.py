n=int(input())
m=int(input())
if m>n:
	n,m=m,n
i=1
while m!=0:
	print("Number of Square(s) of type ",i,"x",i," : ",n*m)
	n,m,i=n-1,m-1,i+1
