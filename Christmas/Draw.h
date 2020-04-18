#ifndef __DRAW_H__
#define __DRAW_H__

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//색상 메크로 정의
#define RED            (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define DRED         (FOREGROUND_RED)
#define GREEN         (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define DGREEN         (FOREGROUND_GREEN)
#define BLUE         (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define DBLUE         (FOREGROUND_BLUE)
#define PURPLE         (RED | BLUE)
#define DPURPLE         (DRED | DBLUE)
#define WHITE         (RED | GREEN | BLUE)
#define GRAY         (DRED | DGREEN | DBLUE)
#define DGRAY         (GRAY | WHITE)
#define YELLOW         (RED | GREEN )
#define DYELLOW         (DRED | DGREEN)
#define SKYBLUE         (GREEN | BLUE)
#define DSKYBLUE      (DGREEN | DBLUE)

#define BG_RED         (BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_DRED         (BACKGROUND_RED)
#define BG_GREEN      (BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_DGREEN      (BACKGROUND_GREEN)
#define BG_BLUE         (BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BG_DBLUE         (BACKGROUND_BLUE)
#define BG_PURPLE      (BG_RED | BG_BLUE)
#define BG_DPURPLE      (BG_DRED | BG_DBLUE)
#define BG_WHITE      (BG_RED | BG_GREEN | BG_BLUE)
#define BG_GRAY         (BG_DRED | BG_DGREEN | BG_DBLUE)
#define BG_DGRAY		(BG_GRAY | BG_WHITE)
#define BG_YELLOW      (BG_RED | BG_GREEN)
#define BG_DYELLOW      (BG_DRED | BG_DGREEN)
#define BG_SKYBLUE      (BG_GREEN | BG_BLUE)
#define BG_DSKYBLUE      (BG_DGREEN | BG_DBLUE)

//Draw 함수
void Draw(int x, int y, int color, char *text, ...);

//커서 깜빡임 제거
void removeCursor(void);


#endif

