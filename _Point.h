#pragma once
#include "conio.h"
#include <iostream>
#include "_Common.h"
using namespace std;
class _Point
{
	// Tọa độ x y trên bàn cờ
	int _x;
	int _y;
	
	// Biến nhận biết X và O ( -1 = X , 1 = O, 0 = Ô trống )
	int _check;

public:
	// Cài đặt biến _check
	bool setCheck(int);
	// Lấy giá trị của _x
	int getX();
	// Lấy giá trị của _y
	int getY();
	// Lấy giá trị của _check
	int getCheck();
	// Cài đặt biến _x
	void setX(int);
	// Cài đặt biến _y
	void setY(int);
	
public:
	_Point(int, int);
	_Point();
	~_Point();
};

