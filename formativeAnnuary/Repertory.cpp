#include "Repertory.h"
#include <iostream>
#include <cctype>
#include <algorithm>

void Repertory::addUser() {

	std::string firstName, lastName, number;

	//get from user the firstName, lastName that we lowercase
	std::cout << "Enter your Firstname : ";
	std::cin >> firstName;
	tolowerString(firstName);

	std::cout << "Enter your Lastname : ";
	std::cin >> lastName;
	tolowerString(lastName);

	//get from user the number and verified that characters are numbers 
	std::cout << "Enter your Number : ";
	std::cin >> number;

	while (!checkNumber(number)) {
		std::cout << "Input not supported, character supported : +01234567989 - Enter your Number : ";
		std::cin >> number;
	}

	//Create an iterator that look in repertory in order to find user with the firstname and lastname given in parameters 
	//If we found an other user with the same name, ask user if it's a mistake 
	auto found = findUserInRepertory(firstName, lastName);
	if (found != repertory.end()) {

		std::cout << firstName << " " << lastName << " already exist and got : " << found->number << " as number \n";
		std::cout << "Add " << firstName << " " << lastName << " number : " << number << " ? Y/N ? (use y for yes, anything else for no)";

		std::string choice;
		std::cin >> choice;
		tolowerString(choice);

		if (choice != "y") {
			std::cout << "Add canceled";
			return;
		}
	}

	repertory.emplace_back(firstName, lastName, number);
	std::cout << "Successfully Added";
};

void Repertory::showRepertory() {
	//we sort the repertory to make it easier to read
	std::sort(repertory.begin(), repertory.end());
	for (auto user : repertory) {
		std::cout << user.lastName << " " << user.firstName;
		std::cout << " number is : " << user.number << "\n";
	}
};

void Repertory::searchUser() {
	std::string firstName, lastName;

	//get from user a firstName and a lastName that we lowercase
	std::cout << "Enter the user's Firstname you're looking for  : ";
	std::cin >> firstName;
	tolowerString(firstName);

	std::cout << "Enter the user's Lastname you're looking for  : ";
	std::cin >> lastName;
	tolowerString(lastName);


	//Create an iterator that look in repertory to find a user with the firstname and lastname given in parameters 
	//If we found a user, show in console the first number entered for this user name
	auto found = findUserInRepertory(firstName, lastName);
	if (found != repertory.end()) {
		std::cout << "First number entered for " << lastName << " " << firstName << " : ";
		std::cout << found->number << "\n";
	}
	else {
		std::cout << "Nothing found for : lastname : " << lastName << " firstname : " << firstName << " \n";
	}
};

void Repertory::startAnnuary() {

	std::string currentChoice; //use to get the user choice in the console 
	//Give the user a choice between different options, clear the console before showing the result
	while (currentChoice != "5") {
		std::cout << "Enter : \n" << "1 to add a User. \n" << "2 search User \n" << "3 print Annuary \n" << "4 add False Users \n" << "5 end program \n";
		std::cin >> currentChoice;

		if (currentChoice == "1") {
			clearConsole();
			addUser();
		}
		else if (currentChoice == "2") {
			clearConsole();
			searchUser();
		}
		else if (currentChoice == "3") {
			clearConsole();
			showRepertory();
		}
		else if (currentChoice == "4") {
			clearConsole();
			addFalseUser();
		}
		else if (currentChoice == "5") {
			clearConsole();
			return;
		}
		else {
			clearConsole();
			std::cout << "I don't understand : " << currentChoice << " Please Retry \n";
		}
		std::cout << "\n";
	}
};

void Repertory::tolowerString(std::string& name) {

	for (auto& letter : name) {
		letter = tolower(letter);
	}
};

bool Repertory::checkNumber(std::string& number) {

	return number.find_first_not_of("+0123456789") == number.npos;
}

void Repertory::clearConsole() {
	std::cout << "\x1B[2J\x1B[H";
}

void Repertory::addFalseUser() {
	repertory.emplace_back(User("snake", "solid", "0130404551"));
	repertory.emplace_back(User("snake", "liquid", "0130404552"));
	repertory.emplace_back(User("snake", "solidus", "0130404553"));

	std::cout << "False Users Added \n";
}

std::vector<User>::iterator Repertory::findUserInRepertory(std::string firstName, std::string lastName) {
	auto found = std::find_if(
		repertory.begin(),
		repertory.end(),
		[&firstName, &lastName](const auto& userIt) { return userIt.firstName == firstName && userIt.lastName == lastName; }
	);
	return found;
}
