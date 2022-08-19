//
// Created by Price Skip on 8/16/22.
//

#include "ScavTrap.h"

ScavTrap::ScavTrap() : _guardGate(false) {
	std::cout << "Default constructor ScavTrap" << std::endl;
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGate(false) {
	std::cout << "Constructor ScavTrap: " + name << std::endl;
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), _guardGate(copy.getGuardGate()) {
	std::cout << "Copy constructor ScavTrap" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	std::cout << "Copy assignment operator ScavTrap" << std::endl;
	this->_name = copy.getName();
	this->_damage = copy.getDamage();
	this->_energy = copy.getEnergy();
	this->_hp = copy.getHp();
	this->_guardGate = copy.getGuardGate();
	return *this;
}
ScavTrap::~ScavTrap() {
	std::cout << "Destructor ScavTrap: " + _name << std::endl;
}

bool ScavTrap::getGuardGate() const {
	return this->_guardGate;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_hp <= 0) {
		std::cout << "Unfortunately, " + _name + " cant attack, its a bit ... you know ... dead" << std::endl;
		return;
	}
	if (this->_energy == 0) {
		std::cout << "ScavTrap " + _name + " has run out of energy" << std::endl;
		return;
	}
	std::cout << "ScavTrap " + _name + " attacks " + target + ", causing " << _damage
			  << " points of damage!" << std::endl;
	this->_energy--;
}

void ScavTrap::guardGate() {
	if (this->_hp <= 0) {
		std::cout << "ScavTrap " + _name + " can no longer change the operating mode" << std::endl;
		return;
	}
	if (this->_guardGate)
		std::cout << "ScavTrap " + _name + " is not now in Gatekeeper mode" << std::endl;
	else
		std::cout << "ScavTrap " + _name + " is now in Gatekeeper mode" << std::endl;
	this->_guardGate = !(this->_guardGate);
}