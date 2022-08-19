//
// Created by Price Skip on 8/16/22.
//

#include "ClapTrap.h"

void test(ClapTrap &clapTrap){
	for (int i = 0; i < 9; i++)
		clapTrap.attack("Molly");
}

int main(void) {
	ClapTrap clapTrap("Dory");
	ClapTrap clapTrap1;

	clapTrap.attack("Lory");
	clapTrap.takeDamage(3);
	clapTrap.beRepaired(1000000);
	clapTrap.beRepaired(2147333333);
	std::cout << clapTrap.getHp() << std::endl;
	clapTrap1 = clapTrap;
	test(clapTrap);
	clapTrap1.beRepaired(2);
	clapTrap1.takeDamage(20);
	clapTrap1.attack("Lory");
	clapTrap1.takeDamage(2);
}