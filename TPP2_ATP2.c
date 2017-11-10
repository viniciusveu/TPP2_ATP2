/* Algoritmo 01 – Algoritmo de QuickSort;                            (obrigatório)
   Algoritmo 03 – Multiplicação de matrizes (algoritmo de Strassen); (opcional)   */

//================================================================scope==============================================================

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX 10
#define JUMP "\n\n"

//===============================================================scopo===============================================================

void ImprimirArray(int *V, int Dim);
void PreencherArray(int *V, int Dim);
void QuickSort(int *V, int p, int r);
static int Separa(int *V, int p, int r);


//===============================================================main================================================================

int main(void){
	
	setlocale(LC_ALL, "");

	int Array[MAX], p, r;
	PreencherArray(Array, MAX);

	printf("O array é:\n");
	ImprimirArray(Array, MAX);

	p = Array[0]; r = Array[MAX-1];

	QuickSort(Array, p, r);

	printf("\n\nO array ordenado por QuickSort é:\n");
	ImprimirArray(Array, MAX);


	return 0;
}


//==============================================================funções==============================================================


void ImprimirArray(int *V, int Dim) {
	int i;

	for(i=0; i<Dim; i++)
		printf("%d\n", *(V+i));
	return;
}//ImprimirArray


void PreencherArray(int *V, int Dim) {
	time_t t;
	int i;

	srand((unsigned) time(&t));
	for(i=0; i<Dim; i++)
		*(V+i) = rand()%1000;
	return;
}//PreencherArray


// void QuickSort(int *V, int p, int r) {
// 	int j;
   	
//    	while (p < r) {      
//     	j = Separa (V, p, r);    
//     	if (j - p < r - j) {     
//         	QuickSort(V, p, j-1);
//         	p = j + 1;            
//     	} else {                 
//         	QuickSort(V, j+1, r);
//         	r = j - 1;
//     	}
//    	}

//    	return;
// }//QuickSort


void QuickSort (int *V, int p, int r) {
	int j;

   	while (p < r) {          
   		j = Separa(V, p, r); 
    	QuickSort(V, p, j-1);
      	p = j + 1;            
   	}
   	
   	return;
}


static int Separa(int *V, int p, int r) {
	int c = *(V+p), i = p+1, j = r, t;
	
	while (i <= j) {
   		if (*(V+i) <= c) ++i;
   		else if (c < *(V+j)) --j; 
   		else {
   			t = *(V+i), *(V+i) = *(V+j), *(V+j) = t;
   			++i; --j;
   		}
	}
   	// agora i == j+1                 
   	*(V+p) = *(V+j); *(V+j) = c;
   
   	return j; 
}//Separa


//===================================================================================================================================




