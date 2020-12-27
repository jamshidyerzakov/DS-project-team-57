#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Seat {
private:
	double price;
	string seat_id;
	string type;
	bool is_reserved;

public:
	void setSeatID(string seat_id) {
		this->seat_id = seat_id;
	}
	void setPrice(double price) {
		this->price = price;
	}
	void setType(string type) {
		this->type = type;
	}
	void setReserved(bool is_reserved) {
		this->is_reserved = is_reserved;
	}

	// getters
	string getSeatID() {
		return seat_id;
	}
	double getPrice() {
		return price;
	}
	string getType() {
		return type;
	}
	bool getReserved() {
		return is_reserved;
	}

};