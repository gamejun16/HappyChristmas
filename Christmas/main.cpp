#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <Windows.h>

#include <iostream>
#include <vector>
using namespace std;


#include "Draw.h"

//´« °´Ã¼
class SNOW {
	//Àû¼³·®
	static int snowdepth;
	//´« °¹¼ö
	static int snowcount;

	//´«ÀÇ x,yÁÂÇ¥
	int xpos;
	int ypos;

public:
	//»ý¼ºÀÚ
	SNOW(int x = 0, int y = 0) :xpos(x), ypos(y) { snowcount++; }
	//¼Ò¸êÀÚ
	~SNOW() {
		snowcount--;
	}
	//yÁÂÇ¥ Á¢±ÙÀÚ
	int getYpos() { return ypos; }
	//´«³»¸®´ÂÀÌÆåÆ®
	void snowing() { 
		if (ypos != 30) {
			Draw(xpos, ypos, WHITE, " ");
			ypos++;
			Draw(xpos, ypos, WHITE, "*");
		}
		else
			this->~SNOW();
	}
};
//int SNOW::snowdepth = 0;
int SNOW::snowcount = 0;


//ÄÜ¼Ö Á¦¾î Çì´õ
void ChangeConsoleSize(HANDLE hBuffer, int cx, int cy);



