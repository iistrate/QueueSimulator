#ifndef PERSON_H
#define PERSON_H

#include "Item.h"
#include <vector>

class Person {
private:
	Person* m_Next;
	std::vector < Item* > m_Items;
public:
	Person(void) : m_Next(0), m_Items(0) {}
	Person(std::vector < Item* > Items) : m_Next(0), m_Items(Items) {}

	//setters
	void setNext(Person* Person) {
		m_Next = Person;
	}
	//getters
	Person* getNext() {
		return m_Next;
	}
};

#endif //end person.h