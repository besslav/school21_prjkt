//
// Created by Price Skip on 8/3/22.
//

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

# define D_ID "index: "
# define D_NAME "Nickname: "
# define D_SECRET "Darkest Secret: "
# define D_PHONE_NUM "Phone Number: "
# define D_FIRST_NAME "First Name: "
# define D_SECOND_NAME "Last Name: "

class Contact {
private:
	int 		id;
	std::string name;
	std::string	secret;
	std::string firstName;
	std::string secondName;
	std::string phoneNumber;

public:
	Contact();
	~Contact();

	int getID() const;
	std::string getName();
	std::string getSecret();
	std::string getFirstName();
	std::string getSecondName();
	std::string getPhoneNumber();

	void setID(int _id);
	void setName(const std::string &_name);
	void setSecret(const std::string &_secret);
	void setFirstName(const std::string &_firstName);
	void setSecondName(const std::string &_secondName);
	void setPhoneNumber(const std::string &_phoneNumber);
	void complain(const std::string &data, int fnc);

	void displayContact();
};


#endif
