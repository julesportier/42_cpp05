#include "RobotomyRequestForm.h"
#include <iostream>
#include <cstdlib>

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm()
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm::AForm("RobotomyRequest", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm::AForm(src)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

/************
* OPERATORS *
************/
RobotomyRequestForm& RobotomyRequestForm::operator=(
		const RobotomyRequestForm& src)
{
	(void)src;
	std::cout << "Can't reasign form\n";
	return (*this);
}

/**********
* METHODS *
**********/
static void robotomize(const std::string target);

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkExecRights(executor);
	robotomize(getTarget());
}

static bool coin()
{
	std::srand(time(NULL));
	if (std::rand() > RAND_MAX / 2)
		return (true);
	else
		return (false);
}

static void robotomize(const std::string target)
{
	if (coin()) {
		std::cout << "BZZZ CRRRR SHHRR\n";
		std::cout << target << " has been robotomized\n";
	}
	else {
		std::cout << "Robotomy failed\n";
	}
}
