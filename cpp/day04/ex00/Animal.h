//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_ANIMAL_H
#define EX00_ANIMAL_H

#include <iostream>

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	const std::string &getType() const;
	virtual ~Animal();

	virtual void makeSound() const;

};


#endif //EX00_ANIMAL_H
