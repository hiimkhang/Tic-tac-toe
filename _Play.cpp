#include "_Play.h"
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <sstream>
using namespace std;

static int size = 7, pvp1 = 0, pvp2 = 0, gameplayed = 0, pvc = 0;

struct Name{
	char data[30];
};
vector <Name> ch;

void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
void AnTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void draw_rect( int width, int height, int x, int y) {   
	int i;  
	_Common::gotoXY(x, y);
	cout << char(218); 
	for (i = 1; i < width - 1; i++) 
		cout << char(196);
	cout << char(191) << endl;

	_Common::gotoXY(x, ++y);
	for (i = 1; i < height - 1; i++) {
		cout << char(179);	
		for (int j = 1; j < width - 1; j++) 
			cout << " ";
		cout << char(179) << endl;
		_Common::gotoXY(x, ++y);
	}

	cout << char(192);
	for(i = 1; i < width - 1; i++)
		cout << char(196);
	cout << char(217) << endl;
}
void board3x3() {
	Textcolor(Cyan);
	_Common::gotoXY(50, 18); cout << "SETTING";
	Textcolor(7);
	_Common::gotoXY(50, 20); cout << "Player icons";
	Textcolor(Red);
	_Common::gotoXY(47, 21); cout << "-> Gameboard size";
	Textcolor(Red);
	_Common::gotoXY(66, 21); cout << "3x3";
	Textcolor(7);
	_Common::gotoXY(70, 21); cout << "5x5";
	_Common::gotoXY(74, 21); cout << "7x7";
	_Common::gotoXY(50, 22); cout << "Sound effect";
	_Common::gotoXY(50, 23); cout << "Background music";
	Textcolor(White);
	_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(40, 32); cout << "Enter   : Select ";
	_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
}
void board5x5() {

	Textcolor(Cyan);
	_Common::gotoXY(50, 18); cout << "SETTING";
	Textcolor(7);
	_Common::gotoXY(50, 20); cout << "Player icons";
	Textcolor(Red);
	_Common::gotoXY(47, 21); cout << "-> Gameboard size";
	Textcolor(7);
	_Common::gotoXY(66, 21); cout << "3x3";
	Textcolor(Red);
	_Common::gotoXY(70, 21); cout << "5x5";
	Textcolor(7);
	_Common::gotoXY(74, 21); cout << "7x7";
	_Common::gotoXY(50, 22); cout << "Sound effect";
	_Common::gotoXY(50, 23); cout << "Background music";
	Textcolor(White);
	_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(40, 32); cout << "Enter   : Select ";
	_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
}

void board7x7() {
	Textcolor(Cyan);
	_Common::gotoXY(50, 18); cout << "SETTING";
	Textcolor(7);
	_Common::gotoXY(50, 20); cout << "Player icons";
	Textcolor(Red);
	_Common::gotoXY(47, 21); cout << "-> Gameboard size";
	Textcolor(7);
	_Common::gotoXY(66, 21); cout << "3x3";
	_Common::gotoXY(70, 21); cout << "5x5";
	Textcolor(Red);
	_Common::gotoXY(74, 21); cout << "7x7";
	Textcolor(7);
	_Common::gotoXY(50, 22); cout << "Sound effect";
	_Common::gotoXY(50, 23); cout << "Background music";
	Textcolor(White);
	_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(40, 32); cout << "Enter   : Select ";
	_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
}

