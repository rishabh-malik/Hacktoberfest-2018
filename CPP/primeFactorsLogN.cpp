#include <bits/stdc++.h>
#define MAXX 87000000

using namespace std;

typedef long long ll;

vector < ll > menorFator (MAXX, -1);

void crivo() {
	register unsigned long long i, j;

	menorFator[1] = 1;

	for( i=2 ; i <= MAXX; i ++) {
		if(menorFator[i] == -1) {
			menorFator[i] = i;
			for(j = i * i; j <= MAXX; j += i) 
				menorFator[j] = i;
		}
	}
}
 
vector < ll > primeFactors(ll n){
	vector < ll > retorno;
	while(menorFator[n] != 1){
		retorno.push_back(menorFator[n]);
		n /= menorFator[n];
	}
	return retorno;
}

int main() {
	crivo();
	while(true){
		ll n;
		cin >> n;
		vector < ll > out = primeFactors(n);
		for(int i = 0; i < out.size(); i++){
			cout << out[i] << " ";
		}
		cout << endl;
	}
	return 0;
} 
