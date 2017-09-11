
#pragma warning( disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int match(int Correct, int input)
{
	if (Correct == input)
		return 1;
	else if (Correct < input)
		return 2;
	else return 0;
}
int replay();

int main()
{
	int tryCount = 6;
	int Correct, input, result = 0;
	int idx = 0;

	int end = 0;

	srand((int)time(NULL));

	for (;end == 0;)
	{
		Correct = rand() % 101;

		printf("���� ���� 0���� 100������ �� �߿� �ϳ��� �����ϰڽ��ϴ�.\n");
		printf("����� �� ���ڸ� %dȸ �ȿ� ���߽ø� �˴ϴ�!\n\n", tryCount);

		//printf("%d\n", Correct);

		for (idx = 0; idx < tryCount && result != 1; idx++)
		{
			printf("0 ~ 100������ �� �ϳ� �Է� : ");
			scanf("%d", &input);

			result = match(Correct, input);
			switch (result)
			{
				case 0: printf("������ %d���� Ů�ϴ�.\n", input);	break;
				case 1: printf("����!\n", input);	break;
				case 2: printf("������ %d���� �۽��ϴ�.\n", input);	break;
			}

			if (Correct != input)
			{
				printf("��ȸ�� [ %d ]�� ���ҽ��ϴ�.\n", tryCount - idx - 1);
			}

			printf("\n");
		}

		if (Correct != input)
		{
			printf("����! ������ %d�����ϴ�!\n", Correct);
		}
		else
		{
			printf("%d������ �����߽��ϴ�!\n", idx);
		}

		////////////////////////////////////////////////

		printf("�ٽ� �Ͻðڽ��ϱ�? (y/n)\n");
		end = replay();
	}

	
	return 0;
}

int replay()
{
	char input;
	for (;;)
	{
		rewind(stdin);
		scanf("%c", &input);
		if (input == 'n' || input == 'N')
		{
			return 1;
		}
		else if (input == 'y' || input == 'Y')
		{
			return 0;
		}
		else
		{
			printf("�ٽ� �Է����ּ��� : \n");
		}
	}
}