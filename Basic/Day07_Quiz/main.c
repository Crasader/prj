//#include <stdio.h>
//
//int main()
//{
//	int ary[] = { 1,2,3,4,5,6 };
//	int ary2[6];
//
//
//	for (int i = 5; i >= 0; i--)
//	{
//		*(ary2 + i) = *(ary + 5 - i);
//	}
//
//	for (int i = 0; i < 6; i++)
//	{
//		printf("Ary[%d] : %d\n", i,*(ary2 + i));
//	}
//
//
//	return 0;
//
//
//}
#pragma warning( disable : 4996)
#include<stdio.h>

int main() {

	int ary[10];
	int temp = 0;
	int i = 0;

	printf("�� 10���� ���ڸ� �Է��ϼ��� : a b c ... \n");
	scanf("%d %d %d %d %d %d %d %d %d %d",
		&ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++]);

	printf("\nȦ�� ��� : ");
	for (int i = 0; i < 10; i++)
	{
		if (ary[i] % 2 != 0)
		{
			if (temp == 0)
			{
				printf("%d", ary[i]);
				temp = 1;
			}
			else
			{
				printf(", %d", ary[i]);
			}
		}
	}

	temp = 0;
	printf("\n¦�� ��� : ");
	for (int i = 0; i < 10; i++)
	{
		if (ary[i] % 2 == 0)
		{
			if (temp == 0)
			{
				printf("%d", ary[i]);
				temp = 1;
			}
			else
			{
				printf(", %d", ary[i]);
			}
		}
	}
	printf("\n");

	return 0;
}



#pragma warning( disable : 4996)
#include<stdio.h>

int main()
{
	//2

	int ary[10];
	int input;
	int NofOdd = 0, NofEven = 0;

	printf("�� 10���� ������ �Է��ϼ��� : \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d��° ���� �Է� : ", i + 1);
		scanf("%d", &input);
		if (input % 2 != 0)
		{
			ary[NofOdd] = input;
			NofOdd++;
		}
		else
		{
			ary[9 - NofEven] = input;
			NofEven++;
		}
	}

	printf("�Էµ� �� : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}

	printf("\n");


	return 0;
}



#pragma warning( disable : 4996)
#include<stdio.h>

int main()
{
	//3
	char str[100];
	int length;
	int check = 1;

	printf("�ܾ �Է����ּ��� : ");
	scanf("%s", str);

	for (length = 0; str[length] != '\0'; length++);
	//printf("Length : %d\n", length);

	for (int i = 0; i < length / 2; i++)
	{
		//printf("%d , %d\n", str[i], str[length - i - 1]);
		if (str[i] != str[length - i - 1])
		{
			check = 0; break;
		}
	}
	if (check == 1)
	{
		printf("\nȸ���Դϴ�.");
	}
	else
	{
		printf("\nȸ���� �ƴմϴ�.");
	}

	return 0;
}



