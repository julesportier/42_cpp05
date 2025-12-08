#include "Bureaucrat.h"
#include "Form.h"

static void printBold(std::string str)
{
	std::cout << "\e[1m" << str << "\e[0m\n";
}

int	main(void)
{
	printBold("###########\nBUREAUCRAT:\n###########");
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
		std::cout << e.what() << '\n';
	}
	try {
		Bureaucrat l1("Low", 151);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	printBold("\nException too high");
	try {
		Bureaucrat l1("Max", 1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		Bureaucrat l0("Low", 0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		Bureaucrat lneg("Low", -9200);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
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
		std::cout << e.what() << '\n';
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
		std::cout << e.what() << '\n';
	}

	printBold("\nsignForm()");
	Bureaucrat m("Mary", 140);
	std::cout << m << '\n';
	Form fb("b82h405", 140, 100);
	std::cout << fb << '\n';
	m.signForm(fb);
	std::cout << fb << '\n';
	std::cout << '\n';
	Bureaucrat p("Paul", 141);
	std::cout << p << '\n';
	Form fp("b82h405", 140, 100);
	std::cout << fp << '\n';
	b.signForm(fp);
	std::cout << fp << '\n';

	printBold("\n#####\nFORM:\n#####");
	printBold("Full constructor");
	Form f("c243b27", 140, 100);
	std::cout << f << '\n';

	printBold("\nDefault constructor");
	Form x;
	std::cout << x << '\n';

	printBold("\nAssignement operator");
	x = f;
	std::cout << x << '\n';

	printBold("\nCopy constructor");
	Form g(f);
	std::cout << g << '\n';

	printBold("\nException too low");
	try {
		Form fl("Min", 150, 150);
		std::cout << fl << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Form fl("Low", 151, 150);
		std::cout << fl << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Form fl("Low", 150, 151);
		std::cout << fl << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	printBold("\nException too high");
	try {
		Form fh("Max", 1, 1);
		std::cout << fh << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Form fh("Low", 0, 1);
		std::cout << fh << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Form fh("Low", 1, 0);
		std::cout << fh << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Form fh("Neg", -1, 1);
		std::cout << fh << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Form fh("Neg", 1, -1);
		std::cout << fh << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	printBold("\nbeSigned()");
	try {
		Bureaucrat b("Mary", 140);
		std::cout << b << '\n';
		Form f("b82h405", 140, 100);
		std::cout << f << '\n';
		f.beSigned(b);
		std::cout << f << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat b("Paul", 141);
		std::cout << b << '\n';
		Form f("b82h405", 140, 100);
		std::cout << f << '\n';
		f.beSigned(b);
		std::cout << f << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	printBold("\nAuto cleaning stage");
	return (0);
}
