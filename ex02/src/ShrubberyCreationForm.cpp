#include "ShrubberyCreationForm.h"
#include <iostream>
#include <fstream>

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm()
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm::AForm("ShrubberyForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm::AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

/************
* OPERATORS *
************/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm& src)
{
	(void)src;
	std::cout << "Can't reasign form\n";
	return (*this);
}

/**********
* METHODS *
**********/
static std::string generateTree();
static int putStrInFile(std::string tree, std::string target);

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkExecRights(executor);
	if (putStrInFile(generateTree(), getTarget()) == -1) {
		throw std::ios_base::failure("file operation failed");
	}
}

static std::string generateTree()
{
	return (
		"    *    \n"
		"   ***   \n"
		"  *****  \n"
		" ******* \n"
		"*********\n"
		"   ***   \n"
		"   ***   \n"
		"\n"
		"      __      \n"
		"    /    \\    \n"
		"   /      \\   \n"
		"  |        |  \n"
		"   \\      /   \n"
		"    \\    /    \n"
		"     |   |    \n"
		"     |   |    \n"
		"     |   |    ");
}

static int putStrInFile(std::string tree, std::string target)
{
	std::string str("_shrubbery");
	std::ofstream ofs((target + str).c_str(), std::ios::out);
	if (ofs.is_open()) {
		ofs << tree;
		ofs.close();
		return (0);
	}
	else
		return (-1);
}
