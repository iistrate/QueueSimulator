#include "Store.h"

void Store::operate() {
	//nr of queues and cashiers
	int cashiers = 0;
	int queues = 0;
	//rand seed
	srand(time(0));
	//assign random speed to cashier since we won't have an actual implementation for it, but maybe later we will;
	int cashierSpeed = 0;
	//customers ready to checkout
	int readyToCheckout = 0;

	//this can be replaced by cashier speed ^^
	int serviceTime = 1; 
	int timeWaited = 0;


	//choose from 30;60;120;480
	enum m_maxTicks { TIME_1 = 30, TIME_2 = 60, TIME_3 = 120, TIME_4 = 480 };
	int maxTime = m_maxTicks::TIME_1;

	switch (m_config) {
	//one cashier one queue
	case ONE_CASHIER:
		cashiers = 1;
		queues = 1;
		break;
	case MULTIPLE_CASHIERS_MULTIPLE_LINES:
		cashiers = 3;
		queues = 3;
		break;
	case MULTIPLE_CASHIERS_ONE_LINE:
		cashiers = 3;
		queues = 1;
		break;
	}
	//populate queues and cashiers
	for (int i = 0; i < queues; i++) {
		m_Queues.push_back(new Queue);
	}
	for (int i = 0; i < cashiers; i++) {
		cashierSpeed = rand() % 9 + 1;
		m_Cashiers.push_back(new Cashier(cashierSpeed));
	}
	//while in the store
	do {
		//each tick add from 0 to 2 customers
		readyToCheckout = rand() % 3;

		switch (m_config) {
		//one cashier one queue
		case ONE_CASHIER:
			//distribute customers to one queue
			for (int i = 0; i < readyToCheckout; i++) {
				//config says one cashier one queue ergo access first queue
				m_Queues[0]->insert();
			}
			//remove customers from
			timeWaited = m_Queues[0]->remove();
			m_longestWaiting = timeWaited > m_longestWaiting ? timeWaited : m_longestWaiting;
			m_totalWait += timeWaited;
			//customers served
			m_customers++;
			break;
		case MULTIPLE_CASHIERS_MULTIPLE_LINES:
			//distribute customers to multiple queues
			for (int i = 0; i < readyToCheckout; i++) {
				//get queue with shortest line add customers there
				int queueIndex = 0;
				int prevQueueSize = 9999;
				for (int j = 0; j < queues; j++) {
					int count = m_Queues[i]->getCount();
					//iterate through queues, get sizes
					if (prevQueueSize > count) {
						prevQueueSize = count;
						//get index
						queueIndex = j;
					}
				}
				m_Queues[queueIndex]->insert();
			}
			//remove customers here
			for (int i = 0; i < cashiers; i++) {
				timeWaited = m_Queues[i]->remove();
				m_longestWaiting = timeWaited > m_longestWaiting ? timeWaited : m_longestWaiting;
				m_totalWait += timeWaited;
				//customers served
				m_customers++;
			}
			break;
		case MULTIPLE_CASHIERS_ONE_LINE:
			//distribute customers to one queue
			for (int i = 0; i < readyToCheckout; i++) {
				//config says one cashier one queue ergo access first queue
				m_Queues[0]->insert();
			}
			//remove customers here
			for (int i = 0; i < cashiers; i++) {
				timeWaited = m_Queues[0]->remove();
				m_longestWaiting = timeWaited > m_longestWaiting ? timeWaited : m_longestWaiting;
				m_totalWait += timeWaited;
				//customers served
				m_customers++;
			}
			break;
		}		
		if (m_debug) {
			//get size for first queue
			std::cout << "Queue size: " << m_Queues[0]->getCount() << std::endl;
		}
		//each tick that passes a person has waited for 1 extra minute
		//get each queue
		for (int i = 0; i < m_Queues.size(); i++) {
			//get each person in a queue and increase their time
			m_Queues[i]->increaseWaitingTime();
		}
		m_ticks++;
		tickCap(maxTime);
	} while (m_running);

	std::cout << "Store opened for: " << m_ticks << " minutes" << std::endl;
	std::cout << "Store served: " << m_customers << " customers" << std::endl;
	std::cout << "Store still waiting to be served: " << m_Queues[0]->getCount() << " customers" << std::endl;
	std::cout << "Longest time a customer had to wait: " << m_longestWaiting << " minutes" << std::endl;
	averageTimes();
	std::cout << "Average time a customer had to wait: " << m_averageWait << " minutes" << std::endl;
	system("pause");

	/*
		* Debug
	*/
	if (m_debug) {
		//debugging linked list
		Queue QueueSLine;
		QueueSLine.insert("Ioan");
		QueueSLine.insert("Aura");
		QueueSLine.insert("Banel");
		QueueSLine.remove();
		QueueSLine.printQueue();

		std::cout << "Nr of cashiers: " << m_Cashiers.size() << std::endl;
		std::cout << "Nr of queues: " << m_Queues.size() << std::endl;
	}
}