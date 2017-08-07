/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "PGWindow.h"
#include <iostream>


using std::cout;


PGWindow::PGWindow():
	posX(0), posY(0), rows(5), cols (5), title("Untitled")
{
	resizeTitle();
}

PGWindow::PGWindow(unint posX, unint posY, unint rows, unint cols, string title):
	posX(posX), posY(posY), rows(rows), cols(cols), title(title)
{
	resizeTitle();
}


PGWindow::~PGWindow()
{}

void PGWindow::drawWindow()
{
	// TOP			+---... (cols - 2) times ...---+
	gotoXY(posX, posY); 
	
	cout << "+";
	for (unint i = 0; i < cols - 1;++i) {
		cout << "-";
	}
	cout << "+";

	// TITLE LINE	|       centered Title        |
	gotoXY(posX, posY + 1);								cout << "|";
	for (unint i = 0; i < cols - 1;++i) {
		cout << " ";
	}
	gotoXY(posX + cols, posY + 1);						cout << "|";
	gotoXY((posX + (cols / 2) - (title.size() / 2) ), posY + 1); cout << title;

	// SEPARATOR	+---... (cols - 2) times ...---+
	gotoXY(posX, posY + 2);
	cout << "+";
	for (unint i = 0; i < cols - 1;++i) {
		cout << "-";
	}
	cout << "+";

	// BODY
	for (unint row = posY+3;row < posY + rows;++row) {
		gotoXY(posX, row);
		cout << "|";
		for (unint i = 0; i < cols - 1;++i) {
			cout << " ";
		}
		gotoXY(posX + cols, row);
		cout << "|";
	}

	// BOTTOM		+---... (cols - 2) times ...---+
	gotoXY(posX, posY + rows);
	cout << "+";
	for (unint i = 0; i < cols - 1;++i) {
		cout << "-";
	}
	cout << "+";
}

void PGWindow::drawSimpleWindow()
{
	drawWindow();
	for (unint row = 1; row <= 2;++row) {
		gotoXY(posX, posY + row);
		cout << "|";
		for (unint i = 0;i < cols-1;++i) {
			cout << " ";
		}
		cout << "|";
	}
}

void PGWindow::drawBackGrid()
{
	//TOP +===... ===+
	gotoXY(0, 0);
	cout << "+";
	for (unint i = 0; i < MAX_CON_COLS - 2;++i) {
		cout << "=";
	}
	cout << "+";
	
	//BODY | ... |
	for (unint row = 1; row <= MAX_CON_ROWS - 5;++row) {
		gotoXY(0, row);
		cout << "|";
		gotoXY(MAX_CON_COLS - 1, row);
		cout << "|";
	}

	drawConsole();
}

void PGWindow::drawConsole()
{
	//PG_CONSOLE TOP
	gotoXY(0, MAX_CON_ROWS - 4);
	cout << "+";
	for (unint i = 0; i < MAX_CON_COLS - 2;++i) {
		cout << "=";
	}
	cout << "+";

	//PG_CONSOLE_COMMAND_LINE
	gotoXY(0, MAX_CON_ROWS - 3);
	cout << "|";
	for (unint i = 0; i < MAX_CON_COLS - 2;++i) {
		cout << " ";
	}
	gotoXY(MAX_CON_COLS - 1, MAX_CON_ROWS - 3);
	cout << "|";

	//PG_CONSOLE_BOTTOM
	gotoXY(0, MAX_CON_ROWS - 2);
	cout << "+";
	for (unint i = 0; i < MAX_CON_COLS - 2;++i) {
		cout << "=";
	}
	cout << "+";
	 
	gotoXY(2, MAX_CON_ROWS - 3);
	cout << "Command => ";
}

void PGWindow::resizeTitle()
{
	unint maxTitleSize = cols - 4;
	if (title.size() > maxTitleSize) {
		title.resize(maxTitleSize);
	}
}

void PGWindow::centerWindow()
{
	posX = MAX_CON_COLS / 2 - cols / 2;
	posY = (MAX_CON_ROWS - 5) / 2 - rows / 2;
}


/**
* Credit goes to : http://www.cplusplus.com/forum/articles/10515/
*/
void PGWindow::clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void PGWindow::gotoXY(unint x, unint y)
{
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleScreenBufferInfo);
	consoleScreenBufferInfo.dwCursorPosition.X = x;
	consoleScreenBufferInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), consoleScreenBufferInfo.dwCursorPosition);
}
//TODO: switch from unint color to ColorType and 
void PGWindow::textColor(unint color)
{
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleScreenBufferInfo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}