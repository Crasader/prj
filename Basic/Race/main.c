
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
}Runner;

void Display();
int Run(Runner runner[]);
void gotoxy(int x, int y);

int NoR;
int Arrive;
int Goal = 60;
double sec;

int main()
{
	srand((int)time(NULL));
	Arrive = 0;
	sec = 0;

	Runner runner[10];
	printf("������ ���� �Է����ּ��� (�ִ� 10) : ");
	scanf("%d", &NoR);

	for (int i = 0; i < NoR; i++)
	{
		printf("%d��° ������ �̸� : ", i);
		scanf("%s", runner[i].name);

		runner[i].currentPoint = 1;
		runner[i].rank = 0;
		runner[i].time = 0.0;
	}

	Display(runner);

	printf("�ƹ� Ű�� ������ �����մϴ�!\n");
	getch();

	for (; Arrive != NoR ;)
	{
		sec += 0.1;
		Sleep(100);
		Run(runner);
		Display(runner);
	}

	return 0;
}

void Display(Runner runner[])
{
	system("cls");
	printf("                                                                      �ð� : %g\n",sec);
	printf("\n");
	printf("          0         10        20        30        40        50        60\n");
	printf("|---------|---------|---------|---------|---------|---------|---------|\n");

	for (int i = 0; i < NoR; i++)
	{
		printf("[%-6s] :", runner[i].name);
		for (int j = 0; j < 61; j++)
		{
			if (j < runner[i].currentPoint)
				printf(" ");
			else if (j == runner[i].currentPoint)
				printf(">%d", runner[i].currentPoint);
			else
				printf(" ");
		}
		
		if (runner[i].currentPoint == Goal)
		{
			printf(" %d��!", runner[i].rank);
			printf(" (%g sec)", runner[i].time);
		}
		printf("\n");
	}
	printf("|---------|---------|---------|---------|---------|---------|---------|\n");
	//printf("Arrive : %d", Arrive);
}
int Run(Runner runner[])
{
	int result = 0;

	for (int i = 0; i < NoR; i++)
	{
		if(runner[i].currentPoint < Goal)
		{
			runner[i].currentPoint += rand() % 2;
		}
		if (runner[i].rank == 0 && runner[i].currentPoint == Goal)
		{
			runner[i].rank = ++Arrive;
			runner[i].time = sec;
		}
	}
	
	return result;
}