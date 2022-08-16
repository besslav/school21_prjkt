//
// Created by Price Skip on 8/10/22.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "new_weapon " << _type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "broke_the_weapon " << _type << std::endl;
}
std::string Weapon::getType()
{
	return (_type);
}
void Weapon::setType(std::string type)
{
	_type = type;
}