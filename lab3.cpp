#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char **argv){
MPI_Init(&argc, &argv);
int process,ID;
MPI_Comm_rank(MPI_COMM_WORLD, &ID);
MPI_Comm_size(MPI_COMM_WORLD, &process);
int msg;

if( ID != 0){
   MPI_Recv(&msg, 1,MPI_INT, ID-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
   cout<<"process "<< ID<<" received $ "<< msg <<"from process"<< ID-1<< endl;  
}else{
     msg= -1;
}
MPI_Send(&msg, 1,MPI_INT,(ID+1)%process, 0, MPI_COMM_WORLD);
if (ID == 0){
      MPI_Recv(&msg, 1,MPI_INT, ID-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
 cout<<"process "<< ID<<" received $ "<< msg <<"from process"<< ID-1<< endl;     
}
MPI::Finalize();

return 0; 
}
