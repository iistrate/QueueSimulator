#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "Queue.h"
#include "Cashier.h"

enum Config {
	ONE_CASHIER,
	MULTIPLE_CASHIERS_ONE_LINE,
	MULTIPLE_CASHIERS_MULTIPLE_LINES
};

class Store {
private:
	bool m_running;
	const int m_config;
	bool m_debug;
	int m_customers;

	std::vector < Cashier* > m_Cashiers;
	std::vector < Queue* > m_Queues;
public:
	Store(void) : m_running(false), m_config(Config::ONE_CASHIER), m_debug(false) {}
	Store(const int config) : m_running(false), m_config(config), m_debug(false) {}

	//contains loop
	void operate(void);
	/*
	 * Inline Funcitons
	*/
	void open(void) {
		m_running = true;
	}
	void close(void) {
		m_running = false;
	}
};

#endif //end Store.h