#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>

#include "utils.h"

using namespace std;

// checks if a string can be converted to unsigned int
unsigned int Utils::validate_number(string string_number)
{
	if (string_number.size() == 0) {
		return 0;
	}
	unsigned int power = 1;
	unsigned int number = 0;
	for (string::iterator it = string_number.end() - 1 ; it >= string_number.begin() ; it--) {
		if (*it < '0' || *it > '9') {
			return 0;
		}
		if (*it == 0 && it == string_number.begin()) {
			return 0;
		}
		number += (*it - '0') * power;
		power *= 10;
	}
	return number;
}

// checks if a string can be a valid room number in the hotel
unsigned int Utils::validate_room_number(string string_number, Hotel* hotel)
{
	unsigned int number = validate_number(string_number);
	if (number == 0) {
		return 0;
	}
	if (!(hotel->is_valid_room_number(number))) {
		cout << "Specified room does not exist" << endl;
		return 0;
	}
	return number;
}

// checks if a name is valid
string Utils::validate_name(string name, bool first_name)
{
	if (name.size() == 0) {
		return "";
	}
	string result = "";
	bool capital = true;
	for (string::iterator it = name.begin() ; it < name.end() ; it++) {
		if ((*it < 'a' || *it > 'z') && (*it < 'A' || *it > 'Z')) {
			if (first_name || *it != '-' || capital) {
				return "";
			}
		}
		if (capital && *it >= 'a' && *it <= 'z') {
			result += (*it - 32);
		} else if (!capital && *it >= 'A' && *it <= 'Z') {
			result += (*it + 32);
		} else {
			result += *it;
		}
		capital = false;
		if (*it == '-') {
			capital = true;
		}
	}
	return result;
}

// checks if a client's name is valid
Person* Utils::validate_client_name(string client_name)
{
	Person* person = NULL;
	string first = client_name.substr(0, client_name.find(hyphen_delimiter));
	client_name.erase(0, first.size() + hyphen_delimiter.length());
	string last = client_name;

	string first_name = validate_name(first, true);
	if (first_name == "") {
		return NULL;
	}
	string last_name = validate_name(last, false);
	if (last_name == "") {
		return NULL;
	}

	return new Person(first_name, last_name);
}

// trims the input string
string Utils::trim(string input)
{
	if (input.size() == 0) {
		return "";
	}

	bool prev_space = false;
	unsigned int start_index = 0, end_index = input.size() - 1;
	string result = "";

	for (string::iterator it = input.begin(); it < input.end() && *it == ' ' ; it++, start_index++);

	if (start_index == input.size()) {
		return "";
	}

	for (string::iterator it = input.end() - 1 ; it >= input.begin() && *it == ' ' ; it--, end_index--);
	
	for (unsigned int current_index = start_index ; current_index <= end_index ; current_index++) {
		char ch = input[current_index];
		if (ch != ' ') {
			result += ch;
			prev_space = false;
		} else if (!prev_space) {
			result += ch;
			prev_space = true;
		}
	}

	return result;
}

// prints to std::cout data contained in the file parameter
void Utils::print_file(string filename)
{
	ifstream infile(filename.c_str());
	string line;
	while (getline(infile, line)) {
		cout << line << endl;
	}
}
