
#pragma warning(disable : 4996)
#include <stdio.h>
//48 ~ 57 0~10
//65 ~ 122 A~z
int main()
{
	char string[1000];
	int length = 0, result = 0;

	printf("���ڿ� �Է� : ");
	scanf("%s", string);

	for (; string[length] != '\0'; length++);

	for (int i = 0; i < length; i++)
	{
		if (string[i] >= 48 && string[i] <= 57)
		{
			result += string[i] - 48;
		}
	}
	printf("������ ���� : %d\n", result);

	return 0;
}
