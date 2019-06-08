#pragma once
#pragma once

#ifndef NORIYUT_H

#define NORIYUT_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

/* --------------------- 구조체 선언부 --------------------- */

/*윷 모 같은 연속적인 수가 나올때*/
typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;


typedef struct {
	int x, y;//좌표
	int Teamcolor;//팀 색상
	int Howmany;//업은 말 개수
	int where;//판위에서의 위치를 표시
	int cango[10];//갈수있는 곳의 위치 표시

}mal;
/*Howmany에는 말판위에 올라가있지 않으면 -1을 올라와있으면 0을 넣어준다.*/

typedef struct {
	int x, y;
}pan;


/* --------------------- 전역변수 선언부 --------------------- */

#define X_MAX 55
#define Y_MAX 29

int YUT; // 윷 선언
int TEAM; // 팀 선언

char penalty_1[50]; // 벌칙 1
char penalty_2[50]; // 벌칙 2
char penalty_3[50]; // 벌칙 3
char penalty_4[50]; // 벌칙 4

pan basic[42];
mal** team;

extern int r; // 잡을지 말지 결정하는 결과를 저장하는 전역변수

int endgame;




/* --------------------- 윷 돌리기, 시작, 끝 화면 선언부 --------------------- */

void print_logo(); // 시작 화면 출력
void print_about(); // 게임 방법 출력
void print_ending(); // 마지막 화면 출력
int random(); // 윷 돌리기
void print_yut_name(); // 윷판에서 윷이름 출력
void print_team_name(); // 윷판에서 팀이름 출력
int input_penalty(); // 벌칙 입력 
int select_logo(); // 시작화면에서 선택
int select_about(); // 게임방법에서 선택
void print_gameover(); // 게임 오버 출력 
void Start_monitor();
void sound_yut();
void sound_mal();
void startyutpan();
void Start_yut_monitor();
void print_Press(HBITMAP hImage);

/* --------------------- 윷 판 선언부 --------------------- */

void all();
void draw_basic_square(int x, int y);
void draw_score(int x, int y);
void draw_yutpan(int x, int y);
void board(int x, int y);
void mal_pan(int x, int y);
void draw_large_square(int x, int y);
void YutNori();
void yut(int x, int y);
void whatyut(int x, int y);
void explain(int yut);
void Print_Game();
void loading();
void print_monitor(HBITMAP hImage);
void print_end();

/* --------------------- 말 잡기 선언부 --------------------- */

char cmp_cat_carry(mal **t, int x, int y, int index, int teamnum); //비교함수 잡을 경우엔 1을 업는경우엔 2를 아무것도 아니면0을 리턴함
void carry(mal *t, int index); //말을 업는 함수
void cat(mal **t, int index, int teamnum); //말을 잡는 함수
void print_score(mal**t); // 점수를 출력

						  /* 색결정 */
void color_menu(mal ** c);
void color_select(mal **t);
void team_mal(mal** t); //윷판에서 사용하며 남은말들을 출력해준다.
void print_all_mal(mal**t); // 말을 전부 출력하는 함수
int visiable(mal *t, int index); //출력가능한지 판단
void print_mal(mal t);


/* --------------------- 말 이동 선언부 --------------------- */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteMiddle(listNode* h, int key);

void setpan(pan* p);//말판의 길 구성
int canmove(int *go, listNode* h, int* yut);//윷의 값만큼 말판의 go번째 배열의 좌표로 갈수있게함
void move_cursor(char key, int* can, const int max);//갈수있는 위치중에서 고를수있도록 커서를 움직임
void move(const int t, int *yut, mal** team);
int Select(mal* team);//말 선택
mal** initalize_mal();
void move_mal(); // 전체 말 구동

#endif
