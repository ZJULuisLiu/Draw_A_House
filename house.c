
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "graphics.h"
#include "genlib.h"
#include "conio.h"




#define HouseWidth 3.0
#define HouseHeight 3.0
#define AtticHeight 2.6
#define WindowWidth 0.6
#define WindowHeight 0.5
#define DoorHeight 2.4
#define DoorWidth 0.6
#define PipeHeight1 1
#define PipeHeight2 0.45
#define ChimneyWidth 0.6
#define ChimneyHeight 0.2



void DrawHouse(double x, double y);
void DrawOutline(double x, double y);
void DrawWindows(double x, double y);
void DrawDoor(double x, double y);
void DrawBox(double x, double y, double width, double height);
void DrawTriangle(double x, double y, double base, double height);
void DrwaChimney(double x, double y);


void Main()
{
    double cx, cy;

    InitGraphics();
    cx = GetWindowWidth() / 2;
    cy = GetWindowHeight() / 2;
    DrawHouse(cx - HouseWidth / 2,
              cy - (HouseHeight + AtticHeight) / 2);
}


void DrawHouse(double x, double y)
{
    DrawOutline(x, y);
    DrawDoor(x + HouseWidth/ 2, y);
    DrawWindows(x, y);
    DrawChimney(x+0.3, y+HouseHeight+0.5);
}



void DrawOutline(double x, double y)
{
    DrawBox(x, y, HouseWidth, HouseHeight);
    DrawTriangle(x, y + HouseHeight, HouseWidth, AtticHeight);
}


void DrawDoor(double x, double y)
{
    DrawBox(x, y, DoorWidth, DoorHeight);
}

void DrawWindows(double x, double y)
{
    double cx, cy;
    cx = x + 0.3;
    cy = y + 1.9;
    DrawBox(cx, cy, WindowWidth, WindowHeight);
}


void DrawBox(double x, double y, double width, double height)
{
    MovePen(x, y);
    DrawLine(0, height);
    DrawLine(width, 0);
    DrawLine(0, -height);
    DrawLine(-width, 0);
}


void DrawTriangle(double x, double y, double base, double height)
{
    MovePen(x, y);
    DrawLine(base, 0);
    DrawLine(-base / 2, height);
    DrawLine(-base / 2, -height);
}


void DrawChimney(double x, double y)
{
	MovePen(x, y);
	DrawLine(0, PipeHeight1);
	MovePen(x+0.3, y+0.55);
	DrawLine(0, PipeHeight2);
	DrawBox(x-0.1, y+PipeHeight1, ChimneyWidth, ChimneyHeight);
}


