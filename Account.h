#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<string>
#include"Date.h"
class SavingAccount {                                                                          //活期储蓄账户类
public:
	SavingAccount(const Date& date, const std::string& id, const double& rate);
	~SavingAccount();
	const std::string &getID()const { return id; }                                                       //获得账号
	double getBalance()const { return balance; }
	double getRate()const { return rate; }
	void show()const;                                                                          //显示账户信息
	void deposit(const Date& date, const double& amount, const std::string& dec);                                   //存款
	void withdraw(const Date& date, const double& amount, const std::string& dec);                                 //取款
	void settle(const Date& date);                                          //结算利息，每年1月1日调用一次函数
	static double getTotal() { return total; }                                                 //显示所有账户总金额
	static unsigned getNum() { return num; }                                                   //显示账户总个数
private:
	std::string id;                                                                               //账号
	double balance;                                                                            //余额
	double rate;                                                                               //年利率
	Date LastDate;                                                                         //上一次余额变动的日期
	double accumulation;                                                                                          //上次计算利息后账户余额按日累积值
	void record(const Date& date, const double& amount, const std::string& dec);                                                        //修改余额，输出变动
	double accumulate(const Date& date)const { return accumulation + date.distance(LastDate) * balance; }                                                                                          //获得截止指定日期账户余额按日累积值
	static double total;                                                                                            //所有账户总金额
	static unsigned num;                                                                                              //有效账户总数
};
#endif//_SAVING_ACCOUNT_

