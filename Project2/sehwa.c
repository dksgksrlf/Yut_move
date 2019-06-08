#include "noriyut.h"

int random() // 윷돌리기 함수
{
	int i;
	int yut;

	yut = percentage();

	switch (yut) {
	case 0:
		return -1;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
	}

}

int percentage()
{


	double h = rand() / (double)RAND_MAX; //{0.0 - 1.0}
	double dr = h * 100.0f; // {0.0 - 100.0}

	double p[] = { 3.0f, 25.0f, 25.0f, 25.0f, 11.0f, 7.0f }; //백도 도 개 걸 윷 모
															 // 0   1  2  3  4 5

	double cumulative = 0.0f;

	for (int i = 0; i<6; i++)
	{
		cumulative += p[i];
		if (dr <= cumulative)
		{
			return i;
		}
	}
}

void print_logo() // 시작 화면 
{

	system("cls");

	gotoxy(10, 18);
	Start_yut_monitor();
	/*printf("+---------------------------------------------------------------+");
	gotoxy(20, 14);
	printf("|                                                               |");
	gotoxy(20, 15);
	printf("|                        N O R I  Y U T                         |");
	gotoxy(20, 16);
	printf("|                                                               |");
	gotoxy(20, 17);
	printf("+---------------------------------------------------------------+");*/
	gotoxy(45, 18);
	printf(" 게임 방법");
	gotoxy(45, 19);
	printf(" 게임 시작");
	gotoxy(45, 20);
	printf(" 게임 종료");


}

void print_about()
{
	system("cls");

	gotoxy(20, 11);
	printf("+---------------------------------------------------------------+");
	gotoxy(20, 12);
	printf("|                                                                |");
	gotoxy(20, 13);
	printf("|                          복불복 윷놀이                         |");
	gotoxy(20, 14);
	printf("|          1. 게임 시작 전, 랜덤 벌칙을 2개 씩 정합니다.         |");
	gotoxy(20, 15);
	printf("|          2. 윷놀이 게임을 진행합니다.                          |");
	gotoxy(20, 16);
	printf("|          3. 진 팀이 랜덤으로 선택된 벌칙을 수행한다.           |");
	gotoxy(20, 17);
	printf("|          4. 스페이스바와 방향키 , esc를 눌러 게임을 동작한다.  |");
	gotoxy(20, 18);
	printf("|                                                                |");
	gotoxy(20, 19);
	printf("+---------------------------------------------------------------+");
	gotoxy(45, 20);
	printf("게임 시작");
	gotoxy(45, 21);
	printf("게임 종료");





}

void print_yut_name() // 윷 출력
{

	switch (YUT) {
	case -1:
		printf("<<백도>>");
		break;
	case 1:
		printf("<<도>>");
		break;
	case 2:
		printf("<<개>>");
		break;
	case 3:
		printf("<<걸>>");
		break;
	case 4:
		printf("<<윷>>");
		break;
	case 5:
		printf("<<모>>");
		break;
	}
}

void print_team_name() // 윷 출력
{
	printf("<<%d팀>>", TEAM + 1);
}

int input_penalty()
{
	int key;

	system("cls");
	gotoxy(13, 5);

	printf("-------------진 팀이 수행 할 벌칙을 적어주세요!------------");

	gotoxy(13, 8);
	printf("벌칙 1 : ");
	gets(penalty_1);
	gotoxy(13, 12);
	printf("벌칙 2 : ");
	gets(penalty_2);
	gotoxy(13, 16);
	printf("벌칙 3 : ");
	gets(penalty_3);
	gotoxy(13, 20);
	printf("벌칙 4 : ");
	gets(penalty_4);

	system("cls");
	return 0;


}

int select_logo()
{

	int key;
	int x, y;

	print_logo();

	x = 44;
	y = 18;

	gotoxy(x, y);

	CursorView(0);
	printf("▶");

	while (1)
	{

		if (kbhit()) // kbhit이 없으면 getch()하기 전까지 다른 것들은 실행되지 않는다
		{
			key = getch();


			while (key == 224) {
				key = getch();
				switch (key) {
				case 72: // 위로
					gotoxy(x - 1, y);
					printf("  ");
					if (y == 18)
						y += 3;
					gotoxy(x, y - 1);
					CursorView(0);
					printf("▶");
					y = y - 1;
					key = getch();
					break;

				case 80: // 아래로
					gotoxy(x - 1, y);
					printf("  ");
					if (y == 20)
						y -= 3;
					gotoxy(x, y + 1);
					CursorView(0);
					printf("▶");
					y = y + 1;
					key = getch();
					break;
				default:
					continue;
				}
			}


			while (key == 13)
			{
				if (y == 18) // 게임방법
					return 1;
				else if (y == 19) // 게임시작
					return 2;
				else if (y == 20) // 게임 종료
					gotoxy(50, 30);
				exit(0);
			}

		}
	}

	return 0;
}

int select_about()
{
	int key;
	int x, y;

	print_about();

	x = 43;
	y = 20;

	gotoxy(x, y);

	CursorView(0);
	printf("▶");

	while (1)
	{
		if (kbhit()) {

			key = getch();

			while (key == 224) {
				key = getch();
				switch (key) {
				case 72: // 위로
					if (y = 20)
						y += 1;
					system("cls");
					print_about();
					gotoxy(x, y - 1);
					CursorView(0);
					printf("▶");
					y = y - 1;
					key = getch();
					break;

				case 80: // 아래로
					if (y = 21)
						y -= 1;
					system("cls");
					print_about();
					gotoxy(x, y + 1);
					CursorView(0);
					printf("▶");
					y = y + 1;
					key = getch();
					break;
				default: // 그 외
					continue;
				}
			}

			while (key == 13)
			{
				if (y == 20) // 게임시작
					return 1;
				else if (y == 21) // 게임 종료
					gotoxy(50, 30);
				exit(0);

			}

		}
	}

	return 0;

}

