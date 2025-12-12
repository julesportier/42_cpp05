#include "Intern.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
Intern::Intern() {}
Intern::Intern(Intern& src)
{
	(void)src;
}
Intern::~Intern() {}

/************
* OPERATORS *
************/
Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

/**********
* METHODS *
**********/
AForm* Intern::makeShruberryCreation(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequest(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardon(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

typedef AForm* (Intern::*formCreationfn)(std::string target) const;

typedef struct s_form_map {
	std::string name;
	formCreationfn func;
} form_map;

AForm* Intern::makeForm(std::string name, std::string target)
{
	static const form_map map[3] = {
		{"shrubbery creation", &Intern::makeShruberryCreation},
		{"robotomy request", &Intern::makeRobotomyRequest},
		{"presidential pardon", &Intern::makePresidentialPardon},
	};
	for (int i = 0; i < 3; ++i) {
		if (name == map[i].name) {
			std::cout << "Intern creates " << name << " form\n";
			return ((this->*(map[i].func))(target));
		}
	}
	std::cout << "Intern can't create form, name is invalid\n";
	throw std::invalid_argument("invalid form name");
	return (NULL);
}
