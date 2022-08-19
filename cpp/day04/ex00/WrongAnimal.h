//
// Created by Price Skip on 8/17/22.
//

#ifndef EX00_WRONGANIMAL_H
#define EX00_WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal&);
	WrongAnimal& operator=(const WrongAnimal&);
	const std::string &getType() const;
	~WrongAnimal();

	void makeSound() const;

};


#endif //EX00_WRONGANIMAL_H
