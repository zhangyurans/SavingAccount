#include<iostream>
#include<cmath>
#include <iomanip>
#include"SavingAccount.h"
using namespace std;

double SavingAccount::total = 0.0;                               //���徲̬���������������ռ����ĳ���ط�ʹ�������޶�����������
unsigned SavingAccount::num = 0;

SavingAccount::SavingAccount(const unsigned& date, const unsigned& id, const double& rate):LastDate(date),id(id),balance(0.0),rate(rate),accumulation(0){
	num++;
	cout << date << "\t#" << id << " is created" << endl;
}
SavingAccount::~SavingAccount() {
	num--;
}
void SavingAccount::show()const{
	cout.setf(ios::right, ios::adjustfield);              //�Ҷ��룬�㱣��С�����2λ
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "\t#" << id << setw(20) << "balance: " << setw(20) << balance << endl;
}
void SavingAccount::record(const unsigned& date, const double& amount) {
	accumulation = accumulate(date);
	LastDate = date;
	double Amount= floor(amount * 100 + 0.5) / 100;              //����С�������λ
	balance += Amount;                            
	total+= Amount;
	cout.setf(ios::right, ios::adjustfield);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << date << "\t#" << id << setw(20) << Amount << setw(20) << balance << endl;
}
void SavingAccount::deposit(const unsigned& date, const double& amount) { 
	record(date, amount);
}                     //���
void SavingAccount::withdraw(const unsigned& date, const double& amount) {
	if (amount > balance)
		cout << "Error:not enough money!" << endl;
	else
		record(date, -amount);
}                     //ȡ��
void SavingAccount::settle(const unsigned& date) {
	double interest = accumulate(date) * rate / 365;             //������Ϣ
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

