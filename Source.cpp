#include <iostream>
#include <string>
#include "event.h"
#include "user.h"
#include "ticket.h"
#include <fstream>
#include <ctime>
#include <cstdlib>

const int Event::MIN_NAME_LENGTH = 3;
const int Event::DATE_LENGTH = 10;
const int Event::TIME_LENGTH = 5;
const int Event::MIN_ID_LENGTH = 10;
const int User::MIN_NAME_LENGTH = 3;
const int User::MIN_AGE = 5;

int main() {
	Event event;
	//std::cout << std::endl << event.generateTicketID();
	event.generateTicketID();
	int numar = event.getNumberOfDigitsInID();
	char* newArray = event.getUniqueID();
	for (int i = 0; i < numar; i++) {
		std::cout << newArray[i];
	}
}