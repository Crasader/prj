#include<stdio.h>

int main()
{/*
	int arr[3] = { 1,2,3 };
	double arr2[3] = { 1.1,2.2,3.3 };
	
	printf("%d %g \n", *arr, *arr2);
	*arr += 100;
	*arr2 += 120.5;
	printf("%d %g \n", arr[0], arr2[0]);


	int ary[3] = { 15,25,35 };
	int *ptr = &ary[0];

	printf("%d %d\n", ptr[0], ary[0]);
	printf("%d %d\n", ptr[1], ary[1]);
	printf("%d %d\n", ptr[2], ary[2]);
	printf("%d %d\n", *ptr, *ary);

	int *badPtr1 = 0x0010;
	double *badPtr2 = 0x0010;

	printf("%p %p\n", badPtr1 + 1, badPtr2 + 2);
	printf("%p %p\n", badPtr2 + 1, badPtr2 + 2);
	printf("%p %p\n", badPtr1 , badPtr2);
	badPtr1++;
	badPtr2++;

	printf("%p %p\n", badPtr1 , badPtr2);
*/
/*
	char str1[] = "My String";
	char strt[] = "Your String";
	char *str2 = strt;
	printf("%s %s \n", str1, str2);

	char strt2[] = "Our String";
	str2 = strt;
	printf("%s %s\n", str1, str2);

	str1[0] = 'X';
	str2[0] = 'X';

	printf("%s %s \n", str1, str2);*/

	char * strArr[3] = { "simple","string","array" };
	printf("%s\n", strArr[0]);
	printf("%s\n", strArr[1]);
	printf("%s\n", strArr[2]);

	return 0;
}