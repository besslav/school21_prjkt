//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_CAT_H
#define EX00_CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat: public Animal{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &copy);
	Cat& operator=(const Cat &copy);
	~Cat();

	void makeSound() const;
	Brain *getBrain() const;
};


#endif //EX00_CAT_H
