//
// Created by Price Skip on 8/16/22.
//

#include "ClapTrap.h"

ClapTrap::ClapTrap() : _hp(10), _energy(10), _damage(0), _name("no_name"){
	std::cout << "Default constructor ClapTrap " << std::endl;
}
ClapTrap::ClapTrap(const std::string& name) :
		_hp(10), _energy(10), _damage(0), _name(name){
	std::cout << "constructor with name ClapTrap " << _name << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << "Destructor ClapTrap " << _name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &copy) :
		_hp(copy.getHp()), _energy(copy.getEnergy()), _damage(copy.getDamage()), _name(copy.getName()) {
	std::cout << "Copy constructor ClapTrap" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
	std::cout << "Copy assignment operator ClapTrap" << std::endl;
	this->_hp = copy.getHp();
	this->_energy = copy.getEnergy();
	this->_damage = copy.getDamage();
	this->_name = copy.getName();
	return *this;
}



int ClapTrap::getHp(void) const {
	std::cout << "getHp member function" << std::endl;
	return this->_hp;
}
int ClapTrap::getEnergy(void) const {
	std::cout << "getEnergy member function" << std::endl;
	return this->_energy;
}
int ClapTrap::getDamage(void) const {
	std::cout << "getDamage member function" << std::endl;
	return this->_damage;
}
std::string ClapTrap::getName(void) const {
	std::cout << "getName member function" << std::endl;
	return this->_name;
}

void ClapTrap::takeDamage(unsigned int amount) {
//	if (amount > _hp)
//		amount = _hp;
	if (_hp <= 0)
		std::cout << "ClapTrap " << _name << " Already dead " << std::endl;
	else {
		_hp -= amount;
		if (_hp > 0)
			std::cout << "ClapTrap " << _name << " takeDamage " << amount << std::endl;
		else {
			std::cout << "ClapTrap " << _name << " takeDamage " << amount << "and died" << std::endl;
		}
	}
}

void ClapTrap::attack(const std::string &target) {
	if (_hp <= 0)
		std::cout << " Dead ClapTrap " << _name << " cant attack " << std::endl;
	else if (_energy <= 0)
		std::cout << "ClapTrap " + _name + " has run out of energy" << std::endl;
	else{
		std::cout << "ClapTrap " << _name << " attacks " << target
					<< ", causing " << _damage << " points of damage!" << std::endl;
		_energy--;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
//	if (amount > UINT_MAX32 - _hp)
//		amount = UINT_MAX32 - _hp;
	if (_hp <= 0)
		std::cout << "Dead ClapTrap " << _name << " cant beRepaired " << std::endl;
	else if (_energy <= 0)
		std::cout << "ClapTrap " + _name + " has run out of energy" << std::endl;
	else{
		_hp += amount;
		std::cout << "ClapTrap " << _name << " beRepaired " << amount << std::endl;
		_energy--;
	}
}