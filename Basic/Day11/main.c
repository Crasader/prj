#pragma warning( disable : 4996)
#include <stdio.h>
#include <stdlib.h>

//char name[30];
//char *ReadUserName(void)
//{
//	char *name = (char *)malloc(sizeof(char)*30);
//	printf("What's your name? ");
//	gets(name);
//	return name;
//}
//char *ReadUserName2(void)
//{
//	printf("What's your name? ");
//	gets(name);
//	return name;
//}
//
//#define NAME "홍길동"
//#define AGE 24
//#define PRINT_ADDR puts("주소 : 경기도 용인시\n");
//
//#define SQUARE(X) X*X
//
//#define PI 3.14
//#define PRODUCT(X,Y) ((X)*(Y))
//#define CIRCLE_AREA(R) (PRODUCT((R),(R))*PI)
//
//#define DIFF_ABS(X,Y) ((X)>(Y) ? (X)-(Y) : (Y)-(X))
//
////#define ADD 1
//#define MIN 0
//
//#define HIT_NUM 7
//
//#define STRING_JOB(A,B) #A"의 직업은"#B"입니다."
//
//#define STNUM(Y,S,P) ((Y)*100000 + (S) * 1000 + (P))
//
//extern void doWork();

#include "Arith.h"
#include "structheader.h"
#include "structheader.h"

int main()
{
	int test = Add(3, 9);
	printf("%d \n", test);
	test = Min(6, 5);
	printf("%d \n", test);
	test = Mul(3, 9);
	printf("%d \n", test);
	test = Div(6, 4);
	printf("%d \n", test);

	doWork();

//#include "header.h"
//	doWork();
//
//	printf("학번 : %d\n", STNUM(10, 65, 175));
//
//	printf("학번 : %d\n", STNUM(10, 65, 075));
/*
	int num1, num2;
	printf("두 개의 정수 입력: a b ");
	scanf("%d %d", &num1, &num2);

#ifndef ADD
	printf("\n%d + %d = %d\n", num1, num2, num1 + num2);
#endif
#ifndef MIN
	printf("\n%d - %d = %d\n", num1, num2, num1 - num2);
#endif

#if HIT_NUM==5
	puts("\n5\n");
#else
	puts("\n!=5\n");
#endif

#if HIT_NUM==5
	puts("\n5\n");
#elif HIT_NUM==6
	puts("\n6\n");
#elif HIT_NUM==7
	puts("\n7\n");
#else
	puts("!= 5,6,7");
#endif

	printf("%s\n", STRING_JOB(이동춘, 나무꾼));
	printf("%s\n", STRING_JOB(한상순, 사냥꾼));
*/
	//printf("두 값의 차 : %d\n", DIFF_ABS(5, 7));
	//printf("두 값의 차 : %g\n", DIFF_ABS(1.8, -1.4));


	//double rad = 2.1;
	//printf("반지름 %g인 원의 넓이 : %g\n",
	//	rad, CIRCLE_AREA(rad));


	//printf("이름 : %s\n", NAME);
	//printf("나이 : %d\n", AGE);
	//PRINT_ADDR;

	//int num = 20;
	//printf("SQUARE OF NUM : %d\n", SQUARE(num));
	//printf("SQUARE OF -5 : %d\n", SQUARE(-5));
	//printf("SQUARE OF 2.5 : %g\n", SQUARE(2.5));

	//printf("SQUARE OF 3+2 : %d\n", SQUARE(3+2));

	//int *ptr = (int*)malloc(sizeof(int));
	//int *ptr2 = (int*)malloc(sizeof(int) * 7);

	//*ptr = 20;
	//for (int i = 0; i < 7; i++)
	//	ptr2[i] = i + 1;
	//printf("%d\n", *ptr);
	//for (int i = 0; i < 7; i++)
	//	printf("%d ", ptr2[i]);
	//free(ptr);
	//free(ptr2);
	
	/*
	char *name1;
	char *name2;
	
	name1 = ReadUserName();
	printf("name1 : %s\n", name1);

	name2 = ReadUserName();
	printf("name2 : %s\n", name2);

	free(name1);
	free(name2);


	name1 = ReadUserName2();
	printf("name1 : %s\n", name1);

	name2 = ReadUserName2();
	printf("name2 : %s\n", name2);

	printf("name1 : %s\n", name1);
	printf("name2 : %s\n", name2);*/

	return 0;
}