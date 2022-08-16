//
// Created by Price Skip on 8/9/22.
//
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	std::string new_name;

		Zombie* horde = new Zombie[N];
	for (int i=0; i < N; i++)
	{
		new_name = name + "_" + std::to_string(i);
		horde[i].setName(new_name);
	}
	return (horde);

}