void onSound() {
	Textcolor(Cyan);
	_Common::gotoXY(50, 18); cout << "SETTING";
	Textcolor(7);
	_Common::gotoXY(50, 20); cout << "Player icons";
	_Common::gotoXY(50, 21); cout << "Gameboard size";
	Textcolor(12);
	_Common::gotoXY(47, 22); cout << "-> Sound effect";
	_Common::gotoXY(64, 22); cout << "On";
	Textcolor(7);
	_Common::gotoXY(68, 22); cout << "Off";
	_Common::gotoXY(50, 23); cout << "Background music";
	Textcolor(White);
	_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(40, 32); cout << "Enter   : Select ";
	_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
}
int ReadChedo(char a[30])
{
	int d1, d2, chedo;
	system("cls");
	ifstream f;
	f.open(a, ios::in);
	if (!f){
		_Common::gotoXY(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
		Sleep(1000);
		ScreenStartGame(99);
	}
	else
		f >> d1>> d2 >> chedo;
	f.close();
	return chedo;
}
void ReadNameFile()
{
	Textcolor(Cyan);
	_Common::gotoXY(60, 18);
	cout << "LIST FILE NAME";
	int i = 19;
	ifstream f;
	f.open("Name.txt", ios::in);
	while (!f.eof())
	{
		char s[30];
		f >> s;
		_Common::gotoXY(50, i);
		cout << s;
		i++;
	}
	f.close();
}

void CreateFile()
{
	fstream fileStream;
	fileStream.open("Data.txt");
	if (fileStream.fail()) {
		
	}

}

void ReadFile()
{
	ifstream ifs;
	ifs.open("Data.txt");
	string s = "";
	getline(ifs, s);
	if (s != "")
	{
		istringstream(s) >> gameplayed;
		getline(ifs, s);
		istringstream(s) >> pvp1;
		getline(ifs, s);
		istringstream(s) >> pvp2;
		getline(ifs, s);
		istringstream(s) >> pvc;

	}

	ifs.close();
}

void Update()
{
	ofstream ofs;
	ofs.open("Data.txt", std::ofstream::out | std::ofstream::trunc);


	ofs << gameplayed << endl << pvp1 << endl << pvp2 << endl << pvc;
	ofs.close();
}

void playericon() {

}

void PrintCaro() {
	int x = 31, y = 5;
    draw_rect(90, 14, x - 9, y - 3);
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 5, y);		cout << "  	   ______        ___     _____        _______"	;
	_Common::gotoXY(x + 5, y + 1);	cout <<	"	 / _____ |      /  |    |  __  |    /   __   | "	;
	_Common::gotoXY(x + 5, y + 2);	cout <<	"	| |            /   |    | |  )  |   |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 3);	cout <<	"	| |           /    |    | |__)  |   |  |  |  | "	;
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 5, y + 4);	cout <<	"	| |          /  /|  |   |   _  |    |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 5);	cout <<	"	| |______   /  ___  |   |  | |  |   |  |__|  |	"	;
	_Common::gotoXY(x + 5, y + 6);	cout <<	"	|________| /__|   |_|   |__|  |__|  |_______ / 	"	;
}
void PrintCaro2()
{
	int x = 31, y = 5;
	Sleep(50);
	draw_rect(90, 14, x - 9, y - 3);
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 5, y);		cout << "  	   ______        ___     _____        _______"	;
	_Common::gotoXY(x + 5, y + 1);	cout <<	"	 / _____ |      /  |    |  __  |    /   __   | "	;
	_Common::gotoXY(x + 5, y + 2);	cout <<	"	| |            /   |    | |  )  |   |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 3);	cout <<	"	| |           /    |    | |__)  |   |  |  |  | "	;
	Textcolor(rand() % 15 + 1);
	_Common::gotoXY(x + 5, y + 4);	cout <<	"	| |          /  /|  |   |   _  |    |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 5);	cout <<	"	| |______   /  ___  |   |  | |  |   |  |__|  |	"	;
	_Common::gotoXY(x + 5, y + 6);	cout <<	"	|________| /__|   |_|   |__|  |__|  |_______ / 	"	;
	Textcolor(defaultColor);


}
void PrintCaro3()
{
	int x = 31, y = 5;
	draw_rect(90, 14, x - 9, y - 3);
	Textcolor(Red);
	_Common::gotoXY(x + 5, y);		cout << "  	   ______        ___     _____        _______"	;
	_Common::gotoXY(x + 5, y + 1);	cout <<	"	 / _____ |      /  |    |  __  |    /   __   | "	;
	_Common::gotoXY(x + 5, y + 2);	cout <<	"	| |            /   |    | |  )  |   |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 3);	cout <<	"	| |           /    |    | |__)  |   |  |  |  | "	;
	Textcolor(Blue);
	_Common::gotoXY(x + 5, y + 4);	cout <<	"	| |          /  /|  |   |   _  |    |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 5);	cout <<	"	| |______   /  ___  |   |  | |  |   |  |__|  |	"	;
	_Common::gotoXY(x + 5, y + 6);	cout <<	"	|________| /__|   |_|   |__|  |__|  |_______ / 	"	;

}

void PrintCaro4()
{
	int x = 31, y = 5;
	Textcolor(Red);
	_Common::gotoXY(x + 5, y);		cout << "  	   ______        ___     _____        _______"	;
	_Common::gotoXY(x + 5, y + 1);	cout <<	"	 / _____ |      /  |    |  __  |    /   __   | "	;
	_Common::gotoXY(x + 5, y + 2);	cout <<	"	| |            /   |    | |  )  |   |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 3);	cout <<	"	| |           /    |    | |__)  |   |  |  |  | "	;
	Textcolor(Blue);
	_Common::gotoXY(x + 5, y + 4);	cout <<	"	| |          /  /|  |   |   _  |    |  |  |  | "	;
	_Common::gotoXY(x + 5, y + 5);	cout <<	"	| |______   /  ___  |   |  | |  |   |  |__|  |	"	;
	_Common::gotoXY(x + 5, y + 6);	cout <<	"	|________| /__|   |_|   |__|  |__|  |_______ / 	"	;

}

