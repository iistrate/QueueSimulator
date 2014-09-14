#include <iostream>

#include "Queue.h"

int main() {
	Queue QueueSLine;
	QueueSLine.insert("Ioan");
	QueueSLine.insert("Aura");
	QueueSLine.insert("Banel");
	QueueSLine.remove();
	QueueSLine.printQueue();
	system("pause");
	return 0;
}