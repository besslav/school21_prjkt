//
// Created by Price Skip on 8/16/22.
//

#include "ScavTrap.h"
#include "FragTrap.h"

void test(ScavTrap scavTrap){
	for (int i = 0; i < 10; i++)
		scavTrap.attack("Molly");
}

int main(void) {
	ScavTrap scavTrap("Dory");
	ScavTrap scavTrap1;

	scavTrap.attack("Lory");
	scavTrap.takeDamage(3);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();

	scavTrap1 = scavTrap;

	scavTrap1.beRepaired(2);
	scavTrap1.takeDamage(20);
	scavTrap1.attack("Lory");
	scavTrap1.takeDamage(2);
	scavTrap1.guardGate();

	FragTrap flager("flag");
	flager.takeDamage(3);
	flager.beRepaired(5);
	flager.highFivesGuys();
	flager.takeDamage(300);
	flager.beRepaired(301);
	flager.highFivesGuys();
}
