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

	printf("총 10개의 숫자를 입력하세요 : a b c ... \n");
	scanf("%d %d %d %d %d %d %d %d %d %d",
		&ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++], &ary[i++]);

	printf("\n홀수 출력 : ");
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
	printf("\n짝수 출력 : ");
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

	printf("총 10개의 정수를 입력하세요 : \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 정수 입력 : ", i + 1);
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

	printf("입력된 수 : ");
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

	printf("단어를 입력해주세요 : ");
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
		printf("\n회문입니다.");
	}
	else
	{
		printf("\n회문이 아닙니다.");
	}

	return 0;
}



