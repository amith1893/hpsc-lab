#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int numtasks, rank, len;
	char hostname[MPI_MAX_PROCESSOR_NAME];

	MPI_Init (&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Get_processor_name (hostname, &len);


	MPI_Status st;
	if (rank == 0) {
		int a = 123;
		MPI_Send(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else if (rank == 1) {
		int b;
		MPI_Recv(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
		std::cout<<"Process 1 received number "<<b<<" from process 0\n";
	}

	MPI_Finalize();
}
