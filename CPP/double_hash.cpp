// Calculates hash of a string in O(n) time. Gets hash of substring in O(1) time.
// Can be used to check matches between strings/substrings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MAXN 250007

struct DoubleHash {
	ll powers1[MAXN], powers2[MAXN], values1[MAXN], values2[MAXN], prime1, prime2;

	DoubleHash(const string &word, const ll base1 = 419, const ll base2 = 521, const ll prime1 = 82517999, const ll prime2 = 76824091) {
		precalcPowers(powers1, base1, prime1);
		precalcPowers(powers2, base2, prime2);

		precalcValues(values1, base1, prime1, powers1, word);
		precalcValues(values2, base2, prime2, powers2, word);

		this->prime1 = prime1;
		this->prime2 = prime2;
	}

	void precalcPowers(ll *powers, const ll base, const ll prime) {
		powers[0] = 1;
		for(int i = 1; i < MAXN; i++) {
			powers[i] = powers[i-1] * base;
			powers[i] %= prime;
		}
	}

    void precalcValues(ll *values, const ll base, const ll prime, ll *powers, const string &word) {
    	int tam = ((int) word.size());
    	values[0] = word[0] + 307;
		for(int i = 1; i < tam; i++) {
			values[i] = ( word[i] + 307 ) + (values[i-1] * base);
			values[i] %= prime;
		}
	}

	P hashSubstr(int l, int r) {
		if(l == 0) return make_pair(values1[r], values2[r]);
		ll r1, r2;	

		r1 = (values1[r] - (values1[l-1] * powers1[r - l + 1])%this->prime1 + this->prime1) % this->prime1;
		r2 = (values2[r] - (values2[l-1] * powers2[r - l + 1])%this->prime2 + this->prime2) % this->prime2;

		return make_pair(r1, r2);
	}
};