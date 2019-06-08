#include "noriyut.h"

void all()
{
	int k = 1; //1,2 팀표현
	int a;
	int x, y;
	r = -1;

	x = 3, y = 3;
	YutNori();                  //윷놀이 판 출력

	printf("\n");

	x = 73;
	y = 4;
	printf("\n\n\n");
	mal_pan(x, y);
	gotoxy(x + 5, y + 1);
	printf("현재순서");
	gotoxy(x + 5, y + 3);
	setcolor(11, 0);
	print_team_name();            //1팀 2팀 번갈아가며 표현하는 위치(순서)
	unsetcolor();

	printf("\n\n\n");

	y = 9;
	draw_yutpan(x, y);
	gotoxy(x + 6, y + 1);
	print_yut_name();                     //무엇이 나왔는지?
	whatyut(x, y);

	y = 28;
	draw_score(x, y);
	gotoxy(x + 4, y + 1);
	setcolor(13, 0);
	printf("<<점수판>>");
	unsetcolor();
	gotoxy(x + 3, y + 3);            //현재 각 팀의 점수를 나타내주는 위치
	printf("팀 1 : ");
	gotoxy(x + 3, y + 5);
	printf("팀 2 : ");

	y = 35;
	mal_pan(x, y);                  //말이 현재 얼마나 남았는 지 알려주는 위치
	gotoxy(x + 2, y + 1);
	printf("팀 1 : ");
	gotoxy(x + 2, y + 3);
	printf("팀 2 : ");

	x = 4;
	y = 38;
	board(x, y);                  //설명문 나오는 위치
	gotoxy(x + 2, y + 3);
	explain(YUT);
	r = 0;


	printf("\n\n");
}


void YutNori() {               //윷놀이 판 출력함수
	int x = 4;
	int y = 4;
	gotoxy(x, y);
	draw_large_square(x, y);
	draw_basic_square(x + 12, y);
	draw_basic_square(x + 24, y);
	draw_basic_square(x + 37, y);
	draw_basic_square(x + 49, y);
	draw_large_square(x + 57, y);
	y = 9;
	draw_basic_square(x + 10, y);
	draw_basic_square(x + 51, y);
	y = 10;
	draw_basic_square(x, y);
	draw_basic_square(x + 61, y);
	y = 14;
	draw_basic_square(x + 20, y);
	draw_basic_square(x + 42, y);
	y = 16;
	draw_basic_square(x, y);
	draw_basic_square(x + 61, y);
	y = 18;
	draw_large_square(x + 29, y);
	y = 22;
	draw_basic_square(x, y);
	draw_basic_square(x + 61, y);
	y = 24;
	draw_basic_square(x + 20, y);
	draw_basic_square(x + 42, y);
	y = 28;
	draw_basic_square(x, y);
	draw_basic_square(x + 61, y);
	y = 29;
	draw_basic_square(x + 10, y);
	draw_basic_square(x + 51, y);
	y = 34;
	gotoxy(x + 59, y - 1);
	setcolor(11, 0);
	printf("START");
	unsetcolor();
	draw_large_square(x, y - 2);
	draw_basic_square(x + 12, y);
	draw_basic_square(x + 24, y);
	draw_basic_square(x + 37, y);
	draw_basic_square(x + 49, y);
	draw_large_square(x + 57, y - 2);
}

void draw_basic_square(int x, int y)         //no touch
{
	unsigned char a = 0xa6, b[7], i;
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	gotoxy(x + 2, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y);
	printf("%c%c", a, b[4]);
	gotoxy(x, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x + 4, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 2);
	printf("%c%c", a, b[6]);
	gotoxy(x + 2, y + 2);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y + 2);
	printf("%c%c", a, b[5]);
}

void draw_large_square(int x, int y) {         //큰 사각형
	unsigned char a = 0xa6, b[7], i;
	//setcolor(16, 0);
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	gotoxy(x + 2, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 6, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 8, y);
	printf("%c%c", a, b[4]);
	gotoxy(x, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x + 8, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 2);
	printf("%c%c", a, b[2]);
	gotoxy(x + 8, y + 2);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 3);
	printf("%c%c", a, b[2]);
	gotoxy(x + 8, y + 3);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 4);
	printf("%c%c", a, b[6]);
	gotoxy(x + 2, y + 4);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y + 4);
	printf("%c%c", a, b[1]);
	gotoxy(x + 6, y + 4);
	printf("%c%c", a, b[1]);
	gotoxy(x + 8, y + 4);
	printf("%c%c", a, b[5]);
	//unsetcolor();
}

