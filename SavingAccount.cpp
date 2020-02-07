#include<iostream>
#include<cmath>
#include <iomanip>
#include"SavingAccount.h"
using namespace std;

double SavingAccount::total = 0.0;                               //定义静态变量必须在命名空间域的某个地方使用类名限定定义性声明
unsigned SavingAccount::num = 0;

SavingAccount::SavingAccount(const unsigned& date, const unsigned& id, const double& rate):LastDate(date),id(id),balance(0.0),rate(rate),accumulation(0){
	num++;
	cout << date << "\t#" << id << " is created" << endl;
}
SavingAccount::~SavingAccount() {
	num--;
}
void SavingAccount::show()const{
	cout.setf(ios::right, ios::adjustfield);              //右对齐，恒保持小数点后2位
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "\t#" << id << setw(20) << "balance: " << setw(20) << balance << endl;
}
void SavingAccount::record(const unsigned& date, const double& amount) {
	accumulation = accumulate(date);
	LastDate = date;
	double Amount= floor(amount * 100 + 0.5) / 100;              //保留小数点后两位
	balance += Amount;                            
	total+= Amount;
	cout.setf(ios::right, ios::adjustfield);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << date << "\t#" << id << setw(20) << Amount << setw(20) << balance << endl;
}
void SavingAccount::deposit(const unsigned& date, const double& amount) { 
	record(date, amount);
}                     //存款
void SavingAccount::withdraw(const unsigned& date, const double& amount) {
	if (amount > balance)
		cout << "Error:not enough money!" << endl;
	else
		record(date, -amount);
}                     //取款
void SavingAccount::settle(const unsigned& date) {
	double interest = accumulate(date) * rate / 365;             //计算年息
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

