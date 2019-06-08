#include "noriyut.h"

/* --------------------- 공통함수 정의부 --------------------- */

void gotoxy(int x, int y); // x,y좌표로 이동
void setcolor(unsigned short text, unsigned short back); // 선택된 색깔 출력
void unsetcolor(); // 색깔 초기화
void CursorView(char show); // 커서 숨김


int main(void)	//출력하는 창의 순서 중요 ( x ,y 좌표가 흔들립니다.)
{
	int menu;
	int i;

	YUT = 0;

	Start_monitor();

	setpan(basic); //판 좌표 설정
	system("title 윷놀이 게임");

	srand(time(NULL)); // 랜덤

	team = initalize_mal(); //전체 말정보 초기화
	menu = select_logo();



	if (menu == 1)// 첫 화면 띄우기
	{
		if (select_about() == 1)
		{
			input_penalty();
			color_menu(team);
			gotoxy(5, 18);
			Print_Game();
			all(); // 윷판 출력
		}
	}
	else if (menu == 2)
	{
		input_penalty();
		color_menu(team);
		gotoxy(5, 18);
		Print_Game();
		all(); // 윷판 출력
	}

	startyutpan();

	move_mal();



	/* ------------- 동적할당 해제 ---------------- */
	for (i = 0; i < 2; i++)
		free(team[i]); // 동적할당 해제
	free(team); // 동적할당 해제

	print_ending(); // 끝내는 함수


	return 0;

}

/* ----------------------- 공통함수 정의부 ----------------------- */

void gotoxy(int x, int y) // x,y좌표로 이동
{
	COORD Pos = { x - 1 , y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setcolor(unsigned short text, unsigned short back) // 선택된 색깔 출력
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void unsetcolor() // 색깔 초기화
{
	unsigned short back = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | (back << 4));
}

void CursorView(char show) // 커서 숨김
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
