//F0 = 0, F1 = 1, F2 = 1, Fn=Fn-1+Fn-2
//(Fn+1, Fn) (1, 1)n
//(Fn, Fn-1)=(1, 0)
#include <memory.h>
int Result[2][2] = { 1, 1, 1, 0 };
void multiply(const int(*a)[2], const int(*b)[2]);
void PowerMatrix(int n);
const int elementMatrix[2][2] = {1,1,1,0};
void initial()
{
	Result[0][0] = 1;
	Result[0][1] = 1;
	Result[1][0] = 1;
	Result[1][1] = 0;
}
int Fibonacci(int n)
{

	if (n == 0)
	{
		return 0;
	}

	PowerMatrix(n);
	int i =  Result[0][1];
	initial();
	return i;
}
void PowerMatrix(int n)
{
	if (n > 1)
	{
		PowerMatrix(n / 2);

		if (n % 2 == 0)
		{
			multiply(Result, Result);
		}
		else
		{
			multiply(Result, Result);
			multiply(Result, elementMatrix);
		}
	}
}

void multiply(const int(*a)[2], const int(*b)[2])
{
	int copyA[2][2] = {0};
	int copyB[2][2] = {0};
	
	memcpy(copyA,a,4*sizeof(int));
	memcpy(copyB, b, 4 * sizeof(int));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Result[i][j] = copyA[i][0] * copyB[0][j] + copyA[i][1] * copyB[1][j];
		}
	}
}

