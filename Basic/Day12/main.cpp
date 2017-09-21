#include <iostream>
using namespace std;

int Add(int *a);
int Add(int a, int b);
int Add(int a, int b, int c);
int Add(int a = 10);

int DefaultFunc(int length, int width = 1, int height1 = 1);


namespace my1
{
	void SimpleFunc(void)
	{
		cout << "BestCom" << endl;
	}
}
namespace my2
{
	void SimpleFunc();
}

namespace my1
{
	void SimpleFunc2();
	namespace my2
	{
		namespace my3
		{
			void notSimpleFunc();
		}
	}
}

namespace hybrid
{
	void hybfunc()
	{
		cout << "SIMPLE FUNC!" << endl;
		cout << "NAMESPACE : hybrid" << endl;
	}
}

using namespace my2;

int main()
{
	// C out & C in //
	//int num = 20, num2;
	//cout << "HELL WORLD!\n"<<endl;
	//cout << "num\n" <<num<< endl;

	//cin >> num;
	//cout << "new num : " << num << endl;
	//cin >> num2;
	//cout << "sec num : " << num << endl;

	//cout << num << " + " << num2 << " = " << num + num2 << endl;


	// MultiInput //

	//int val1, val2;
	//int result = 0;
	//cout << "두 개의 숫자 입력 : ";
	//cin >> val1 >> val2;
	//if (val1 < val2)
	//{
	//	for (int i = val1 + 1; i < val2; i++)
	//		result += i;
	//}
	//else
	//{
	//	for (int i = val2 + 1; i < val1; i++)
	//		result += i;
	//}
	//cout << "두 수 사이의 정수 합 : " << result << endl;

	// String Input //
	//char name[100];
	//char lang[100];

	//cout << "이름은?";
	//cin >> name;
	//cout << "좋아하는 언어는?";
	//cin >> lang;

	//cout << "이름은 " << name << endl;
	//cout << "좋아하는 언어는 " << lang << endl;

	// Overloading //
/*
	int a = 3, b = 6, c = 9;
	int &k = a;

	cout << "Add(3) = " << Add(&a) << endl;
	cout << "4 + 6 = " << Add(a,b) << endl;
	cout << "4 + 6 + 9 = " << Add(a, b, c) << endl;

	cout << "Add_Default = " << Add() << endl;

	cout << " 3, 3, 3 -> " << DefaultFunc(3, 3, 3) << endl;
	cout << " 5, 5,  -> " << DefaultFunc(5, 5) << endl;
	cout << " 7, ,  -> " << DefaultFunc(7) << endl;

	SimpleFunc();
	my2::SimpleFunc();

	using hybrid::hybfunc;
	hybfunc();

	namespace quick = my1::my2::my3;
	quick::notSimpleFunc();

	printf("원본 : %d \n", a);
	printf("참조 : %d \n", k);

	int arr[3] = { 1,3,5 };
	int &ref1 = arr[0];

	cout << ref1 << endl;*/



	return 0;
}
int Add(int *a)
{
	*a += 1;
	return *a;
}
int Add(int a, int b)
{
	return a + b;
}
int Add(int a, int b, int c)
{
	return a + b + c;
}
int Add(int a)
{
	a += 1;
	return a;
}
int DefaultFunc(int length, int width, int height)
{
	return length * width * height;
}

void my2::SimpleFunc()
{
	cout << "ProgCom" << endl;
	my1::SimpleFunc2();
}

namespace my1
{
	void SimpleFunc2()
	{
		cout << "SOPRT" << endl;
	}
}

void my1::my2::my3::notSimpleFunc()
{
	cout << "my1::my2::my3::notSImpleFunc()"<<endl;
}