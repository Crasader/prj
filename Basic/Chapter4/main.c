
#pragma warning( disable : 4996)
#include <stdio.h>

int main()
{/*
	int num1 = 0xA7, num2 = 0x43;
	int num3 = 032, num4 = 024;

	printf("0xA7�� 10���� ���� �� : %d\n", num1);
	printf("0x43�� 10���� ���� �� : %d\n", num2);
	printf("032�� 10���� ���� �� : %d\n", num3);
	printf("024�� 10���� ���� �� : %d\n", num4);

	printf("%d - %d = %d \n", num1, num2, num1 - num2);
	printf("%d + %d = %d \n", num3, num4, num3 + num4);
*//*
	float result = 0;
	for (int i = 0; i < 100; i++)
	{
		result += 0.1;
	}
	printf("Result : %f\n", result);

	int num = 15;

	printf("<<1 move : %d\n", num << 1);
	printf("<<2 move : %d\n", num << 2);
	printf("<<3 move : %d\n", num << 3);

	num = -16;

	printf("\n>>1 move : %d\n", num >> 1);
	printf(">>2 move : %d\n", num >> 2);
	printf(">>3 move : %d\n", num >> 3);
*/
/*

	char num1 = 1, num2 = 2;
	short num3 = 300, num4 = 400;

	printf("sizeof num1 & num2 : %d, %d \n", sizeof(num1), sizeof(num2));
	printf("sizeof num3 & num4 : %d, %d \n", sizeof(num3), sizeof(num4));
	printf("sizeof char add : %d \n", sizeof(num1 + num2));
	printf("sizeof short add %d \n", sizeof(num3 + num4));

	char result1 = num1 + num2; short result2 = num3 + num4;
	printf("sizeof result 1 & result 2 : %d, %d \n", sizeof(result1), sizeof(result2));
*//*
	double rad;
	double area;
	printf("���� ������ : ");
	scanf("%lf", &rad);

	area = rad*rad*3.1415;
	printf("���� : %f\n", area);
*/
/*
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;

	printf("%c %d\n", ch1, ch1);
	printf("%c %d\n", ch2, ch2);
	printf("%c %d\n", ch3, ch3);
	printf("%c %d\n", ch4, ch4);

	scanf("%c", &ch1);
	printf("\n%c", ch1 + 'a'-'A');
*/
/*
	printf("lieral int size : %d\n", sizeof(7));
	printf("lieral double size : %d\n", sizeof(7.14));
	printf("lieral char size : %d\n", sizeof('A'));
*//*
	double num1 = 245;
	int num2 = 3.1415;
	int num3 = 129;
	char ch = num3;

	printf("���� 245�� �Ǽ��� : %f\n", num1);
	printf("���� 3.1415�� �Ǽ��� : %d\n", num2);
	printf("int 129�� char�� : %d\n", ch);
*//*
	int num1 = 3, num2 = 4;
	double divRes = num1 / num2;
	printf("DivRes : %f\n", divRes);

	divRes = (double)num1 / num2;
	printf("DivRes : %f\n", divRes);

	divRes = 1.0 * num1 / num2;
	printf("DivRes : %f\n", divRes);
*/
/*
	unsigned char a = 200;
	signed char b = 100;
	printf(" a = %d , b = %d \n", a, b);

	a = -1; b = -129;
	printf(" a = %d , b = %d \n", a, b);

	a = 256; b = 128;
	printf(" a = %d , b = %d \n", a, b);

	a = -2; b = 130;
	printf(" a = %d , b = %d \n", a, b);

	int num3 = 129;
	char ch = num3;

	printf("ū���� 129�� ��������\b�� : %d\n", ch);
*/

	//int myAge = 12;
	//printf("10������ %d��, 16������ %x��\n", myAge, myAge);

	//printf("%f \n", 0.1234);
	//printf("%e \n", 0.1234);
	//printf("%f \n", 0.12345678);
	//printf("%e \n", 0.12345678);

	//printf("%e \n", 0.00000000000000000001);

	//double d1 = 1.23e-3,
	//	d2 = 1.23e-4,
	//	d3 = 1.23e-5,
	//	d4 = 1.23e-6;

	//printf("%g \n", d1);
	//printf("%G \n", d2);
	//printf("%g \n", d3);
	//printf("%G \n", d4);

	//printf("%s, %s, %s\n", "AAA", "BBB", "CCC");

	//printf("%-8s %14s %5s\n", "��  ��", "�����а�", "�г�");
	//printf("%-8s %14s %5d\n", "�赿��", "���ڰ���", 3);
	//printf("%-8s %14s %5d\n", "������", "��ǻ�Ͱ���", 2);
	//printf("%-8s %14s %5d\n", "�Ѽ���", "�̼�������", 4);

	/*int num1, num2, num3;

	printf("�� ���� ���� �Է� : a b c\n");
	scanf("%d %o %x", &num1, &num2, &num3);
	printf("�Էµ� ���� 10���� ��� : ");
	printf("%d %d %d \n", num1, num2, num3);

	*/

	//float num1; double num2; long double num3;
	//
	//printf("�Ǽ� �Է� 1 (e ǥ���) : ");
	//scanf("%f", &num1);
	//printf("�Էµ� �Ǽ� : %lf \n", num1);

	//printf("�Ǽ� �Է� 2 (e ǥ���) : ");
	//scanf("%lf", &num2);
	//printf("�Էµ� �Ǽ� : %lf \n", num2);

	//printf("�Ǽ� �Է� 3 (e ǥ���) : ");
	//scanf("%Lf", &num3);
	//printf("�Էµ� �Ǽ� : %Lf \n", num3);

	/*int num = 0;
	while (num < 3)
	{
		printf("Hello World! %d\n", num);
		num++;
	}
*/

	//int dan = 0, num = 1;
	//
	//printf("���?");
	//scanf("%d", &dan);

	//while (num < 10)
	//{
	//	printf("%d * %d = %d \n", dan, num, dan*num);
	//	num++;
	//}

	//int a = 2, b = 1;
	//
	//while (a <= 9)
	//{
	//	b = 1;

	//	while (b <= 9)
	//	{
	//		printf("%d * %d = %d\n", a, b, a*b);
	//		b++;
	//	}	
	//	printf("\n");
	//	a++;
	//}


	//int a = 1, b = 1;

	//while (a <= 3)
	//{
	//	b = 1;

	//	while (b <= 9)
	//	{
	//		printf("%d * %d = %d", a, b, a*b);
	//		printf("\t%d * %d = %d", a+3, b, (a+3)*b);
	//		printf("\t%d * %d = %d", a+6, b, (a+6)*b);
	//		b++;
	//		printf("\n");
	//	}
	//	printf("\n");
	//	a++;
	//}

	//int input = 0;
	//int result = 0;
	//
	//do 
	//{
	//	printf("�����Է� :\n");
	//	scanf("%d", &input);
	//	result += input;
	//}
	//while (input != 0);

	//printf(" result : %d", result);

	//int total = 0;
	//int num;

	//printf("0���� num������ ����, num��?\n");
	//scanf("%d", &num);

	//for (int i = 0; i <= num; i++)
	//{
	//	total += i;
	//}

	//printf("Result : %d\n", total);

	//double total = 0.0, input = 0.0;
	//int NoN = 0;

	//for (; input >= 0.0;)
	//{
	//	printf("�Ǽ� �Է� : ");
	//	scanf("%lf", &input);
	//	total += input;
	//	NoN++;
	//}
	//printf("��� : %lf", total / NoN);

	//for (int i = 2; i <= 9; i++)
	//{
	//	for (int j = 1; j <= 9; j++)
	//	{
	//		printf("%d * %d = %d\n", i, j, i*j);
	//	}
	//	printf("\n");
	//}



	//07 - 01
//
//int input = 0, result = 0;
//
//do
//{
//	printf("���� �Է� : \n");
//	scanf("%d", &input);
//	result += input;
//} while (input != 0);
//
//printf("���� : %d\n", result);
//
////07 - 02
//
//int non = 0, result = 0, input = 0;
//
//printf("�Է��� ������ �� : \n");
//scanf("%d", &non);
//
//for (int i = 1; i <= non; i++)
//{
//	printf("%d��° ���� : \n", i);
//	scanf("%d", &input);
//	result += input;
//}
//printf("\n��� %d / %d = %lf\n", result, non, (double)result / non);
//
////07 - 03
//
//int input = 0;
//printf("���� �Է� : \n");
//scanf("%d", &input);
//
//for (; input > 1; input--)
//{
//	printf("- %d�� -\n", input);
//	for (int i = 1; i <= 9; i++)
//	{
//		printf("%d * %d = %d\n", input, i, input * i);
//	}
//	printf("\n");
//}
//
////07 - 04
//
//int input = 0, result = 1;
//printf("���� �Է� : \n");
//scanf("%d", &input);
//
//for (; input > 1; input--)
//{
//	printf("%d * ", input);
//	result *= input;
//}
//printf("%d = %d\n", 1, result);
//
//
////07 - 05
//
//int i = 0, result = 0;
//
//do
//{
//	i++;
//	result += i;
//	printf("%d + ", i);
//} while (i < 999);
//result += 1000;
//printf("%d = %d\n", 1000, result);



//07 - 06

printf("�Ѱ����� �����ܤ�\n");
for (int i = 1; i <= 9; i++)
{
	for (int j = 2; j <= 9; j++)
	{
		printf("%d * %d = %d\t", j, i, i*j);
	}
	printf("\n");
}

printf("\n�Ѽ����� �����ܤ�\n");
for (int i = 2; i <= 9; i++)
{
	for (int j = 1; j <= 9; j++)
	{
		printf("%d * %d = %d\t", i, j, i*j);
	}
	printf("\n\n");
}




	return 0;
}