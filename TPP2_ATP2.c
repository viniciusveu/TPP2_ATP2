//Vinícius Vedovotto
//João Pedro Silva Baptista

//Trabalho Prático de Programação 2
//ATP II - FCT/UNESP

//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

//==============================================================================

int num;
int vetor[MAX];

//==============================================================================

void QuickSort(int *array, int count);
void quick(int *array, int ini, int fin);
void strassen(int a[][num], int b[][num], int c[][num], int size);
void startStrassen();
int padding(int num);
void arrayPrint(int *A, int size);
void arrayGen(int *A, int size);

//==============================================================================

void QuickSort(int *array, int count){
	quick(array, 0, count-1);
}

//==============================================================================

void quick(int *array, int ini, int fin){
	int m, i, j, aux;

	i = ini; j = fin;
	m = array[(ini+fin)/2];

	do{
		while(array[i] < m && i<fin)
			i++;
		while(m < array[j] && j>ini)
			j--;

		if(i<=j){
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			i++; j--;
		}

	} while(i <= j);

	if(ini<j) quick(array, ini, j);
	if(i<fin) quick(array, i, fin);

}

//==============================================================================

void strassen(int a[][num], int b[][num], int c[][num], int size) {
	int p1[size/2][size/2], p2[size/2][size/2], p3[size/2][size/2], p4[size/2][size/2],
	p5[size/2][size/2], p6[size/2][size/2], p7[size/2][size/2];
	int temp1[size/2][size/2], temp2[size/2][size/2];
	int q1, q2, q3, q4, q5, q6, q7, i, j;

	if(size >= 2) {
	//p1
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp1[i][j] = a[i][j] + a[i + size / 2][j + size / 2];
		}
	}
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp2[i][j] = b[i][j] + b[i + size / 2][j + size / 2];
		}
	}
	num = size / 2;
	strassen(temp1, temp2, p1, size / 2);
    //p2
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp1[i][j] = a[i + size / 2][j] + a[i + size / 2][j + size / 2];
		}
	}
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp2[i][j] = b[i][j];
		}
	}
	num = size / 2;
	strassen(temp1, temp2, p2, size / 2);
	//p3
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp1[i][j] = a[i][j];
		}
	}
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp2[i][j] = b[i][j + size / 2] - b[i + size / 2][j + size / 2];
		}
	}
	num = size / 2;
	strassen(temp1, temp2, p3, size / 2);
	//p4
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp1[i][j] = a[i + size / 2][j + size / 2];
		}
	}
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			temp2[i][j] = b[i + size / 2][j] - b[i][j];
		}
	}
	num = size / 2;
	strassen(temp1, temp2, p4, size / 2);
	//p5
	for(i = 0; i < size / 2; i++)
		for(j = 0; j < size / 2; j++)
			temp1[i][j] = a[i][j] + a[i][j + size / 2];

	for(i = 0; i < size / 2; i++)
		for(j = 0; j < size / 2; j++)
			temp2[i][j] = b[i + size / 2][j + size / 2];

	num = size / 2;
	strassen(temp1, temp2, p5, size / 2);
	//p6
	for(i = 0; i < size / 2; i++)
		for(j = 0; j < size / 2; j++)
			temp1[i][j] = a[i + size / 2][j] - a[i][j];

	num = size / 2;
	for(i = 0; i < size / 2; i++)
		for(j = 0; j < size / 2; j++)
			temp2[i][j] = b[i][j] + b[i][j + size / 2];

	num = size / 2;
	strassen(temp1, temp2, p6, size / 2);
	//p7
	for(i = 0; i < size / 2; i++)
		for(j = 0; j < size / 2; j++)
			temp1[i][j] = a[i][j + size / 2] - a[i + size / 2][j + size / 2];

	for(i = 0; i < size / 2; i++)
		for(j = 0; j < size / 2; j++)
			temp2[i][j] = b[i + size / 2][j] + b[i + size / 2][j + size / 2];


	num = size / 2;
	strassen(temp1, temp2, p7, size / 2);
	//c11
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			c[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
		}
	}
	//c12
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			c[i][j + size / 2] = p3[i][j] + p5[i][j];
		}
	}
	//c21
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			c[i + size / 2][j] = p2[i][j] + p4[i][j];
		}
	}
	//c22
	for(i = 0; i < size / 2; i++) {
		for(j = 0; j < size / 2; j++) {
			c[i + size / 2][j + size / 2] = p1[i][j] + p3[i][j] - p2[i][j] + p6[i][j];
		}
	}
 }
 else if(size == 1) {
 	c[0][0] = a[0][0] * b[0][0];
 }
}

//==============================================================================

int padding(int num) {
	int original_num = num, lower_power = 0, i, actual_num = 1;

	if(num == 1)
		return 1;

	while(num > 1) {
		lower_power++;
		num /= 2;
	}

	for(i = 0; i < lower_power; i++) {
		actual_num *= 2;
	}

	if(actual_num == original_num)
		return original_num;
	else
		return actual_num * 2;
}

//==============================================================================

void startStrassen(){
	int i, j, temp;
	printf("Digite o tamanho das Matrizes:\n");
	scanf("%d", &num);
	temp = num;

	if(num <= 0)
		return;

	num = padding(num);

	int a[num][num], b[num][num], c[num][num];

	printf("Digite a Matriz A:\n");
	for(i = 0; i < temp; i++) {
		for(j = 0; j < temp; j++) {
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}

	for(j = temp; j < num; j++) {
		a[i][j] = 0;
		}
	}

	for(i = temp; i < num; i++)
		for(j = 0; j < num; j++)
			a[i][j] = 0;

	printf("\nDigite a Matriz B:\n");
	for(i = 0; i < temp; i++) {
		for(j = 0; j < temp; j++) {
			printf("B[%d][%d] = ", i+1, j+1);
			scanf("%d", &b[i][j]);
		}

	for(j = temp; j < num; j++) {
		b[i][j] = 0;
		}
	}

	for(i = temp; i < num; i++)
		for(j = 0; j < num; j++)
		b[i][j] = 0;

	printf("Matriz A:\n");

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			printf("%d ", a[i][j]);
		}

	printf("\n");
	}

	printf("\nMatriz B:\n");

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			printf("%d ", b[i][j]);
		}
	printf("\n");
	}

	strassen(a, b, c, num);

	printf("\nMatriz C (A x B):\n");

	for(i = 0; i < temp; i++) {
		for(j = 0; j < temp; j++) {
			printf("%4d ", c[i][j]);
	}
		printf("\n");
	}
}

//==============================================================================

void arrayPrint(int *A, int size){
	int i;

	for(i=0; i<size; i++)
		printf("[%d]\n", *(A+i));
}

//==============================================================================

void arrayGen(int *A, int size){
	time_t t;
	int i;

	srand((unsigned) time(&t));
	for(i=0; i<size; i++)
		*(A+i) = rand()%1000;
	return;
}

//==============================================================================

void menu(){
	//system("cls");
	int res;
	time_t t;
	int i;
	printf("QUICKSORT [1]\nALGORITMO DE STRASSEN [2]\n");
	scanf("%d", &res);

	switch(res){
		case 1:
			arrayGen(vetor, MAX);
			printf("Vetor atual, não ordenado: \n");
			arrayPrint(vetor, MAX);
			printf("===================================\n");
			QuickSort(vetor, MAX);
			printf("Vetor atual, ordenado: \n");
			arrayPrint(vetor, MAX);
			printf("===================================\n");
			break;
		case 2:
			startStrassen();
			break;
		default:
			menu();

	}

}

//==============================================================================

int main(){
	menu();

	//system("pause");
	return 0;

}
