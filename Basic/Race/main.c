
#pragma warning( disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Runner
{
	char name[100];
	int currentPoint;
	int rank;
	double time;
	int Number;
}Runner;

void Display();	//화면 표시
void Run(Runner runner[]);	//0~1 전진
void Set(Runner runner[], int NoR); //1회전 후 등수순 정리
void swap(Runner *a, Runner *b);
void Refresh(Runner runner[]); //초기화
void ShowRunners(Runner runner[]);
void gotoxy(int x, int y);

int NoR;	//주자 수
int Arrive;
int Goal = 60;
int Term = 200; // 대기시간
double sec;

int main()
{
	srand((int)time(NULL));

	Runner runner[10];
	for (;;)
	{
		printf("주자의 수를 입력해주세요 (최대 10) : ");
		scanf("%d", &NoR);
		if (NoR >= 1 && NoR <= 10)
			break;
	}

	for (int i = 0; i < NoR; i++)
	{
		printf("%d번째 주자의 이름 : ", i + 1);
		scanf("%s", runner[i].name);

		runner[i].currentPoint = 1;
		runner[i].rank = 0;
		runner[i].time = 0.0;
		runner[i].Number = i + 1;
	}

	for (;;)
	{
		Arrive = 0;
		sec = 0;
		Display(runner);

		printf("아무 키나 누르면 시작합니다!\n");
		getch();

		for (; Arrive != NoR;)
		{
			sec += Term / 1000.0;;
			Sleep(Term);
			Run(runner);
			Display(runner);
		}


		if (NoR / 2 > 1)
		{
			printf("종료! %d위까지 다음 경기에 참여합니다!\n", NoR / 2);
			Set(runner, NoR);
			NoR /= 2;
			ShowRunners(runner);

			Refresh(runner);
			getch();

		}
		else
		{
			printf("종료!\n");
			break;
		}
	}
	Set(runner, NoR);
	printf("%d번 주자 %s의 우승입니다!\n", runner[0].Number, runner[0].name);

	return 0;
}

void Display(Runner runner[])
{
	system("cls");
	printf("                                                                      시간 : %g\n", sec);
	printf("\n");
	printf("          0         10        20        30        40        50        60\n");
	printf("|---------|---------|---------|---------|---------|---------|---------|\n");

	for (int i = 0; i < NoR; i++)
	{
		printf("%-2d%-7s:", runner[i].Number, runner[i].name);
		gotoxy(runner[i].currentPoint + 11, 5 + i);
		printf(">%d", runner[i].currentPoint);

		if (runner[i].currentPoint == Goal)
		{
			printf(" %d위!", runner[i].rank);
			printf(" (%g sec)", runner[i].time);
		}
		printf("\n");
	}
	printf("|---------|---------|---------|---------|---------|---------|---------|\n");
}
void Run(Runner runner[])
{
	for (int i = 0; i < NoR; i++)
	{
		if (runner[i].currentPoint < Goal)
		{
			runner[i].currentPoint += rand() % 2;
		}
		if (runner[i].rank == 0 && runner[i].currentPoint == Goal)
		{
			runner[i].rank = ++Arrive;
			runner[i].time = sec;
		}
	}
}

void swap(Runner *a, Runner *b)
{
	Runner temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Set(Runner runner[], int NoR)
{
	int rankLimit = NoR / 2;
	for (int i = 0; i < NoR / 2; i++)
	{
		for (int j = 0; j < NoR; j++)
		{
			if (runner[j].rank == i + 1)
			{
				swap(&runner[i], &runner[j]);
				break;
			}
		}
	}
}

void Refresh(Runner runner[])
{
	for (int i = 0; i < NoR; i++)
	{
		runner[i].currentPoint = 1;
		runner[i].rank = 0;
		runner[i].time = 0.0;
	}
}
void ShowRunners(Runner runner[])
{
	for (int i = 0; i < NoR; i++)
	{
		printf("[%-2d번] %-7s: %d위, 기록 %g초\n", runner[i].Number, runner[i].name, runner[i].rank, runner[i].time);
	}
}


void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

