
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
	int xpos;
	int ypos;

	struct point *ptr;

}point;

typedef struct person
{
	char name[20];
	char phoneNum[20];
	int age;
}person;

typedef struct circle
{
	double radius;
	point *center;
}circle;

int main()
{
/*
	point pos1 = { 1,1 };
	point pos2 = { 2,2 };
	point pos3 = { 3,3 };

	pos1.ptr = &pos2;
	pos2.ptr = &pos3;
	pos3.ptr = &pos1;

	printf("[%d, %d]와 [%d, %d] 연결\n",
		pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
	printf("[%d, %d]와 [%d, %d] 연결\n",
		pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
	printf("[%d, %d]와 [%d, %d] 연결\n",
		pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
*/

	point pos = { 10,20 };

	printf("%p %p\n", &pos, &pos.xpos);

/*
	point cen = {2, 7};
	double rad = 5.5;

	circle ring = { rad, &cen };

	printf("반지름 : %g\n", ring.radius);
	printf("중심점 [%d, %d]\n", ring.center->xpos, ring.center->ypos);
	*/
	/*
	point pos1 = { 1,2 };
	point pos2 = { 100,200 };
	point *pptr = &pos1;

	(*pptr).xpos += 4;
	(*pptr).ypos += 5;

	printf("[%d, %d]\n", pptr->xpos, pptr->ypos);

	pptr = &pos2;

	pptr->xpos += 1;
	pptr->ypos += 2;
	printf("[%d, %d]\n", pptr->xpos, pptr->ypos);

*/

	/*point pos = { 10,20 };
	person man = { "이승기","010-1212-0001",21 };
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d\n", man.name, man.phoneNum, man.age);
*/
/*
	person arr[3] = {
		{ "이승기","010-1212-0001",21 },
		{ "정지영","010-1315-0002",22 },
		{ "한지수","010-1617-0003",19 }
	};

	for (int i = 0; i < 3; i++)
	{
		printf("%s %s %d\n", arr[i].name, arr[i].phoneNum, arr[i].age);
	}*/

	//struct person man1, man2;
	//strcpy(man1.name, "안성준");
	//strcpy(man1.phoneNum, "010-1122-3344");
	//man1.age = 23;

	//printf("이름 입력 : ");
	//scanf("%s", man2.name);
	//printf("번호 입력 : ");
	//scanf("%s", man2.phoneNum);
	//printf("나이 입력 : ");
	//scanf("%d", &(man2.age));

	//printf("이름 : %s \n", man1.name);
	//printf("번호 : %s \n", man1.phoneNum);
	//printf("나이 : %d \n", man1.age);

	//printf("이름 : %s \n", man2.name);
	//printf("번호 : %s \n", man2.phoneNum);
	//printf("나이 : %d \n", man2.age);

	//int ch1, ch2;

	//ch1 = getch();
	////ch2 = fgetc(stdin);

	//printf("\n");

	//putchar(ch1);
	////fputc(ch2, stdout);
/*
	int ch;
	while (1)
	{
		ch = getchar();
		if (ch == EOF)
			break;
		putchar(ch);
		printf("\n");
	}*/
/*
	char *str = "Simple String";

	printf("1. puts test ---- \n");
	puts(str);
	puts("So Simple String");

	printf("2. fputs test ---- \n");
	fputs(str, stdout); printf("\n");
	fputs("So Simple String", stdout); printf("\n");
	printf("3. end of main ---- \n");
*/
/*
	char str[7];
	
	for (int i = 0; i < 3; i++)
	{
		fgets(str, sizeof(str), stdin);
		printf("Read %d : %s \n", i + 1, str);
		rewind(stdin);
	}*/
	//
	//char perID[7];
	//char name[10];

	//fputs("주민번호 앞 6자리 입력 : ", stdout);
	//fgets(perID,sizeof(perID), stdin);
	////rewind(stdin);
	//while (getchar() != '\n');

	//fputs("이름 입력 : ", stdout);
	//fgets(name, sizeof(name), stdin);

	//printf("주민번호 : %s\n", perID);
	//printf("이름 : %s\n", name);
/*
	char str[100];
	printf("입력 : ");
	fgets(str, sizeof(str), stdin);
	printf("길이 %d, 내용 %s \n", strlen(str), str);

	str[strlen(str) - 1] = 0;
	printf("길이 %d, 내용 %s \n", strlen(str), str);
	*/
	/*
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	strcpy(str2, str1);
	puts(str2);

	strcpy(str3, str1, sizeof(str3));
	puts(str3);

	strcpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0;
	puts(str3);
*/
/*
	char str1[20] = "First~";
	char str2[20] = "Second";
	char str3[20] = "Simple num:";
	char str4[20] = "1234567890";

	strcat(str1, str2);
	puts(str1);

	strcat(str3, str4);
	puts(str3);*/
/*
	char str[100] = "warn";
	char str2[100] = "warz";
	printf("%d", strcmp(str2, str));
	printf("%d", strncmp(str2, str,3));
*//*
	char str[20];
	printf("정수 입력 : ");
	scanf("%s", str);
	printf("%d \n", atoi(str));

	rewind(stdin);

	printf("실수 입력 : ");
	scanf_s("%s", str);
	printf("%g \n", atof(str));
*/



	return 0;
}