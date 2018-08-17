#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <cstdlib>
#include <cassert>

#include "slurp_file.h"

int main(int argc, char *argv[])
{

	int numtasks, taskid, len;
	char hostname[MPI_MAX_PROCESSOR_NAME];


	MPI_Init (&argc, &argv);
	MPI_Comm_size (MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank (MPI_COMM_WORLD, &taskid);

	MPI_Get_processor_name (hostname, &len);

	int rank;

	std::vector<int> v[4];
	slurp_file_line("array.txt", taskid+1, &v[taskid]);

#if 1	
	for (std::vector<int>::iterator i=v[taskid].begin(); i!=v[taskid].end(); i++)
	{

		std::cout << *i << " " ;
	}
	std::cout << "\n";
#endif

	MPI_Finalize();

}
