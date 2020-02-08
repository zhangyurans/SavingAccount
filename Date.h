#ifndef _DATE_H_
#define _DATE_H_
class Date {
public:
	Date(const int& year, const int& month, const int& day);
	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }
	int getMaxDay()const;                      //��ø����м���
	bool IsLeapYear()const { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
	void show()const;                          //��ʾ����
	int distance(const Date& date)const {
		return this->totalDays - date.totalDays;  //������������֮������˶�����
	}
private:
	int year;
	int month;
	int day;
	int totalDays;                                  //�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
};
#endif
