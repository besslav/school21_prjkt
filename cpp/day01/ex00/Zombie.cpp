//
// Created by Price Skip on 8/8/22.
//

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << ": alive" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": dead_again" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}