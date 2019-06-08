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

/* --------------------- ����ü ����� --------------------- */

/*�� �� ���� �������� ���� ���ö�*/
typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;


typedef struct {
	int x, y;//��ǥ
	int Teamcolor;//�� ����
	int Howmany;//���� �� ����
	int where;//���������� ��ġ�� ǥ��
	int cango[10];//�����ִ� ���� ��ġ ǥ��

}mal;
/*Howmany���� �������� �ö����� ������ -1�� �ö�������� 0�� �־��ش�.*/

typedef struct {
	int x, y;
}pan;


/* --------------------- �������� ����� --------------------- */

#define X_MAX 55
#define Y_MAX 29

int YUT; // �� ����
int TEAM; // �� ����

char penalty_1[50]; // ��Ģ 1
char penalty_2[50]; // ��Ģ 2
char penalty_3[50]; // ��Ģ 3
char penalty_4[50]; // ��Ģ 4

pan basic[42];
mal** team;

extern int r; // ������ ���� �����ϴ� ����� �����ϴ� ��������

int endgame;




/* --------------------- �� ������, ����, �� ȭ�� ����� --------------------- */

void print_logo(); // ���� ȭ�� ���
void print_about(); // ���� ��� ���
void print_ending(); // ������ ȭ�� ���
int random(); // �� ������
void print_yut_name(); // ���ǿ��� ���̸� ���
void print_team_name(); // ���ǿ��� ���̸� ���
int input_penalty(); // ��Ģ �Է� 
int select_logo(); // ����ȭ�鿡�� ����
int select_about(); // ���ӹ������ ����
void print_gameover(); // ���� ���� ��� 
void Start_monitor();
void sound_yut();
void sound_mal();
void startyutpan();
void Start_yut_monitor();
void print_Press(HBITMAP hImage);

/* --------------------- �� �� ����� --------------------- */

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

/* --------------------- �� ��� ����� --------------------- */

char cmp_cat_carry(mal **t, int x, int y, int index, int teamnum); //���Լ� ���� ��쿣 1�� ���°�쿣 2�� �ƹ��͵� �ƴϸ�0�� ������
void carry(mal *t, int index); //���� ���� �Լ�
void cat(mal **t, int index, int teamnum); //���� ��� �Լ�
void print_score(mal**t); // ������ ���

						  /* ������ */
void color_menu(mal ** c);
void color_select(mal **t);
void team_mal(mal** t); //���ǿ��� ����ϸ� ���������� ������ش�.
void print_all_mal(mal**t); // ���� ���� ����ϴ� �Լ�
int visiable(mal *t, int index); //��°������� �Ǵ�
void print_mal(mal t);


/* --------------------- �� �̵� ����� --------------------- */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteMiddle(listNode* h, int key);

void setpan(pan* p);//������ �� ����
int canmove(int *go, listNode* h, int* yut);//���� ����ŭ ������ go��° �迭�� ��ǥ�� �����ְ���
void move_cursor(char key, int* can, const int max);//�����ִ� ��ġ�߿��� �����ֵ��� Ŀ���� ������
void move(const int t, int *yut, mal** team);
int Select(mal* team);//�� ����
mal** initalize_mal();
void move_mal(); // ��ü �� ����

#endif
