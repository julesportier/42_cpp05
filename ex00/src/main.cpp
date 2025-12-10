#include "Bureaucrat.h"

static void printBold(std::string str)
{
	std::cout << "\e[1m" << str << "\e[0m\n";
}

int main(void)
{
	printBold("Full constructor");
	Bureaucrat j("Janine", 149);
	std::cout << j << '\n';

	printBold("\nDefault constructor");
	Bureaucrat a;
	std::cout << a << '\n';

	printBold("\nAssignement operator");
	a = j;
	std::cout << a << '\n';

	printBold("\nCopy constructor");
	Bureaucrat b(j);
	std::cout << b << '\n';

	printBold("\nException too low");
	try {
		Bureaucrat l0("Min", 150);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	try {
		Bureaucrat l1("Low", 151);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	printBold("\nException too high");
	try {
		Bureaucrat l1("Max", 1);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	try {
		Bureaucrat l0("Low", 0);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	try {
		Bureaucrat lneg("Low", -9200);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	printBold("\nDecrement grade");
	std::cout << j << '\n';
	j.decrementGrade();
	std::cout << j << '\n';
	try {
		j.decrementGrade();
		std::cout << j << '\n';
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	printBold("\nIncrement grade");
	Bureaucrat d("Didier", 2);
	std::cout << d << '\n';
	d.incrementGrade();
	std::cout << d << '\n';
	try {
		d.incrementGrade();
		std::cout << d << '\n';
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	printBold("\nAuto cleaning stage");
	return (0);
}
