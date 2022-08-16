//
// Created by Price Skip on 8/10/22.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
	std::cout << _name << " enter_the_battle " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "leave_the_battle" << _name << std::endl;
}

void HumanB::attack()
{
	std::cout << _name << " attacks ";
	if (_weapon != NULL)
	{
		std::cout << " with their " << _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << "without a weapon " << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
