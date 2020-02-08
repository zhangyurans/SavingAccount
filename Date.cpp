#include<iostream>
#include<iomanip>
#include"Date.h"
using namespace std;

namespace {
	const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};//平年某个月1日之前有多少天，为了便于getMaxDay函数的实现，该数组多出了一项
}

Date::Date(const int& year, const int& month, const int& day) :year(year), month(month), day(day) {
	if (day <= 0 || day > getMaxDay()) {
		cout << "Invalid date: ";
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
	if (month > 2)
		totalDays += IsLeapYear();
}
int Date::getMaxDay()const {
	if (month == 2 && IsLeapYear())
		return 29;
	else
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}
void Date::show()const {
	cout.fill('0');                                             //设置填充方式,不足位补0
	cout.width(2);                                              //设置宽度为2 
	cout << setw(4) << getYear() << " - " << setw(2) << getMonth() << " - " << setw(2) << getDay();
	cout.fill(' ');
}