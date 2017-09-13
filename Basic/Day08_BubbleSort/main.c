#pragma warning(disable : 4996)
#include <stdio.h>

void Sort_Bubble(int Ary[], int opt);
void Sort_Quick(int Ary[], int opt);
//opt 1 -> ASC, 0 -> DES
void Sort_QuickASC(int Ary[], int Start, int End);
void Sort_QuickDES(int Ary[], int Start, int End);
void Sort_QuickDES2(int Ary[], int Start, int End);

void Swap(int *a, int *b);
void ShowAry(int Ary[]);


int temp = 0;

int main()
{/*
	int Ary[10];

	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 수 입력 : ", i + 1);
		scanf("%d", &Ary[i]);
	}

	printf("\n입력된 배열 : ");
	ShowAry(Ary);

	printf("오름차순 정렬 : ");
	Sort_Bubble(Ary, 1);
	ShowAry(Ary);

	printf("내림차순 정렬 : ");
	Sort_Bubble(Ary, 0);
	ShowAry(Ary);*/

	int Ary[10] = { 2,19,6,15,8,14,27,6,45,1 };
	ShowAry(Ary);
/*
	Sort_Quick(Ary, 1);
	printf("오름차순 퀵 정렬 : ");
	ShowAry(Ary);*/

	Sort_Quick(Ary, 0);
	printf("내림차순 퀵 정렬 : ");
	ShowAry(Ary);

	return 0;
}

void Sort_Bubble(int Ary[], int opt)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (opt)
			{
				if (Ary[j] > Ary[j + 1])
					Swap(&Ary[j], &Ary[j + 1]);
			}
			else
			{
				if (Ary[j] < Ary[j + 1])
					Swap(&Ary[j], &Ary[j + 1]);
			}
		}
	}
}

void Sort_Quick(int Ary[], int opt)
{
	if(opt)Sort_QuickASC(Ary, 0, 9);
	else Sort_QuickDES2(Ary, 0, 9);
}
void Sort_QuickASC(int Ary[], int Start, int End)
{
	int pivot = End;
	int left = Start;
	int right = End-1;

	for (; Ary[right] >= Ary[pivot] && right > left; right--);
	for (; left < right; left++)
	{
		if (Ary[left] > Ary[pivot])
		{
			Swap(&Ary[left], &Ary[right]);
			right--;
		}
		for (; Ary[right] >= Ary[pivot] && right > left; right--);
	}
	if(Ary[pivot] < Ary[left])
		Swap(&Ary[left], &Ary[pivot]);

	printf("Check : ");
	for (int i = Start; i <= End; i++)
	{
		printf("%d ", Ary[i]);
	}
	printf("\n");

	printf("%d %d\n", Start, left - 1);
	printf("%d %d\n", left+1, End);

	if (Start < left)
	{
		Sort_QuickASC(Ary, Start, left - 1);
	}
	if (left+1 < End)
	{
		Sort_QuickASC(Ary, left + 1, End);
	}
}

void Sort_QuickDES2(int Ary[], int Start, int End)
{
	int left = Start;
	int right = End;
	int pivot = End;

	printf("Left : %d, Right : %d, Pivot : %d", left, right, pivot);
	printf("\nPivotNum : %d\n", Ary[pivot]);

	for (; left < right; left++)
	{
		if (Ary[left] > Ary[pivot])
		{
			for (; left < right; right--)
			{
				if (Ary[right] > Ary[pivot])
					break;
			}

			if (Ary[left] > Ary[pivot])
			{
				Swap(&Ary[left], &Ary[right]);
			}
		}
	}
	
	Swap(&Ary[left], &Ary[pivot]);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", Ary[i]);
	}
	
	
}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void ShowAry(int Ary[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", Ary[i]);
	}
	printf("\n");
}
