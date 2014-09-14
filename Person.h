#ifndef PERSON_H
#define PERSON_H

#include "Item.h"
#include <vector>
#include <string>

class Person {
	friend class Queue;
private:
	Person* m_Next;
	std::vector < Item* > m_Items;
	int m_speed;
	std::string m_name;
	int m_waiting;
public:
	//Default
	Person(std::string name = "") : m_Next(0), m_Items(0), m_speed(0), m_name(name), m_waiting(0) {}
	//Person with Items
	Person(std::vector < Item* > Items, std::string name = "") : m_Next(0), m_Items(Items), m_speed(0), m_name(name), m_waiting(0) {}
	//Person with Items and speed
	Person(std::vector < Item* > Items, int speed, std::string name = "") : m_Next(0), m_Items(Items), m_speed(speed), m_name(name), m_waiting(0) {}
	//Person without Items but known speed
	Person(int speed, std::string name = "") : m_Next(0), m_Items(0), m_speed(speed), m_name(name), m_waiting(0) {}

	/*
	 *	Inline functions
	*/
	//setters
	void setNext(Person* Person) {
		m_Next = Person;
	}
	void setWaitingTime() {
		m_waiting++;
	}
	//getters
	Person* getNext(void) {
		return m_Next;
	}
	std::vector < Item* > getItems(void) {
		return m_Items;
	}
	std::string getName() {
		return m_name;
	}
	int getWaitingTime() {
		return m_waiting;
	}
};

#endif //end person.h