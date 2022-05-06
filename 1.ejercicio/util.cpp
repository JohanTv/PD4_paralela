double** inicializar_matriz(int n){
    double** matrix = new double*[n];
    for(int i = 0; i < n; ++i)
        matrix[i] = new double[n];
    return matrix;
}

double** generar_matriz(int n){
    double** matrix = inicializar_matriz(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = (int) rand()%250 + 1;
        }
    }
    return matrix;
}

double** copiar_matriz(double** A, int n){
    double** B = inicializar_matriz(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            B[i][j] = A[i][j];
        }
    }
    return B;
}

void imprimir_matriz(double** A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("\t%f\t", A[i][j]);
        }
        printf("\n");
    }
}