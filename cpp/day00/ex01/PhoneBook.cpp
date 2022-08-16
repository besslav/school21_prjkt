#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int i)
{
	std::cout << "Constructor PhoneBook" << std::endl;
	this->num_contact = 0;

}
PhoneBook::~PhoneBook() {
	std::cout << "Destructor PhoneBook "<< std::endl;
}

void PhoneBook::AddContact()
{
	std::string	data;

	std::string	str_data[5] = { "First name: ", "Second name: ",
								   "nickname: ", "phone number: ", "Darkest Secret: " };
	if (this->num_contact == MAX_OF_CONTACTS)
	{
		for (int i = 0; i < MAX_OF_CONTACTS-1; i++)
		{
			contacts[i] = contacts[i+1];
			contacts[i].setID(i+1);
		}
		this->num_contact--;
	}
	for (int i = 0; i < 5; i++)
	{
		do {
			std::cout << str_data[i];
			std::cin >> data;
			if (std::cin.eof())
				return ;
		} while (data.empty());
		contacts[num_contact].complain(data, i);
	}
	contacts[num_contact].setID(this->num_contact + 1);
	this->num_contact++;
}

void PhoneBook::SearchContact()
{
	std::string j;

	if (this->num_contact == 0)
	{
		std::cout << "empty book" << std::endl;
		return ;
	}
	for (int i = 0; i < this->num_contact; ++i) {
		std::cout << std::setw(10) << contacts[i].getID() << "\t|\t";
		std::cout << std::setw(10) << contacts[i].getFirstName() << "\t|\t";
		std::cout << std::setw(10) << contacts[i].getSecondName() << "\t|\t";
		std::cout << std::setw(10) << contacts[i].getName() << std::endl;
	}
	std::cout << "Please enter the contact\'s index: " << std::endl;
	std::cin >> j;
	if (std::cin.eof())
		return ;
	int k = atoi(j.c_str()) - 1;
	if (k < 0 || k >= this->num_contact){
		std::cout << "Invalid index" << std::endl;
	} else {
		this->contacts[k].displayContact();
	}
}
