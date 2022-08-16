//
// Created by Price Skip on 8/8/22.
//

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie {
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	void setName(const std::string name);
	void announce( void );
};

Zombie* zombieHorde( int N, std::string name );


#endif
