#include <stdio.h>
#include <string.h>

#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h" 
#include "windows.h"

#include "variables.h"
#define MAX_LENGTH 10 
#define MAX_WIDTH 10

FILE *fp;
int map[MAX_LENGTH][MAX_WIDTH]; /* 0代表墙体，1代表路径，2代表人物，3代表起点，4代表终点*/
int row=0,col=0;//row 代表行，col代表列 

void choose_map(int k)
{
	switch (k)
	{
		case 1:
			if((fp=fopen("map1.txt","rt"))==NULL)
			{
				DrawTextString("Cannnot open the map!");
				exit(0);
			}
			break;
		case 2:
			if((fp=fopen("map2.txt","rt"))==NULL)
			{
				DrawTextString("Cannnot open the map!");
				exit(0);
			}
			break;
		case 3:
			if((fp=fopen("map3.txt","rt"))==NULL)
			{
				DrawTextString("Cannnot open the map!");
				exit(0);
			}
		    break;
		default:
			exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d",&map[row][col]);
		col++;
		if(col%10==0)
		{
			row++;col=0;
		}
	}
	if(fclose(fp))
	{
		DrawTextString("Cannot close the file!\n");
	}
}

void draw_map()
{
	DisplayClear(); 
	int i,j,m;
	SetPenColor("Black");
	for(i=0;i<=5;i+=0.5)
	{
		MovePen(i,0);
		DrawLine(0,5);
	}
	for(i=0;i<=5;i+=0.5)
	{
		for(j=0;j<=5;j+=0.5)
		{
			m = map[i][j];
			switch (m)                   /* 0代表墙体，1代表路径，2代表人物，3代表起点，4代表终点*/
			{
				case 0:
					drawBox(i,j,0.5,0.5,1,"",'r',"Black"); 
					break;
				case 1:
					drawBox(i,j,0.5,0.5,1,"",'r',"Green");
					break;
				case 2:
					/*画个人*/ 
					break;
				case 3:
					/*画个起点*/ 
					break;
				case 4:
				    /*画个终点*/ 
				    break; 
			}
		}
	}
}

void random_create_map(int **map,int x,int y)
{
	int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	int i,j;
	for(i=0;i<4;i++)
	{
		int temp=direction[0][0];
		int r=rand()%4;
		direction[0][0]=direction[r][0];
		direction[r][0]=temp;
		temp=direction[0][1];
		direction[0][1]=direction[r][1];
		direction[r][1]=temp;
	}
	for(i=0;i<4;i++)
	{
		
	}
}

void edit_map()
{
	
}


