//
// Created by Price Skip on 8/3/22.
//

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Constructor Contact" << std::endl;
}

Contact::~Contact() {
	std::cout << "Destructor Contact: " + firstName + " " + secondName << std::endl;
}

std::string Contact::getName()
{
	if (this->name.length() <= 10)
		return (this->name);
	return (this->name.substr(0, 9).append("."));
}

std::string Contact::getFirstName()
{
	if (firstName.length() <= 10)
		return (this->firstName);
	return (this->firstName.substr(0, 9).append("."));
}

std::string Contact::getSecondName()
{
	if (this->secondName.length() <= 10)
		return (this->secondName);
	return (this->secondName.substr(0, 9).append("."));
}

std::string Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string Contact::getSecret()
{
	return (this->secret);
}

int Contact::getID() const
{
	return (this->id);
}

void Contact::setID(int _id)
{
	this->id = _id;
}

void Contact::setName(const std::string &_name)
{
	this->name = _name;
}

void Contact::setFirstName(const std::string &_firstName)
{
	this->firstName = _firstName;
}

void Contact::setSecondName(const std::string &_secondName)
{
	this->secondName = _secondName;
}

void Contact::setSecret(const std::string &_secret)
{
	this->secret = _secret;
}

void Contact::setPhoneNumber(const std::string &_phoneNumber)
{
	this->phoneNumber = _phoneNumber;
}

void Contact::complain(const std::string &data, int fnc)
{
	void (Contact::*func[5])(const std::string&) =
			{&Contact::setFirstName, &Contact::setSecondName, &Contact::setName,
			 &Contact::setPhoneNumber, &Contact::setSecret};
	(this->*(func[fnc]))(data);
}

void Contact::displayContact()
{
	std::cout << D_ID << this->id << std::endl;
	std::cout << D_NAME << this->name << std::endl;
	std::cout << D_FIRST_NAME << this->firstName << std::endl;
	std::cout << D_SECOND_NAME << this->secondName << std::endl;
	std::cout << D_PHONE_NUM << this->phoneNumber << std::endl;
	std::cout << D_SECRET << this->secret << std::endl;
}