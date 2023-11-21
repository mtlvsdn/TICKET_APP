#pragma once

enum class Concession { Standard, Teen = 30, Retired = 40, Child = 50 };

class User {
private:
	std::string name = "John Doe";
	int age = 23;
	std::string emailAddress = "john.doe23@gmail.com";
	Concession concession = Concession::Standard;
	double price = 100;

	//STATIC ATTRIBUTES
	static const int MIN_NAME_LENGTH = 3;
	static const int MIN_AGE = 5;

public:
	//SETTERS
	void setName(std::string newName) {
		if (newName.size() < MIN_NAME_LENGTH) {
			throw std::exception("Name is too short!");
		}
		this->name = newName;
	}
	void setAge(int newAge) {
		if (newAge < MIN_AGE) {
			throw std::exception("Age is too small!");
		}
		this->age = newAge;
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
		else if (this->age >= 64 && newConcession == Concession::Retired) {
			this->concession = newConcession;
		}
		else {
			throw std::exception("Invalid concession!");
		}
		
	}
	//GETTERS
	std::string getrName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	std::string getEmailAddress() {
		return this->emailAddress;
	}
	Concession getConcession() {
		return this->concession;
	}
	//CONSTRUCTORS
	User() {

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

	}
	//OTHER METHODS
	int calculateTicketPrice(Event newEvent) {
		int newPrice = newEvent.getEventPrice() * (int(this->concession) / 100);
		return newPrice;
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