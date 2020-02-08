#include<iostream>
#include"Account.h"
using namespace std;
namespace {
	const double rate = 0.015;
}
int main() {
	Date date(2018, 11, 1);
	SavingAccount sa[] = { SavingAccount(date, "04016237", rate),SavingAccount(date, "04016236", rate) };
	sa[0].deposit(Date(2018, 11, 5), 5000,"salary");
	sa[1].deposit(Date(2018, 11, 25), 10000,"sell stock 0323");
	sa[0].deposit(Date(2018, 12, 15), 5500,"salary");
	sa[1].withdraw(Date(2018, 12, 30), 4000,"buy a laptop");
	//开户后第90天到了银行计息日，结算所有帐户年息
	for (size_t i = 0; i < sizeof(sa) / sizeof(sa[0]); i++) {
		sa[i].settle(Date(2019, 1, 1));
		sa[i].show();
	}

	cout << "Total:" << SavingAccount::getTotal() << endl;
	cout << "Num:" << SavingAccount::getNum() << endl;
	return 0;
}
