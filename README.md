# Friendlio
User-friendly input validation

Provides functions to ask the user for certain types of inputs (string, integer, or double) at the console.

## Install
- Copy `friendlio.hpp`, `friendlio.cpp`, and the copyright notice to your application.

- Compile with `g++ demo.cpp friendlio.cpp` or other C++ compiler

## Use

Available functions are listed in the header file:
```c++
// Asks user for a string or an integer or double number within the given bounds (inclusive)
std::string ask_string(const std::string& prompt);
int ask_integer(const std::string& prompt, int min_bound, int max_bound);
double ask_double(const std::string& prompt, double min_bound, double max_bound);

// Displays a menu and returns the index of the user's choice
int ask_choice(const std::string& prompt, const std::vector<std::string>& choices);
```

Example program that uses the library:
```c++
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
```

Example session:
```
Enter your name: Alice
Enter integer from -100 to 100, inclusive: 123
Number not in range.
Enter integer from -100 to 100, inclusive: asdf34
Couldn't recognize the number.
Enter integer from -100 to 100, inclusive: 12
Alice entered 12
Now give me a real number between 0 and 1: -9
Number not in range.
Now give me a real number between 0 and 1: asdf
Couldn't recognize the number.
Now give me a real number between 0 and 1: 0.2
The product of 12 and 0.2 is 2.4
Do you want to continue?
1. Yes
2. No
Your choice: 2
Goodbye Alice!
```


## Author, License
Copyright (C) 2020 Alan Tseng

MIT License
