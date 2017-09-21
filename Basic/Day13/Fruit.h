#pragma once
#include <string>

class item
{
private:
	int price1;
protected:
	int price2;
public:
	int price3;

public:
	item()
	{
		price1 = 50;
		price2 = 200;
		price3 = 100;
	}
public:
	void print1()
	{
		printf("부모 - item의 Price 1 : %d\n",price1);
	}
};

class Food
{
private:
	int price1;
protected:
	int price2;
public:
	int price3;

public:
	Food()
	{
		price1 = 20;
		price2 = 30;
		price3 = 40;
	}

	void print1()
	{
		printf("부모 프린트 & price 1 : %d\n",price1);
	}
};

class Fruit : public Food, public item
{
public:
	void print2()
	{
		printf("자식 프린트 & price 2 : %d\n",Food::price2);
	}
	void print3()
	{
		printf("자식 프린트 & price 3 : %d\n", Food::price3);
	}
};