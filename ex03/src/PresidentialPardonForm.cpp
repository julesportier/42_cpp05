#include "PresidentialPardonForm.h"
#include <iostream>
#include <cstdlib>

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm()
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm::AForm("PresidentialPardon", 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm::AForm(src)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

/************
* OPERATORS *
************/
PresidentialPardonForm& PresidentialPardonForm::operator=(
		const PresidentialPardonForm& src)
{
	(void)src;
	std::cout << "Can't reasign form\n";
	return (*this);
}

/**********
* METHODS *
**********/
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkExecRights(executor);
	std::cout << getTarget() << " has been pardoned by Zaphold Beeblebrox.\n";
}
