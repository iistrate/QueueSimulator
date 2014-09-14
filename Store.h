#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "Queue.h"
#include "Cashier.h"

class Store {
private:
	bool m_running;
	std::vector < Cashier* > m_Cashiers;
	std::vector < Queue* > m_Queues;
public:
	Store(void) : m_running(false) {}

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