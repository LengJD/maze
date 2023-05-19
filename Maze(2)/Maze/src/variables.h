#ifndef _variable_h
#define _variable_h

#include "linkedlist.h"
#include "boolean.h"
#include "strlib.h"
//by inches
#define Win_Width  7.5	//窗口
#define Win_Height 8	//窗口
#define Game_Width 10	//格子数 X轴
#define Game_Height 10	//格子数 Y轴

//二维数组 记录坐标 表示状态  
//左下角(0,0) (x,y)
enum State_P
{
	Path,
	Wall,
	Gamer,
	End
};
//坐标 及 此坐标下状态
typedef struct
{
    double x;	//x,y为英寸坐标
    double y;
	int px;		//px，py为格子坐标(均为整数)  Game_Width * Game_Height 
	int py;
	enum State_P state;
}Point;  
//记录整体状态
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
//记录玩家  最多十个
struct GAMER
{
	char name[10];
	int rank;		//from 1 to ...
	double time;	//by seconds
}gamer[10];



#endif
