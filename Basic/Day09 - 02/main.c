
#pragma warning(disable : 4996)
#include <stdio.h>

typedef int INT;
typedef int *PTR_INT;

typedef unsigned int UINT;
typedef unsigned int *PTR_UINT;

typedef unsigned char UCHAR;
typedef unsigned char *PTR_UCHAR;

typedef struct point
{
	int xpos;
	int ypos;
}point;

typedef struct person
{
	char name[20];
	char phoneNum[20];
	int age;
}person;

void ShowPosition(point pos)
{
	printf("[%d, %d]\n", pos.xpos, pos.ypos);
}

point GetCurrentPosition(void)
{
	point cen;
	printf("Input current pos : ");
	scanf("%d %d", &cen.xpos, &cen.ypos);
	return cen;
}

void ShowPersonInfo(person man)
{
	printf("name : %s\n", man.name);
	printf("phone : %s\n", man.phoneNum);
	printf("age : %d\n", man.age);
}

void OrgSymTrans(point *ptr)
{
	ptr->xpos = (ptr->xpos) * -1;
	ptr->ypos = (ptr->ypos) * -1;
}

person ReadPersonInfo(void)
{
	person man;
	printf("name? ");
	scanf("%s", man.name);
	printf("phone? ");
	scanf("%s", man.phoneNum);
	printf("age? ");
	scanf("%d", &man.age);
	return man;
}

point AddPoint(point pos1, point pos2)
{
	point pos = { pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos };
	return pos;
}
point MinPoint(point pos1, point pos2)
{
	point pos = { pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos };
	return pos;
}

int main()
{
	point pos = { 7,-5 };
	OrgSymTrans(&pos);
	ShowPosition(pos);

	pos = AddPoint(pos, pos);
	ShowPosition(pos);

	point pos2 = { 8,8 };
	pos = MinPoint(pos, pos2);
	ShowPosition(pos);
/*
	person man = ReadPersonInfo();
	ShowPersonInfo(man);
	*/
	
	/*
	point curPos = GetCurrentPosition();
	ShowPosition(curPos);*/


	/*point pos = { 10,20 };
	person man = { "ÀÌ½Â±â","010-1212-0001",21 };
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d\n", man.name, man.phoneNum, man.age);
*/
	/*
	INT num1 = 120;
	PTR_INT pnum1 = &num1;

	UINT num2 = 190;
	PTR_UINT pnum2 = &num2;

	UCHAR ch = 'Z';
	PTR_UCHAR pch = &ch;

	printf("%d, %u, %c\n",*pnum1, *pnum2,*pch);
*/

	return 0;
}