#pragma once
#include <fstream>
#include <ctime>
#include <cstdlib>

enum class EventType {Movie, Theater, Match};

class Event {
private:
	//LOCATION
	EventType eventType = EventType::Movie;
	int numberOfRows = 0;
	int numberfOfSeatsPerRow = 0;
	//CHARACTERISTICS OF THE EVENT
	std::string name = "Event Name";
	char* nameEvent = nullptr;
	std::string date = "20/01/2011";
	std::string time = "20:00";
	char year[5] = "2010";
	const int eventPrice = 0;

	//STATIC ATTRIBUTES
	static const int MIN_NAME_LENGTH = 3;
	static const int DATE_LENGTH = 10;
	static const int TIME_LENGTH = 5;

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
	//SETTERS CHARACTERISTICS OF THE EVENT
	void setName(std::string newName) {
		if (newName.size() < MIN_NAME_LENGTH) {
			throw std::exception("Name length is too short!");
		}
		this->name = newName;
	}
	void setNameEvent(char* newNameEvent) {
		if (this->nameEvent != NULL) {
			delete[] this->nameEvent;
			this->nameEvent = new char[strlen(newNameEvent) + 1];
		}
		strcpy_s(this->nameEvent, strlen(newNameEvent) + 1, newNameEvent);
		/*for (int i = 0; i < strlen(newNameEvent); i++) {
			this->nameEvent[i] = newNameEvent[i];
		}*/
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
	void setYear(const char* newYear) {
		//char newArray[5];
		//if (this->year != NULL) {
		//	delete[] this->year;
		//}
		if (strlen(newYear) > 5) {
			throw std::exception("The length of the year is to high!");
		}
		for (int i = 0; i < 5; i++) {
			this->year[i] = newYear[i];
		}
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
	//GETTERS CHARACTERISTICS OF THE EVENT
	std::string getName() {
		return this->name;
	}
	char* getNameEvent() {
		char* newArray = new char[strlen(this->nameEvent) + 1];
		for (int i = 0; i < strlen(this->nameEvent) + 1; i++) {
			newArray[i] = this->nameEvent[i];
		}
		return newArray;
	}
	std::string getDate() {
		return this->date;
	}
	std::string getTime() {
		return this->time;
	}
	const char* getYear() const {
		return this->year;
	}
	int getEventPrice() const {
		return this->eventPrice;
	}
	//CONSTRUCTOR
	Event(): eventPrice(100) {
		this->setEventType(EventType::Movie);
		this->setNumberOfRows(20);
		this->setNumberOfSeatsPerRow(10);
		this->setName("Name Event");
		this->setDate("20/01/2011");
		this->setTime("20:00");
	}
	//COPY CONSTRUCTOR
	Event(const Event& newEvent) {
		this->eventType = newEvent.eventType;
		this->numberOfRows = newEvent.numberOfRows;
		this->name = newEvent.name;
		this->date = newEvent.date;
		this->time = newEvent.time;
		this->setEventPrice(newEvent.eventPrice);
	}
	//DESTRUCTOR
	~Event() {

	}
	//OTHER METHODS
	int maximumNumberOfSeats() {
		return getNumberOfRows() * getNumberOfSeatsPerRow();
	}
	//OVERLOADING OPERATORS (each class 2 different overloaded operators)
	//operator =
	Event operator=(const Event& source) {
		this->eventType = source.eventType;
		this->numberOfRows = source.numberOfRows;
		this->numberfOfSeatsPerRow = source.numberfOfSeatsPerRow;
		this->name = source.name;
		this->date = source.date;
		this->time = source.time;
		this->setEventPrice(source.eventPrice);
	}
	//operator << (cout)
	friend std::ostream& operator<<(std::ostream& console, const Event& newEvent);
	//operator >> (cin)
	friend std::istream& operator>>(std::istream& console, Event& newEvent);
	//operator >=
	bool operator>=(Event& newEvent) {
		if (this->eventPrice > newEvent.eventPrice) {
			return true;
		}
		else
		{
			return false;
		}
	}
	//operator ==
	bool operator==(Event& newEvent) {
		if (this->date == newEvent.date) {
			return true;
		}
		else {
			return false;
		}
	}
	
};

//operator << (cout)
std::ostream& operator<<(std::ostream& console, const Event& newEvent) {
	console << std::endl << "Number Of Rows: " << newEvent.numberOfRows;
	console << std::endl << "Number of Seats per Row: " << newEvent.numberfOfSeatsPerRow;
	console << std::endl << "Name: " << newEvent.name;
	console << std::endl << "Date: " << newEvent.date;
	console << std::endl << "Time: " << newEvent.time;
	console << std::endl << "Event Price: " << newEvent.eventPrice;
	return console;
}
//operator >> (cin)
std::istream& operator>>(std::istream& console, Event& newEvent) {
	console >> newEvent.numberOfRows;
	console >> newEvent.numberfOfSeatsPerRow;
	console >> newEvent.name;
	console >> newEvent.date;
	console >> newEvent.time;
	return console;
}