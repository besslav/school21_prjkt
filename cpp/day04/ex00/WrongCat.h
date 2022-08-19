//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_WRONGCAT_H
#define EX00_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat: public WrongAnimal{

public:
	WrongCat();
	WrongCat(const WrongCat&);
	WrongCat& operator=(const WrongCat&);

	~WrongCat();

	void makeSound() const;
};


#endif //EX00_WRONGCAT_H
