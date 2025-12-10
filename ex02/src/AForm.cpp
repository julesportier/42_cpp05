#include "AForm.h"

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
AForm::AForm()
	: m_name("Form x")
	, m_signed(false)
	, m_gradeToSign(150)
	, m_gradeToExecute(150)
	, m_target("default")
{
	std::cout << "AForm default constructor called\n";
}

AForm::AForm(
		const std::string name,
		const int gradeToSign,
		const int gradeToExecute,
		const std::string target)
	: m_name(name)
	, m_signed(false)
	, m_gradeToSign(gradeToSign)
	, m_gradeToExecute(gradeToExecute)
	, m_target(target)
{
	std::cout << "AForm constructor called\n";
	if (m_gradeToSign > 150 || m_gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
	else if (m_gradeToSign < 1 || m_gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(const AForm& src)
	: m_name(src.m_name)
	, m_signed(src.m_signed)
	, m_gradeToSign(src.m_gradeToSign)
	, m_gradeToExecute(src.m_gradeToExecute)
	, m_target(src.m_target)
{
	std::cout << "AForm copy constructor called\n";
}

AForm::~AForm()
{
	std::cout << "AForm destructor called\n";
}

/************
* OPERATORS *
************/
AForm& AForm::operator=(const AForm& src)
{
	(void)src;
	std::cout << "Can't reasign form\n";
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& src)
{
	os << "Form: " << src.getName() << " ; ";
	src.getSignedStatus() ? os << "signed: yes" : os << "signed: no";
	os << " ; grade to sign: " << src.getGradeToSign();
	os << " ; grade to execute: " << src.getGradeToExecute();
	os << " ; target: " << src.getTarget();
	return (os);
}

/**********
* GETTERS *
**********/
std::string AForm::getName() const
{
	return (m_name);
}

bool AForm::getSignedStatus() const
{
	return (m_signed);
}

int AForm::getGradeToSign() const
{
	return (m_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (m_gradeToExecute);
}

std::string AForm::getTarget() const
{
	return (m_target);
}

/**********
* METHODS *
**********/
void AForm::beSigned(const Bureaucrat& signatory)
{
	if (signatory.getGrade() <= m_gradeToSign) {
		m_signed = true;
	}
	else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::checkExecRights(const Bureaucrat& executor) const
{
	if (executor.getGrade() > m_gradeToExecute)
		throw AForm::GradeTooLowException();
	if (m_signed == false)
		throw AForm::UnsignedFormException();
}

/*************
* EXCEPTIONS *
*************/
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return ("form is unsigned");
}