void Play()
{
	AnTroChuot();
	int x = 50, y = 20;
	int i;
	char s[30] = " ";	
	int check = 1;

	system("cls");
	PrintCaro3();
	Textcolor(Cyan);
	_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";

	Textcolor(Red);
	_Common::gotoXY(50, 20); cout << "Player vs Player";
	Textcolor(7);
	_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
	_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
	_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
	Textcolor(White);
	_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(40, 32); cout << "Enter : Select ";
	_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";

	
	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (y > 20)
				{
					y--;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";

					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
					
				}
				if (y == 21)
				{
					
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
				}
				if (y == 22)
				{
	
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					Textcolor(Red);
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
				}
				if (y == 23)
				{
					
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					Textcolor(Red);
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
				}
				break;
			case 's':
				if (y<23)
				{
					y++;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";

					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
					
				}
				if (y == 21)
				{
					
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
				}
				if (y == 22)
				{
	
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					Textcolor(Red);
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
				}
				if (y == 23)
				{
					
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "CHOOSE YOUR GAME MODE";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player vs Player";
					_Common::gotoXY(50, 21); cout << "Player vs Computer (Easy)";
					_Common::gotoXY(50, 22); cout << "Player vs Computer (Medium)";
					Textcolor(Red);
					_Common::gotoXY(50, 23); cout << "Player vs Computer (Hard)";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
				}
				break;
			case 13:
				if (y == 20)
				{
					Diem a;
					a.score1 = 0;
					a.score2 = 0;
					int t = PlayerVsPlayer(a,0,s, size);
					if (t == 27)
					{
						system("cls");
						ScreenStartGame(99);
					}
				}
				if (y == 21)
				{
					Diem a;
					a.score1 = 0;
					a.score2 = 0;
					int t = PlayerVsCom2(a,0,s, size);
					if (t == 27)
					{
						system("cls");
						ScreenStartGame(99);
					}
				}
				if (y == 22)
				{
					Diem a;
					a.score1 = 0;
					a.score2 = 0;
					int t = PlayerVsCom3(a,0,s, size);
					if (t == 27)
					{
						system("cls");
						ScreenStartGame(99);
					}
				}
				if (y == 23)
				{
					Diem a;
					a.score1 = 0;
					a.score2 = 0;
					int t = PlayerVsCom(a,0,s, size);
					if (t == 27)
					{
						system("cls");
						ScreenStartGame(99);
					}
				}
				break;
			case 27:
				system("cls");
				ScreenStartGame(99);
				break;
			}
		}	
	}
}

