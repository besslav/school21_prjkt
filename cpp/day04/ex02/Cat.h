//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_CAT_H
#define EX00_CAT_H

#include "AAnimal.h"
#include "Brain.h"

class Cat: public AAnimal{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	~Cat();

	void makeSound() const;
	Brain getBrain() const;
};


#endif //EX00_CAT_H