void print_ending()
{

	int n;
	char penalty[50] = { NULL };
	system("cls");

	print_end();

	//print_gameover();

	n = rand() % 4 + 1;

	switch (n)
	{
	case 1:
		strcpy(penalty, penalty_1);
		break;
	case 2:
		strcpy(penalty, penalty_2);
		break;
	case 3:
		strcpy(penalty, penalty_3);
		break;
	case 4:
		strcpy(penalty, penalty_4);
		break;
	default:
		printf("오류입니다");
		break;

	}

	gotoxy(20, 11);
	printf("+---------------------------------------------------------------+");
	gotoxy(20, 12);
	printf("|                                                               |");
	gotoxy(20, 13);
	printf("|                                                               |");
	gotoxy(20, 14);
	printf("|                                                               |");
	gotoxy(20, 15);
	printf("|                                                               |");
	gotoxy(20, 16);
	printf("|                       우승팀은 %d팀 입니다                     |", TEAM + 1);
	gotoxy(20, 17);
	printf("|                                                               |");
	gotoxy(20, 18);
	printf("|   수행벌칙은...                                               |");
	gotoxy(20, 19);
	printf("|                                                               |");
	gotoxy(20, 20);
	printf("|                                                               |");
	gotoxy(20, 21);
	printf("|                                                               |");
	gotoxy(20, 22);
	printf("|                                                               |");
	gotoxy(20, 23);
	printf("|                                                               |");
	gotoxy(20, 24);
	printf("+---------------------------------------------------------------+");

	gotoxy(24, 20);
	printf("%s", penalty);

	gotoxy(50, 30);

}

void print_gameover()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		system("cls");
		setcolor(11, 0);
		gotoxy(20, 15);
		printf("\n\t▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷ GAMEOVER ▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷");
		Sleep(300);
		unsetcolor();
		system("cls");
		setcolor(14, 0);
		gotoxy(20, 15);
		printf("\n\t▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷ GAMEOVER ▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷");
		unsetcolor();
		Sleep(300);
		system("cls");
		setcolor(13, 0);
		gotoxy(20, 15);
		printf("\n\t▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶ GAMEOVER ▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶▷▷▶");
		Sleep(300);
		unsetcolor();
		system("cls");
	}

}


void move_mal() {

	int yut[10] = { 0 }; // 전체 윷을 저장하는 배열
	int i = 0, j = 0, y = 0;
	int n = 0;
	char key = NULL;

	endgame = 0;


	/* ------------------- 말의 움직임 시작 ------------------ */
	do {

		i = 0;
		TEAM = (TEAM + 1) % 2;

		do {


			do {
				YUT = random();
			} while (YUT == 6);

			yut[i] = YUT;
			sound_yut();

			if (yut[i] == 4 || yut[i] == 5)
			{
				switch (yut[i]) {
				case 4:
					gotoxy(6, 41);
					setcolor(11, 0);
					printf("윷이 나왔습니다. 윷을 한번 더 돌립니다.                      ");
					unsetcolor();
					break;
				case 5:
					gotoxy(6, 41);
					setcolor(11, 0);
					printf("모가 나왔습니다. 윷을 한번 더 돌립니다.                      ");
					unsetcolor();
					break;
				}

				while (getch() != 32);

			}

			all();
			i++;
		} while (yut[i - 1] == 4 || yut[i - 1] == 5); // 윷이나 모일 때

		move(TEAM, yut, team);


		if (endgame == 1)
			break;

		for (i = 0; i < 10; i++)
			yut[i] = 0;
		YUT = 0;

		if (kbhit()) {
			key = _getch();
		}
		printf("\b\b\b\b\b\b\b\b\b");



	} while (key != 27);
}


void print_end()
{
	HBITMAP image;
	image = (HBITMAP)LoadImage(NULL, TEXT("gameover.bmp"), IMAGE_BITMAP, 1700, 900, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_monitor(image);
	Sleep(1000);
	system("cls");
}

void sound_yut()
{
	sndPlaySoundA(".\\yut.wav", SND_ASYNC | SND_NODEFAULT); // 음악연주 C:\\~~~ 는 경로명을 입력합니다. (단, 폴더를 구분하는 역슬래쉬는 2번 써 줘야 합니다. 예) C:\test\aa.wav  일 경우 "C:\\test\\aa.wav"

}

void sound_mal()
{
	sndPlaySoundA(".\\button.wav", SND_ASYNC | SND_NODEFAULT); // 음악연주 C:\\~~~ 는 경로명을 입력합니다. (단, 폴더를 구분하는 역슬래쉬는 2번 써 줘야 합니다. 예) C:\test\aa.wav  일 경우 "C:\\test\\aa.wav"

}

void startyutpan()
{
	all();

	gotoxy(6, 41);
	setcolor(11, 0);
	printf("게임을 시작하려면 space바를 누르세요.");
	unsetcolor();

	//system("PAUSE");
	while (getch() != 32);
}

void Start_yut_monitor() {
	HBITMAP image;

	image = (HBITMAP)LoadImage(NULL, TEXT("Start_logo.bmp"), IMAGE_BITMAP, 1000, 320, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_Press(image);
	Sleep(100);
}


void print_Press(HBITMAP hImage)
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	HBITMAP hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 100, 80, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}