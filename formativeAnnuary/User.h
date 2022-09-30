#pragma once
#include <string> 

class User
{

public:
	std::string firstName;
	std::string lastName;
	std::string number;

	User(std::string, std::string, std::string);
	bool operator<(const User) const; //Operator Overloading to make the vector sortable
};


