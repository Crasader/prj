//
//#pragma warning( disable : 4996)
//#include <stdio.h>
//#include <conio.h>
//#include <time.h>
//#include <windows.h>
//
//void print_time(struct tm *now, int tail)
//{
//	COORD CursorPosition = { 0,1 };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
//
//	printf("%d시 %d분 %d초 %2d\n",
//		now->tm_hour, now->tm_min, now->tm_sec, tail);
//}
//
//
//int main()
//{
//	clock_t sclock, nclock;
//	time_t seconds;
//	struct tm *now;
//	int tail = 0;
//
//	printf("종료를 원하시면 아무키나 누르세요.\n");
//
//	sclock = clock();
//	time(&seconds);
//	now = localtime(&seconds);
//	print_time(now, tail);
//
//	while (1)
//	{
//		if (kbhit())
//		{
//			break;
//		}
//
//		nclock = clock;
//		if (nclock - sclock >= (CLOCKS_PER_SEC / 100))
//		{
//			tail++;
//			if (tail == 100)
//			{
//				tail = 0;
//				sclock = clock();
//				time(&seconds);
//				now = localtime(&seconds);
//			}
//			print_time(now, tail);
//		}
//	}
//	printf("종료\n");
//
//	return 0;
//}