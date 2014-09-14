#include "Queue.h"

//print queue
void Queue::printQueue() {
	const int count = getCount();
	if (count > 0) {
		Person* Navigator = m_First;
		while (Navigator != 0) {
			std::cout << Navigator->getName() << std::endl;
			Navigator = Navigator->getNext();
		}
	}
	else {
		std::cout << "Queue is empty!" << std::endl;
	}
}
void Queue::insert(std::string name) {
	const int count = getCount();
	//if no persons in queue
	if (count == 0) {
		m_First = new Person(name);
		m_count++;
	}
	else {
		Person* Navigator = m_First;
		while (Navigator->getNext() != 0) {
			Navigator = Navigator->getNext();
		}
		Navigator->setNext(new Person(name));
		m_count++;
	}
}
int Queue::remove() {
	int waitingTime = 0;
	const int count = getCount();
	if (count) {
		//no persons in queue
		if (count == 1) {
			//1 person in queue
			waitingTime = m_First->getWaitingTime();
			delete m_First;
		}
		//more than 1 person in queue
		else {
			Person* temp = m_First;
			waitingTime = m_First->getNext()->getWaitingTime();
			m_First = m_First->getNext();
			delete temp;
		}
		//decrement person counter
		m_count--;
	}
	else {
		std::cout << "No persons in queue!" << std::endl;
	}
	return waitingTime;
}
void Queue::increaseWaitingTime() {
	const int count = getCount();
	//if there's persons in the queue
	if (count) {
		Person* Navigator = m_First;
		while (Navigator->getNext() != 0) {
			Navigator->setWaitingTime();
			Navigator = Navigator->getNext();
		}
	}
}