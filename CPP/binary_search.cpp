#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ar[n];
	for(int i=0;i<n;++i) cin >> ar[i];
	sort(ar, ar + n);

	int target;
	cin >> target;
	int hi = n-1, lo = 0;
	while(lo <= hi) {
		int mid = (hi+lo)/2;
		if(ar[mid] == target) {
			cout << "Found!\n";
			return 0;
		}
		if(target > ar[mid]) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << "Not Found!\n";
	return 0;
}