#pragma once

enum class Concession { Standard, Teen = 30, Retired = 40, Child = 50 };

class User {
private:
	std::string name = "John Doe";
	char* nameUser = nullptr;
	int age = 17;
	char birthYear[5] = "2000";
	std::string emailAddress = "john.doe23@gmail.com";
	Concession concession = Concession::Standard;
	bool isAdult = false;
	double price = 0;

	//STATIC ATTRIBUTES
	static const int MIN_NAME_LENGTH = 3;
	static const int MIN_AGE = 5;

public:
	//SETTERS
	void setName(std::string newName) {
		if (newName.length() > MIN_NAME_LENGTH) {
			throw std::exception("Name is too short!");
		}
		this->name = newName;
	}
	void setNameUser(char* newNameUser) {
		if (this->nameUser != NULL) {
			delete[] this->nameUser;
		}
		this->nameUser = new char[strlen(newNameUser) + 1];
		strcpy_s(this->nameUser, strlen(newNameUser) + 1, newNameUser);
	}
	void setAge(int newAge) {
		if (newAge < MIN_AGE) {
			throw std::exception("Age is too small!");
		}
		this->age = newAge;
	}
	void setBirthYear(char newBirthYear[5]) {
		if (strlen(newBirthYear) > 6) {
			throw std::exception("The length of the year is to high!");
		}
		strcpy_s(this->birthYear, newBirthYear);
		/*for (int i = 0; i < 4; i++) {
			this->birthYear[i] = newBirthYear[i];
		}*/
	}
	void setEmailAddress(std::string newEmailAddress) {
		//validation
		if (newEmailAddress.find("@") == std::string::npos) {
			throw std::exception("Invalid email address");
		}
		this->emailAddress = newEmailAddress;
	}
	void setConcession(Concession newConcession) {
		if (this->age < 18 && newConcession == Concession::Child) {
			this->concession = newConcession;
		}
		else if (this->age >= 18 && this->age <= 26 && newConcession == Concession::Teen) {
			this->concession = newConcession;
		}
		else if (this->age >= 27 && this->age <= 64 && newConcession == Concession::Standard) {
			this->concession = newConcession;
		}
		else if (this->age >= 65 && newConcession == Concession::Retired) {
			this->concession = newConcession;
		}
		else {
			throw std::exception("Invalid concession!");
		}
		
	}
	void setAdult() {
		if (this->age < 18) {
			throw std::exception("User is underaged!");
		}
		this->isAdult = true;
	}
	//GETTERS
	std::string getName() {
		return this->name;
	}
	char* getNameUser() {
		char* newArray = new char[strlen(this->nameUser) + 1];
		strcpy_s(newArray, strlen(this->nameUser) + 1, this->nameUser);
		return newArray;
	}
	int getAge() {
		return this->age;
	}
	const char* getBirthYear() const {
		return this->birthYear;
	}
	std::string getEmailAddress() {
		return this->emailAddress;
	}
	Concession getConcession() {
		return this->concession;
	}
	bool getAdult() {
		return this->isAdult;
	}
	//CONSTRUCTORS
	User() {

	}
	User(std::string newName, int newAge) {
		setName(newName);
		setAge(newAge);
	}
	User(std::string newName, int newAge, std::string newEmailAddress, Concession newConcession) {
		setName(newName);
		setAge(newAge);
		setEmailAddress(newEmailAddress);
		setConcession(newConcession);
	}
	//COPY CONSTRUCTOR
	User(const User& newUser) {
		this->name = newUser.name;
		this->age = newUser.age;
		this->emailAddress = newUser.emailAddress;
		this->concession = newUser.concession;
	}
	//DESTRUCTORS
	~User() {
		delete[] this->nameUser;
	}
	//OTHER METHODS
	void calculateTicketPrice(Event newEvent) {
		this->price = newEvent.getEventPrice() * (int(this->concession) / 100);
		//return newPrice;
	}
	float howMuchConcessionDoIHave() {
		if (this->age < 18) {
			std::cout << std::endl << "You have 50% discount";
		}
		else if (this->age >= 18 && this->age <= 26) {
			std::cout << std::endl << "You have 30% discount";
		}
		else if (this->age >= 27 && this->age <= 64) {
			std::cout << std::endl << "You have no discount";
		}
		else if (this->age >= 64) {
			std::cout << std::endl << "You have 50% discount";
		}

	}
	//OVERLOADING OPERATORS (each class 2 different overloaded operators)
	//operator =
	User operator=(const User& source) {
		this->setName(source.name);
		this->setAge(source.age);
		this->setEmailAddress(source.emailAddress);
		this->setConcession(source.concession);
		return source;
	}
	//operator << (cout)
	friend std::ostream& operator<<(std::ostream& console, const User& newUser);
	//operator >> (cin)
	friend std::istream& operator>>(std::istream& console, User& newUser);
	//operator ++
	void operator++() {
		this->age++;
	}
	//operator <
	bool operator<(const User& newUser) {
		if (this->age < newUser.age) {
			return true;
		}
		else {
			return false;
		}
	}
	//operator []
	char& operator[](int index) {
		if (index < 0 || index > strlen(this->nameUser)) {
			throw std::exception("The index you are trying to provide for the Array is invalid!");
		}
		return this->nameUser[index];
	}
	//cast operator
	operator int() const {
		int c0 = static_cast<int>(this->birthYear[0]);
		int c1 = static_cast<int>(this->birthYear[1]);
		int c2 = static_cast<int>(this->birthYear[2]);
		int c3 = static_cast<int>(this->birthYear[3]);
		return c0 * 1000 + c1 * 100 + c2 * 10 + c3;
	}
	//operator ==
	bool operator==(User& newUser) {
		if (this->name == newUser.name) {
			return true;
		}
		else {
			return false;
		}
	}
	//oprator !
	bool operator!() {
		return !this->isAdult;
	}
	virtual void virtualMethodForUser1() {
		std::cout << "This is the 1st overriden virtual method for the User class" << std::endl;
	}
	virtual void virtualMethodForUser2() {
		std::cout << "This is the 2nd overriden virtual method for the User class" << std::endl;
	}
};

//operator << (cout)
std::ostream& operator<<(std::ostream& console, const User& newUser) {
	console << "Name: " << newUser.name;
	console << "Age: " << newUser.age;
	console << "Email Address: " << newUser.emailAddress;
	//console << "Concession: " << newUser.concession;
	return console;
}
//operator >> (cin)
std::istream& operator>>(std::istream& console, User& newUser) {
	std::string variable;
	console >> variable;
	newUser.setName(variable);
	int number;
	console >> number;
	newUser.setAge(number);
	console >> variable;
	newUser.setEmailAddress(variable);
	return console;
}

class UserMessage : public User {
	std::string happyMessage = "Have fun at your event!";
public:
	void setHappyMesssage(std::string newMessage) {
		if (newMessage.length() < 5) {
			throw std::exception("Invalid message!");
		}
		this->happyMessage = newMessage;
	}
	std::string getHappyMessage() {
		return this->happyMessage;
	}
	UserMessage() : User(){

	}
};

class ChildClassForUser : public User {
public:
	void virtualMethodForUser1() override {
		std::cout << "This is the 1st overriden virtual method for the User class" << std::endl;
	}
	void virtualMethodForUser2() override {
		std::cout << "This is the 2nd overriden virtual method for the User class" << std::endl;
	}
};