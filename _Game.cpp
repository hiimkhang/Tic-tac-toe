#include "_Game.h"




_Game::_Game(int pSize, int pLeft, int  pTop)
{
	if (pSize == 3) {
		pLeft = 56, pTop = 18;
		_b = new _Board(pSize, pLeft, pTop);
		_loop = _turn = true;
		_command = -1;
		_x = pLeft;
		_y = pTop;
	}
	if (pSize == 5) {
		pLeft = 52, pTop = 15;
		_b = new _Board(pSize, pLeft, pTop);
		_loop = _turn = true;
		_command = -1;
		_x = pLeft;
		_y = pTop;
	}
	if (pSize == 7) {
		pLeft = 48, pTop = 14;
		_b = new _Board(pSize, pLeft, pTop);
		_loop = _turn = true;
		_command = -1;
		_x = pLeft;
		_y = pTop;
	}
}
int _Game::getCommand(){ return _command; }
bool _Game::isContinue(){ return _loop; }
char _Game::waitKeyBoard()
{
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue()
{
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
	return waitKeyBoard();
}
void _Game::startGame(int size)
{
	system("cls");
	_b->resetData();
	if (size == 3)
		_b->drawBoard3();
	if (size == 5)
		_b->drawBoard5();
	if (size == 7)
		_b->drawBoard7();
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
	if (_turn == 1)
	{
		Textcolor(Blue);
		_Common::gotoXY(56, 2);
		cout << "Player 1's turn ";
	}
	else
	{
		Textcolor(Red);
		_Common::gotoXY(56, 2);
		cout << "Player 2's turn ";
	}
	Textcolor(Blue);
	_Common::gotoXY(19, 5);
	cout << _b->CountX;
	Textcolor(Red);
	_Common::gotoXY(108, 5);
	cout << _b->CountY;
}
void _Game::exitGame()
{
	_loop = false;
}
void _Game::moveRight()
{
	if (_x<_b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		_x += 4;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::moveLeft(){
	if (_x>_b->getXAt(0,0))
	{
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}
void P1WIN()
{
	AnTroChuot();
	int check = 1;
	Box();
	while (check<30)
	{
		P1();
		Sleep(200);
		check++;
	}
}
void P2WIN()
{
	AnTroChuot();
	int check = 1;
	Box();
	while (check<30)
	{
		P2();
		Sleep(200);
		check++;
	}
}
void PDraw()
{
	AnTroChuot();
	int check = 1;
	Box();
	while (check<30)
	{
		Draw();
		Sleep(200);
		check++;
	}
}
void _Game::moveDown() {
	if (_y<_b->getYAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		_y += 2;
		_Common::gotoXY(_x, _y);
	} 
}
void _Game::moveUp() {
	if (_y>_b->getYAt(0,0))
	{
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}
bool _Game::processCheckBoard()	
{
	switch (_b->checkBoard(_x, _y, _turn))
	{
	case -1:
		Textcolor(Blue);
		cout << "X";
		_Common::gotoXY(19, 5);
		cout << _b->CountX;
		Textcolor(Red);
		_Common::gotoXY(108, 5);
		cout << _b->CountY;
		_Common::gotoXY(56, 2);
		cout << "Player 2's turn ";

		_Common::gotoXY(_x, _y);
		break;
	case 1:
		Textcolor(Red);
		cout << "O";
		Textcolor(Blue);
		_Common::gotoXY(19, 5);
		cout << _b->CountX;
		_Common::gotoXY(56, 2);
		cout << "Player 1's turn ";
		Textcolor(Red);
		_Common::gotoXY(108, 5);
		cout << _b->CountY;

		break;
	case 0:
		return false;
		break;
	}
	return true;
}
int _Game::DemNuocCoDaDi()
{
	return _b->CountX + _b->CountY;
}
void P1()
{
	int x = 19, y = 11;
	Textcolor(rand()%15 + 1);
	_Common::gotoXY(x+6, y);		            cout << "         _____    _                           __                 _           ";
	_Common::gotoXY(x, y+1);					cout << "		 |  __ |  | |                         /_ |               (_)   ";       
	_Common::gotoXY(x, y+2);					cout << "		 | |__) | | |   __ _ _   _  ___ _ __   | |   __      __ _ _ __  ___ ";
	_Common::gotoXY(x, y+3);					cout << "		 |  ___/  | | /  _` | | | |/ _ | '__|  | |   | | /| / /| | '_ |/ __|  ";
	Textcolor(rand()%15 + 1);
	_Common::gotoXY(x, y+4);					cout << "		 | |      | | | (_| | |_| |  __/ |     | |    | V  V / | | | | |__ |   ";
	_Common::gotoXY(x, y+5);					cout << "		 |_|      |_| |__,_ ||__,  ||___| _|     |_|     |_/|_/  |_|_| |_|___/   ";
	_Common::gotoXY(x, y+6);				  cout << "                                   __/ |                                        ";
	_Common::gotoXY(x, y+7);			      cout << "                                  |___/                                       ";
}
void P2()
{
	int x = 30, y = 11;
	Textcolor(rand()%15 + 1);
	_Common::gotoXY(x, y);		            cout << "   _____  _                          ___             _   "  ;      
	_Common::gotoXY(x, y+1);					cout << "  |  __ || |                        |__ |           (_)     "    ; 
	_Common::gotoXY(x, y+2);					cout << "  | |__) | |   ___ _   _  ___ _ __     ) | __      ___ _ __  ___ " ;
	_Common::gotoXY(x, y+3);					cout << "  |  ___/| | / _` | | | |/ _ | '__|   / /  | | /| / / | '_ |/ __| ";
	Textcolor(rand()%15 + 1);
	_Common::gotoXY(x, y+4);					cout << "  | |    | || (_| | |_| |  __/ |     / /_   | V  V /| | | | |__ | ";
	_Common::gotoXY(x, y+5);					cout << "  |_|    |_| |__,_||__, ||___|_|    |____|   |_/|_/ |_|_| |_|___/ ";
	_Common::gotoXY(x, y+6);					cout << "                    __/ |                                        ";
	_Common::gotoXY(x, y+7);					cout << "                   |___/                                         ";
}
void Draw()
{
	int x = 30, y = 11;
	Textcolor(rand()%15 + 1);
	_Common::gotoXY(x+3, y);		            cout << "        _____                     ";
	_Common::gotoXY(x, y+1);					cout << "		|  __ |                    ";
	_Common::gotoXY(x, y+2);					cout << "		| |  | |  _ __  __ _  __      __ ";
	_Common::gotoXY(x, y+3);					cout << "		| |  | | |'__/ / _` | | | /| / / ";
	Textcolor(rand()%15 + 1);
	_Common::gotoXY(x, y+4);					cout << "		| |__| | | |  | (_| |  | V  V / ";
	_Common::gotoXY(x, y+5);					cout << "		|_____/  |_|   |__,_|   |_/|_/  ";
}
void Box()
{
	int i = 8, j = 8;
		Textcolor(Cyan);
		_Common::gotoXY(50, j + 18);
		cout << "Y   : Play again";
		_Common::gotoXY(50, j + 19);
		cout << "ESC : Back";
}
int _Game::processFinish(int x,int y)
{
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int pWhoWin = _b->testBoard(x,y, size);
	switch (pWhoWin)
	{
	case -1:
		system("cls");
		P1WIN();
		break;
	case 1:
		system("cls");
		P2WIN();
		break;
	case 0:
		system("cls");
	
		PDraw();
		break;
	case 2:
		_turn = !_turn;
	}
	_Common::gotoXY(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
int _Game::getXatEnter()
{
	return _x;
}
int _Game::getYatEnter()
{
	return _y;
}
void _Game::TimKiemNuocDi()
{
	_x = _b->Tim_Kiem_NuocDi_1(size).getX();
	_y = _b->Tim_Kiem_NuocDi_1(size).getY();
}
void _Game::TimKiemNuocDi2()
{
	_x = _b->Tim_Kiem_NuocDi_2(size).getX();
	_y = _b->Tim_Kiem_NuocDi_2(size).getY();
}
void _Game::TimKiemNuocDi3()
{
	_x = _b->Tim_Kiem_NuocDi_3(size).getX();
	_y = _b->Tim_Kiem_NuocDi_3(size).getY();
}
_Game::~_Game()
{
	delete _b;
}

void _Game::SaveGame(int n)
{
	char data[30];
	ofstream f1;
	ofstream f2;
	_Common::gotoXY(35, SIZE *2+1);
	cout << "ENTER FILE NAME: ";
	Textcolor(Cyan);
	cin.getline(data, 30);
	f1.open(data, ios::out);
	f2.open("Name.txt", ios::app);
	f2 << data << " " << endl;
	//thong tin
	f1 << scorep1 << " " << scorep2 << " " << n << endl;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			f1 << _b->get_Check(i, j) << " ";
		}
		f1 << endl;
	}
	f1.close();
	f2.close();
	_Common::gotoXY(35, SIZE * 2 + 2);
	cout << "ESC : BACK";
	int t = 1;
	while (t)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 27:
				t = 0;
				system("cls");
				ScreenStartGame(99);
				break;
			}
		}
	}
}
void _Game::LoadGame(char data[30], int size)
{

	//NHAP FILE
	ifstream f;
	f.open(data, ios::in);
	if (!f){
		_Common::gotoXY(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
	}
	else
	{
		f >> scorep1 >> scorep2 >> chedo;
		system("cls");
		//thong tin
		//ban co
		int k;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				f >> k;
				_b->loadData(i, j, k);
			}
		}
		_x = _b->getXAt(0, 0);
		_y = _b->getYAt(0, 0);
		if (size == 5)
			_b->drawBoard5();
		if (size == 7)
			_b->drawBoard7();
		f.close();
	}
	Textcolor(Blue);
	_Common::gotoXY(SIZE * 4 + 30 + 12, 4);
	cout << _b->CountX;
	Textcolor(Red);
	_Common::gotoXY(SIZE * 4 + 30 + 12, 14);
	cout << _b->CountY;
	if (_turn == 1)
	{
		Textcolor(Blue);
		_Common::gotoXY(56, 2);
		cout << "Player 1's turn ";
	}
	else
	{
		Textcolor(Red);
		_Common::gotoXY(56, 2);
		cout << "Player 2's turn ";
	}
}
