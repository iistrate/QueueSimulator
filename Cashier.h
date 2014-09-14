#ifndef CASHIER_H
#define CASHIER_H

class Cashier {
private:
	int m_speed;
public:
	Cashier(int speed) : m_speed(speed) {}

	int getSpeed(void) {
		return m_speed;
	}
	void setSpeed(int speed) {
		m_speed = speed;
	}
};

#endif // end Cashier.h