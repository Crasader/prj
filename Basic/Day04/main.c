
#pragma warning( disable : 4996)
#include <stdio.h>

int main()
{
/*
	int num = 0;
	printf("정수 입력 : \n");
	scanf_s("%d", &num);

	if (num < 0) printf("입력 값은 0보다 작다.\n");
	if (num > 0) printf("입력 값은 0보다 크다.\n");
	if (num == 0) printf("입력 값은 0이다.\n");
*/

	//int opt;
	//double input1, input2;
	//double result;

	//for (;;)
	//{
	//	printf("1. +\n2. -\n3. *\n4. /\n0.Exit\n");
	//	scanf_s("%d", &opt);

	//	if (opt != 0 && opt <= 4)
	//	{
	//		printf("두 개의 실수 입력 : a b\n");
	//		scanf_s("%lf %lf", &input1, &input2);

	//		switch (opt)
	//		{
	//		case 1: result = input1 + input2; break;
	//		case 2: result = input1 - input2; break;
	//		case 3: result = input1 * input2; break;
	//		case 4: result = input1 / input2; break;
	//		}
	//		printf("Result : %f\n", result);
	//	}
	//	else break;
	//}
/*
	int num;
	printf("정수 입력 :\n");
	scanf_s("%d", &num);
	if (num < 0)
	{
		printf("입력값은 0보다 작다.\n");
	}
	else
	{
		printf("입력값은 0보다 작지 않다.\n");
	}*/

//
//	int opt;
//	double input1, input2;
//	double result;
//
//	for (;;)
//	{
//		printf("1. +\n2. -\n3. *\n4. /\n0.Exit\n");
//		scanf_s("%d", &opt);
//
//		if (opt != 0 && opt <= 4)
//		{
//			printf("두 개의 실수 입력 : a b\n");
//			scanf_s("%lf %lf", &input1, &input2);
///*
//			if (opt == 1) result = input1 + input2;
//			else if (opt == 2) result = input1 - input2;
//			else if (opt == 3) result = input1 * input2;
//			else if (opt == 4) result = input1 / input2;
//*/
//			switch (opt)
//			{
//			case 1: result = input1 + input2; break;
//			case 2: result = input1 - input2; break;
//			case 3: result = input1 * input2; break;
//			case 4: result = input1 / input2; break;
//			}
//			printf("Result : %f\n", result);
//		}
//		else break;
//	}
/*
	int num, abs;
	printf("정수 입력 : \n");
	scanf("%d", &num);

	abs = num > 0 ? num : num*(-1);
	printf("절대값 : %d\n", abs);
	*/
/*
	int sum = 0, num = 0;
	
	while (1)
	{
		sum += num;
		if (sum > 5000) break;
		num++;
	}

	printf("sum : %d\n", sum);
	printf("num : %d\n", num);
*//*

	printf("start ! ");
	for (int num = 1; num < 20; num++)
	{
		if (num % 2 == 0 || num % 3 == 0)
			continue;
		printf("%d ", num);
	}
	printf("end! \n");
*/

	//int num;
	//printf("1 이상 5 이하의 정수 입력 : ");
	//scanf("%d", &num);

	//switch (num)
	//{
	//case 1: printf("1은 ONE\n");
	//	break;
	//case 2: printf("2는 TWO\n");
	//	break;
	//case 3: printf("3은 THREE\n");
	//	break;
	//case 4: printf("4는 FOUR\n");
	//	break;
	//case 5:printf("5는 FIVE\n");
	//	break;
	//default:
	//	printf("I don't know! \n");
	//}

	//char sel;
	//printf("M 오전, A 오후, E 저녁\n");
	//printf(" 입력 : ");
	//scanf("%c", &sel);

	//switch (sel)
	//{
	//case 'M':
	//case 'm':
	//	printf("MORNING!\n");
	//	break;
	//case 'A':
	//case 'a':
	//	printf("Afternoon\n");
	//	break;
	//case 'E':
	//case 'e':
	//	printf("Evening\n");
	//	break;
	//}

for (int i = 2; i <= 9; i++)
{
	if (i % 2 == 0)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d * %d = %d\n", i, j, i*j);
		}
		printf("\n");
	}
}

int result = 0;

if (result >= 90)
{
	printf("A");
}
else
{
	if (result >= 80 && result <90)
	{
		printf("B");
	}
}


if (result >= 90)
{
	printf("A");
}
if (result >= 80 && result <90)
{
	printf("B");
}



	return 0;
}