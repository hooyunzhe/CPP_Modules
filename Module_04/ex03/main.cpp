#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	// From pdf
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
		system("leaks interface");
	}
	// Error handling
	{
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		ICharacter	*p1 = new Character("P1");
		ICharacter	*p2 = new Character("P2");
		AMateria	*tmp;

		p1->use(3, *p2);
		tmp = src->createMateria("Water");
		cout << tmp << endl;

		tmp = src->createMateria("Ice");
		p1->equip(tmp);
		p1->equip(tmp);

		tmp = src->createMateria("Cure");
		p1->equip(tmp);
		tmp = src->createMateria("Ice");
		p1->equip(tmp);
		tmp = src->createMateria("Cure");
		p1->equip(tmp);

		p1->unequip(4);
		p1->unequip(1);

		tmp = src->createMateria("Ice");
		p1->equip(tmp);
		tmp = src->createMateria("Cure");
		p1->equip(tmp);

		delete p1;
		delete p2;
		delete src;
		system("leaks interface");
		return 0;
	}
}