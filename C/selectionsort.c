#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *v, int n){
	//localiza o menor elemento
	int aux, menor;
	for(int i = 0; i < n; i++){
		menor = i;
		for(int j = i+1; j < n; j++)
		{	
			if(v[j] < v[menor]){
			menor = j;
			}
		}
		//faz o swap
		aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;
	}
}

int main(){
	
	int vetor[5] = {3, 1, 4, 2, 5};
	selection_sort(vetor, 5);
	
	for (int i = 0; i < 5; i++){
		printf("V[%d] = %d\n", i, vetor[i]);
	}
	
	return 0;
}