//void Setting (int &sizeBoard)
void Setting(int &size)
{
	AnTroChuot();
	int x = 50, y = 20;
	int i = 0;
	char s[30] = " ";	
	int check = 1;
	int sizeBoard = 0, soundState = 0, bgState = 0;
	int a = sizeBoard, b = soundState, c = bgState;

	system("cls");
	PrintCaro3();
	Textcolor(Cyan);
	_Common::gotoXY(50, 18); cout << "SETTING";

	Textcolor(Red);
	_Common::gotoXY(47, 20); cout << "-> Player icons";
	Textcolor(7);
	_Common::gotoXY(50, 21); cout << "Gameboard size";
	_Common::gotoXY(50, 22); cout << "Sound effect";
	_Common::gotoXY(50, 23); cout << "Background music";
	Textcolor(White);
	_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(40, 32); cout << "Enter : Select ";
	_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (y > 20)
				{
					y--;
					
				}
				if (y == 20)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";

					Textcolor(Red);
					_Common::gotoXY(47, 20); cout << "-> Player icons";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					_Common::gotoXY(50, 22); cout << "Sound effect";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
					
				}
				if (y == 21)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					Textcolor(Red);
					_Common::gotoXY(47, 21); cout << "-> Gameboard size";
					Textcolor(Cyan);
					_Common::gotoXY(70, 21); cout << "5x5";
					Textcolor(7);
					_Common::gotoXY(66, 21); cout << "3x3";
					_Common::gotoXY(74, 21); cout << "7x7";
		     		_Common::gotoXY(50, 22); cout << "Sound effect";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 22)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					Textcolor(Red);
					_Common::gotoXY(47, 22); cout << "-> Sound effect";
					Textcolor(Cyan);
					_Common::gotoXY(64, 22); cout << "On";
					Textcolor(7);
					_Common::gotoXY(68, 22); cout << "Off";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 23)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					_Common::gotoXY(50, 22); cout << "Sound effect";
					Textcolor(Red);
					_Common::gotoXY(47, 23); cout << "-> Background music";
					Textcolor(Cyan);
					_Common::gotoXY(68, 23); cout << "On";
					Textcolor(7);
					_Common::gotoXY(72, 23); cout << "Off";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				break;
			case 's':
				if (y < 24)
					y++;
				if (y == 20)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";

					Textcolor(Red);
					_Common::gotoXY(47, 20); cout << "-> Player icons";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					_Common::gotoXY(50, 22); cout << "Sound effect";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
					_Common::gotoXY(40, 33); cout << "ESC   : Return to main menu ";
					
				}
				if (y == 21)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					Textcolor(Red);
					_Common::gotoXY(47, 21); cout << "-> Gameboard size";
					Textcolor(Cyan);
					_Common::gotoXY(70, 21); cout << "5x5";
					Textcolor(7);
					_Common::gotoXY(66, 21); cout << "3x3";
					_Common::gotoXY(74, 21); cout << "7x7";
		     		_Common::gotoXY(50, 22); cout << "Sound effect";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 22)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					Textcolor(Red);
					_Common::gotoXY(47, 22); cout << "-> Sound effect";
					Textcolor(Cyan);
					_Common::gotoXY(64, 22); cout << "On";
					Textcolor(7);
					_Common::gotoXY(68, 22); cout << "Off";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 23)
				{
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					_Common::gotoXY(50, 22); cout << "Sound effect";
					Textcolor(Red);
					_Common::gotoXY(47, 23); cout << "-> Background music";
					Textcolor(Cyan);
					_Common::gotoXY(68, 23); cout << "On";
					Textcolor(7);
					_Common::gotoXY(72, 23); cout << "Off";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				break;
			case 'd':	
				if (y == 21 && a < 2) {
					a++;		
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					Textcolor(Red);
					_Common::gotoXY(47, 21); cout << "-> Gameboard size";
					if (a == 0) {
						Textcolor(Cyan);
						_Common::gotoXY(66, 21); cout << "3x3";
						Textcolor(7);
						_Common::gotoXY(70, 21); cout << "5x5";
						_Common::gotoXY(74, 21); cout << "7x7";
					}
					if (a == 1) {
						Textcolor(7);
						_Common::gotoXY(66, 21); cout << "3x3";
						Textcolor(Cyan);
						_Common::gotoXY(70, 21); cout << "5x5";
						Textcolor(7);
						_Common::gotoXY(74, 21); cout << "7x7";
					}
					if (a == 2) {
						Textcolor(7);
						_Common::gotoXY(66, 21); cout << "3x3";				
						_Common::gotoXY(70, 21); cout << "5x5";
						Textcolor(Cyan);
						_Common::gotoXY(74, 21); cout << "7x7";
					}
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "Sound effect";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 22 && b < 1) {
					b++;
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					Textcolor(Red);
					_Common::gotoXY(47, 22); cout << "-> Sound effect";
					if (b == 0) {
						Textcolor(Cyan);
						_Common::gotoXY(64, 22); cout << "On";
						Textcolor(7);
						_Common::gotoXY(68, 22); cout << "Off";
					}
					if (b == 1) {
						Textcolor(7);
						_Common::gotoXY(64, 22); cout << "On";
						Textcolor(Cyan);
						_Common::gotoXY(68, 22); cout << "Off";
					}
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 23 && c < 1) {
					c++;
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					_Common::gotoXY(50, 22); cout << "Sound effect";
					Textcolor(Red);
					_Common::gotoXY(47, 23); cout << "-> Background music";
					if (c == 0) {
						Textcolor(Cyan);
						_Common::gotoXY(68, 23); cout << "On";
						Textcolor(7);
						_Common::gotoXY(72, 23); cout << "Off";
					}
					if (c == 1) {
						Textcolor(7);
						_Common::gotoXY(68, 23); cout << "On";
						Textcolor(Cyan);
						_Common::gotoXY(72, 23); cout << "Off";
					}
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				break;
			case 'a':
				if (y == 21 && a > 0) {
					a--;
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					Textcolor(Red);
					_Common::gotoXY(47, 21); cout << "-> Gameboard size";
					if (a == 0) {
						Textcolor(Cyan);
						_Common::gotoXY(66, 21); cout << "3x3";
						Textcolor(7);
						_Common::gotoXY(70, 21); cout << "5x5";
						_Common::gotoXY(74, 21); cout << "7x7";
					}
					if (a == 1) {
						Textcolor(7);
						_Common::gotoXY(66, 21); cout << "3x3";
						Textcolor(Cyan);
						_Common::gotoXY(70, 21); cout << "5x5";
						Textcolor(7);
						_Common::gotoXY(74, 21); cout << "7x7";
					}
					if (a == 2) {
						Textcolor(7);
						_Common::gotoXY(66, 21); cout << "3x3";				
						_Common::gotoXY(70, 21); cout << "5x5";
						Textcolor(Cyan);
						_Common::gotoXY(74, 21); cout << "7x7";
					}
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "Sound effect";
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 22 && b > 0) {
					b--;
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					Textcolor(Red);
					_Common::gotoXY(47, 22); cout << "-> Sound effect";
					if (b == 0) {
						Textcolor(Cyan);
						_Common::gotoXY(64, 22); cout << "On";
						Textcolor(7);
						_Common::gotoXY(68, 22); cout << "Off";
					}
					if (b == 1) {
						Textcolor(7);
						_Common::gotoXY(64, 22); cout << "On";
						Textcolor(Cyan);
						_Common::gotoXY(68, 22); cout << "Off";
					}
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				if (y == 23 && c > 0) {
					c--;
					system("cls");
					PrintCaro4();
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					_Common::gotoXY(50, 22); cout << "Sound effect";
					Textcolor(Red);
					_Common::gotoXY(47, 23); cout << "-> Background music";
					if (c == 0) {
						Textcolor(Cyan);
						_Common::gotoXY(68, 23); cout << "On";
						Textcolor(7);
						_Common::gotoXY(72, 23); cout << "Off";
					}
					if (c == 1) {
						Textcolor(7);
						_Common::gotoXY(68, 23); cout << "On";
						Textcolor(Cyan);
						_Common::gotoXY(72, 23); cout << "Off";
					}
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				break;
			case 13:
				if (y == 21 && a == 0) {
					board3x3();
					size = 3;
				}
				if (y == 21 && a == 1) {
					board5x5();
					size = 5;
				}
				if (y == 21 && a == 2) {
					board7x7();
					size = 7;
				if (y == 22 && b == 0) {
					board5x5();
					soundState = 1;
				}
				if (y == 22 && b == 1) {
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					Textcolor(Red);
					_Common::gotoXY(47, 22); cout << "-> Sound effect";
					Textcolor(7);
					_Common::gotoXY(64, 22); cout << "On";
					Textcolor(Red);
					_Common::gotoXY(68, 22); cout << "Off";
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "Background music";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
					soundState = 0;
				}
				if (y == 23) {
					Textcolor(Cyan);
					_Common::gotoXY(50, 18); cout << "SETTING";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Player icons";
					_Common::gotoXY(50, 21); cout << "Gameboard size";
					_Common::gotoXY(50, 22); cout << "Sound effect";
					Textcolor(Red);
					_Common::gotoXY(47, 23); cout << "-> Background music";
					if (c == 0) {
						Textcolor(Red);
						_Common::gotoXY(68, 23); cout << "On";
						Textcolor(7);
						_Common::gotoXY(72, 23); cout << "Off";
						bgState = 1;
					}
					if (c == 1) {
						Textcolor(7);
						_Common::gotoXY(68, 23); cout << "On";
						Textcolor(Red);
						_Common::gotoXY(72, 23); cout << "Off";
						bgState = 0;
					}
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W A S D : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter   : Select ";
					_Common::gotoXY(40, 33); cout << "ESC     : Return to main menu ";
				}
				break;
			case 27:
				system("cls");
				ScreenStartGame(99);
				break;
				}
			}
		}
	}
}
						
