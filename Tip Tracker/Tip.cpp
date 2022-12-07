#include "Header.h"

//Constructor definition
Tip::Tip(std::string new_day_part, int new_tip_amount, std::string new_day, double new_hours)
	:day_part(new_day_part), tip_amount(new_tip_amount), day(new_day), hours(new_hours) {}

//"Get" Function Defintions
std::string Tip::getDay() {
	return day;
}

std::string Tip::getDay_part() {
	return day_part;
}

int Tip::getTip_Amount() {
	return tip_amount;
}

double Tip::getHours() {
	return hours;
}

int Tip::TipPerHour() {
	return getTip_Amount() / getHours();
}
