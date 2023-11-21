#pragma once
class Ticket {
	Event event;
	User user;
	int price;

	//SETTERS
	void setEvent(const Event& newEvent) {
		this->event = newEvent;
	}
	void setUser(const User& newUser) {
		this->user = newUser;
	}
	void setPrice(int newPrice) {
		if (newPrice < MIN_PRICE) {
			throw std::exception("Price is invalid!");
		}
		int discount;
		switch (user.getConcession()) {
		case Concession::Standard:
			discount = 0;
			break;
		case Concession::Teen:
			discount = 0.3;
			break;
		case Concession::Retired:
			discount = 0.4;
			break;
		case Concession::Child:
			discount = 0.5;
			break;
		}
		this->price = newPrice + newPrice * discount;
	}

	//GETTERS
	Event getEvent() {
		return this->event;
	}
	User getUser() {
		return this->user;
	}
	int getPrice() {
		return this->price;
	}

	//STATIC ATTRIBUTES
	static const int MIN_PRICE = 0;

	void generateTicketAsTxt() {
		//will allow the generation of nominal tickets according to the
		//  desired characteristics(ex: VIP, lawn, tribune, boxes, etc.) .)
		 
	}
	void downloadTicket() {

	}
	//OVERLOADING OPERATORS (each class 2 different overloaded operators)

};