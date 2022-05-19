#include<mpi.h>
#include<iostream>
#include<iomanip>

int main(int argc, char **argv){
    int rank{},size{},inside_points{};
    double begin{},end{};
    double x{},y{};

    MPI_Init( &argc , &argv);
    MPI_Comm_rank( MPI_COMM_WORLD , &rank);
    MPI_Comm_size( MPI_COMM_WORLD , &size);
    begin = MPI_Wtime();

    
    for (size_t j = 0; j < size-1; j++)
    {
        x = (long double)rand()/(long double)(RAND_MAX);
        y = (long double)rand()/(long double)(RAND_MAX);
        if(rank == j){
            if(x*x+y*y <= 1){
                inside_points = inside_points + 1;
            }
            MPI_Send( &inside_points , 1 , MPI_INT , j+1 , 0 , MPI_COMM_WORLD);
        }
        if(rank == j+1){
            MPI_Recv( &inside_points , 1 , MPI_INT , j , MPI_ANY_TAG , MPI_COMM_WORLD , MPI_STATUS_IGNORE);
        }
    
    }

    if(rank == size - 1){
        if(x*x+y*y <= 1){
                inside_points = inside_points + 1;
        }
        MPI_Send( &inside_points , 1 , MPI_INT , 0 , 0 , MPI_COMM_WORLD);
    }
    if(rank == 0){
        MPI_Recv( &inside_points , 1 , MPI_INT , size-1 , MPI_ANY_TAG , MPI_COMM_WORLD , MPI_STATUS_IGNORE);
    }
    end = MPI_Wtime();
    MPI_Finalize();
    std::cout<<"Tiempo:"<<(end-begin)<<" "<<(inside_points/(double)size)*4.0<<std::endl;
}