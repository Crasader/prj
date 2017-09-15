
#pragma warning( disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define PlayerNumber 9
#define PlayerImage '*'

int get_directionkey()//방향키를 입력받는 함수
{
	int key;
	key = _getch();
	if (key == 224)//방향키
	{
		return _getch(); //어떤 방향 키인지 반환
	}
	return 0;	//방향키가 아님
}
int getPlayerPosition(int Board[]); //PlayerNumber의 위치 반환
int Check(int Board[]);	//Board의 정렬이 1-9 순으로 되있으면 0 반환

void Set(int Board[]); //Board 배열을 랜덤하게 재설정
void Display(int Board[]); //Board 표시
void swap(int *a, int *b); 
void Move(char input, int Board[]);
void Set2(int Board[]);

int main()
{
	srand((int)time(NULL));

	int Board[9] = { 1,2,3,4,5,6,7,8,PlayerNumber};

	//Display(Board);
	//Set(Board); //망함
	Set2(Board);
	Display(Board);

	while (1)
	{
		Move(get_directionkey(), Board);
		Display(Board);

		if (Check(Board) == 0) break;
	}

	printf("\n★클리어★\n\n");

	return 0;
}

int getPlayerPosition(int Board[])
{
	for (int i = 0; i < 9; i++)
	{
		if (Board[i] == PlayerNumber) return i;
	}
	return -1;
}
int Check(int Board[])
{
	int result = 0;
	for (int i = 0; i<9; i++)
	{
		if (Board[i] != i + 1) result = 1;
	}
	return result;
}

void Set(int Board[])
{
	int Array[8] = { 1,2,3,4,5,6,7,8 };
	int NoA = 8;

	/////////////////////////////////

	int ran;
	for (int i = 0; i < 8; i++)
	{
		ran = rand() % NoA;

		Board[i] = Array[ran];
		
		for (int j = ran; j < NoA && j < 7; j++)
		{
			swap(&Array[j], &Array[j + 1]);
		}
		NoA--;
	}
}
void Display(int Board[])
{
	system("cls");

	for (int i = 0; i < 9; i++)
	{
		if (Board[i] == PlayerNumber)
		{
			printf("%-3c", PlayerImage);
		}
		else
		{
			printf("%-3d", Board[i]);
		}

		if (i % 3 == 2) printf("\n");
	}

	printf("방향키 입력 : \n");
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Move(char input, int Board[])
{
	int PlayerP = getPlayerPosition(Board);

	if (input == 77 && (PlayerP != 2 && PlayerP != 5 && PlayerP != 8))
	{
		swap(&Board[PlayerP],&Board[PlayerP + 1]);
	}
	else if(input == 75 && (PlayerP != 0 && PlayerP != 3 && PlayerP != 6))
	{
		swap(&Board[PlayerP], &Board[PlayerP - 1]);
	}
	else if (input == 72 && (PlayerP != 0 && PlayerP != 1 && PlayerP != 2))
	{
		swap(&Board[PlayerP], &Board[PlayerP - 3]);
	}
	else if (input == 80 && (PlayerP != 6 && PlayerP != 7 && PlayerP != 8))
	{
		swap(&Board[PlayerP], &Board[PlayerP + 3]);
	}
}

void Set2(int Board[])
{
	int temp;
	for (int i = 0; i < 200; i++)
	{
		temp = rand() % 4;
		switch (temp)
		{
			case 0: temp = 77; break;
			case 1: temp = 75; break;
			case 2: temp = 72; break;
			case 3: temp = 80; break;
		}
		Move(temp, Board);
	}
}