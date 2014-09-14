#ifndef ITEM_H
#define ITEM_H

enum items {
	TOOTHBRUSH,
	SOAP,
	PORK_CHOPS,
	WATER_12oz
};

class Item {
private:
	const int m_name;
public:
	Item(const int name) : m_name(name) {}

	/*
	*	Inline functions
	*/
	//getters
	const int getItemName(void) {
		return m_name;
	}
};

#endif