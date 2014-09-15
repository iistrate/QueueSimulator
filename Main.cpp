/*
* Queue Simulator
* Author:Ioan George Istrate
*/

#include "Store.h"

int main() {
	Store WalMart(Config::MULTIPLE_CASHIERS_ONE_LINE);
	WalMart.open();
	WalMart.operate();
	return 0;
}