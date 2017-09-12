#include<stdio.h>

//
//
//int main()
//{/*
//	int arr[3] = { 1,2,3 };
//	double arr2[3] = { 1.1,2.2,3.3 };
//	
//	printf("%d %g \n", *arr, *arr2);
//	*arr += 100;
//	*arr2 += 120.5;
//	printf("%d %g \n", arr[0], arr2[0]);
//
//
//	int ary[3] = { 15,25,35 };
//	int *ptr = &ary[0];
//
//	printf("%d %d\n", ptr[0], ary[0]);
//	printf("%d %d\n", ptr[1], ary[1]);
//	printf("%d %d\n", ptr[2], ary[2]);
//	printf("%d %d\n", *ptr, *ary);
//
//	int *badPtr1 = 0x0010;
//	double *badPtr2 = 0x0010;
//
//	printf("%p %p\n", badPtr1 + 1, badPtr2 + 2);
//	printf("%p %p\n", badPtr2 + 1, badPtr2 + 2);
//	printf("%p %p\n", badPtr1 , badPtr2);
//	badPtr1++;
//	badPtr2++;
//
//	printf("%p %p\n", badPtr1 , badPtr2);
//*/
///*
//	char str1[] = "My String";
//	char strt[] = "Your String";
//	char *str2 = strt;
//	printf("%s %s \n", str1, str2);
//
//	char strt2[] = "Our String";
//	str2 = strt;
//	printf("%s %s\n", str1, str2);
//
//	str1[0] = 'X';
//	str2[0] = 'X';
//
//	printf("%s %s \n", str1, str2);*/
//
//	return 0;
//}

void swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
void badSwap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main()
{
	int num1 = 10;
	int num2 = 20;

	printf("num1 : %d, num2 : %d\n", num1, num2);

	badSwap(num1, num2);
	printf("BADSwap : \nnum1 : %d, num2 : %d\n", num1, num2);

	swap(&num1, &num2);
	printf("Swap : \nnum1 : %d, num2 : %d\n", num1, num2);

	return 0;
}

