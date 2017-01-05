#include<stdio.h>
#include<string.h>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <dos.h>
#include<ctype.h>
#include <amp_graphics.h>

union REGS in, out;
int welcome();
int board();
int callmouse()
{
	in.x.ax = 1;
	int86(51, &in, &out)
		return 1;


}
int welcome()
{
	char n1[10];
	char n2[10];
	char *name1, *name2;
	printf("WELCOME TO THE BACKGAMMON GAME\n\n\n");
	printf("Write your name 1:\n");
	scanf("%s, &n1");
	while (strlen(n1) > 9)
	{
		scanf("%s", &n1);
	}
	printf("Write your name 2\n")
		scanf("%s,&n2");
	while (strlen(n2) > 9)
	{
		scanf("%s", &n2);
	}
	int dice[2];
	printf("Press any key for %s to roll the dice\n", n1);
	randomize()
		dice[0] = (rand() % 6) + 1;
	printf("Result of the roll is %d\n", dice[0]);
	getch();
	printf("Press any key for %s to roll the dice\n", n2);
	randomize();
	dice[1] = (rand() % 6) + 1;
	printf("Result of roll is %d\n", dice[1]);
	if (dice[0] > dice[1])
	{
		name1 = n1;
		name2 = n2;
	}
	else {
		name1 = n2;
		name2 = n1;

	}

	callmouse();
	board();
	return 0;
}
int board()
{
	int p0[18] = { 24,0,36,128,48,0,72,0,84,128,96,0,120,0,132,128,144,0 };
	int p1[18] = { 48,0,54,128,72,0,96,0,108,128,120,0,144,0,156,128,168,0 };
	int p2[18] = { 216,0,228,128,240,0,264,0,276,128,288,0,312,0,324,128,336,0 };
	int p3[18] = { 240,0,252,128,264,0,288,0,300,128,312,0,336,0,348,128,360,0 };
	int p4[18] = { 24,384,36,256,48,384,72,384,84,256,96,384,120,384,132,256,144,384 };
	int p5[18] = { 48,384,60,256,72,384,96,384,108,256,120,384,144,384,156,256,168,384 };
	int p6[18] = { 216,384,228,256,240,384,264,384,276,256,288,384,312,384,324,256,336,384 };
	int p7[18] = { 240,384,252,256,264,384,288,384,300,256,312,384,336,384,348,256,360,384 };
	setbkcolor(BLACK);
	setcolor(2);
	rectangle(0, 0, 415, 384);
	rectangle(370, 15, 405, 190);
	rectangle(370, 369, 405, 200);
	line(24, 0, 24, 384);
	line(168, 0, 168, 384);
	line(216, 0, 216, 384);
	line(360, 0, 360, 384);
	/* First v shape */
	setcolor(3);
	drawpoly(9, p0);
	drawpoly(9, p2);
	drawpoly(9, p4);
	drawpoly(9, p6);
	/* Second V shape */
	setcolor(4);
	drawpoly(9, p1);
	drawpoly(9, p3);
	drawpoly(9, p5);
	drawpoly(9, p7;

	/* filling the v-shape no. 1 */
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillpoly(9, p0);
	fillpoly(9, p2);
	fillpoly(9, p4);
	fillpoly(9, p6);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	fillpoly(9, p1);
	fillpoly(9, p3);
	fillpoly(9, p5);
	fillpoly(9, p7);
	/*1st player*/
	setfillstyle(SOLID_FILL, RED);
	setcolor(6);
	/*first quadrant*/
	fillellipse(36, 12, 12, 12);
	fillellipse(36, 36, 12, 12);
	fillellipse(36, 60, 12, 12);
	fillellipse(36, 84, 12, 12);
	fillellipse(36, 108, 12, 12);
	/*2nd quadrant*/
	fillellipse(348, 12, 12, 12);
	fillellipse(348, 36, 12, 12);
	/* 3rd quadrant */
	fillellipse(132, 372, 12, 12);
	fillellipse(132, 348, 12, 12);
	fillellipse(132, 324, 12, 12);
	/* 4th quadrant */
	fillellipse(228, 372, 12, 12);
	fillellipse(228, 348, 12, 12);
	fillellipse(228, 324, 12, 12);
	fillellipse(228, 300, 12, 12);
	fillellipse(228, 276, 12, 12);


	/* 2nd player*/

	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(8);
	/*first quadrant*/
	fillellipse(132, 12, 12, 12);
	fillellipse(132, 36, 12, 12);
	fillellipse(132, 60, 12, 12);

	/*2nd quadrant*/
	fillellipse(228, 12, 12, 12);
	fillellipse(228, 36, 12, 12);
	fillellipse(228, 60, 12, 12);
	fillellipse(228, 84, 12, 12);
	fillellipse(228, 108, 12, 12);

	/* 3rd quadrant */

	fillellipse(36, 372, 12, 12);
	fillellipse(36, 348, 12, 12);
	fillellipse(36, 324, 12, 12);
	fillellipse(36, 300, 12, 12);
	fillellipse(36, 276, 12, 12);

	/* 4th quadrant */
	fillellipse(348, 372, 12, 12);
	fillellipse(348, 348, 12, 12);

	/* message area */
	setcolor(BROWN);
	rectangle(10, 427, 215, 467);
	outtextxy(11, 416, "MESSAGE DISPLAY AREA");
	setcolor(WHITE);
	outtextxy(50, 440, "BACKGAMMON FURY");
	setcolor(GREEN);
	outtextxy(44, 452, "BY IULIA BELDIMAN”);

		/* Dice */
		setcolor(GREEN);
	outtextxy(244, 160, "DICE");
	rectangle(243, 172, 333, 212);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, GREEN);
	rectangle(248, 177, 278, 207);
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(298, 177, 328, 207);
	/* TEXT BOX FOR PLAYER 1 */
	setcolor(RED);
	rectangle(420, 28, 500, 56);
	outtextxy(420, 7, "PLAYER 1");
	outtextxy(425, 39, "name1");
	rectangle(505, 28, 580, 56);
	outtextxy(505, 7, "SCORE");
	/* TEXT BOX FOR PLAYER 2 */
	setcolor(YELLOW);
	rectangle(420, 80, 500, 109);
	outtextxy(420, 60, "PLAYER 2");
	outtextxy(425, 91, "name2");
	rectangle(505, 80, 580, 109);
	outtextxy(505, 60, "SCORE");
	/* MENU BAR */
	setcolor(WHITE);
	outtextxy(465, 140, "MENU");
	setcolor(CYAN);
	rectangle(450, 157, 530, 188);
	outtextxy(459, 165, "START");
	rectangle(450, 200, 530, 232);
	outtextxy(459, 209, "RESTART");
	rectangle(450, 243, 530, 276);
	(455, 253, "ROLL DICE");
	rectangle(450, 286, 530, 319);
	outtextxy(459, 297, "QUIT");
	return 0;
}
void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	welcome();
	getch();
	closegraph();
}






