#pragma warning(disable : 4996)
#include<stdio.h>

int main()
{/*
	int arr1[2][3][4];
	double arr2[5][5][5];

	printf("���� 2, ���� 3, ���� 4�� int�� �迭 : %d\n", sizeof(arr1));
	printf("���� 5, ���� 5, ���� 5�� double�� �迭 : %d\n", sizeof(arr2));

	return 0;*/

	int mean = 0, i, j;
	int record[3][3][2] = {
		{
			{ 70,80 },
			{ 94,90 },
			{ 70,85 }
		},
		{
			{ 83,90 },
			{ 95,60 },
			{ 90,82 }
		},
		{
			{ 98,89 },
			{ 99,94 },
			{ 91,87 }
		}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				mean += record[i][j][k];
				//printf("%d", record[i][j][k]);
			}
		}
		switch (i)
		{
			case 0:printf("A"); break;
			case 1:printf("B"); break;
			case 2:printf("C"); break;
		}
		printf(" �б� ��ü ��� : %g\n", (double)mean / 6);
		mean = 0;
	}

	return 0;
}