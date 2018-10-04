// Using segment tree of maximum value in the interval as an example

#include <bits/stdc++.h>
using namespace std;

#define MAXN 201110
typedef long long ll;

ll elements[MAXN], segtree[4*MAXN];

// Time complexity: O(n)
void build(int id, int left, int right) {
	if(left == right) {
		segtree[id] = elements[left];
		return;
	}

	int mid = (left + right)/2;
	
	build(id*2, left, mid);
	build(id*2+1, mid+1, right);

	segtree[id] = max(segtree[id*2], segtree[id*2+1]);
}

// Time complexity: O(logn)
void update(int id, int left, int right, int index) {
	if(left == right) {
		segtree[id] = elements[left];
		return;
	}

	int mid = (left + right)/2;

	if(index <= mid) update(id*2, left, mid, index);
	else update(id*2+1, mid+1, right, index);

	segtree[id] = max(segtree[id*2], segtree[id*2+1]);
}

// Time complexity: O(logn)
ll query(int id, int left, int right, int a, int b) {
	if(left >= a and right <= b) return segtree[id];
	if(right < a or left > b) return ((ll) -1);

	int mid = (left+right)/2;
	return max( query(id*2, left, mid, a, b), query(id*2+1, mid+1, right, a, b) );
}