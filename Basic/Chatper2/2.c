#pragma warning( disable : 4996)
#include<stdio.h>

int main()
{/*
	int age = 0;

	printf("Hello world! %d\n", 3);
	printf(" %d + %d = %d\n", 21, 5, 21 + 5);

	printf("%d is my my", 20);

	scanf_s("%d", &age);
	printf("\n%d\n", age);
*/

	////01

	//3 + 4;


	////02

	//int num1, num2, num3 = 30, num4 = 40;
	//printf("num1 : %d, num2 : %d\n", num1, num2);
	//num1 = 10, num2 = 20;

	//printf("num1 : %d,num2 : %d\n",num1,num2);
	//printf("num3 : %d,num4 : %d\n", num3, num4);


	////03

	//int num1 = 3, num2 = 4;
	//int result = num1 + num2;

	//printf("��� : %d \n ", result);
	//printf("%d + %d = %d \n", num1, num2, result);
	//printf("%d�� %d�� ���� %d��\n", num1, num2, num1 + num2);

	////04

	//int num1 = 9, num2 = 2;
	//printf("%d + %d = %d\n", num1, num2, num1 + num2);
	//printf("%d - %d = %d\n", num1, num2, num1 - num2);
	//printf("%d * %d = %d\n", num1, num2, num1 * num2);
	//printf("%d / %d = %d\n", num1, num2, num1 / num2);

	//printf("%d %% %d = %d\n", num1, num2, num1 % num2);

	////05

	//int num1 = 2, num2 = 4, num3 = 6;
	//num1 += 3; num2 *= 4; num3 %= 5;

	//printf("Result : %d,%d,%d\n", num1, num2, num3);
	//

	////06

	//int num1 = +2, num2 = -4;
	//num1 = -num1; num2 = -num2;

	//printf("num1 : %d\n num2 : %d\n", num1, num2);
	/*
	//07
	int num1 = 12, num2 = 12;
	printf("num1 : %d \n",num1);
	printf("num1++ : %d \n",num1++);
	printf("num1 : %d \n",num1);
	printf("num2 : %d \n",num2);
	printf("++num2 : %d \n",++num2);
	printf("num2 : %d \n\n\n",num2);

	//08
	int num3 = 10, num4 = (num3--) + 2;

	printf("num3 : %d\n", num3);
	printf("num4 : %d\n", num4);

	//09
	num1 = 10, num2 = 12;

	printf("\nresult1 : %d\n", num1 == num2);
	printf("result2 : %d\n", num1 <= num2);
	printf("result3 : %d\n", num1 > num2);
	
	printf("\nresult1 : %d\n", num1 == 10 && num2 == 12);
	printf("result1 : %d\n", num1 < 12 || num2 > 12);
	printf("result1 : %d\n", !num1);
	*/
	
	/*
	
	int num1, num2, num3;
	printf("������ ���� :");
	scanf("%d %o %x", &num1, &num2, &num3);

	printf("\n�Էµ� �� ���� 10���� : %d,%d,%d\n", num1, num2, num3);

	*/
	/*
	float num1; double num2; long double num3;
	printf("�Ǽ� �Է� 1 (e ǥ���) : ");
	scanf("%f", &num1);
	printf("\n�Էµ� �Ǽ� %f \n", num1);

	printf("�Ǽ� �Է� 2 (e ǥ���) : ");
	scanf("%lf", &num2);
	printf("\n�Էµ� �Ǽ� %lf \n", num2);

	printf("�Ǽ� �Է� 3 (e ǥ���) : ");
	scanf("%Lf", &num3);
	printf("\n�Էµ� �Ǽ� %Lf \n", num3);
	*/

	int num1 = 0, num2 = 0;
	printf("���� �Է� : a b\n");
	scanf("%d %d", &num1, &num2);

	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	printf("%d %% %d = %d\n", num1, num2, num1 % num2);

	printf("\n");

	num1 = 0;
	printf("������ ���� �Է� : ");
	scanf("%d", &num1);
	printf("%d ^ 2 = %d\n", num1, num1*num1);

	printf("\n");

	num1 = 0, num2 = 0;
	printf("���� �Է� : a/b\n");
	scanf("%d/%d", &num1, &num2);
	printf("%d ������ %d�� ���� %d�Դϴ�.\n", num1, num2, num1 / num2);
	printf("%d ������ %d�� �������� %d�Դϴ�.\n", num1, num2, num1 % num2);

	printf("\n");

	return 0;
}