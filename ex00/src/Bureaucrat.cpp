#include "Bureaucrat.h"
#include <iostream>

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
Bureaucrat::Bureaucrat()
	: m_name("Anonymous")
	, m_grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: m_name(name)
	, m_grade(grade)
{
	std::cout << "Bureaucrat constructor called\n";
	if (m_grade > 150) {
		m_grade = -1;
		throw GradeTooLowException();
	}
	else if (m_grade < 1) {
		m_grade = -1;
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: m_name(src.m_name)
{
	std::cout << "Bureaucrat copy constructor called\n";
	if (src.m_grade > 150) {
		m_grade = -1;
		throw GradeTooLowException();
	}
	else if (src.m_grade < 1) {
		m_grade = -1;
		throw GradeTooHighException();
	}
	else {
		m_grade = src.m_grade;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

/************
* OPERATORS *
************/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	(void)src;
	std::cout << "Bureaucrat body transmigration not implemented yet\n";
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << '.';
	return (os);
}

/**********
* GETTERS *
**********/
std::string Bureaucrat::getName() const
{
	return (m_name);
}

int	Bureaucrat::getGrade() const
{
	return (m_grade);
}

/**********
* METHODS *
**********/
void	Bureaucrat::incrementGrade()
{
	if (m_grade <= 1) {
		m_grade = -1;
		throw GradeTooHighException();
	}
	else {
		--m_grade;
	}
}

void	Bureaucrat::decrementGrade()
{
	if (m_grade >= 150) {
		m_grade = -1;
		throw GradeTooLowException();
	}
	else if (m_grade < 1) {
		m_grade = -1;
		throw GradeTooHighException();
	}
	else {
		++m_grade;
	}
}

/*************
* EXCEPTIONS *
*************/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
