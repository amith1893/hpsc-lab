#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int numtasks, taskid, len;
	char hostname[MPI_MAX_PROCESSOR_NAME];

	MPI_Init (&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

	MPI_Get_processor_name (hostname, &len);

	int a[] = {7,1,4,3,5};

	int max = 0;
	
	int i = 4;

	{

		/* One way for the first processor ie. the highest ranked processor */
		if (rank == 4)
		{
			MPI_Send(&a[i], 1, MPI_INT, i-1, 0, MPI_COMM_WORLD);

			i--;
		}
		else if (rank == i)
		{
			int b;
			MPI_Recv(&b, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &st);
			
			if (i == 0)
			{
				printf("MAX is %d\n", b);
				break;
			}

			i--;
			MPI_Send(&b, 1, MPI_INT, i-1, 0, MPI_COMM_WORLD);

		}
	}

	MPI_Finalize();
}
