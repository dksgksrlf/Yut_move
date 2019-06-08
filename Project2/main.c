#include "noriyut.h"

/* --------------------- �����Լ� ���Ǻ� --------------------- */

void gotoxy(int x, int y); // x,y��ǥ�� �̵�
void setcolor(unsigned short text, unsigned short back); // ���õ� ���� ���
void unsetcolor(); // ���� �ʱ�ȭ
void CursorView(char show); // Ŀ�� ����


int main(void)	//����ϴ� â�� ���� �߿� ( x ,y ��ǥ�� ��鸳�ϴ�.)
{
	int menu;
	int i;

	YUT = 0;

	Start_monitor();

	setpan(basic); //�� ��ǥ ����
	system("title ������ ����");

	srand(time(NULL)); // ����

	team = initalize_mal(); //��ü ������ �ʱ�ȭ
	menu = select_logo();



	if (menu == 1)// ù ȭ�� ����
	{
		if (select_about() == 1)
		{
			input_penalty();
			color_menu(team);
			gotoxy(5, 18);
			Print_Game();
			all(); // ���� ���
		}
	}
	else if (menu == 2)
	{
		input_penalty();
		color_menu(team);
		gotoxy(5, 18);
		Print_Game();
		all(); // ���� ���
	}

	startyutpan();

	move_mal();



	/* ------------- �����Ҵ� ���� ---------------- */
	for (i = 0; i < 2; i++)
		free(team[i]); // �����Ҵ� ����
	free(team); // �����Ҵ� ����

	print_ending(); // ������ �Լ�


	return 0;

}

/* ----------------------- �����Լ� ���Ǻ� ----------------------- */

void gotoxy(int x, int y) // x,y��ǥ�� �̵�
{
	COORD Pos = { x - 1 , y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setcolor(unsigned short text, unsigned short back) // ���õ� ���� ���
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void unsetcolor() // ���� �ʱ�ȭ
{
	unsigned short back = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | (back << 4));
}

void CursorView(char show) // Ŀ�� ����
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
