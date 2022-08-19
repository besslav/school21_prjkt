//
// Created by Price Skip on 8/16/22.
//

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap&);
	ScavTrap& operator=(const ScavTrap&);
	~ScavTrap();

	void guardGate(void);
	void attack(const std::string &target);

	bool getGuardGate(void) const;

private:
	bool _guardGate;
};


#endif //SCAVTRAP_H
