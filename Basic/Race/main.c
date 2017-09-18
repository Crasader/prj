
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

void Display();	//ȭ�� ǥ��
void Run(Runner runner[]);	//0~1 ����
void Set(Runner runner[], int NoR); //1ȸ�� �� ����� ����
void swap(Runner *a, Runner *b);
void Refresh(Runner runner[]); //�ʱ�ȭ
void ShowRunners(Runner runner[]);
void gotoxy(int x, int y);

int NoR;	//���� ��
int Arrive;
int Goal = 60;
int Term = 200; // ���ð�
double sec;

int main()
{
	srand((int)time(NULL));

	Runner runner[10];
	for (;;)
	{
		printf("������ ���� �Է����ּ��� (�ִ� 10) : ");
		scanf("%d", &NoR);
		if (NoR >= 1 && NoR <= 10)
			break;
	}

	for (int i = 0; i < NoR; i++)
	{
		printf("%d��° ������ �̸� : ", i + 1);
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

		printf("�ƹ� Ű�� ������ �����մϴ�!\n");
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
			printf("����! %d������ ���� ��⿡ �����մϴ�!\n", NoR / 2);
			Set(runner, NoR);
			NoR /= 2;
			ShowRunners(runner);

			Refresh(runner);
			getch();

		}
		else
		{
			printf("����!\n");
			break;
		}
	}
	Set(runner, NoR);
	printf("%d�� ���� %s�� ����Դϴ�!\n", runner[0].Number, runner[0].name);

	return 0;
}

void Display(Runner runner[])
{
	system("cls");
	printf("                                                                      �ð� : %g\n", sec);
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
			printf(" %d��!", runner[i].rank);
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
		printf("[%-2d��] %-7s: %d��, ��� %g��\n", runner[i].Number, runner[i].name, runner[i].rank, runner[i].time);
	}
}


void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

