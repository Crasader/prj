#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

char * MakeStrAdr2(int len)
{
	char * str = new char[len];
	return str;
}

void SwapByValue(int val1, int val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}
void SwapByRef(int *val1, int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
void SwapByRef2(int &val1, int &val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

int &RefReturnFunc(int &ref)
{
	ref++;
	return ref;
}

int main()
{
	int val = 15;
	int val2 = 23;

	SwapByValue(val, val2);

	cout << "Swap By Val" << endl;
	cout << "val 1 : " << val << endl;
	cout << "val 2 : " << val2 << endl;
	cout << endl;

	SwapByRef(&val, &val2);

	cout << "Swap By Ref" << endl;
	cout << "val 1 : " << val << endl;
	cout << "val 2 : " << val2 << endl;
	cout << endl;

	SwapByRef2(val, val2);

	cout << "Swap By Ref 2" << endl;
	cout << "val 1 : " << val << endl;
	cout << "val 2 : " << val2 << endl;
	cout << endl;

	int val3 = RefReturnFunc(val);
	cout << val << endl;

	val++; val3++;
	cout << val << endl;
	cout << val3 << endl;

	char *str = MakeStrAdr2(20);
	
	strcpy_s(str, sizeof("IAAA"),"IAAA");

	cout << str << endl;
	delete []str;

	char str1[] = "Result";
	char str2[30];

	strcpy_s(str2,sizeof(str1), str1);
	printf("%s : %f\n", str1, sin(0.14));
	printf("%s : %f\n", str2, abs(-1.25));

	return 0;
}