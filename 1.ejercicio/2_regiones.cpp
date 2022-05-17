void normaliza_parallel_2_regiones(double** A, int n){
    int i, j;
    double suma = 0.0, factor;
    double start=0.0,end=0.0;
    #pragma omp parallel num_threads(8) shared(n) private(i,j)
    {
        start = omp_get_wtime(); 
        #pragma omp for reduction(+:suma)
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
                suma = suma + A[i][j]*A[i][j];
        } 
        end = omp_get_wtime(); 
    }
    double start2=0.0,end2=0.0;
    #pragma omp parallel num_threads(8) shared(factor, suma) private(i,j)
    {
        start2 = omp_get_wtime(); 
        #pragma omp master
        factor = 1.0/sqrt(suma);
        #pragma omp barrier
        #pragma omp for
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++)
                A[i][j] = factor*A[i][j];
        }
        end2 = omp_get_wtime();  
    }
    printf("2 Regiones\t %f\n", (end - start)+(end2 - start2));
}