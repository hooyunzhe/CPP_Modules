#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	// From pdf
	{
		Animal	*animals[10];

		for (int i = 0; i < 10; i++) {
			if (i < 5) {
				animals[i] = new Dog();
			}
			else {
				animals[i] = new Cat();
			}
		}
		for (int i = 0; i < 10; i++) {
			cout << "Animal " << i << " is a " << animals[i]->getType() << endl;
		}
		for (int i = 0; i < 10; i++) {
			delete animals[i];
		}
		system("leaks polymorphism_v2");
	}
	// Make sure copies are deep and not shallow
	{
		Dog		*dog_og = new Dog();
		Dog		*dog_copy = new Dog();

		*dog_copy = *dog_og;
		delete dog_og;
		cout << "Dog copy is a " << dog_copy->getType() << " and has ideas: \n";
		for (int i = 0; i < 100; i++) {
			cout << i << ": " << dog_copy->getBrain()->ideas[i] << endl;
		};
		delete dog_copy;
		system("leaks polymorphism_v2");
		return (0);
	}
	// If "virtual" isn't used in the base class
	{
		WrongAnimal	*i = new WrongCat();

		i->makeSound();
		delete i;
		system("leaks polymorphism_v2");
	}
}
