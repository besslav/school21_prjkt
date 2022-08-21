#include "Cat.h"
#include "Dog.h"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	delete(j);
	delete(i);

	//const AAnimal* k = new AAnimal();
	//std::cout << k->getType() << " " << std::endl;
	//k->makeSound();


	return 0;
}