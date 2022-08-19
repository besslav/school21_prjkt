#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

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

	std::cout << "--------------------" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();
	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound(); //will output the cat sound!
	wrongMeta->makeSound();

	delete(wrongMeta);
	delete(wrongI);


	return 0;
}