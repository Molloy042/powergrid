/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#pragma once
#include "Windows.h"
#include <string>

using std::string;
typedef unsigned int unint;
const unint MAX_CON_ROWS = 25; //MAX CONSOLE ROWS
const unint MAX_CON_COLS = 80; //MAX CONSOLE COLUMNS

class PGWindow
{
private:
	unint posX, posY, rows, cols;
	string title;
public:
	PGWindow();
	PGWindow(unint posX, unint posY, unint rows, unint cols, string title);
	~PGWindow();

	//GETTERS
	inline unint getPosY() const { return posY; }
	inline unint getPosX() const { return posX; }
	inline unint getRows() const { return rows; }
	inline unint getCols() const { return cols; }
	inline string getTitle() const { return title; }

	//SETTERS
	inline void setPosX(unint posX) { this->posX = posX; }
	inline void setPosY(unint posY) { this->posY = posY; }
	inline void setRows(unint rows) { this->rows = rows; }
	inline void setCols(unint cols) { this->cols = cols; }
	inline void setTitle(string title) { this->title = title; }
	
	void drawWindow();
	void drawSimpleWindow();
	static void drawBackGrid(); //this also redraws Console
	static void drawConsole();

	void centerWindow();
	static void clearScreen();
	static void gotoXY(unint x, unint y);
	static void textColor(unint color);
	//DRAW METHODS
private:
	//INTERNAL METHODS
	void resizeTitle();
	
};