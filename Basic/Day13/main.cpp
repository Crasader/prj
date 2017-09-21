#include <iostream>
#include <string>

#include "car.h"
#include "OrangeBox.h"
#include "Fruit.h"
using namespace std;

void test(Food a);

int main()
{
	//cout << "Exam 01 : " << endl;
	//
	//Car a("run99",100,0);
	//a.Accel();
	//a.Accel();
	//a.ShowState();
	//a.Break();
	//a.ShowState();

	//Car b = { "ad93",100,0 };
	//b.Accel();
	//b.Break();
	//b.ShowState();
/*
	OrangeBox obox;
	obox.Empty();
	obox.Add(5);
	obox.Del(4);
	int nResult = obox.GetTotal();
	cout << nResult << endl;

	OrangeBox *obox2 = new OrangeBox;
	(*obox2).Empty();
	obox2->Add(2);
	delete obox2;

	OrangeBox obox3(15);
	obox.Add(5);
	obox.Del(4);
	nResult = obox.GetTotal();
	cout << nResult << endl;

	OrangeBox *obox4 = new OrangeBox(23);
	(*obox4).Empty();
	obox4->Add(24);
	delete obox4;*/

	Fruit fruit;
	fruit.item::print1();
	fruit.print2();
	fruit.print3();

	printf("Price 3 : %d\n", fruit.item::price3);

	Food food = fruit;
	food.print1();

	item Item = fruit;
	Item.print1();

	test(fruit);

	return 0;
}

void test(Food a)
{
	a.print1();
}