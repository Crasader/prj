#pragma warning( disable : 4996)
#include <stdio.h>

//void ShowAry(int Ary[4][4])
//{
//	for (int i = 0; i < 16; i++)
//	{
//		if (i % 4 == 0 && i != 0)
//		{
//			printf("\n");
//		}
//		printf("%-3d ", *(Ary[0] + i));
//	}
//	printf("\n\n");
//}
//
//int main()
//{
//	int Ary[4][4];
//	int input;
//
//	int inputAry[16];
//	for (int i = 0; i < 16; i++)
//	{
//		inputAry[i] = i;
//	}
//
//	printf("몇번 돌릴까요");
//	scanf("%d", &input);
//
//	for (int k = 0; k < input; k++)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				switch (k%4)
//				{
//				case 0: Ary[i][j] = inputAry[(i * 4) + (j)]; break;
//				case 1: Ary[i][j] = inputAry[(i + 12) + (j * -4)]; break;
//				case 2: Ary[i][j] = inputAry[(i * -4) + (-j + 16) - 1]; break;
//				case 3: Ary[i][j] = inputAry[(-i + 4) + (j * 4) - 1]; break;
//				}
//			}
//		}
//		ShowAry(Ary);
//	}
//
//	return 0;
//}
//
//
//typedef struct point
//{
//	int type;
//	int x, y;
//}point;
//
//void add(point *a, point *b)
//{
//	a->x += b->x;
//	a->y += b->y;
//}
//void sub(point *a, point *b)
//{
//	a->x -= b->x;
//	a->y -= b->y;
//}
//
//int main()
//{
//	int input;
//	printf("n 입력 : ");
//	scanf("%d", &input);
//
//	int snailAry[30][30];
//
//	//////////////////////////////////
//
//	for (int i = 0; i < input * input; i++)
//	{
//		*(snailAry[0] + ((i / input) * input) + (i % input)) = 0;
//	}
//
//	////////////////////////////////
//
//	point CurrentPoint;
//	CurrentPoint.x = 0; CurrentPoint.y = 0;
//
//	int stage = 0;
//	point WayToGo[4];
//	WayToGo[0].x = 1; WayToGo[0].y = 0;
//	WayToGo[1].x = 0; WayToGo[1].y = 1;
//	WayToGo[2].x = -1; WayToGo[2].y = 0;
//	WayToGo[3].x = 0; WayToGo[3].y = -1;
//
//	for (int i = 0; i < input * input;i++)
//	{
//		*(snailAry[0] + (CurrentPoint.y * input) + (CurrentPoint.x)) = i + 1;
//
//		add(&CurrentPoint, &WayToGo[stage%4]); 
//		
//		if (CurrentPoint.x > input-1 || CurrentPoint.y > input-1 || CurrentPoint.x < 0 || CurrentPoint.y < 0 ||
//			*(snailAry[0] + (CurrentPoint.y * input) + (CurrentPoint.x)) != 0)
//		{
//			sub(&CurrentPoint, &WayToGo[stage%4]);
//			stage++;
//
//			add(&CurrentPoint, &WayToGo[stage%4]);
//		}
//	}
//	for (int i = 0; i < input; i++)
//	{
//		for (int j = 0; j < input; j++)
//		{
//			printf("%-3d ", *(snailAry[0] + i*input + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//
//}
