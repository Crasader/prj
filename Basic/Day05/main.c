
#pragma warning( disable : 4996)
#include<stdio.h>

int num1;

void OneAdd(int val);

//

int Add(int a, int b);
void ShowAddResult(int num);
int ReadNum();
void HowToUseThisProg();
int NumberCompare(int num1, int num2);

//

int AbsoCompare(int num1, int num2);
int GetAbsoValue(int num);

//

int SimpleFuncOne(void);
int SimpleFuncTwo(void);

//

void SimpleFunc(void)
{
	static int num1 = 0;
	int num2 = 0;
	num1++; num2++;
	printf("static : %d, local : %d\n", num1, num2);
}

void Recursive(int input)
{
	if (input <= 0)
	{
		return;
	}
	printf("Recursive Call : %d\n", input);
	Recursive(input - 1);
}
int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main()
{
	Recursive(3);
	for (int i = 0; i < 9; i++)
	{
		printf("%d! = %d \n", i,Factorial(i));
	}

	return 0;
}

void OneAdd(int val)
{
	num1 += val;
}

//

int SimpleFuncOne(void)
{
	int num = 10;
	num++;
	printf("SimpleFuncOne num : %d\n", num);
	return 0;
}
int SimpleFuncTwo(void)
{
	int num1 = 20;
	int num2 = 30;
	num1++, num2--;
	printf("num1 & num2 : %d %d\n", num1, num2);
	return 0;
}

//

int Add(int a, int b)
{
	return a + b;
}
void ShowAddResult(int num)
{
	printf("결과 : %d\n", num);
}
int ReadNum()
{
	int num;
	scanf_s("%d", &num);
	return num;
}
void HowToUseThisProg()
{
	printf("두 개의 정수 입력\n");
}

int NumberCompare(int num1, int num2)
{
	int result;
	if (num1 > num2)result = num1;
	else result = num2;

	return result;
}

//

int AbsoCompare(int num1, int num2)
{
	if (GetAbsoValue(num1) > GetAbsoValue(num2))
	{
		return num1;
	}
	else
	{
		return num2;
	}
}
int GetAbsoValue(int num)
{
	if (num < 0)
		return num * -1;
	else return num;
}

//
