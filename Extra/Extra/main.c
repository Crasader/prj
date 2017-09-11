#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((int)time(NULL));

	for (int i = 0; i < 20; i++)
	{

		int A, B, C;

		A = rand() % 10;
		B = rand() % 10;
		C = rand() % 10;

		for (;A == B || B == C || A == C;)
		{
			B = rand() % 10;
			C = rand() % 10;
		}

		printf("%d%d%d\n", A, B, C);

	}

	return 0;
}