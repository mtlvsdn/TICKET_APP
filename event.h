#pragma once
#include <fstream>
#include <ctime>
#include <cstdlib>

enum class ZoneType { Category1, Category2, VIP, Tribune };
enum class EventType {Movie, Theater, Match};

class Event {
private:
	//LOCATION
	EventType eventType = EventType::Movie;
	int numberOfRows = 0;
	int numberfOfSeatsPerRow = 0;
	ZoneType zone = ZoneType::Category1;
	//CHARACTERISTICS OF THE EVENT
	std::string name = "Event Name";
	std::string date = "20/01/2011";
	std::string time = "20:00";
	int numberOfDigitsInID = 10; //trebuie initializat??
	char* uniqueID = nullptr;
	const int eventPrice = 0;

	//STATIC ATTRIBUTES
	static const int MIN_NAME_LENGTH = 3;
	static const int DATE_LENGTH = 10;
	static const int TIME_LENGTH = 5;
	static const int MIN_ID_LENGTH = 10;

public:
	//SETTERS LOCATION
	void setEventType(EventType newEventType) {
		this->eventType = newEventType;
	}
	void setNumberOfRows(int newNumberOfRows) {
		if (newNumberOfRows <= 0) {
			throw std::exception("Number of Rows cannot be negative!");
		}
		this->numberOfRows = newNumberOfRows;
	}
	void setNumberOfSeatsPerRow(int newNumberOfSeatsPerRow) {
		if (newNumberOfSeatsPerRow <= 0) {
			throw std::exception("Number of Seats cannot be negative!");
		}
		this->numberfOfSeatsPerRow = newNumberOfSeatsPerRow;
	}
	void setZone(ZoneType newZone) {
		if (this->eventType == EventType::Match && (this->zone == ZoneType::Category1 || this->zone == ZoneType::Category2)) {
			throw std::exception("Zone type for matches can be only VIP and Tribune");
		}
		this->zone = newZone;
	}
	//SETTERS CHARACTERISTICS OF THE EVENT
	void setName(std::string newName) {
		if (newName.size() < MIN_NAME_LENGTH) {
			throw std::exception("Name length is too short!");
		}
		this->name = newName;
	}
	void setDate(std::string newDate) {
		if (newDate.size() != DATE_LENGTH) {
			throw std::exception("Date length is invalid!");
		}
		this->date = newDate;
	}
	void setTime(std::string newTime) {
		if (newTime.size() != 5) {
			throw std::exception("Time length is invalid!");
		}
		this->time = newTime;
	}
	void setNumberOfDigitsInID(int newNumberOfDigitsInID) {
		if (newNumberOfDigitsInID < MIN_ID_LENGTH) {
			throw std::exception("Length of ID is to short!");
		}
	}
	void setUniqueID(char* newUniqueID) {
		std::ifstream file("allTicketIDs.txt");
		std::string line;
		while (file >> line) {
			if (line == newUniqueID) {
				file.close();
				throw std::exception("ID cannot be set because it is not unique!");
			}
		}
		char* newArray = new char[strlen(newUniqueID) + 1];
		for (int i = 0; i < strlen(newUniqueID) + 1; i++) {
			newArray[i] = newUniqueID[i];
		}
		this->uniqueID = newArray;
		file.close();
	}
	void setEventPrice(const int newEventPrice) {
		if (newEventPrice < 0) {
			throw std::exception("Price cannot have a negative value!");
		}
	}
	//GETTERS LOCATION
	EventType getEventType() {
		return this->eventType;
	}
	int getNumberOfRows() {
		return this->numberOfRows;
	}
	int getNumberOfSeatsPerRow() {
		return this->numberfOfSeatsPerRow;
	}
	ZoneType getZone() {
		return this->zone;
	}
	//GETTERS CHARACTERISTICS OF THE EVENT
	std::string getName() {
		return this->name;
	}
	std::string getDate() {
		return this->date;
	}
	std::string getTime() {
		return this->time;
	}
	int getNumberOfDigitsInID() {
		return this->numberOfDigitsInID;
	}
	char* getUniqueID() {
		char* newArray = new char[static_cast<size_t>(this->numberOfDigitsInID) + 1];
		for (int i = 0; i < this->numberOfDigitsInID; i++) {
			newArray[i] = this->uniqueID[i];
		}
		return newArray;
	}
	int getEventPrice() const {
		return this->eventPrice;
	}
	//CONSTRUCTOR
	Event(): eventPrice(100) {
		this->setEventType(EventType::Movie);
		this->setNumberOfRows(20);
		this->setNumberOfSeatsPerRow(10);
		this->setZone(ZoneType::Category1);
		this->setName("Name Event");
		this->setDate("20/01/2011");
		this->setTime("20:00");
		//unique id & id length??
	}
	//DESTRUCTOR
	~Event() {
		delete[] this->uniqueID;
	}
	//OTHER METHODS
	int maximumNumberOfSeats() {
		return getNumberOfRows() * getNumberOfSeatsPerRow();
	}
	void generateTicketID() {
		int randomNumber = rand() % 1000;
		long long newUniqueID = static_cast<long long>(std::time(0)) * 1000 + randomNumber;
		long long copy = newUniqueID;
		int newNumberOfDigits = 0;

		while (copy != 0) {
			newNumberOfDigits++;
			copy = copy / 10;
		}
		this->setNumberOfDigitsInID(newNumberOfDigits);
		char* newArray = new char[newNumberOfDigits + 1];
		for (int i = 0; i < newNumberOfDigits; i++) {
			newArray[i] = static_cast<char>(newUniqueID % 10) + '0';
			newUniqueID /= 10;
		}
		this->setUniqueID(newArray);
	}
	//OVERLOADING OPERATORS (each class 2 different overloaded operators)

};