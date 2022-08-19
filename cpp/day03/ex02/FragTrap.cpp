//
// Created by Price Skip on 8/17/22.
//

#include "FragTrap.h"

FragTrap::FragTrap() {
	std::cout << "Default constructor FragTrap" << std::endl;
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Constructor FragTrap: " + name << std::endl;
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "Copy constructor FragTrap" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &copy) {
	std::cout << "Copy assignment operator FragTrap" << std::endl;
	this->_name = copy.getName();
	this->_damage = copy.getDamage();
	this->_energy = copy.getEnergy();
	this->_hp = copy.getHp();
	return *this;
}
FragTrap::~FragTrap() {
	std::cout << "Destructor FragTrap: " + _name << std::endl;
}

void FragTrap::highFivesGuys() {
	if (_hp > 0)
		std::cout << "high Five " + _name << std::endl;
	else
		std::cout << "befor his death, FragTrap " + _name +
					" always asking you to give him five. Will you do it, in his memory?"<< std::endl;
}
