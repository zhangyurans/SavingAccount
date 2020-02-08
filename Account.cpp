#include<iostream>
#include<cmath>
#include <iomanip>
#include<string>
#include"Account.h"
using namespace std;

double SavingAccount::total = 0.0;                                                                        //���徲̬���������������ռ����ĳ���ط�ʹ�������޶�����������
unsigned SavingAccount::num = 0;

SavingAccount::SavingAccount(const Date& date, const string& id, const double& rate):LastDate(date),id(id),balance(0.0),rate(rate),accumulation(0){
	num++;
	date.show();
	cout << "\t#" << id << " is created" << endl;
}
SavingAccount::~SavingAccount() {
	num--;
	total -= this->balance;
}
void SavingAccount::show()const{
	cout.setf(ios::right, ios::adjustfield);                                                              //�Ҷ��룬�㱣��С�����2λ
	cout.setf(ios::fixed);
	cout.precision(2);
	cout <<setw(17)<< "#" << id << setw(20) << "balance: " << setw(20) << balance << endl;
}
void SavingAccount::record(const Date& date, const double& amount, const string& dec) {
	accumulation = accumulate(date);
	LastDate = date;
	double Amount = floor(amount * 100 + 0.5) / 100;                                                         //����С�������λ
	balance += Amount;
	total += Amount;
	cout.setf(ios::right, ios::adjustfield);
	cout.setf(ios::fixed);
	cout.precision(2);
	date.show();
	cout << "\t#" << id << setw(20) << Amount << setw(20) << balance << setw(10)<<' ';                     //���������ʽ
	cout.setf(ios::left, ios::adjustfield);
	cout << dec << endl;
}
void SavingAccount::deposit(const Date& date, const double& amount, const string& dec) {
	record(date, amount, dec);
}                                                                                                          //���
void SavingAccount::withdraw(const Date& date, const double& amount, const string& dec) {
	if (amount > balance)
		cout << "Error:not enough money!" << endl;
	else
		record(date, -amount, dec);
}                                                                                                          //ȡ��
void SavingAccount::settle(const Date& date) {
	double interest = accumulate(date) * rate / date.distance(Date(date.getYear()-1,1,1));                                                       //������Ϣ
	if (interest != 0)
		record(date, interest, "interest");
	accumulation = 0;
}

