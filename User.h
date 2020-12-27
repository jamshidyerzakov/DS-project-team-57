
#pragma once
#include<string>
using namespace std;

class User {
private:
	string id;
	string first_name;
	string second_name;
	int age;

public:
	void setID(string id) {
		this->id = id;
	}
	string getID() {
		return id;
	}

	void setFirstName(string first_name) {
		this->first_name = first_name;
	}
	string getFirstName() {
		return first_name;
	}

	void setSecondName(string second_name) {
		this->second_name = second_name;
	}
	string getSecondName() {
		return second_name;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return age;
	}
};
