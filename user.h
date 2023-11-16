#pragma once

enum class Concession { Standard, Teen = 30, Child = 50, Retired = 50 };

class User {
private:
	std::string name;
	int age;
	std::string emailAddress;
	Concession concession;

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
};