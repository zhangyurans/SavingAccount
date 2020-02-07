#ifndef _SAVING_ACCOUNT_H
#define _SAVING_ACCOUNT_H
class SavingAccount {                                                                          //���ڴ����˻���
public:
	SavingAccount(const unsigned& date, const unsigned& id, const double& rate);
	~SavingAccount();
	unsigned getID()const { return id; }                                                       //����˺�
	double getBalance()const { return balance; }
	double getRate()const { return rate; }
	void show()const;                                                                          //��ʾ�˻���Ϣ
	void deposit(const unsigned& date, const double& amount);                                   //���
	void withdraw(const unsigned& date, const double& amount);                                 //ȡ��
	void settle(const unsigned& date);                                                         //������Ϣ��ÿ��1��1�յ���һ�κ������ڲ����м���ÿ�궼��365�죩
	static double getTotal() { return total; }                                                 //��ʾ�����˻��ܽ��
	static unsigned getNum() { return num; }                                                   //��ʾ�˻��ܸ���
private:
	unsigned id;                                                                               //�˺�
	double balance;                                                                            //���
	double rate;                                                                               //������
	unsigned LastDate;                                                                         //��һ�����䶯������
	double accumulation;                                                                                          //�ϴμ�����Ϣ���˻������ۻ�ֵ
	void record(const unsigned& date, const double& amount);                                                        //�޸�������䶯
	double accumulate(const unsigned& date)const { return accumulation + (date - LastDate) * balance; }                                                                                          //��ý�ָֹ�������˻������ۻ�ֵ
	static double total;                                                                                            //�����˻��ܽ��
	static unsigned num;                                                                                              //��Ч�˻�����
};
#endif//_SAVING_ACCOUNT_

