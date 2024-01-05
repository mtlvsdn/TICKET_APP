#pragma once

//15 TICKET
class TicketNrOfDigitsInId : public std::exception {
public:
	TicketNrOfDigitsInId(std::string message) : exception(message.c_str()) {

	}
};
//16
class TicketRowNr : public std::exception {
public:
	TicketRowNr(std::string message) : exception(message.c_str()) {

	}
};
//17
class TicketSeatNr : public std::exception {
public:
	TicketSeatNr(std::string message) : exception(message.c_str()) {

	}
};
//18
class TicketPersonalMessage : public std::exception {
public:
	TicketPersonalMessage(std::string message) : exception(message.c_str()) {

	}
};


enum class ZoneType { Category1, Category2, VIP, Tribune };

class Ticket {
	ZoneType zone = ZoneType::Category1;
	int numberOfDigitsInID = 10;
	char* uniqueID = nullptr;
	int rowNumber = 2;
	int seatNumber = 1;
	char personalisedMessage[30] = "Have fun at your event!";
	bool isFirstRow = false;
	long long intId = 0;

	//STATIC ATTRIBUTES
	static const int MIN_ID_LENGTH = 10;
	static int numberOfTickets;

	//METHOD STATIC
	static void setNumberOfTickets() {
		numberOfTickets = 0;
	}
	static void increaseNumberOfTickets() {
		numberOfTickets++;
	}
public:
	//SETTERS
	void setZone(ZoneType newZone) {
		this->zone = newZone;
	}
	void setNumberOfDigitsInID(int newNumberOfDigitsInID) {
		if (newNumberOfDigitsInID < MIN_ID_LENGTH) {
			throw TicketNrOfDigitsInId("Length of ID is to short!");
		}
	}
	void setUniqueID(char* newUniqueID) {
		/*std::ifstream file("allTicketIDs.txt");
		std::string line;
		while (file >> line) {
			if (line == newUniqueID) {
				file.close();
				throw std::exception("ID cannot be set because it is not unique!");
			}
		}*/
		char* newArray = new char[this->numberOfDigitsInID + 1];
		for (int i = 0; i < this->numberOfDigitsInID; i++) {
			newArray[i] = newUniqueID[i];
		}
		//strcpy_s(this->uniqueID, static_cast<rsize_t>(this->numberOfDigitsInID) + 1, newArray);
		delete[] this->uniqueID;
		this->uniqueID = newArray;
		std::cout << std::endl;
		for (int i = 0; i < this->numberOfDigitsInID + 1; i++) {
			std::cout << this->uniqueID[i];
		}
		//file.close();
	}
	void setRowNumber(int newRow) {
		if (newRow < 1) {
			throw TicketRowNr("Seat place cannot be a negative number!");
		}
		this->rowNumber = newRow;
	}
	void setSeatNumber(int newSeat) {
		if (newSeat < 1) {
			throw TicketSeatNr("Seat place cannot be a negative number!");
		}
		this->seatNumber = newSeat;
	}
	void setPersonalisedMessage(const char* newPersonalisedMessage) {
		if (strlen(newPersonalisedMessage) > 30) {
			throw TicketPersonalMessage("Message is too long!");
		}
		strcpy_s(this->personalisedMessage, strlen(newPersonalisedMessage) + 1, newPersonalisedMessage);
	}
	void setFirstRow() {
		this->isFirstRow = true;
	}
	//GETTERS
	ZoneType getZone() {
		return this->zone;
	}
	int getNumberOfDigitsInID() {
		return this->numberOfDigitsInID;
	}
	char* getUniqueID() const {
		//char* newArray = new char[static_cast<size_t>(this->numberOfDigitsInID) + 1];
		////char* newArray = new char[this->numberOfDigitsInID + 1];
		//for (int i = 0; i < this->numberOfDigitsInID; i++) {
		//	newArray[i] = this->uniqueID[i];
		//	std::cout << std::endl << newArray[i] << " ";
		//}
		//std::cout << std::endl << "DISPLAY THIS MESSSAGE";
		//return newArray;
		////return this->uniqueID;

		// int intValue = std::stoi(charPointer);
		return this->uniqueID;
	}
	int getRowNumber() {
		return this->rowNumber;
	}
	int getSeatNumber() {
		return this->seatNumber;
	}
	const char* getPersonalisedMessage() const {
		return this->personalisedMessage;
	}
	bool getIsFirstRow() {
		return this->isFirstRow;
	}
	long long getId() {
		return this->intId;
	}
	//STATIC ATTRIBUTES
	static const int MIN_PRICE = 0;
	//OTHER METHODS
	void generateTicketID() {
		int randomNumber = rand() % 1000;
		long long newUniqueID = static_cast<long long>(std::time(0)) * 1000 + randomNumber;
		long long copy = newUniqueID;
		int newNumberOfDigits = 0;

		while (copy != 0) {
			newNumberOfDigits++;
			copy = copy / 10;
		}
		//this->setNumberOfDigitsInID(newNumberOfDigits);

		/*std::string myString = std::to_string(newUniqueID);
		const char* myChar = myString.c_str();
		char* nonConstChar = const_cast<char*>(myChar);

		this->setUniqueID(nonConstChar);*/

		this->intId = newUniqueID;
		/*std::cout << std::endl << std::endl << "THIS IS A MESSAGE";
		for (int j = 0; j < this->numberOfDigitsInID; j++) {
			std::cout << nonConstChar[j];
		}*/


		/*const char* constString = "Hello, World!";
		char* nonConstString = const_cast<char*>(constString);
		nonConstString[0] = 'h';*/

		/*long long myNumber = 123456789012345LL;
		std::string myString = std::to_string(myNumber);
		const char* myCharPointer = myString.c_str();*/

		////MEMORY ALLOCATION
		//char* newArray = nullptr;// = new char[newNumberOfDigits + 1];
		//if (newArray != nullptr) {
		//	delete[] newArray;
		//}
		//newArray = new char[newNumberOfDigits + 1];
		//for (int i = 0; i < newNumberOfDigits; i++) {
		//	newArray[i] = static_cast<char>(newUniqueID % 10) +'0';
		//	newUniqueID /= 10;
		//}
		//newArray[newNumberOfDigits] = '\0';
		//std::cout << std::endl << std::endl;
		///*for (int i = 0; i < newNumberOfDigits; i++) {
		//	std::cout << newArray[i] << " ";
		//}*/
		//std::cout << std::endl;
		////this->setUniqueID(newArray);
		//delete[] newArray;
	}
	void generateTicketAsTxt() {
		//will allow the generation of nominal tickets according to the
		//  desired characteristics(ex: VIP, lawn, tribune, boxes, etc.) .)

	}
	//CONSTRUCTOR
	Ticket() {
		this->zone = ZoneType::Category1;
		this->numberOfDigitsInID = 10;
		generateTicketID();
		this->rowNumber = 1;
		this->seatNumber = 1;
	}
	Ticket(ZoneType newZone, int newNumberOfDigitsInID, char* newUniqueID) {
		setZone(newZone);
		setNumberOfDigitsInID(newNumberOfDigitsInID);
		setUniqueID(newUniqueID);
	}
	Ticket(ZoneType newZone, int newNumberOfDigitsInID, int newRowNumber, int newSeatNumber) {
		this->zone = newZone;
		this->numberOfDigitsInID = newNumberOfDigitsInID;
		generateTicketID();
		this->rowNumber = newRowNumber;
		this->seatNumber = newSeatNumber;
	}
	//COPY CONSTRUCTOR
	Ticket(const Ticket& newTicket) {
		this->setZone(newTicket.zone);
		this->setNumberOfDigitsInID(newTicket.numberOfDigitsInID);
		this->intId = newTicket.intId;
		//generateTicketID();
		this->rowNumber = newTicket.rowNumber;
		this->seatNumber = newTicket.seatNumber;
	}
	//DESTRUCTOR
	~Ticket() {
		delete[] this->uniqueID;
	}
	//OVERLOADING OPERATORS (each class 2 different overloaded operators)
	//operator =
	Ticket operator=(const Ticket& source) {
		this->zone = source.zone;
		this->numberOfDigitsInID = source.numberOfDigitsInID;
		this->intId = source.intId;
		this->rowNumber = source.rowNumber;
		this->seatNumber = source.seatNumber;
		return source;
	}
	//operator << (cout)
	friend std::ostream& operator<<(std::ostream& console, const Ticket& newTicket);
	//operator >> (cin)
	friend std::istream& operator>>(std::istream& console, Ticket& newTicket);
	//operator >
	bool operator>(const Ticket& source) {
		if (this->rowNumber > source.rowNumber) {
			if (this->seatNumber > source.seatNumber) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	//operator ++
	void operator++() {
		this->seatNumber++;
	}
	//operator []
	char& operator[](int index) {
		if (index < 0 || index > strlen(this->uniqueID)) {
			throw std::exception("The index you are trying to provide for the array is invalid");
		}
		return this->uniqueID[index];
	}
	//cast operator
	operator std::string() const {
		return std::to_string(this->numberOfDigitsInID);
	}
	//operator ==
	bool operator==(Ticket& newTicket) {
		if (this->intId == newTicket.intId) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!() {
		return !this->isFirstRow;
	}

	virtual void virtualMethodForTicket1() {
		std::cout << "This is the 1st virtual method for the Ticket class" << std::endl;
	}
	virtual void virtualMethodForTicket2() {
		std::cout << "This is the 2nd virtual method for the Ticket class" << std::endl;
	}
};

//operator << (cout)
std::ostream& operator<<(std::ostream& console, const Ticket& newTicket) {
	//console << std::endl << "Zone: " << std::to_string(newTicket.zone);
	if (newTicket.zone == ZoneType::Category1) {
		console << std::endl << "Zone: Category1";
	}
	else if(newTicket.zone == ZoneType::Category2) {
		console << std::endl << "Zone: Category2";
	}
	else if (newTicket.zone == ZoneType::VIP) {
		console << std::endl << "Zone: VIP";
	}
	else if (newTicket.zone == ZoneType::Tribune) {
		console << std::endl << "Zone: Tribune";
	}
	//console << std::endl << "Ticket ID: " << newTicket.uniqueID;
	console << std::endl << "Unique ID: " << newTicket.intId;
	console << std::endl << "Row Number: " << newTicket.rowNumber;
	console << std::endl << "Seat Number: " << newTicket.seatNumber;
	console << std::endl << "Personalised Message: " << newTicket.personalisedMessage;
	console << std::endl << "Is the ticket in the first row?: " << newTicket.isFirstRow;
	return console;
}
//operator >> (cin)
std::istream& operator>>(std::istream& console, Ticket& newTicket) {
	console >> newTicket.uniqueID;
	console >> newTicket.rowNumber;
	console >> newTicket.seatNumber;
	return console;
}

class ChildClassForTicket : public Ticket {
public:
	void virtualMethodForTicket1() override {
		std::cout << "This is the 1st overriden virtual method for the Ticket class" << std::endl;
	}
	void virtualMethodForTicket2() override {
		std::cout << "This is the 2nd overriden virtual method for the Ticket class" << std::endl;
	}
};

class AbstractTicket {
public:
	// Pure virtual function
	virtual void pureVirtualFunctionForTheTicket() const = 0;

	// Non-pure virtual function with an implementation
	void nonPureFunctionForTheTicket() const {
		std::cout << "Always attend the events you like!" << std::endl;
	}

	// Virtual destructor (important for polymorphism)
	virtual ~AbstractTicket() {}
};

class ConcreteClass : public AbstractTicket {
private:
	int variable = 0;
public:
	void setVariable(int newVariable) {
		if (variable > 0) {
			throw std::exception("Invalid number! Your number is negative!");
		}
		this->variable = newVariable;
	}
	int getVariable() {
		return this->variable;
	}
	// Implementation of the pure virtual function
	void pureVirtualFunctionForTheTicket() const override {
		std::cout << this->variable << std::endl;
	}
};