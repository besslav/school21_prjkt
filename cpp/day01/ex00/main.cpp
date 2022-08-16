//
// Created by Price Skip on 8/8/22.
//

#include "Zombie.hpp"

int main()
{
	std::string name1 = "Nina", name2 = "Dail";
	Zombie *zombie = newZombie(name1);
	zombie->announce();
	randomChump(name2);
	delete(zombie);
}