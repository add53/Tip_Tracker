#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<limits>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include<istream>
#include<algorithm>
#include<ctime>
#pragma warning(disable : 4996)
#define KEY_X 120
#undef max

//"Tip" Class
class Tip {
	std::string day_part;
	int tip_amount;
	std::string day;
	double hours;

public:
	//Constructor Declaration
	Tip(std::string new_day_part, int new_tip_amount, std::string new_day, double new_hours);

	//"Get" Function Declarations
	std::string getDay();
	std::string getDay_part();
	int getTip_Amount();
	double getHours();
	int TipPerHour();
};

