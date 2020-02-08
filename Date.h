#ifndef _DATE_H_
#define _DATE_H_
class Date {
public:
	Date(const int& year, const int& month, const int& day);
	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }
	int getMaxDay()const;                      //获得该月有几天
	bool IsLeapYear()const { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
	void show()const;                          //显示日期
	int distance(const Date& date)const {
		return this->totalDays - date.totalDays;  //计算两个日期之间相差了多少天
	}
private:
	int year;
	int month;
	int day;
	int totalDays;                                  //该日期是从公元元年1月1日开始的第几天
};
#endif
