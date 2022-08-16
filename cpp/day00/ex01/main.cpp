//
// Created by Price Skip on 8/6/22.
//

#include "PhoneBook.hpp"

int main() {
	PhoneBook book;
	std::string str;

	while (true){
		std::cout << "Write command: ";
		std::cin >> str;
		if (std::cin.eof())
			return (0);
		if (str == "ADD")
			book.AddContact();
		else if (str == "SEARCH")
			book.SearchContact();
		else if (str == "EXIT")
			return (0);
		else
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	}
}