#include "Cat.h"
#include "Dog.h"

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




	return 0;
}