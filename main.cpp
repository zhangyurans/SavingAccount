#include<iostream>
#include"SavingAccount.h"
using namespace std;
namespace {
	const double rate = 0.015;
}
int main() {
	SavingAccount sa0(1, 237, rate);
	SavingAccount sa1(1, 236, rate);
	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);
	//开户后第90天到了银行计息日，结算所有帐户年息
	sa0.settle(90);
	sa1.settle(90);
	sa0.show();
	sa1.show();
	cout << "Total:" << SavingAccount::getTotal() << endl;
	cout << "Num:" << SavingAccount::getNum() << endl;
	return 0;
}
