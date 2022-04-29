#pragma once
#include "_Board.h"
#include "_Point.h"
#include "_Common.h"
#include "_Play.h"
#include <Windows.h>
#include <fstream>

// Xử lí hiệu ứng thắng - thua - hòa .
void P1();
void P2();
void P1WIN();
void P2WIN();
void Box();
void Draw();
void PDraw();

class _Game
{
	_Board* _b;		// Khởi tạo 1 bàn cờ
	bool _turn;		// True là lượt người chơi 1 , false là người chơi 2.
	int _x, _y;		// Tọa độ
	int _command;	// Nhận phím
	bool _loop;		// True chơi tiếp, False Out.
	int size;	   // Size bàn cờ 
	int scorep1;  // Số trận thắng P1
	int scorep2;// Số trận thắng P2
	int chedo; // Đọc file để nhận biết chế độ chơi
	// -31 : Chế độ P vs P đang đến lượt X
	// -30 : Chế độ P vs P đang đến lượt O
	// -4  : Chế độ P vs Bot (Dễ ) đang đến lượt X
	// -5  : Chế độ P vs Bot (Khó ) đang đến lượt X

public:
	// Cài đặt biến đếm nước cờ X và Y = 0.
	void setCountXY(){
		_b->CountX = 0;
		_b->CountY = 0;
	}

	// Nhận biết chế độ .
	int getChedo(){ return chedo; }
	// Nhận biết size bàn cờ.
	int getSize() { return size; }
	// Lấy tỉ số thắng 
	int getScore1(){ return scorep1; }
	int getScore2(){ return scorep2; }
	// Cài đặt tỉ số thắng = 0 .
	void setScore1(){ scorep1 = 0; }
	void setScore2(){ scorep2 = 0; }
	// Lấy giá trị của phím nhập vào .
	int getCommand();
	// Cài đặt phím nhập vào
	void setCommand(int x){ _command = x; }
	// Trò chơi tiếp tục
	bool isContinue();
	// Chờ nhập phím
	char waitKeyBoard();
	// Chơi lại hay không ?
	char askContinue();
	
public:
	// Khởi tạo game . Bắt đầu game 
	void startGame(int size); 
	// Thoát Game
	void exitGame(); 
	// Lưu Game đang chơi với biến n là chế độ và lượt .
	void SaveGame(int n);  
	// Khởi tạo game . Bắt đầu game ( trường hợp Load Game ) 
	void LoadGame(char data[30], int size); 
public:
	// Kiểm tra thắng thua - tiếp tục
	int processFinish(int x,int y);
	// Đánh dấu X và O trên bàn cờ
	bool processCheckBoard();
	// Di chuyển lên - xuống - trái - phải
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	// Cài đặt biến _x _y 
	void setX(int x){ _x = x; }
	void setY(int y){ _y = y; }
	// Lấy giá trị _x _y 
	int getXatEnter();
	int getYatEnter();
	// Lấy giá trị của lượt chơi .
	bool getTurn(){ return _turn; }
	// Đảo lượt chơi
	void setTurn(){ _turn = !_turn; }
	// Tìm kiếm nước đi cho máy
	void TimKiemNuocDi();
	void TimKiemNuocDi2();
	void TimKiemNuocDi3();
	// Đếm nước cờ đã đi được
	int DemNuocCoDaDi();
public:
	_Game();
	_Game(int pSize, int pLeft, int pTop);
	~_Game();
};

