#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& src);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	bool signForm(AForm& form) const;

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
	int m_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif
