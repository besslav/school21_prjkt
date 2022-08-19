//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_DOG_H
#define EX00_DOG_H

#include "AAnimal.h"
#include "Brain.h"

class Dog: public AAnimal{
private:
	Brain *_brain;
public:
	Dog();
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	~Dog();

	void makeSound() const;
	Brain getBrain() const;
};


#endif //EX00_DOG_H
