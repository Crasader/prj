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

	//printf("결과 : %d \n ", result);
	//printf("%d + %d = %d \n", num1, num2, result);
	//printf("%d와 %d의 합은 %d임\n", num1, num2, num1 + num2);

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
	printf("세개의 정수 :");
	scanf("%d %o %x", &num1, &num2, &num3);

	printf("\n입력된 세 정수 10진수 : %d,%d,%d\n", num1, num2, num3);

	*/
	/*
	float num1; double num2; long double num3;
	printf("실수 입력 1 (e 표기법) : ");
	scanf("%f", &num1);
	printf("\n입력된 실수 %f \n", num1);

	printf("실수 입력 2 (e 표기법) : ");
	scanf("%lf", &num2);
	printf("\n입력된 실수 %lf \n", num2);

	printf("실수 입력 3 (e 표기법) : ");
	scanf("%Lf", &num3);
	printf("\n입력된 실수 %Lf \n", num3);
	*/

	int num1 = 0, num2 = 0;
	printf("정수 입력 : a b\n");
	scanf("%d %d", &num1, &num2);

	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	printf("%d %% %d = %d\n", num1, num2, num1 % num2);

	printf("\n");

	num1 = 0;
	printf("제곱할 정수 입력 : ");
	scanf("%d", &num1);
	printf("%d ^ 2 = %d\n", num1, num1*num1);

	printf("\n");

	num1 = 0, num2 = 0;
	printf("정수 입력 : a/b\n");
	scanf("%d/%d", &num1, &num2);
	printf("%d 나누기 %d의 몫은 %d입니다.\n", num1, num2, num1 / num2);
	printf("%d 나누기 %d의 나머지는 %d입니다.\n", num1, num2, num1 % num2);

	printf("\n");

	return 0;
}