void main()
{
	//system("mode con:cols=80 lines=32");
	//ÄÜ¼ÖÅ©±â Á¦¾î
	ChangeConsoleSize(GetStdHandle(STD_OUTPUT_HANDLE), 80, 32);
	//Ä¿¼­±ôºýÀÓ Á¦°Å
	removeCursor();
	//Ä¿¼­ Á¦¾î
	HANDLE hIn, hOut;
	INPUT_RECORD rec;
	DWORD dw;

	// ÀÔÃâ·Â¿¡ »ç¿ëµÉ ÇÚµéÀ» °¡Á®¿É´Ï´Ù.
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos{ 0,0 };

	//º¤ÅÍ ¼±¾ð
	vector<SNOW> snows;
	vector<SNOW>::iterator it;
	float time_1 = 0, time_2 = 0, time_3 = 0;
	time_1 = clock();
	while (1) {
		// »ç¿ëÀÚ·ÎºÎÅÍ ÀÔ·ÂÀ» ¹Þ½À´Ï´Ù.
		PeekConsoleInput(hIn, &rec, 1, &dw);
		if (dw > 0)
			ReadConsoleInput(hIn, &rec, 1, &dw);

			//ÁÂÅ¬¸¯½Ã
			//if (rec.Event.MouseEvent.dwButtonState &FROM_LEFT_1ST_BUTTON_PRESSED) {
		if (rec.EventType == MOUSE_EVENT) {
			cout << "click" << endl;
			if (rec.Event.MouseEvent.dwButtonState&FROM_LEFT_1ST_BUTTON_PRESSED) {
				pos = rec.Event.MouseEvent.dwMousePosition;
				
				snows.insert(snows.end(), SNOW(pos.X, pos.Y));
			}
		}

		time_2 = clock() - time_1;
		time_1 = clock();
		time_3 += time_2;

		if (time_3 > 50) {
			for (it = snows.begin(); it != snows.end(); it++) {
				it->snowing();
			}
			time_3 = 0;
		}
		//ÀÙ
		{
			//ÀÙ(ÃÖ»ó´Ü)
			Draw(39, 5, YELLOW, "¡Ú");
			Draw(39, 6, BG_DGREEN, "¡¡");
			Draw(38, 7, BG_DGREEN, "¡¡¡¡");
			Draw(37, 8, BG_DGREEN, "¡¡¡¡¡¡");
			Draw(36, 9, BG_DGREEN, "¡¡¡¡¡¡¡¡");
			

			//ÀÙ(»ó´Ü)
			Draw(34, 11, BG_DGREEN, "¡¡ ¡¡");		Draw(41, 11, BG_DGREEN, "¡¡ ¡¡");
			Draw(33, 12, BG_DGREEN, "¡¡¡¡¡¡");		Draw(41, 12, BG_DGREEN, "¡¡¡¡¡¡");
			Draw(32, 13, BG_DGREEN, "¡¡¡¡¡¡ ");		Draw(41, 13, BG_DGREEN, "¡¡¡¡¡¡ ");
			Draw(31, 14, BG_DGREEN, "¡¡¡¡¡¡¡¡");	Draw(41, 14, BG_DGREEN, "¡¡¡¡¡¡¡¡");

			Draw(31, 15, RED, "¦¢"); Draw(47, 15, RED, "¦¢");
			Draw(31, 16, RED|BG_DGREEN, "¡Ü"); Draw(47, 16, RED|BG_DGREEN, "¡Ü");

			//ÀÙ(Áß´Ü)
			Draw(29, 16, BG_DGREEN, "¡¡"); Draw(33, 16, BG_DGREEN, " "); Draw(36, 16, BG_DGREEN, "  ¡¡  ¡¡");	Draw(46, 16, BG_DGREEN, " "); Draw(49, 16, BG_DGREEN, "  ");
			Draw(28, 17, BG_DGREEN, "¡¡¡¡¡¡");		Draw(36, 17, BG_DGREEN, "¡¡  ¡¡¡¡");	Draw(46, 17, BG_DGREEN, "¡¡¡¡¡¡");
			Draw(27, 18, BG_DGREEN, "¡¡¡¡¡¡ ");		Draw(36, 18, BG_DGREEN, "¡¡¡¡¡¡  ");	Draw(46, 18, BG_DGREEN, "¡¡¡¡¡¡ ");
			Draw(26, 19, BG_DGREEN, "¡¡¡¡¡¡¡¡");	Draw(36, 19, BG_DGREEN, "¡¡¡¡¡¡¡¡");	Draw(46, 19, BG_DGREEN, "¡¡¡¡¡¡¡¡");

			Draw(26, 20, RED, "¦¢"); Draw(52, 20, RED, "¦¢");
			Draw(26, 21, RED|BG_DGREEN, "¡Ü"); Draw(52, 21, RED|BG_DGREEN, "¡Ü");

			//ÀÙ(ÇÏ´Ü)
			Draw(24, 21, BG_DGREEN, "  "); Draw(28, 21, BG_DGREEN, " ");		Draw(31, 21, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(41, 21, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(51, 21, BG_DGREEN, " ");Draw(54, 21, BG_DGREEN, "  ");
			Draw(23, 22, BG_DGREEN, "¡¡¡¡¡¡");		Draw(31, 22, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(41, 22, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(51, 22, BG_DGREEN, "¡¡¡¡¡¡");
			Draw(22, 23, BG_DGREEN, " ¡¡¡¡¡¡");		Draw(31, 23, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(41, 23, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(51, 23, BG_DGREEN, "¡¡¡¡¡¡ ");
			Draw(21, 24, BG_DGREEN, "¡¡¡¡¡¡¡¡");	Draw(31, 24, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(41, 24, BG_DGREEN, "¡¡¡¡¡¡¡¡"); Draw(51, 24, BG_DGREEN, "¡¡¡¡¡¡¡¡");

			Draw(21, 25, RED, "¦¢"); Draw(57, 25, RED, "¦¢");
			Draw(21, 26, RED, "¡Ü"); Draw(57, 26, RED, "¡Ü");
		}

		//ÁÙ±â
		{
			for (int y = 29; y > 25; y--)
				Draw(36, y, BG_DRED, "¡¡¡¡¡¡¡¡");
		}

		//¹Ù´Ú ´«
		{
			for (int x = 0; x < 80; x++) {
				Draw(x, 30, WHITE, "/");
			}
		}

	}
}

//ÄÜ¼Ö Å©±â Á¦¾î
void ChangeConsoleSize(HANDLE hBuffer, int cx, int cy)
{
	enum EFlag
	{
		FlagNoChange,
		FlagWindowFirst,
		FlagScreenFirst
	};

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hBuffer, &csbi);
	csbi.srWindow.Right -= csbi.srWindow.Left;
	csbi.srWindow.Bottom -= csbi.srWindow.Top;
	csbi.srWindow.Left = 0;
	csbi.srWindow.Top = 0;
	SetConsoleWindowInfo(hBuffer, TRUE, &csbi.srWindow);

	COORD coordLargestSize = GetLargestConsoleWindowSize(hBuffer);
	COORD coordNewSize = { min(coordLargestSize.X, cx), min(coordLargestSize.Y, cy) };
	COORD coordWindowSize = { csbi.srWindow.Right + 1, csbi.srWindow.Bottom + 1 };
	SMALL_RECT srWindowRect = {};

	EFlag eFlag = FlagNoChange;

	if (coordWindowSize.Y > coordNewSize.Y)
	{
		if (coordWindowSize.X < coordNewSize.X)
		{
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Bottom = coordNewSize.Y - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
			eFlag = FlagScreenFirst;
		}
		else
		{
			eFlag = FlagWindowFirst;
		}
	}
	else if (coordWindowSize.Y < coordNewSize.Y)
	{
		if (coordWindowSize.X > coordNewSize.X)
		{
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Right = coordNewSize.X - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
		}
		eFlag = FlagScreenFirst;
	}
	else
	{
		if (coordWindowSize.X > coordNewSize.X)
		{
			eFlag = FlagWindowFirst;
		}
		else if (coordWindowSize.X < coordNewSize.X)
		{
			eFlag = FlagScreenFirst;
		}
	}


	if (eFlag != FlagNoChange)
	{
		srWindowRect.Right = coordNewSize.X - 1;
		srWindowRect.Bottom = coordNewSize.Y - 1;
		if (eFlag == FlagWindowFirst)
		{
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
		}
		else
		{
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
		}
	}
}

