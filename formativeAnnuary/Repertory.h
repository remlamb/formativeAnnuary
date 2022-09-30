#pragma once
#include <vector>
#include "User.h"

class Repertory
{
public:
	std::vector<User> repertory;

	void addUser();
	void showRepertory();
	void searchUser();

	void startAnnuary(); //Give the user a choice between different operations

	void tolowerString(std::string&); //put each element in a string to lowercase, use to avoid failure during searchUser
	bool checkNumber(std::string&); //return true if the string is composed of numbers or character '+' 
	void clearConsole();

	void addFalseUser(); //add 3 pre entered Users in the repertory

	std::vector<User>::iterator findUserInRepertory(std::string, std::string); //Create an iterator that look in repertory in order to find user with the firstname and lastname given in parameters 
};

