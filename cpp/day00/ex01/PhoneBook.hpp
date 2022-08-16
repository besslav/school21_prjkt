#ifndef CPP_D00_PHONEBOOK_HPP
#define CPP_D00_PHONEBOOK_HPP

# define MAX_OF_CONTACTS 8

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook {
private:
	int 	num_contact;
	Contact contacts[MAX_OF_CONTACTS];

public:
	PhoneBook();
	~PhoneBook();
	void AddContact();
	void SearchContact();
};

#endif
