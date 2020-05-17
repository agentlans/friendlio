#include <iostream>
#include <string>

#include "friendlio.hpp"

int main()
{
	std::string name = ask_string("Enter your name");
	while (1) {
		int x = ask_integer("Enter integer from -100 to 100, inclusive", -100, 100);
		std::cout << name << " entered " << x << std::endl;

		double y = ask_double("Now give me a real number between 0 and 1", 0, 1);
		std::cout << "The product of " << x << " and " << y << " is " << x*y << std::endl;

		int c = ask_choice("Do you want to continue?", {"Yes", "No"});
		if (c == 1) break;
	}
	std::cout << "Goodbye " << name << "!" << std::endl;
	return 0;
}


