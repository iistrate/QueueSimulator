#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "Person.h"

class Queue {
private:
	Person* m_First;
	int m_count;
public:
	Queue(void) : m_First(0), m_count(0) {}

	//print queue
	void printQueue(void);
	//add persons to queue
	void insert(std::string name = "");
	//remove first person in queue, return waiting time
	int remove(void);
	//increase time waited for each person in the queue
	void increaseWaitingTime(void);

	/*
	*	Inline functions
	*/
	//getters
	int getCount(void) {
		return m_count;
	}

};

#endif // end Queue.h