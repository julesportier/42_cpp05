#ifndef FORM_H
# define FORM_H

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.h"

class Form {

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form& src);
	Form& operator=(const Form& src);
	~Form();

	std::string getName() const;
	bool getSignedStatus() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& signatory);

	// Exceptions subclasses
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

private:
	const std::string m_name;
	bool m_signed;
	const int m_gradeToSign;
	const int m_gradeToExecute;

};

std::ostream& operator<<(std::ostream& os, const Form& src);

#endif
