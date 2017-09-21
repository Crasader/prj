#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	char sNum[] = "1234567";
	int nUserScore = 100;
	int nComScore = 200;

	//--
	int nNum = atoi(sNum);
	printf("%d \n", nNum);

	//--
	double temp = 13.112;
	char myNum[30] = { 0 };
	sprintf_s(myNum, "Your Score : %d, %g", nUserScore,temp);
	printf("%s \n", myNum);

	//__
	stringstream out2;
	out2 << nComScore;
	string comNum = "Computer Score : " + out2.str() + "\n";
	cout << comNum.c_str();

	return 0;
}