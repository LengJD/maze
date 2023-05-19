#include <stdio.h>
#include <string.h>

#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h" 
#include "windows.h"
#include "file.h"
#include "variables.h"
Maze maze;
void KeyboardEventProcess(int key, int event);
void MouseEventProcess(int x, int y, int button, int event);
void CharEventProcess(char ch);
void mytimer(int timerID);
void Main(); 

void Main()
{
	//实现窗口的初始化
	SetWindowTitle("MazeEditor Of EOF");
	SetWindowSize(Win_Width,Win_Height);
	InitGraphics();

	
	display(&maze);
	registerKeyboardEvent(KeyboardEventProcess); 
	registerMouseEvent(MouseEventProcess);   
	registerTimerEvent(mytimer);
	registerCharEvent(CharEventProcess);
}

void CharEventProcess(char ch)
{
	//在游戏页面实现移动
	if (maze.State==GamePageChoice)
	{
		
	}
}
void KeyboardEventProcess(int key, int event)
{
	//在游戏页面实现移动
	if (maze.State==GamePageChoice)
	{
		
	}
}
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event);
	static double omx = 0.0, omy = 0.0;
	double dx = 0.0,dy= 0.0;	
	switch (event)
	{
		case BUTTON_UP:
			
			break;
		
		case MOUSEMOVE:
			
			break;
	
		default:
			break;
	}
	display(&maze);
}

void mytimer(int timerID)
{


}