void Statistic() {
	int check = 1;
	system("cls");
	PrintCaro3();
	_Common::gotoXY(60, 19);
	Textcolor(Cyan);
	cout << "STATISTIC";
	Textcolor(7);
	_Common::gotoXY(43, 31);
	cout << "R  : Reset statistic ";
	_Common::gotoXY(39, 32);
	cout << "<-- Press any key to return to main menu ";
	Textcolor(Cyan);
	_Common::gotoXY(33, 21);
	cout << "Games played: ";
	Textcolor(7);
	_Common::gotoXY(48, 21);
	cout << gameplayed;
	Textcolor(Cyan);
	_Common::gotoXY(33, 23);
	cout << "Player vs Player mode";
	Textcolor(7);
	_Common::gotoXY(45, 24);
	cout << "P1's score: " << pvp1;
	_Common::gotoXY(45, 25);
	cout << "P2's score: " << pvp2;
	_Common::gotoXY(33, 27);
	Textcolor(Cyan);
	cout << "Player vs Computer mode";
	Textcolor(7);
	_Common::gotoXY(45, 28);
	cout << "Player's score: " << pvc;
	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
				case 27: 
					system("cls");
					ScreenStartGame(99);
					break;
				case 'r':
				{
					gameplayed = 0;
					pvp1 = 0;
					pvp2 = 0;
					pvc = 0;
					Statistic();
					break;
				}
				case 'R':
				{
					gameplayed = 0;
					pvp1 = 0;
					pvp2 = 0;
					pvc = 0;
					Statistic();
					break;
				}
				default: 
					system("cls");
					ScreenStartGame(99);
					break;
			}
		}
	}
}

