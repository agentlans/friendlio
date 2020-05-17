/* 
MIT License

Copyright (c) 2020 Alan Tseng

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "friendlio.hpp"

// Asks for a string from the user and returns it or throws an error.
std::string ask_string(const std::string& prompt)
{
	std::cout << prompt << ": ";

	std::string input;
	std::getline(std::cin, input);
	if (std::cin.rdstate()) { // When EOF immediately
		throw std::invalid_argument("No input.");
	}
	return input;
}

// Joins a vector of strings using the given delimiter.  Returns the joined string.
std::string join_strings(const std::vector<std::string>& strings, const std::string& delim)
{
	std::stringstream ss;
	int num_str = strings.size();
	for (int i = 0; i < num_str; ++i) {
		ss << strings[i];
		if (i != num_str - 1) {
			ss << delim;
		}
	}
	return ss.str();
}

// Asks user for an integer within the specified bounds. Will keep asking if there is an error or
// will raise exception if it's end of file.
int ask_integer(const std::string& prompt, int min_bound, int max_bound)
{
ask_num:
	std::string input = ask_string(prompt);
	int x;
	try {
		x = std::stoi(input);
		if (!(min_bound <= x && x <= max_bound)) {
			throw std::domain_error("Number not in range.");
		}
	} catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
		goto ask_num;
	} catch (std::invalid_argument e) {
		std::cout << "Couldn't recognize the number." << std::endl;
		goto ask_num;
	}
	return x;
}

// Displays a menu and asks user for a choice. Returns the index of the chosen option.
int ask_choice(const std::string& prompt, const std::vector<std::string>& choices)
{
	std::cout << prompt << std::endl;
	// Show a menu of choices
	int cs = choices.size();
	for (int i = 0; i < cs; ++i) {
		std::cout << i+1 << ". " << choices[i] << std::endl;
	}
	int user_input = ask_integer("Your choice", 1, cs);
	return user_input - 1;
}

// Asks user for a double type number within the specified bounds. Will keep asking if there is an error or
// will raise exception if it's end of file.
double ask_double(const std::string& prompt, double min_bound, double max_bound)
{
ask_num:
	std::string input = ask_string(prompt);
	double x;
	try {
		x = std::stod(input);
		if (!(min_bound <= x && x <= max_bound)) {
			throw std::domain_error("Number not in range.");
		}
	} catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
		goto ask_num;
	} catch (std::invalid_argument e) {
		std::cout << "Couldn't recognize the number." << std::endl;
		goto ask_num;
	}
	return x;
}

