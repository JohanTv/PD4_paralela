void normaliza_parallel_1_region(double** A, int n){
    int i, j;
    double start=0.0,end=0.0;
    double suma = 0.0, factor;
    #pragma omp parallel num_threads(8) shared(n, factor) private(i,j)
    {
        start = omp_get_wtime(); 
        #pragma omp for reduction(+:suma)
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
                suma = suma + A[i][j]*A[i][j];
        }
        #pragma omp barrier
        #pragma omp master
        factor = 1.0/sqrt(suma);
        #pragma omp barrier
        #pragma omp for
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
                A[i][j] = factor*A[i][j];
        }
        end = omp_get_wtime(); 
    }
    printf("1 Region\t %f\n", end - start);
}