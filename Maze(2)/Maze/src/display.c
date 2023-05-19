#include <stdio.h>
#include <string.h>

#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h" 
#include "windows.h"

#include "variables.h"

/*Page*/ 
void displayInitialPage(Maze *maze);//初始界面 
void displayEditPage(Maze *maze);//编辑界面 
void displayHelpPage(Maze *maze);//帮助界面 
void drawMenu(Maze *maze); //菜单栏 

void drawbackground(char colorname[])
{
	SetPenColor(colorname);
	drawRectangle(0,0,Win_Width,Win_Height,1); 
	SetPenColor("White");
	drawRectangle(0.1,0.1,Win_Width-0.3,Win_Height-0.2,0);
	drawRectangle(0.2,0.2,Win_Width-0.5,Win_Height-0.4,0);
}
void ColorExtend()
{
	DefineColor("LightGreen",0,0.191,0.255);  //墨绿色 
	DefineColor("Grey",0.135,0.206,0.250);	//灰色 
	DefineColor("LBlue",0.6,0.8,1);	//浅蓝 
	
}

void displayInitialPage(Maze *maze)
{
	double fH = GetFontHeight();
	double h = fH*1.5;
	double w = Win_Width/2.5;
    double x = Win_Width/2.5; 
	double y = Win_Height/2-h;
	drawbackground("LBlue");
	
	SetPointSize(50); 
	SetPenColor("LBlue");
	SetFont("DeFault");
	drawBox(x/1.3,y+8*h,w,h,1,"Maze Editor",1,"LightGreen");
	SetPenColor("LBlue");
	SetPointSize(20);
	SetFont("宋体");
	setButtonColors("Grey","Grey","White","White",0);
	if (button(GenUIID(0),x/1.3, y-h, w, h*1.2, "开始游戏"))
	{
		maze->State=GamePageChoice; 
	}
	if (button(GenUIID(0),x/1.3, y-3*h, w, h*1.2, "帮助/关于"))
	{
		maze->State=HelpPage;
	}
	if (button(GenUIID(0),x/1.3, y-5*h, w, h*1.2, "点击退出游戏"))
	{
		exit(-1);
	}
	 
}
void DrawMeau()
{
	SetPointSize(13);
  	double dx = Win_Width/20;
	double dy = Win_Height/20;
	double fH = GetFontHeight();
	double h = fH*1.5; 
	static int file_selection;
	
	char * menuListFile[] =
	{	"文件",  
		"新建  | Ctrl-N",
		"打开  | Ctrl-O",  
		"保存  | Ctrl-S",           
		"退出  | Ctrl-E"
	};
	
	setMenuColors("Grey","Grey","White","White",0);
	file_selection = menuList(GenUIID(0),0.5,Win_Height-0.6,Win_Width/6,Win_Width/6, h, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
	switch(file_selection)
	{
		case 1:
			//NewMap(Maze *maze);
			break;
		case 2:
			//OpenMap(Maze *maze);
			break;
		case 3:
			//SavaMap(Maze *maze);
			break;
		case 4:
			//
			exit(0);
	}
}
void displayHelpPage(Maze *maze)
{
	
}
void displayEditPage(Maze *maze)
{
	
}
void display(Maze *maze)
{
    DisplayClear();
    ColorExtend();

	switch (maze->State)
    {
    case InitialPage:
        displayInitialPage(maze);
        break;
    case HelpPage:
    
        break;
    case GamePageChoice:
    	drawbackground("LBlue");
		DrawMeau();
        break;
    
    case EditPage:
		DrawMeau();
        break;

    }
	
}
