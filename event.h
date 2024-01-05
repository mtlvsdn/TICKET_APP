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
	std::string location = "Bucharest";
	std::string venue = "Romexpo";
	std::string name = "Event Name";
	char* nameEvent = nullptr;
	std::string date = "20/01/2011";
	std::string time = "20:00";
	char year[5] = "2010";
	const int eventPrice = 0;
	bool isBigEvent = false;

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
	void setLocation(std::string newlocation) {
		if (newlocation.size() > 50) {
			throw std::exception("Name of the location is too long!");
		}
		this->location = newlocation;
	}
	void setVenue(std::string newVenue) {
		if (newVenue.size() > 50) {
			throw std::exception("Name of the venue is too long!");
		}
		this->location = newVenue;
	}
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
		if (newDate.size() > DATE_LENGTH + 1) {
			throw std::exception("Date length is invalid!");
		}
		this->date = newDate;
	}
	void setTime(std::string newTime) {
		if (newTime.size() > 6) {
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
		//this->eventPrice = newEventPrice;
	}
	void setBigEvent() {
		if (this->numberOfRows > 10) {
			this->isBigEvent = true;
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
	std::string getLocation() {
		return this->location;
	}
	std::string getVenue() {
		return this->venue;
	}
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
	bool getBigEvent() {
		return this->isBigEvent;
	}
	//CONSTRUCTOR
	Event(): eventPrice(100) {
		this->setEventType(EventType::Movie);
		this->setNumberOfRows(20);
		this->setNumberOfSeatsPerRow(10);
		this->setLocation("Bucharest");
		this->setVenue("Romexpo");
		this->setName("Name Event");
		this->setDate("20/01/2011");
		this->setTime("20:00");
	}
	Event(EventType newEventType, std::string newName) {
		setEventType(newEventType);
		setName(newName);
	}
	Event(EventType newEventType, int newNumberOfRows, int newNumberOfSeatsPerRow, std::string newName) {
		setEventType(newEventType);
		setNumberOfRows(newNumberOfRows);
		setNumberOfSeatsPerRow(newNumberOfSeatsPerRow);
		setName(newName);
		setBigEvent();
	}
	Event(EventType newEventType, std::string newName, std::string newLocation, std::string newVenue, std::string newDate, std::string newTime, int newNumberOfRows, int newNumberOfSeatsPerRow, int newEventPrice) : eventPrice(newEventPrice) {
		setEventType(newEventType);
		setName(newName);
		setLocation(newLocation);
		setVenue(newVenue);
		setDate(newDate);
		setTime(newTime);
		setVenue(newVenue);
		setNumberOfRows(newNumberOfRows);
		setNumberOfSeatsPerRow(newNumberOfSeatsPerRow);
		//setEventPrice(newEventPrice);
	}
	//COPY CONSTRUCTOR
	Event(const Event& newEvent): eventPrice(newEvent.eventPrice + this->eventPrice) {
		this->eventType = newEvent.eventType;
		this->numberOfRows = newEvent.numberOfRows;
		this->numberfOfSeatsPerRow = newEvent.numberfOfSeatsPerRow;
		this->name = newEvent.name;
		this->date = newEvent.date;
		this->time = newEvent.time;
		this->setEventPrice(newEvent.eventPrice);
	}
	//MyClass(const MyClass& other, int additionalVariable)
	//	: myVariable(other.myVariable + additionalVariable) {
	//	// Additional copy construction code if needed
	//}
	//DESTRUCTOR
	~Event() {
		delete[] this->nameEvent;
	}
	//OTHER METHODS
	int maximumNumberOfSeats() {
		return getNumberOfRows() * getNumberOfSeatsPerRow();
	}
	std::string isTheEventBig() {
		if (isBigEvent == true) {
			return "This is considered a big event!. A big event is considered one with a venue with more than 10 rows of seatings. Please be aware of pick-pocketers at such big events and always pay attention at your belongings!";
		}
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
	//operator []
	char& operator[](int index) {
		if (index < 0 || index > strlen(this->nameEvent)) {
			throw std::exception("The index of the Array is invalid!");
		}
		return this->nameEvent[index];
	}
	//cast operator
	operator int() const {
		int c0 = static_cast<int>(this->year[0]);
		int c1 = static_cast<int>(this->year[1]);
		int c2 = static_cast<int>(this->year[2]);
		int c3 = static_cast<int>(this->year[3]);
		return c0 * 1000 + c1 * 100 + c2 * 10 + c3;
	}
	//operator++
	void operator++() {
		this->numberOfRows++;
	}
	//operator!
	bool operator!() {
		return !this->isBigEvent;
	}
	virtual void virtualMethodForEvent1() {
		std::cout << "This is the 1st virtual method for the User class" << std::endl;
	}
	virtual void virtualMethodForEvent2() {
		std::cout << "This is the 2nd virtual method for the User class" << std::endl;
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

class ChildClassForEvent : public Event {
public:
	void virtualMethodForEvent1() override {
		std::cout << "This is the 1st overriden virtual method for the User class" << std::endl;
	}
	void virtualMethodForEvent2() override {
		std::cout << "This is the 2nd overriden virtual method for the User class" << std::endl;
	}
};