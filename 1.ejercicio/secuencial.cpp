void normaliza_secuencial(double** A, int n){
    int i, j;
    double suma = 0.0, factor;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            suma = suma + A[i][j]*A[i][j]; 
        }
    }
    factor = 1.0/sqrt(suma);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            A[i][j] = factor*A[i][j];
        }
    }
}