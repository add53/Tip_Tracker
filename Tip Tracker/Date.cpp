#include "Header.h"

Date::Date(int new_day, int new_month, int new_year)
	:m_day(new_day), m_month(new_month), m_year(new_year) {}

int Date::getWeek_number() {
	return week_number;
}

int Date::getDay() {
	return m_day;
}

int Date::getMonth() {
	return m_month;
}

int Date::getYear() {
	return m_year;
}