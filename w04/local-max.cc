#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <cstdlib>
#include <cassert>

#include "slurp_file.h"

#if 0
int get_max (std::vector<data_t> *v)
{       
   int max = 0;
   for (std::vector<int>::iterator i=v.begin(); i!= v.end(); i++)
   {
        
   }
}
#endif

int main(int argc, char *argv[])
{

    int numtasks, taskid, len;
    char hostname[MPI_MAX_PROCESSOR_NAME];


	char *filename = argv[1];

    MPI_Init (&argc, &argv);
    MPI_Comm_size (MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank (MPI_COMM_WORLD, &taskid);

    MPI_Get_processor_name (hostname, &len);

    int rank;

    std::vector<int> v[numtasks];
    slurp_file_line(filename, taskid, &v[taskid]);

    int max = 0;
    std::vector<int>::iterator i;
    for (i=v[taskid].begin(); i!=v[taskid].end(); i++)
    {
        
        if (*i>max)
           max=*i;

    }
    std::cout << "MAX of processor with rank " << taskid << " is " << max;    
    std::cout << "\n";

    MPI_Finalize();

}

