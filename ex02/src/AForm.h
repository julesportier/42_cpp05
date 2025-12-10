#ifndef AFORM_H
# define AFORM_H

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.h"

class AForm {

public:
	AForm();
	AForm(
		const std::string name,
		const int gradeToSign,
		const int gradeToExecute,
		const std::string target);
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);
	virtual ~AForm();

	std::string getName() const;
	bool getSignedStatus() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getTarget() const;

	void beSigned(const Bureaucrat& signatory);
	void checkExecRights(const Bureaucrat& executor) const;
	virtual void execute(const Bureaucrat& executor) const = 0;

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
	const std::string m_target;

};

std::ostream& operator<<(std::ostream& os, const AForm& src);

#endif
