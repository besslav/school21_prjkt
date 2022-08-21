#include "Cat.h"
#include "Dog.h"

# define ANIMAL_COUNT 10
# define SEPARATOR "------------------------------"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	meta->makeSound();
	delete(meta);
	delete(j);
	delete(i);

	Animal *animals[ANIMAL_COUNT];
	for (int k = 0; k < ANIMAL_COUNT; ++k) {
		std::cout << k << SEPARATOR << std::endl;
		if (k < ANIMAL_COUNT / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
		std::cout << k << SEPARATOR << std::endl;
	}
	for (int k = 0; k < ANIMAL_COUNT; ++k) {
		std::cout << k << SEPARATOR << std::endl;
		delete animals[k];
		std::cout << k << SEPARATOR << std::endl;
	}

	return 0;
}