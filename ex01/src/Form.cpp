#include "Form.h"

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
Form::Form()
	: m_name("Form x")
	, m_signed(false)
	, m_gradeToSign(150)
	, m_gradeToExecute(150)
{
	std::cout << "Form default constructor called\n";
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute)
	: m_name(name)
	, m_signed(false)
	, m_gradeToSign(gradeToSign)
	, m_gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called\n";
	if (m_gradeToSign > 150 || m_gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
	else if (m_gradeToSign < 1 || m_gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form& src)
	: m_name(src.m_name)
	, m_signed(src.m_signed)
	, m_gradeToSign(src.m_gradeToSign)
	, m_gradeToExecute(src.m_gradeToExecute)
{
	std::cout << "Form copy constructor called\n";
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}

/************
* OPERATORS *
************/
Form& Form::operator=(const Form& src)
{
	(void)src;
	std::cout << "Can't reasign form\n";
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& src)
{
	os << "Form: " << src.getName() << " ; ";
	src.getSignedStatus() ? os << "signed: yes" : os << "signed: no";
	os << " ; grade to sign: " << src.getGradeToSign();
	os << " ; grade to execute: " << src.getGradeToExecute();
	return (os);
}

/**********
* GETTERS *
**********/
std::string Form::getName() const
{
	return (m_name);
}

bool Form::getSignedStatus() const
{
	return (m_signed);
}

int Form::getGradeToSign() const
{
	return (m_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (m_gradeToExecute);
}

/**********
* METHODS *
**********/
void Form::beSigned(const Bureaucrat& signatory)
{
	if (signatory.getGrade() <= m_gradeToSign) {
		m_signed = true;
	}
	else {
		throw Form::GradeTooLowException();
	}
}

/*************
* EXCEPTIONS *
*************/
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Error: grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Error: grade is too low");
}
