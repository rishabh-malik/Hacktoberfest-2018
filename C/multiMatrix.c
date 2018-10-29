#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    if(argc < 2){
        fprintf(stderr, "Falta el tamaño de las componentes\n");
        exit(-1);
    }


    unsigned int N = atoi(argv[1]); 

    int **matriz1, **matriz2, **matriz3, i, j, k;
    matriz1 = (int **) malloc(N*sizeof(int*));
    matriz2 = (int **) malloc(N*sizeof(int*));
    matriz3 = (int **) malloc(N*sizeof(int*));

    for (i=0; i<N; i++){
        matriz1[i] = (int *) malloc(N*sizeof(int));
        matriz2[i] = (int *) malloc(N*sizeof(int));
        matriz3[i] = (int *) malloc(N*sizeof(int));
    }

    // Initialization
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            matriz1[i][j] = 0;
            matriz2[i][j] = 3;
            matriz3[i][j] = 3;
        }
    }
    

    // Multiplication
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            for (k=0; k<N; k++)
                matriz1[i][j] += matriz2[i][k] * matriz3[k][j];

    
    
    for (i=0; i<N; i++){
        free(matriz1[i]);
        free(matriz2[i]);
        free(matriz3[i]);
    }

    free(matriz1);
    free(matriz2);
    free(matriz3);

    return 0;
}
