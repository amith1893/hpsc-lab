#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <cstdlib>
#include <cassert>

#include "slurp_file.h"

int get_max (std::vector<data_t> v)
{
   int max = 0;
   for (std::vector<int>::iterator i=v.begin(); i!=v.end(); i++)
   {
        if (*i>max)
           max=*i;
   }

   return max;
}

int main(int argc, char *argv[])
{

    int numtasks, taskid, len;
    char hostname[MPI_MAX_PROCESSOR_NAME];
    
	MPI_Status st;
    MPI_Init (&argc, &argv);
    MPI_Comm_size (MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank (MPI_COMM_WORLD, &taskid);
    
    MPI_Get_processor_name (hostname, &len);

    std::vector<int> v[4];
    slurp_file_line("array.txt", taskid, &v[taskid]);
    

	int b, r, gmax;

    if (taskid == numtasks-1)
    {
        b = get_max (v[taskid]);
        
		MPI_Send(&b, 1, MPI_INT, taskid-1, 0, MPI_COMM_WORLD);
        printf("SENT %d to processor %d\n", b, taskid-1);
    }

	if ((taskid > 0) && (taskid < numtasks-1))
    {
        
		b = get_max (v[taskid]);
        
		//Receive
        MPI_Recv (&r, 1, MPI_INT, taskid+1, 0, MPI_COMM_WORLD, &st);

        printf("RECEIVED %d from processor %d\n", r, taskid+1);
        //Compare
        gmax = (r>b) ? r:b;
       
	   	printf("MAXIMUM in processor %d is %d\n", taskid, gmax);	
        //Then Send
       	MPI_Send (&gmax, 1, MPI_INT, taskid-1, 0, MPI_COMM_WORLD);
    }

	if (taskid == 0)
    {
        MPI_Status st;

        b = get_max (v[taskid]);
        
		//Receive
        MPI_Recv (&r, 1, MPI_INT, taskid+1, 0, MPI_COMM_WORLD, &st);

        printf("RECEIVED %d from processor %d\n", r, taskid+1);
        gmax = r > b ? r:b;
       
	   	//Print the result
        printf("The maximum of all the arrays read from the file %d\n", gmax);
    }

    MPI_Finalize();
}

