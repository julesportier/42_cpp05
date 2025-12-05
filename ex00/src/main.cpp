#include "Bureaucrat.h"

static void printBold(std::string str)
{
	std::cout << "\e[1m" << str << "\e[0m\n";
}

int	main(void)
{
	printBold("Full constructor");
	Bureaucrat j("Janine", 123);
	std::cout << j << '\n';
	printBold("\nDefault constructor");
	Bureaucrat a;
	std::cout << a << '\n';
	printBold("\nAssignement operator");
	a = j;
	printBold("\nCopy constructor");
	Bureaucrat b(j);
	printBold("\nException too low");
	try {
		Bureaucrat l0("Min", 150);
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		Bureaucrat l1("Low", 151);
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	printBold("\nException too high");
	try {
		Bureaucrat l1("Max", 1);
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		Bureaucrat l0("Low", 0);
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		Bureaucrat lneg("Low", -9200);
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	printBold("\nAuto cleaning stage");
	return (0);
}
