#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// From pdf
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		cout << j->getType() << " " << std::endl;
		cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound(); //will output the cat sound!
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
		system("leaks polymorphism");
	}
	// If "virtual" isn't used in a base class
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongCat();
		const WrongCat* j_cat = new WrongCat();

		cout << j->getType() << " " << std::endl;
		cout << j_cat->getType() << " " << std::endl;
		j->makeSound(); // will output the animal sound
		j_cat->makeSound(); // will output the cat sound
		meta->makeSound();

		delete meta;
		delete j;
		delete j_cat;
		system("leaks polymorphism");
		return (0);
	}
}
