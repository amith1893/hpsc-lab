#include <stdio.h>
#include <stdlib.h>

int calc_prod (int a[], int x[])
{
	
}

int main()
{

	int a[4][4] = {
					{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}
				  };


	int y[4] = {1, 2, 3, 4};
	int x[4] = {5,6,7,8};


	int z[4][4];

	int i, j, k;
	for (i=0; i<4; i++)
	{
		for (k=0; k<4; k++)
		{
			z[i][k] =  a[i] * x[k];
		}
	}
}
}
