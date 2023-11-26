#pragma once

enum class ZoneType { Category1, Category2, VIP, Tribune };

class Ticket {
	ZoneType zone = ZoneType::Category1;
	int numberOfDigitsInID = 10;
	char* uniqueID = nullptr;
	int rowNumber = 2;
	int seatNumber = 1;
	char personalisedMessage[30] = "Have fun at your event!";
	bool isFirstRow = false;

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
	void setRowNumber(int newRow) {
		if (newRow < 1) {
			throw std::exception("Seat place cannot be a negative number!");
		}
		this->rowNumber = newRow;
	}
	void setSeatNumber(int newSeat) {
		if (newSeat < 1) {
			throw std::exception("Seat place cannot be a negative number!");
		}
		this->seatNumber = newSeat;
	}
	void setPersonalisedMessage(const char* newPersonalisedMessage) {
		if (strlen(newPersonalisedMessage) > 30) {
			throw std::exception("Message is too long!");
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
	char* getUniqueID() {
		char* newArray = new char[static_cast<size_t>(this->numberOfDigitsInID) + 1];
		for (int i = 0; i < this->numberOfDigitsInID; i++) {
			newArray[i] = this->uniqueID[i];
		}
		return newArray;
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
		this->setNumberOfDigitsInID(newNumberOfDigits);
		char* newArray = new char[newNumberOfDigits + 1];
		for (int i = 0; i < newNumberOfDigits; i++) {
			newArray[i] = static_cast<char>(newUniqueID % 10) + '0';
			newUniqueID /= 10;
		}
		this->setUniqueID(newArray);
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
		this->seatNumber - newSeatNumber;
	}
	//COPY CONSTRUCTOR
	Ticket(const Ticket& newTicket) {
		this->setZone(newTicket.zone);
		this->setNumberOfDigitsInID(newTicket.numberOfDigitsInID);
		generateTicketID();
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
		this->setUniqueID(source.uniqueID);
		this->rowNumber = source.rowNumber;
		this->seatNumber = source.seatNumber;
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
		if (strcmp(this->uniqueID, newTicket.uniqueID)) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!() {
		return !this->isFirstRow;
	}
};

//operator << (cout)
std::ostream& operator<<(std::ostream& console, const Ticket& newTicket) {
	console << std::endl << "Ticket ID: " << newTicket.uniqueID;
	console << std::endl << "Row Number: " << newTicket.rowNumber;
	console << std::endl << "Seat Number: " << newTicket.seatNumber;
	return console;
}
//operator >> (cin)
std::istream& operator>>(std::istream& console, Ticket& newTicket) {
	console >> newTicket.uniqueID;
	console >> newTicket.rowNumber;
	console >> newTicket.seatNumber;
	return console;
}