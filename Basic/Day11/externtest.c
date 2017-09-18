extern int item;
#include "structheader.h"

void doWork()
{
	headstruct a;
	a.x = item;
	a.y = -item;

	printf("%d + %d\n",a.x,a.y);
}