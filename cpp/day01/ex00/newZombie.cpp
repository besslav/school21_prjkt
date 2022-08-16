//
// Created by Price Skip on 8/8/22.
//
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	return (new Zombie(name));
}