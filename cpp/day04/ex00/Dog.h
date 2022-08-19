//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_DOG_H
#define EX00_DOG_H

#include "Animal.h"

class Dog: public Animal{

public:
	Dog();
	Dog(const Dog&);
	Dog& operator=(const Dog&);

	~Dog();

	void makeSound() const;
};


#endif //EX00_DOG_H
