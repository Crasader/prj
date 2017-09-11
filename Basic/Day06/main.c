
#pragma warning( disable : 4996)
#include <stdio.h>

int max(int ary[], int length);
int min(int ary[], int length);
int sum(int ary[], int length);
void BackPrint(char ary[], int n);
char maxChar(char ary[], int length);

int Max = 0;
int Min = 0;
int Sum = 0;

void max2(int input)
{
	if (input > Max) Max = input;
}
void min2(int input)
{
	if (Min == 0) Min = input;
	else if (input < Min) Min = input;
}
void sum2(int input)
{
	Sum += input;
}

int main()
{
//	//11 - 1
//
//	int ary[5];
//	int length;
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d번째 정수 입력 : \n", i);
//		scanf("%d", &ary[i]);
//	}
//	length = sizeof(ary) / sizeof(ary[0]);
//
//	for (int i = 0; i < length; i++)
//	{
//		max2(ary[i]);
//	}
//	printf("\n최대값 : %d\n", Max);
//	for (int i = 0; i < length; i++)
//	{
//		min2(ary[i]);
//	}
//	printf("\n최소값 : %d\n", Min);
//	for (int i = 0; i < length; i++)
//	{
//		sum2(ary[i]);
//	}
//	printf("\n총합 : %d\n", Sum);
/*
	printf("\n최대값 : %d\n", max(ary, length));
	printf("최소값 : %d\n", min(ary, length));
	printf("총합 : %d\n", sum(ary, length));
*/
	////11 - 2

	//char strAry[100] = "Good time";
	//printf("%s\n", strAry);

	////11 - 3
	//char input[100];
	//int idx;
	//printf("영단어 입력 : ");
	//scanf("%s", input);

	//for (idx = 0; input[idx] != '\0'; idx++)
	//{
	//}
	//printf("영단어 %s의 길이 : %d\n", input, idx);

	////11 - 4
	//char input[100];
	//printf("영단어 입력 : ");
	//scanf("%s", input);

	//BackPrint(input, 0);

	//printf("\n");

	//11 - 5
	Max = 0;
	char input[100];
	int length;

	printf("영단어 입력 : ");
	scanf("%s", input);

	for (length = 0; input[length] != '\0'; length++) 
	{
		max2(input[length]);
	}
	printf("아스키 코드값이 가장 큰 문자 : %c", Max);


	printf("\n");

	return 0;
	//printf("아스키 코드값이 가장 큰 문자 : %c", maxChar(input, length));
}

int max(int ary[], int length)
{
	int max = ary[0];

	for (int i = 1; i < length; i++)
	{
		if (ary[i] > max) max = ary[i];
	}

	return max;
}
int min(int ary[], int length)
{
	int min = ary[0];

	for (int i = 1; i < length; i++)
	{
		if (ary[i] < min) min = ary[i];
	}

	return min;
}
int sum(int ary[], int length)
{
	int result = 0;

	for (int i = 0; length < 5; i++)
	{
		result += ary[i];
	}

	return result;
}

void BackPrint(char ary[], int n)
{
	if (ary[n] != '\0')
	{
		BackPrint(ary, n + 1);
	}
	printf("%c", ary[n]);
}

char maxChar(char ary[], int length)
{
	int max = ary[0];

	for (int i = 1; i < length; i++)
	{
		if (ary[i] > max) max = ary[i];
	}

	return max;
}