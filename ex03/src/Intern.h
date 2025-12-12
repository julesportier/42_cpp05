#ifndef INTERN_H
# define INTERN_H

# include "AForm.h"
# include <string.h>

class Intern {
public:
	Intern();
	Intern(Intern& src);
	~Intern();
	Intern& operator=(const Intern& src);

	AForm* makeForm(std::string name, std::string target);

private:
	AForm* makeShruberryCreation(std::string target) const;
	AForm* makeRobotomyRequest(std::string target) const;
	AForm* makePresidentialPardon(std::string target) const;
};

#endif
