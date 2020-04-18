#include "Draw.h"

void Draw(int x, int y, int color, char *text, ...)
{
	//콘솔 내 커서위치 지정
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	//"..."을 통해 들어온 변수들을 문자열로 처리하기 위한 방법
	va_list va_ptr;
	char msg[512] = { NULL, };
	va_start(va_ptr, text);
	vsprintf(msg, text, va_ptr);
	va_end(va_ptr);
	//색상지정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//그리기
	printf("%s", msg);
	//색상 원래대로 지정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}

void removeCursor(void)//커서 깜빡임 제거
{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
