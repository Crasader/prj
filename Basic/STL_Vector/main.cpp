#include <iostream>
#include <vector>

using namespace std;

class Box
{
public:
	Box() {	Empty();}
	void Add(int n) { total += n; }
	void Empty() { total = 0; }
	int GetTotal() { return total; }

	Box operator+(Box a);
	Box &operator=(Box &a);

private:
	int total;
};

Box &Box::operator= (Box &a)
{
	if (this == &a)
		return *this;

	Empty();
	Add(a.GetTotal() + 60);
	return *this;
}

Box Box::operator+ (Box a)
{
	Box result;
	
	int total;
	total = a.GetTotal() + GetTotal();

	result.Add(total);

	return result;
}

int main()
{
	//vector<int> v1;

	//v1.push_back(10);
	//v1.push_back(11);
	//v1.push_back(15);
	//
	//vector<int>::iterator itr_first, itr_last,i;
	//itr_first = v1.begin();
	//itr_last = v1.end();
	//
	//for ( i = itr_first; i != itr_last; i++)
	//{
	//	cout << *i << endl;
	//}

	//for (int j = 0; j < v1.size(); j++)
	//{
	//	cout << v1.at(j) << endl;
	//}

	Box a1; a1.Add(10);
	Box a2; a2.Add(30);
	Box a3; a3.Add(90);

	vector<Box> v2;

	v2.push_back(a1);
	v2.push_back(a2);
	v2.push_back(a3);

	vector<Box>::iterator first, last, idx;

	first = v2.begin();
	last = v2.end();

	for (vector<Box>::size_type i = 0; i < (int)v2.size(); i++)
	{
		cout << v2.at(i).GetTotal() << endl;
	}

	v2[1] = v2[0] + v2[0];
	cout<<v2.at(1).GetTotal()<<endl;

	v2[2] = v2[0];
	cout << v2.at(2).GetTotal() << endl;

	return 0;
}