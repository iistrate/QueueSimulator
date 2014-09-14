#ifndef PERSON_H
#define PERSON_H

#include "Item.h"
#include <vector>

class Person {
private:
	Person* m_Next;
	std::vector < Item* > m_Items;
	int m_speed;
public:
	//Default
	Person(void) : m_Next(0), m_Items(0), m_speed(0) {}
	//Person with Items
	Person(std::vector < Item* > Items) : m_Next(0), m_Items(Items), m_speed(0) {}
	//Person with Items and speed
	Person(std::vector < Item* > Items, int speed) : m_Next(0), m_Items(Items), m_speed(speed) {}
	//Person without Items but known speed
	Person(int speed) : m_Next(0), m_Items(0), m_speed(speed) {}

	//setters
	void setNext(Person* Person) {
		m_Next = Person;
	}
	//getters
	Person* getNext() {
		return m_Next;
	}
	std::vector < Item* > getItems() {
		return m_Items;
	}
};

#endif //end person.h