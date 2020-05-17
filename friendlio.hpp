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

#ifndef _FRIENDLIO
#define _FRIENDLIO

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>

// Asks user for a string or an integer or double number within the given bounds (inclusive)
std::string ask_string(const std::string& prompt);
int ask_integer(const std::string& prompt, int min_bound, int max_bound);
double ask_double(const std::string& prompt, double min_bound, double max_bound);

// Displays a menu and returns the index of the user's choice
int ask_choice(const std::string& prompt, const std::vector<std::string>& choices);

// Joins a vector of strings into a single string separated by the delimiter
std::string join_strings(const std::vector<std::string>& strings, const std::string& delim);

#endif

