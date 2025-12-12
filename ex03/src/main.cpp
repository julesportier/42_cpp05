#include "Intern.h"

static void printBold(std::string str)
{
	std::cout << "\e[1m" << str << "\e[0m\n";
}

int main(void)
{
	printBold("\n#####\nIntern:\n#####\n");
	try {
		Intern i;
		AForm* s = i.makeForm("shrubbery creation", "garden");
		std::cout << *s << '\n';
		delete s;
		AForm* r = i.makeForm("robotomy request", "cellar");
		std::cout << *r << '\n';
		delete r;
		AForm* p = i.makeForm("presidential pardon", "intern");
		std::cout << *p << '\n';
		delete p;
		AForm* u = i.makeForm("unknown", "???");
		std::cout << *u << '\n';
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	try {
		Intern i;
		AForm* r = i.makeForm("robotomy request", "zak");
		std::cout << *r << '\n';
		Bureaucrat p("manager", 40);
		p.signForm(*r);
		std::cout << *r << '\n';
		p.executeForm(*r);
		delete r;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	return (0);
}
