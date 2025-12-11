#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

static void printBold(std::string str)
{
	std::cout << "\e[1m" << str << "\e[0m\n";
}

int main(void)
{
	printBold("###########\nBUREAUCRAT:\n###########");
	// printBold("Full constructor");
	// Bureaucrat j("Janine", 149);
	// std::cout << j << '\n';
	//
	// printBold("\nDefault constructor");
	// Bureaucrat a;
	// std::cout << a << '\n';
	//
	// printBold("\nAssignement operator");
	// a = j;
	// std::cout << a << '\n';
	//
	// printBold("\nCopy constructor");
	// Bureaucrat b(j);
	// std::cout << b << '\n';
	//
	// printBold("\nException too low");
	// try {
	// 	Bureaucrat l0("Min", 150);
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Error: " << e.what() << '\n';
	// }
	// try {
	// 	Bureaucrat l1("Low", 151);
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Error: " << e.what() << '\n';
	// }
	//
	// printBold("\nException too high");
	// try {
	// 	Bureaucrat l1("Max", 1);
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Error: " << e.what() << '\n';
	// }
	// try {
	// 	Bureaucrat l0("Low", 0);
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Error: " << e.what() << '\n';
	// }
	// try {
	// 	Bureaucrat lneg("Low", -9200);
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Error: " << e.what() << '\n';
	// }
	//
	// printBold("\nDecrement grade");
	// std::cout << j << '\n';
	// j.decrementGrade();
	// std::cout << j << '\n';
	// try {
	// 	j.decrementGrade();
	// 	std::cout << j << '\n';
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Error: " << e.what() << '\n';
	// }
	//
	// printBold("\nIncrement grade");
	// Bureaucrat d("Didier", 2);
	// std::cout << d << '\n';
	// d.incrementGrade();
	// std::cout << d << '\n';
	// try {
	// 	d.incrementGrade();
	// 	std::cout << d << '\n';
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Error: " << e.what() << '\n';
	// }

	printBold("\nsignForm() & executeForm()");
	Bureaucrat m("Mary", 140);
	std::cout << m << '\n';
	ShrubberyCreationForm fb("garden");
	std::cout << fb << '\n';
	m.signForm(fb);
	m.executeForm(fb);
	std::cout << fb << '\n';
	std::cout << '\n';
	Bureaucrat p("Paul", 137);
	std::cout << p << '\n';
	ShrubberyCreationForm fp("garden");
	std::cout << fp << '\n';
	p.executeForm(fp);
	p.signForm(fp);
	p.executeForm(fp);
	std::cout << fp << '\n';

	printBold("\n#####\nFORMS:\n#####");
	printBold("\n#####\nShrubberyCreationForm:\n#####");
	printBold("Full constructor");
	try {
		ShrubberyCreationForm f("garden");
		std::cout << f << '\n';
		Bureaucrat d("Didier", 137);
		d.signForm(f);
		f.execute(d);
		d.executeForm(f);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	printBold("\n#####\nRobotomyRequestForm:\n#####");
	printBold("Full constructor");
	try {
		RobotomyRequestForm f("cellar");
		std::cout << f << '\n';
		Bureaucrat a("Alice", 45);
		a.signForm(f);
		f.execute(a);
		a.executeForm(f);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	printBold("\n#####\nPresidentialPardonForm:\n#####");
	printBold("Full constructor");
	try {
		PresidentialPardonForm d("Didier");
		std::cout << d << '\n';
		Bureaucrat z("Zaphold", 5);
		z.signForm(d);
		d.execute(z);
		z.executeForm(d);
		Bureaucrat di("Didier", 142);
		d.execute(di);
		di.executeForm(d);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	printBold("\nAuto cleaning stage");
	return (0);
}
