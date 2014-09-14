#ifndef STORE_H
#define STORE_H

#include <iostream>
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

	std::vector < Cashier* > m_Cashiers;
	std::vector < Queue* > m_Queues;
public:
	Store(void) : m_running(false), m_config(Config::ONE_CASHIER) {}
	Store(const int config) : m_running(false), m_config(config) {}

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