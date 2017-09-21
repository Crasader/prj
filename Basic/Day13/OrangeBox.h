#pragma once
#include <iostream>

class OrangeBox
{
private:
	int total;
public:
	OrangeBox();
	OrangeBox(int init);
	~OrangeBox();

	void Add(int num);
	void Del(int num);
	void Empty();
	int GetTotal()
	{
		return total;
	}
};

OrangeBox::OrangeBox()
{
	total = 0;
	printf("������Ʈ ���� (%d)\n",total);
}
OrangeBox::OrangeBox(int init)
{
	total = init;
	printf("������Ʈ ���� (%d)\n", total);
}
OrangeBox::~OrangeBox()
{
	std::cout << "������Ʈ �ֱ�!" << std::endl;
}

void OrangeBox::Add(int num)
{
	total += num;
}
void OrangeBox::Del(int num)
{
	total -= num;
	if (total < 0)
	{
		Empty();
	}
}
void OrangeBox::Empty()
{
	total = 0;
}
