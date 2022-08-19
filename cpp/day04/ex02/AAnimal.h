//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_AANIMAL_H
#define EX00_AANIMAL_H

#include <iostream>

class AAnimal {
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const std::string &type);
	AAnimal(const AAnimal&);
	AAnimal& operator=(const AAnimal&);
	virtual ~AAnimal();

	const std::string &getType() const;
	virtual void makeSound() const = 0;

};


#endif //EX00_AANIMAL_H
