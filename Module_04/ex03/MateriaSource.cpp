#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	cout << "MateriaSource default constructor called\n";
	for (int i = 0; i < 4; i++) {
		this->_templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiasource_var) {
	cout << "MateriaSource copy constructor called\n";
	*this = materiasource_var;
}

MateriaSource::~MateriaSource() {
	cout << "MateriaSource destructor called\n";
	for (int i = 0; i < 4; i++) {
		if (this->_templates[i]) {
			delete this->_templates[i];
		}
	}
}

MateriaSource	&MateriaSource::operator = (const MateriaSource &materiasource_var) {
	cout << "MateriaSource copy assignment operator called\n";
	for (int i = 0; i < 4; i++) {
		if (this->_templates[i]) {
			delete this->_templates[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (materiasource_var._templates[i]) {
			this->_templates[i] = materiasource_var._templates[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_templates[i]) {
			this->_templates[i] = m->clone();
			return ;
		}
	}
	cout << "Failed to learn Materia of type " << m->getType() << " because 4 templates have been learned!\n";
}

AMateria	*MateriaSource::createMateria(string const &type) {
	string	template_type;
	string	to_create_type;

	for (int i = 0; i < 4; i++) {
		if (this->_templates[i]) {
			template_type = this->_templates[i]->getType();
			to_create_type = type;
			std::transform(template_type.begin(), template_type.end(), template_type.begin(), ::tolower);
			std::transform(to_create_type.begin(), to_create_type.end(), to_create_type.begin(), ::tolower);
			if (template_type == to_create_type) {
				return (this->_templates[i]->clone());
			}
		}
	}
	cout << "Failed to create Materia of type " << type << " because it's an unknown type!\n";
	return (0);
}