void About()
{
	system("cls");
	PrintCaro3();
	_Common::gotoXY(60, 19);
	Textcolor(Cyan);
	cout << "ABOUT";
	Textcolor(7);
	_Common::gotoXY(30, 21);
	cout << "PROJECT - CARO GAME - 20CTT2 - HCMUS" << endl;
	_Common::gotoXY(30, 22);
	cout << "-> SID       : 20125096." << endl;
	_Common::gotoXY(30, 23);
	cout << "-> Full Name : PHAN VINH KHANG." << endl;
	_Common::gotoXY(30, 24);
	cout << "-> Class     : 20CTT2." << endl;
	_Common::gotoXY(30, 25);
	cout << "-> Mentor    : BUY HUY THONG - PHAN THI PHUONG UYEN" << endl;

	_Common::gotoXY(30, 28);
	cout << "-> Have fun !!" << endl;
	Textcolor(15);
	_Common::gotoXY(40, 32);
	cout << "<-- Press any key to return to main menu.";
	char command = ' ';
	command = _getch();			
	system("cls");
}
void Help()
{
	system("cls");
	PrintCaro3();
	_Common::gotoXY(60, 19);
	Textcolor(Cyan);
	cout << "HELP";
	Textcolor(7);
	_Common::gotoXY(20, 21);
	cout << "TUTORIAL" << endl;
	_Common::gotoXY(20, 22);
	cout << "1. You may set to mode 3x3, 5x5 or 7x7 as you wish." << endl;
	_Common::gotoXY(20, 23);
	cout << "2. Use W A S D to move - Enter to drop." << endl;
	_Common::gotoXY(20, 24);
	cout << "3. Aim for 5 pieces in a row to win the game.";
    _Common::gotoXY(20, 25);
    cout << "   To win, you must be the first player to create an unbroken line "
            "of 5 of your moves.";
    _Common::gotoXY(20, 26);
    cout << "   The line can go in any direction: horizontally, "
            "vertically, or diagonally." << endl;
	_Common::gotoXY(20, 27);
	cout << "4. If the rows is covered at both sides, it will not count as win. " << endl;

	_Common::gotoXY(50, 30);
	cout << "-> Have fun !!" << endl;
	_Common::gotoXY(40, 32);
	Textcolor(15);
	cout << "<-- Press any key to return to main menu.";
	char command = ' ';
	command = _getch();
	system("cls");
}
void LoadLoad()
{
	int n = 100;
	system("cls");
	PrintCaro3();
	ReadNameFile();
	char data[30];
	_Common::gotoXY(50, 32);
	HienTroChuot();
	cout << "Enter file name: ";
	cin.getline(data, 30);
	int chedo = ReadChedo(data);
	if (chedo == -30 || chedo == -31)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = PlayerVsPlayer(a, chedo, data, size);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(n - 1);
		}
	}
	if (chedo == -4)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = PlayerVsCom2(a, -4, data, size);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(n - 1);
		}
	}
	if (chedo == -5)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = PlayerVsCom(a, -5, data, size);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(n - 1);
		}
	}
}
void ScreenStartGame(int n)
{
	
	AnTroChuot();
	int x = 50, y = 20;
	int i;
	char s[30] = " ";	
	int check = 1;
	PrintCaro3();
	Textcolor(Cyan);
	_Common::gotoXY(60, 18); cout << "MAIN MENU";
	Textcolor(Red);
	_Common::gotoXY(50, 20); cout << "Play";
	Textcolor(7);
	_Common::gotoXY(50, 21); cout << "Setting";
	_Common::gotoXY(50, 22); cout << "Player Statistics";
	_Common::gotoXY(50, 23); cout << "Load Game";
	_Common::gotoXY(50, 24); cout << "Help";
	_Common::gotoXY(50, 25); cout << "About";
	_Common::gotoXY(50, 26); cout << "Exit";
	Textcolor(White);
	_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
	_Common::gotoXY(40, 32); cout << "Enter : Select ";
	if (n == 100)
	{
		Screen();
		PrintCaro2();
	}
	else
		PrintCaro3();
	
	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (y > 20)
				{
					y--;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "Play";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 21)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "Setting";
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 22)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					Textcolor(Red);
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 23)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					Textcolor(Red);
					_Common::gotoXY(50, 23); cout << "Load Game";
					Textcolor(7);
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 24)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					Textcolor(Red);
					_Common::gotoXY(50, 24); cout << "Help";
					Textcolor(7);
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 25)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					Textcolor(Red);
					_Common::gotoXY(50, 25); cout << "About";
					Textcolor(7);
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 26)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					Textcolor(Red);
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				break;
			case 's':
				if (y<26)
				{
					y++;
					_Common::gotoXY(x, y);
				}
				if (y == 20)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(Red);
					_Common::gotoXY(50, 20); cout << "Play";
					Textcolor(7);
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 21)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					Textcolor(Red);
					_Common::gotoXY(50, 21); cout << "Setting";
					Textcolor(7);
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 22)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					Textcolor(Red);
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					Textcolor(7);
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 23)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					Textcolor(Red);
					_Common::gotoXY(50, 23); cout << "Load Game";
					Textcolor(7);
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 24)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					Textcolor(Red);
					_Common::gotoXY(50, 24); cout << "Help";
					Textcolor(7);
					_Common::gotoXY(50, 25); cout << "About";
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 25)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					Textcolor(Red);
					_Common::gotoXY(50, 25); cout << "About";
					Textcolor(7);
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				if (y == 26)
				{
					Textcolor(Cyan);
					_Common::gotoXY(60, 18); cout << "MAIN MENU";
					Textcolor(7);
					_Common::gotoXY(50, 20); cout << "Play";
					_Common::gotoXY(50, 21); cout << "Setting";
					_Common::gotoXY(50, 22); cout << "Player Statistics";
					_Common::gotoXY(50, 23); cout << "Load Game";
					_Common::gotoXY(50, 24); cout << "Help";
					_Common::gotoXY(50, 25); cout << "About";
					Textcolor(Red);
					_Common::gotoXY(50, 26); cout << "Exit";
					Textcolor(White);
					_Common::gotoXY(40, 31); cout << "W - S : Move ( Off Unikey - Off Caps Lock ) ";
					_Common::gotoXY(40, 32); cout << "Enter : Select ";
				}
				break;
			case 13:
				if (y == 20)
				{
					Play();
					ScreenStartGame(99);
				}
				if (y == 21)
				{
					Setting(size);
					ScreenStartGame(99);
				}
				if (y == 22)
				{
					Statistic();
					ScreenStartGame(99);
				}
				if (y == 23)
				{
					LoadLoad();
					ScreenStartGame(99);
				}
				if (y == 24)
				{
					Help();
					ScreenStartGame(99);
				}
				if (y == 25)
				{
					About();
					ScreenStartGame(99);
				}
				if (y == 26)
				{
					exit(0);
				}
				break;
			}
		}	
	}
}
void PrintScoreBoard()
{
	Textcolor(1);
	for (int i = 0; i < 128; i++) {
		_Common::gotoXY(i, 9);
		cout << char(220);
	}
	for (int i = 0; i < 90; i++) {
		_Common::gotoXY(i+18, 34);
		cout << char(220);
	}
	for (int i = 0; i < 25; i++) {
		Sleep(1);
		_Common::gotoXY(18, i+10);
		cout << char(219);
	}
	for (int i = 0; i < 25; i++) {
		Sleep(1);
		_Common::gotoXY(108, i+10);
		cout << char(219);
	}

	//Cot ke 2 ben
	Textcolor(Yellow);
	_Common::gotoXY(0, 22); cout << char(219);
	for (int i = 0; i < 17; i++) {
		Sleep(1);
		_Common::gotoXY(1+i, 22);
		cout << char(205);
	}
	_Common::gotoXY(0, 23); cout << char(219);
	for (int i = 0; i < 17; i++) {
		Sleep(1);
		_Common::gotoXY(1+i, 23);
		cout << char(205);
	}
	_Common::gotoXY(128, 22); cout << char(219);
	for (int i = 0; i < 19; i++) {
		Sleep(1);
		_Common::gotoXY(109+i, 22);
		cout << char(205);
	}
	_Common::gotoXY(128, 23); cout << char(219);
	for (int i = 0; i < 19; i++) {
		Sleep(1);
		_Common::gotoXY(109+i, 23);
		cout << char(205);
	}
	Textcolor(White);
	for (int i = 0; i < 8; i++){
		Sleep(1);
		_Common::gotoXY(0, i);
		cout << char(219);
	}
	for (int i = 1; i < 8; i++){
		Sleep(1);
		_Common::gotoXY(37, i);
		cout << char(219);
	}
	_Common::gotoXY(0, 0);
	for (int i = 0; i <= 37; i++){ 
		Sleep(1);
		cout << char(220);
	}
	_Common::gotoXY(0, 8);
	for (int i = 0; i <= 37; i++){ 
		Sleep(1);
		cout << char(223);
	}
	
	// Bang turn
	for (int i = 0; i < 8; i++){
		Sleep(1);
		_Common::gotoXY(44, i);
		cout << char(219);
	}
	for (int i = 1; i < 8; i++){
		Sleep(1);
		_Common::gotoXY(81, i);
		cout << char(219);
	}
	_Common::gotoXY(44, 0);
	for (int i = 0; i <= 37; i++){ 
		Sleep(1);
		cout << char(220);
	}
	_Common::gotoXY(44, 8);
	for (int i = 0; i <= 37; i++){ 
		Sleep(1);
		cout << char(223);
	}

	// Bang player2
	for (int i = 0; i < 8; i++){
		Sleep(1);
		_Common::gotoXY(88, i);
		cout << char(219);
	}
	for (int i = 1; i < 8; i++){
		Sleep(1);
		_Common::gotoXY(125, i);
		cout << char(219);
	}
	_Common::gotoXY(88, 0);
	for (int i = 0; i <= 37; i++){ 
		Sleep(1);
		cout << char(220);
	}
	_Common::gotoXY(88, 8);
	for (int i = 0; i <= 37; i++){ 
		Sleep(1);
		cout << char(223);
	}
	
	_Common::gotoXY(15,2);
	cout << "PLAYER 1";
	_Common::gotoXY(7, 5);
	cout << "Step: ";
	_Common::gotoXY(7, 6);
	cout << "Games won: ";


	_Common::gotoXY(104, 2);
	cout << "PLAYER 2";
	_Common::gotoXY(96, 5);
	cout << "Step: ";
	_Common::gotoXY(96, 6);
	cout << "Games won: ";

	_Common::gotoXY(51, 4);
	cout << "-----------------------";
	_Common::gotoXY(53, 5);
	cout << " W A S D: Move ";
	_Common::gotoXY(53, 6);
	cout << " ESC: Exit ";

	_Common::gotoXY(2,1);
} // IN BANG DIEM
void Screen()
{
	int check = 1;
	while (check < 7)
	{
		PrintCaro();
		Sleep(100);
		check++;
	}
}
int PlayerVsCom(Diem &a, int load , char data[30], int size)
{
	
	int k = 1, n = 100;
	HienTroChuot();
	_Game g(size, 0, 0);
	g.setCountXY();
	if (load == -5)
	{
		g.LoadGame(data, 3);
	}
	else
	{
		g.startGame(size);
		g.setTurn();
	}
	PrintScoreBoard();
	Textcolor(Blue);
	_Common::gotoXY(19, 6);
	cout << a.score1;
	Textcolor(Red);
	_Common::gotoXY(108, 6);
	cout << a.score2;
	_Common::gotoXY(56, 18);
	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				if (size == 3) {
					g.setX(62);
					g.setY(21);
					_Common::gotoXY(62, 21);
					g.setCommand(13);
				} 
				if (size == 5) {
					g.setX(62);
					g.setY(20);
					_Common::gotoXY(62, 20);
					g.setCommand(13);
				}
				if (size == 7) {
					g.setX(62);
					g.setY(21);
					_Common::gotoXY(62, 21);
					g.setCommand(13);
				}
			}
			else
			{
				g.TimKiemNuocDi();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				_Common::gotoXY(x, y);
				Sleep(300);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27)
		{
			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':
				g.moveLeft();
				break;
			case 'D':
				g.moveRight();
				break;
			case 'W':
				g.moveUp();
				break;
			case 'S':
				g.moveDown();
				break;
			case 'L':
				g.SaveGame(-5);
				break;
			case 'T':
				LoadLoad();
				break;
			case 13:
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()){
					switch (g.processFinish(x, y)){
					case -1:
						a.score1++;
						pvc++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom(a,load,data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n-1);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom(a, load, data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n-1);
									break;
								}
							}
						}

						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom(a, load, data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n-1);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
}
int PlayerVsCom2(Diem &a, int load, char data[30], int size)
{
	int n = 99;
	int k = 1;
	HienTroChuot();
	_Game g(size, 0, 0);
	g.setCountXY();
	if (load == -4)
	{
		g.LoadGame(data, size);
	}
	else
	{
		g.startGame(size);
		g.setTurn();
	}
	PrintScoreBoard();
	Textcolor(Cyan);
	/*_Common::gotoXY(size * 4 + 32, 24);
	cout << " PLAYER VS BOT (EASY) ";*/
	Textcolor(Blue);
	_Common::gotoXY(19, 6);
	cout << a.score1;
	Textcolor(Red);
	_Common::gotoXY(108, 6);
	cout << a.score2;
	_Common::gotoXY(56, 18);
	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				if (size == 3) {
					g.setX(62);
					g.setY(21);
					_Common::gotoXY(62, 21);
					g.setCommand(13);
				} 
				if (size == 5) {
					g.setX(62);
					g.setY(20);
					_Common::gotoXY(62, 20);
					g.setCommand(13);
				}
				if (size == 7) {
					g.setX(62);
					g.setY(21);
					_Common::gotoXY(62, 21);
					g.setCommand(13);
				}
			}
			else
			{
				g.TimKiemNuocDi2();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				_Common::gotoXY(x, y);
				Sleep(300);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27){
			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':
				g.moveLeft();
				break;
			case 'D':
				g.moveRight();
				break;
			case 'W':
				g.moveUp();
				break;
			case 'S':
				g.moveDown();
				break;
			case 'L':
					g.SaveGame(-4);
				break;
			case 'T':
				LoadLoad();
				break;
			case 13:
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()){
					switch (g.processFinish(x, y)){
					case -1:
						a.score1++;
						pvc++;
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom2(a,load,data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}

						break;
					case 1:
						a.score2++;
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom2(a,load,data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}

						break;
					case 0:
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom2(a,load,data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
}

int PlayerVsCom3(Diem &a, int load , char data[30], int size)
{
	int k = 1, n = 100;
	HienTroChuot();
	_Game g(size, 0, 0);
	g.setCountXY();
	if (load == -5)
	{
		g.LoadGame(data, 3);
	}
	else
	{
		g.startGame(size);
		g.setTurn();
	}
	PrintScoreBoard();
	Textcolor(Blue);
	_Common::gotoXY(19, 6);
	cout << a.score1;
	Textcolor(Red);
	_Common::gotoXY(108, 6);
	cout << a.score2;
	_Common::gotoXY(56, 18);
	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				if (size == 3) {
					g.setX(62);
					g.setY(21);
					_Common::gotoXY(62, 21);
					g.setCommand(13);
				} 
				if (size == 5) {
					g.setX(62);
					g.setY(20);
					_Common::gotoXY(62, 20);
					g.setCommand(13);
				}
				if (size == 7) {
					g.setX(62);
					g.setY(21);
					_Common::gotoXY(62, 21);
					g.setCommand(13);
				}
			}
			else
			{
				g.TimKiemNuocDi3();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				_Common::gotoXY(x, y);
				Sleep(300);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27)
		{
			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':
				g.moveLeft();
				break;
			case 'D':
				g.moveRight();
				break;
			case 'W':
				g.moveUp();
				break;
			case 'S':
				g.moveDown();
				break;
			case 'L':
				g.SaveGame(-5);
				break;
			case 'T':
				LoadLoad();
				break;
			case 13:
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()){
					switch (g.processFinish(x, y)){
					case -1:
						a.score1++;
						pvc++;
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom3(a,load,data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n-1);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom3(a, load, data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n-1);
									break;
								}
							}
						}

						break;
					case 0:
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom3(a, load, data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n-1);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
}

