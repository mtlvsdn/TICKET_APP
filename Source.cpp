#include <iostream>
#include <string>
#include "event.h"
#include "user.h"
#include "ticket.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>

//const int Event::MIN_NAME_LENGTH = 3;
//const int Event::DATE_LENGTH = 10;
//const int Event::TIME_LENGTH = 5;
//const int Event::MIN_ID_LENGTH = 10;
//const int User::MIN_NAME_LENGTH = 3;
//const int User::MIN_AGE = 5;

void menu() {
	Event myEvent;
	//MENU LAYOUT
	std::cout << std::endl;
	std::cout << "	" << "Ticketing APP";
	std::cout << std::endl << std::endl;
	std::cout << "	1. Buy a Ticket";
	std::cout << std::endl << "	2. Exit";
	std::cout << std::endl << std::endl << "	-> ";

	//USER INPUT
	int choice;
	std::cin >> choice;
	while (true) {
		if (choice == 1 || choice == 2) {
			break;
		}
		std::cin >> choice;
	}

	system("cls");
	//which choice
	if (choice == 1) {
		int numericVar;
		float floatVar;
		std::string stringVar;
		EventType eventVar;
		std::cout << "	Ok, let us gather some information about your desired event";
		std::cout << std::endl;

		//EVENT TYPE
		std::cout << "	What type of event are you interested in?: ";
		std::cin >> stringVar;
		while (true) {
			if (stringVar == "Movie" || stringVar == "movie" || stringVar == "MOVIE") {
				eventVar = EventType::Movie;
				break;
			}
			else if (stringVar == "Theater" || stringVar == "theater" || stringVar == "THEATER") {
				eventVar = EventType::Theater;
				break;
			}
			else if (stringVar == "Match" || stringVar == "match" || stringVar == "MATCH") {
				eventVar = EventType::Match;
				break;
			}
			else {
				std::cout << std::endl << "The type of event you entered does not exist. We offer tickets just for Movies, Theater or Match events. Try entering in one of these event types: ";
				std::cin >> stringVar;
			}
		}
		std::ifstream file;
		std::ofstream choices;
		//OPEN TXT FILE WITH EVENT DATA
		if (eventVar == EventType::Movie) {
			file.open("movieEvents.txt");
		}
		else if (eventVar == EventType::Theater) {
			file.open("theaterEvents.txt");
		}
		else if (eventVar == EventType::Match) {
			file.open("matchEvents.txt");
		}

		//NAME
		std::cout << std::endl << "	What is the name of your event?: ";
		std::cin >> stringVar;
		std::cout << std::endl;
		std::string line;
		int number = 1;
		choices.open("choices.txt");
		while (std::getline(file, line)) {
			std::stringstream ss(line); // Create a stringstream from the line

			std::string token;
			std::vector<std::string> tokens; // Vector to store tokens

			while (std::getline(ss, token, ',')) {
				tokens.push_back(token); // Store each token in the vector
			}
			//for (int i = 0; i < token)

			if (tokens[0] == stringVar) {
				std::cout << "	" << number << ". ";
				choices << number << ",";
				number++;
				for (size_t i = 0; i < tokens.size(); ++i) {
					std::cout << tokens[i] << " ";
					choices << tokens[i] << ",";
				}
				choices << std::endl;
				std::cout << std::endl;
			}
			tokens.clear();
		}
		choices.close();
		file.close();

		//std::cout << std::endl << number << std::endl;
		int ok1 = 1;
		file.open("choices.txt");
		
		std::cout << "	For which of the following do you want to buy a ticket?: ";
		std::cout << std::endl << std::endl;
		std::cout << "	-> ";
		std::cin >> choice;
		while (ok1 == 1) {
			ok1 = 0;
			if (choice >= number || choice < 1) {
				ok1 = 1;
				std::cout << "	The number you entered is incorrect. Please try choosing a valid option: ";
				std::cin >> choice;
			}
		}
		int i = 0;
		while (i < choice) {
			std::getline(file, line);
			i++;
		}
		std::stringstream ss(line);
		std::string tk;
		std::vector<std::string> tks; // Vector to store tokens

		while (std::getline(ss, tk, ',')) {
			tks.push_back(tk); // Store each token in the vector
		}

		for (int j = 0; j < tks.size(); j++) {
			std::cout << " " << tks[j];
		}

		std::cout << std::endl << tks[0];
		int tks6 = std::stoi(tks[6]);
		int tks7 = std::stoi(tks[7]);
		int tks8 = std::stoi(tks[8]);
		Event event(eventVar, tks[1], tks[2], tks[3], tks[4], tks[5], tks6, tks7, tks8);
		std::cout << event;

	}
	else if (choice == 2) {

	}
}

int main() {
	Event event;
	User user;
	//std::cout << std::endl << event.generateTicketID();
	/*event.generateTicketID();
	int numar = event.getNumberOfDigitsInID();
	char* newArray = event.getUniqueID();
	for (int i = 0; i < numar; i++) {
		std::cout << newArray[i];
	}*/
	Ticket ticket1;
	Ticket ticket2;
	while (true) {
		menu();
	}
}