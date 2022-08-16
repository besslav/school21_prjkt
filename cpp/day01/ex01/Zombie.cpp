//
// Created by Price Skip on 8/8/22.
//

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "alive" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": dead_again" << std::endl;
}

void Zombie::setName(const std::string name)
{
	this->_name = name;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}