#pragma once
#include "_Point.h"
#include "_Common.h"
#include "_Board.h"
#include "_Game.h"

// MẶC ĐỊNH CÁC MÀU CƠ BẢN
#define SIZE			7
#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed			4
#define DarkPink		5
#define DarkYellow		6
#define DarkWhite		7
#define Grey			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red				12
#define Pink			13
#define Yellow			14
#define White			15
#define defaultColor	7 

// Tỉ số thắng thua 
struct Diem
{
	int score1;
	int score2;
};

// Đọc chế độ chơi
int ReadChedo(char a[30]); 
// Đọc tên các file đã lưu
void ReadNameFile();  
// Tạo file lưu statistic
void CreateFile();
// Đọc file statistic  
void ReadFile();
// Cập nhật dữ liệu người chơi 
void UpdateFile();
void PrintCaro();
void PrintCaro2();
void PrintCaro3();
void Screen();

// In chữ CARO 
// Đổi màu kí tự 
void Textcolor(int n); 
 // Ẩn trỏ chuột
void AnTroChuot();   
// Hiện trỏ chuột
void HienTroChuot();  
// Menu Chính
void ScreenStartGame(int); 
// In bảng điểm
void PrintScoreBoard(); 
// In menu 
void Play();
// In cài đặt 
void Setting(int &size);
// In dữ liệu người chơi
void Statistic();
// Doi icon
void playericon();
// BOT Khó 
int PlayerVsCom(Diem &a,int ,char data[30], int size); 
// BOT Dễ 
int PlayerVsCom2(Diem &a, int, char data[30], int size); 
// BOT Trung bình 
int PlayerVsCom3(Diem &a, int, char data[30], int size); 
 // P VS P
int PlayerVsPlayer(Diem &a, int,char data[30], int size);
void Help(); // Help
void About(); // About 
// Load Game
void LoadLoad(); 
