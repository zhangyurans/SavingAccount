#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<string>
#include"Date.h"
class SavingAccount {                                                                          //���ڴ����˻���
public:
	SavingAccount(const Date& date, const std::string& id, const double& rate);
	~SavingAccount();
	const std::string &getID()const { return id; }                                                       //����˺�
	double getBalance()const { return balance; }
	double getRate()const { return rate; }
	void show()const;                                                                          //��ʾ�˻���Ϣ
	void deposit(const Date& date, const double& amount, const std::string& dec);                                   //���
	void withdraw(const Date& date, const double& amount, const std::string& dec);                                 //ȡ��
	void settle(const Date& date);                                          //������Ϣ��ÿ��1��1�յ���һ�κ���
	static double getTotal() { return total; }                                                 //��ʾ�����˻��ܽ��
	static unsigned getNum() { return num; }                                                   //��ʾ�˻��ܸ���
private:
	std::string id;                                                                               //�˺�
	double balance;                                                                            //���
	double rate;                                                                               //������
	Date LastDate;                                                                         //��һ�����䶯������
	double accumulation;                                                                                          //�ϴμ�����Ϣ���˻������ۻ�ֵ
	void record(const Date& date, const double& amount, const std::string& dec);                                                        //�޸�������䶯
	double accumulate(const Date& date)const { return accumulation + date.distance(LastDate) * balance; }                                                                                          //��ý�ָֹ�������˻������ۻ�ֵ
	static double total;                                                                                            //�����˻��ܽ��
	static unsigned num;                                                                                              //��Ч�˻�����
};
#endif//_SAVING_ACCOUNT_

