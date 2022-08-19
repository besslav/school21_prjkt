//
// Created by Price Skip on 8/17/22.
//

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);
	~FragTrap();

	void highFivesGuys(void);
};


#endif //FRAGTRAP_H
