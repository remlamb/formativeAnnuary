#include "User.h"
#include <iostream>

User::User(std::string userFirstName, std::string userLastName, std::string userNumber) {
	firstName = userFirstName;
	lastName = userLastName;
	number = userNumber;
};

bool User::operator<(User user) const {
	if (lastName != user.lastName) {
		return lastName < user.lastName;
	}
	else {
		return firstName < user.firstName;
	}
}

