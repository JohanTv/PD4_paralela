#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "util.cpp"
#include "secuencial.cpp"
#include "1_region.cpp"
#include "2_regiones.cpp"
using namespace std;

int main(){
    srand(time(NULL));
    int n = 5;
    double** A = generar_matriz(n);
    double** B = copiar_matriz(A, n);
    double** C = copiar_matriz(A, n);
    normaliza_secuencial(A, n);
    normaliza_parallel_2_regiones(B, n);
    normaliza_parallel_1_region(C, n);
    printf("Matriz A:\n");
    imprimir_matriz(A, n);
    printf("\n\n");
    printf("Matriz B:\n");
    imprimir_matriz(B, n);
    printf("\n\n");
    printf("Matriz C:\n");
    imprimir_matriz(C, n);
}