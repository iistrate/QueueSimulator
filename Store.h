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

	//time
	int m_ticks;
	int m_maxTicks[4];
	int m_longestWaiting;
	float m_averageWait;

	//composition
	std::vector < Cashier* > m_Cashiers;
	std::vector < Queue* > m_Queues;
public:
	Store(void) : m_running(false), m_config(Config::ONE_CASHIER), m_debug(false), m_ticks(0), m_longestWaiting(0), m_averageWait(0) {}
	Store(const int config) : m_running(false), m_config(config), m_debug(false), m_ticks(0), m_longestWaiting(0), m_averageWait(0) {}

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
	void tickCap(int time) {
		if (time == m_ticks) {
			close();
		}
	}
	void averageTimes(int time, bool compute = false) {
		static int counter = 1;
		static int sum = 0;
		sum += time;
		counter++;
		if (compute) {
			m_averageWait = sum / counter;
			std::cout << sum << " " << counter << std::endl;
		}
	}
};

#endif //end Store.h