//
// Created by Price Skip on 8/16/22.
//

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap {
protected:
	int 		_hp;
	int 		_energy;
	int 		_damage;
	std::string _name;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	~ClapTrap();
	ClapTrap(const ClapTrap&);
	ClapTrap& operator=(const ClapTrap&);
	std::string getName(void) const;
	int getHp(void) const;
	int getDamage(void) const;
	int getEnergy(void) const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif //CLAPTRAP_H
