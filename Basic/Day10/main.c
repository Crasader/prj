#pragma warning(disable : 4996)
#include<stdio.h>

typedef struct student
{
	char name[20];
	char stdnum[20];
	char school[20];
	char major[20];
	int year;
}student;

void ShowStudentInfo(student *std)
{
	printf("학생 이름 : %s\n", std->name);
	printf("학번 : %s\n", std->stdnum);
	printf("학교 이름 : %s\n", std->school);
	printf("전공 : %s\n", std->major);
	printf("학년 : %d\n", std->year);
}

typedef struct point
{
	int pos[2];
}point;

typedef struct circle
{
	point cen;
	double rad;
}circle;

void ShowCircleInfo(circle *c)
{
	printf("[%d, %d]\n", c->cen.pos[0], c->cen.pos[1]);
	printf("radius : %g\n\n", c->rad);
}

typedef union ubox
{
	int mem1;
	int mem2;
	double mem3;
}ubox;

typedef enum syllable
{
	Do = 1, Re = 2, Mi = 3
}syllable;

void Sound(syllable sy)
{
	switch (sy)
	{
	case Do:
		puts("AAAAAAAAAA"); return;
	case Re:
		puts("BBBBBBBBBBBB"); return;
	case Mi:
		puts("CCCCCCCCCCCCCCC"); return;
	}
	puts("뺩");
}

int main()
{

	long fpos;
	int i;

	FILE *fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	fp = fopen("text.txt", "rt");
	for (i = 0; i < 4; i++)
	{
		putchar(fgetc(fp));
		fpos = ftell(fp);
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);
	}
	fclose(fp);


	//FILE *fp = fopen("text.txt", "wt");
	//fputs("123456789", fp);
	//fclose(fp);

	//fp = fopen("text.txt", "rt");

	//fseek(fp, -2, SEEK_END);
	//putchar(fgetc(fp));

	//fseek(fp, 2, SEEK_SET);
	//putchar(fgetc(fp));

	//fseek(fp, 2, SEEK_CUR);
	//putchar(fgetc(fp));

	//fclose(fp);

	//FILE *src = fopen("simple.txt", "rt");
	//FILE *des = fopen("data.txt", "wt");

	//char str[2];

	//if(src == NULL || des == NULL)
	//{
	//	puts("파일 오픈 실패!\n");
	//	return -1;
	//}

	//while (fgets(str, sizeof(str), src) != NULL)
	//	fputs(str, des);
	//

	//if (feof(src) != 0)
	//{
	//	puts("복사 끝!");
	//}
	//else
	//{
	//	puts("복사 실패!");
	//}

	//fclose(src);
	//fclose(des);

	//FILE *fp = fopen("simple.txt", "wt");
	//if (fp == NULL)
	//{
	//	puts("open failed");
	//	return -1;
	//}

	//fputc('A', fp);
	//fputc('B', fp);
	//fputs("My name is Hong\n", fp);
	//fputs("Your Name is Yoon \n", fp);
	//fclose(fp);
	//
	//char str[30];
	//int ch;
	//fp = fopen("simple.txt", "rt");
	//if (fp == NULL)
	//{
	//	puts("open failed");
	//	return -1;
	//}

	//ch = fgetc(fp);
	//printf("%c\n", ch);
	//ch = fgetc(fp);
	//printf("%c\n", ch);

	//fgets(str, sizeof(str), fp);
	//printf("%s", str);
	//fgets(str, sizeof(str), fp);
	//printf("%s", str);
	//fclose(fp);

	/*
	int ch, i;
	FILE *fp = fopen("data.txt", "wt");
	if (fp == NULL)
	{
		printf("open failed!\n");
		return -1;
	}

	for (i = 0; i < 3; i++)
	{
		fputc('B',fp);
	}
	fclose(fp);


	fp = fopen("data.txt", "rt");
	if (fp == NULL)
	{
		printf("open failed!\n");
		return -1;
	}

	for (i = 0; i < 3; i++)
	{
		ch = fgetc(fp);
		printf("%c\n", ch);
	}
	fclose(fp);
*/


	//syllable tone;
	//for (tone = Do; tone < Mi; tone++)
	//{
	//	Sound(tone);
	//}
	


	/*
	ubox ubx;
	ubx.mem1 = 20;
	printf("%d \n", ubx.mem2);

	ubx.mem3 = 7.15;
	printf("%g\n", ubx.mem1);
	printf("%d\n", ubx.mem2);
	printf("%g\n", ubx.mem3);

	printf("%p %p %p\n", &ubx.mem1, &ubx.mem2, &ubx.mem3);
	printf("%d\n", sizeof(ubx));*/

	//circle c1 = { {1,2},3.5 };
	//circle c2 = { 2,4 ,3.5 };

	//ShowCircleInfo(&c1);
	//ShowCircleInfo(&c2);

	/*
	student arr[7];
	
	for (int i = 0; i < 1; i++)
	{
		scanf("%s", arr[i].name);
		scanf("%s", arr[i].stdnum);
		scanf("%s", arr[i].school);
		scanf("%s", arr[i].major);
		scanf("%d", &arr[i].year);
	}

	for (int i = 0; i < 1; i++)
	{
		ShowStudentInfo(&arr[i]);
	}
*/
	return 0;
}