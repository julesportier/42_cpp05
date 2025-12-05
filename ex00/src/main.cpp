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
	return (0);
}
