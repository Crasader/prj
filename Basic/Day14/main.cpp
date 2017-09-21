#include <iostream>
using namespace std;
//
//int GetMax(int a, int b)
//{
//	int buf;
//	if (a > b)
//		buf = a;
//	else
//		buf = b;
//	return buf;
//}
//double GetMax(double a, double b)
//{
//	double buf;
//	if (a > b)
//		buf = a;
//	else
//		buf = b;
//	return buf;
//}

template<class T, class T2>
T2 GetMax(T a, T2 b)
{
	T buf;

	if (a > b)
		buf = a;
	else
		buf = b;

	return buf;
}

template<class T>
class Rectangle
{
public:
	Rectangle(T n1, T n2, T n3, T n4)
	{
		left = n1;
		top = n2;
		width = n3;
		height = n4;
	}

	T GetRight()
	{
		return left = width;
	}

	T GetBottom()
	{
		return top + height;
	}

	T left, top, width, height;
};

int main()
{
	int n1 = 1, n2 = 6, ret1;
	double r1 = 10.15, r2 = 12.45, ret2;
	ret1 = GetMax<int, double>(n1, r2);
	ret2 = GetMax<double, double>(r1, n2);
	cout << "test 1 : " << endl;
	cout << ret1 << endl;

	Rectangle<int> rect1(50, 50, 100, 100);
	cout << rect1.GetRight() << endl;

	Rectangle<double> rect2(50.5, 50.5, 100.1, 100.1);
	cout << rect2.GetRight() << endl;

	return 0;
}