int PlayerVsPlayer(Diem &a, int load, char data[30], int size)
{
	int k = 1;
	int n = 99;
	HienTroChuot();
	_Game g(size, 0, 0);
	g.setCountXY();
	if (load == -30)
	{
		g.setTurn();
		g.LoadGame(data, size);
	}
	else if (load == -31)
		{
		g.LoadGame(data, size);
		}
		else 
			g.startGame(size);
	PrintScoreBoard();
	Textcolor(Cyan);
	/*_Common::gotoXY(size * 4 + 32, 24);
	cout << " PLAYER VS PLAYER ";*/
	Textcolor(Blue);
	_Common::gotoXY(19, 6);
	cout << a.score1;
	Textcolor(Red);
	_Common::gotoXY(108, 6);
	cout << a.score2;
	_Common::gotoXY(56, 18);
	while (g.isContinue())
	{
		g.waitKeyBoard();
		if (g.getCommand() == 27){
			return 27;
		}
			
		else
		{
			switch (g.getCommand())
			{
			case 'A':
				g.moveLeft();
				break;
			case 'D':
				g.moveRight();
				break;
			case 'W':
				g.moveUp();
				break;
			case 'S':
				g.moveDown();
				break;
			case 'L':
				if (g.getTurn() == 1)
					g.SaveGame(-31);
				else
					g.SaveGame(-30);
				break;
			case 'T':
				LoadLoad();
				break;
			case 13:
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()){
					switch (g.processFinish(x, y)){
					case -1:
						a.score1++;
						pvp1++;
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsPlayer(a,load,data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						pvp2++;
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsPlayer(a, load, data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					case 0:
						gameplayed++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsPlayer(a, load, data, size);
									break;
								case 27:
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;

					}
				}
			}
		}
	}
}
