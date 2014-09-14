#include "Store.h"

void Store::operate() {
	//rand seed
	srand(time(0));
	int cashierSpeed = rand() % 9 + 1;
	int readyToCheckout = 0;

	switch (m_config) {
	//one cashier one queue
	case ONE_CASHIER:
		m_Queues.push_back(new Queue);
		break;
	case MULTIPLE_CASHIERS_MULTIPLE_LINES:
		//cashiers
		//assign random speed to cashier since we won't have an actual implementation for it, but maybe later we will;
		m_Cashiers.push_back(new Cashier(cashierSpeed));
		m_Cashiers.push_back(new Cashier(cashierSpeed));
		m_Cashiers.push_back(new Cashier(cashierSpeed));
		//queues
		m_Queues.push_back(new Queue);
		m_Queues.push_back(new Queue);
		m_Queues.push_back(new Queue);
		break;
	case MULTIPLE_CASHIERS_ONE_LINE:
		m_Cashiers.push_back(new Cashier(cashierSpeed));
		m_Cashiers.push_back(new Cashier(cashierSpeed));
		m_Cashiers.push_back(new Cashier(cashierSpeed));
		m_Queues.push_back(new Queue);
		break;
	}


	//while in the store
	do {
		//each tick add from 0 to 2 customers
		readyToCheckout = rand() % 2;

	} while (m_running);

	/*
		* Debug
	*/
	if (m_debug) {
		Queue QueueSLine;

		QueueSLine.insert("Ioan");
		QueueSLine.insert("Aura");
		QueueSLine.insert("Banel");
		QueueSLine.remove();
		QueueSLine.printQueue();
	}
}