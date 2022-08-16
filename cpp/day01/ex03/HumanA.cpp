//
// Created by Price Skip on 8/10/22.
//

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << _name << " enter_the_battle_with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "leave_the_battle" << std::endl;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
