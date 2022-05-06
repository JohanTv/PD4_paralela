void normaliza_parallel_2_regiones(double** A, int n){
    int i, j;
    double suma = 0.0, factor;
    #pragma omp parallel num_threads(4) shared(n) private(i,j)
    {
        #pragma omp for reduction(+:suma)
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
                suma = suma + A[i][j]*A[i][j];
        } 
    }

    #pragma omp parallel num_threads(4) shared(factor, suma) private(i,j)
    {
        #pragma omp master
        factor = 1.0/sqrt(suma);
        #pragma omp barrier
        #pragma omp for
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
                A[i][j] = factor*A[i][j];
        } 
    }
}