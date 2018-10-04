// EUCLID'S ALGORITHM
#include <iostream>
#include <algorithm>
using namespace std;

int euclid(int n,int m){
	if(m==0)
		return n;
	return euclid(m,n%m);
}

int main(){
	int n,m;
	cout << "Enter two numbers: ";
	cin >> n >> m;
	cout << "GCD of " << n << " " << m << ": ";
	if(n<m)
		swap(n,m);
	int gcd = euclid(n,m);
	cout << gcd << "\n";
	return 0;
}