void draw_score(int x, int y)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 15; n++) {
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 6; k++) {
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);
		gotoxy(x + 16, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 6);
	printf("%c%c", a, b[6]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y + 6);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y + 6);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void draw_yutpan(int x, int y)               //윷이 무엇인 지 출력되는 판
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);               //윗변
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 18; k++)   //세로
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);
		gotoxy(x + 16, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 18);            //아랫변
	printf("%c%c", a, b[6]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y + 18);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y + 18);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void board(int x, int y)               //설명문 출력되는 창
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 63; n++)      //가로
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 64, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 6; k++)         //세로
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);

		gotoxy(x + 64, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 6);
	printf("%c%c", a, b[6]);
	for (int m = 1; m < 63; m++)
	{
		gotoxy(x + (m + 1), y + 6);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 64, y + 6);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void mal_pan(int x, int y)      //현재 각팀의 말 상황을 나타내 주는 판
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 4; k++)
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);

		gotoxy(x + 16, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 4);
	printf("%c%c", a, b[6]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y + 4);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y + 4);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void yut(int x, int y)                  //기본적인 윷 모양 막대기 4개
{
	unsigned char a = 0xa6, b[7], i;
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	gotoxy(x + 2, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 6; k++)         //세로
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);

		gotoxy(x + 4, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 6);
	printf("%c%c", a, b[6]);
	gotoxy(x + 2, y + 6);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y + 6);
	printf("%c%c", a, b[5]);
}            //윷막대기

void whatyut(int x, int y)            //도개걸윷모 or 빽도 표현
{
	switch (YUT)
	{
	case 0:
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			printf(" ");
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			printf(" ");
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			printf(" ");
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			printf(" ");
		}
		break;
	case 1:
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			printf("  ");
		}
		break;
	case 2:
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			printf("  ");
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			printf("  ");
		}
		break;
	case 3:
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			printf("  ");
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			printf("  ");
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			printf("  ");
		}
		break;
	case 4:
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			printf("  ");
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			printf("  ");
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			printf("  ");
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			printf("  ");
		}
		break;
	case 5:
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		break;
	case -1:
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			setcolor(12, 0);
			printf("Φ");
			unsetcolor();
		}
		break;
	}
}

void explain(int yut)
{
	int key;

	if (YUT == 1) {
		setcolor(10, 0);
		printf("'도'가 나왔습니다 말을 한칸 이동합니다.                      ");
		unsetcolor();
	}
	else if (YUT == 2) {
		setcolor(13, 0);
		printf("'개'가 나왔습니다 말을 두칸 이동합니다.                      ");
		unsetcolor();
	}
	else if (YUT == 3) {
		setcolor(6, 0);
		printf("'걸'이 나왔습니다 말을 세칸 이동합니다.                      ");
		unsetcolor();
	}
	else if (YUT == 4) {
		setcolor(11, 0);
		printf("'윷'이 나왔습니다 윷을 한번 더 던지고 말을 네칸 이동합니다.  ");
		unsetcolor();
	}
	else if (YUT == 5) {
		setcolor(14, 0);
		printf("'모'가 나왔습니다 윷을 한번 더 던지고 말을 다섯칸 이동합니다.");
		unsetcolor();
	}

	else if (YUT == -1) {
		setcolor(12, 0);
		printf("'빽도'가 나왔습니다 말을 뒤로 한칸 움직입니다.              ");
		unsetcolor();
	}

	gotoxy(6, 42);
	printf("                                                          ");
}

void Print_Game()
{
	int i;

	loading();

	system("cls");
	setcolor(12, 0);
	printf("\n\t◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇ COMPLETE ◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆");
	Sleep(300);
	unsetcolor();
	system("cls");
	setcolor(11, 0);
	printf("\n\t★☆★☆★☆★☆★☆★☆★☆◀ YUTNORI ▶☆★☆★☆★☆★☆★☆★☆★");
	unsetcolor();
}

void loading() {
	HBITMAP image;
	for (int i = 0; i < 2; i++)
	{
		image = (HBITMAP)LoadImage(NULL, TEXT("loading1.bmp"), IMAGE_BITMAP, 1500, 900, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_monitor(image);
		Sleep(300);


		image = (HBITMAP)LoadImage(NULL, TEXT("loading2.bmp"), IMAGE_BITMAP, 1500, 900, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_monitor(image);
		Sleep(300);


		image = (HBITMAP)LoadImage(NULL, TEXT("loading3.bmp"), IMAGE_BITMAP, 1500, 900, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_monitor(image);
		Sleep(300);

		image = (HBITMAP)LoadImage(NULL, TEXT("loading4.bmp"), IMAGE_BITMAP, 1500, 900, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_monitor(image);
		Sleep(300);


		image = (HBITMAP)LoadImage(NULL, TEXT("loading5.bmp"), IMAGE_BITMAP, 1500, 900, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_monitor(image);
		Sleep(300);


		image = (HBITMAP)LoadImage(NULL, TEXT("loading6.bmp"), IMAGE_BITMAP, 1500, 900, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_monitor(image);
		Sleep(300);
	}
}

void Start_monitor() {
	HBITMAP image;

	image = (HBITMAP)LoadImage(NULL, TEXT("Start.bmp"), IMAGE_BITMAP, 1700, 1000, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	CursorView(0);
	print_monitor(image);
	Sleep(1500);
}

void print_monitor(HBITMAP hImage)
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	HBITMAP hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 0, 0, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}
