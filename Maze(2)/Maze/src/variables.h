#ifndef _variable_h
#define _variable_h

#include "linkedlist.h"
#include "boolean.h"
#include "strlib.h"
//by inches
#define Win_Width  7.5	//����
#define Win_Height 8	//����
#define Game_Width 10	//������ X��
#define Game_Height 10	//������ Y��

//��ά���� ��¼���� ��ʾ״̬  
//���½�(0,0) (x,y)
enum State_P
{
	Path,
	Wall,
	Gamer,
	End
};
//���� �� ��������״̬
typedef struct
{
    double x;	//x,yΪӢ������
    double y;
	int px;		//px��pyΪ��������(��Ϊ����)  Game_Width * Game_Height 
	int py;
	enum State_P state;
}Point;  
//��¼����״̬
enum Maze_State
{
	InitialPage,
	HelpPage,
	GamePageChoice,
	EditPage
};
typedef struct
{
	enum Maze_State State;
	Point point[Game_Width][Game_Height];
}Maze;
//��¼���  ���ʮ��
struct GAMER
{
	char name[10];
	int rank;		//from 1 to ...
	double time;	//by seconds
}gamer[10];



#endif
