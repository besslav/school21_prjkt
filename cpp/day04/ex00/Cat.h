//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_CAT_H
#define EX00_CAT_H

#include "Animal.h"

class Cat: public Animal{

public:
	Cat();
	Cat(const Cat&);
	Cat& operator=(const Cat&);

	~Cat();

	void makeSound() const;
};


#endif //EX00_CAT_H
