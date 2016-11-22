#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "parser.h"

using namespace std;

// parse check_in command with parameters - options
void Parser::parse_check_in(string options, Hotel* hotel)
{
	size_t pos = 0;

	string room_nr = options.substr(0, options.find(space_delimiter));
	options.erase(0, room_nr.size() + space_delimiter.length());

	if (options.size() == 0) {
		cout << "Invalid input for client name" << endl;
		return;
	}

	unsigned int room_number = Utils::validate_room_number(room_nr, hotel);
	if (room_number == 0) {
		cout << "Invalid input for room number" << endl;
		return;
	}

	Person* client;
	vector<Person*> guests;

	bool first_person = true;

	// while there are more names to be processed
	while (options.size() > 0) {
		size_t pos = options.find(space_delimiter);

		string token = options.substr(0, pos);

		if (token.size() == 0) {
			cout << "Invalid input for client name" << endl;
			return;
		}

		options.erase(0, token.size() + space_delimiter.length());

		Person *person = Utils::validate_client_name(token);
		if (person == NULL) {
			cout << "Invalid input for client name" << endl;
			return;
		}

		if (first_person) {
			client = person;
			first_person = false;
		} else {
			guests.push_back(person);
		}
	}

	hotel->check_in(room_number, client, guests);
}

// parse check_out command with parameters - options
void Parser::parse_check_out(string options, Hotel* hotel)
{
	string room_nr = options.substr(0, options.find(space_delimiter));
	options.erase(0, room_nr.size() + space_delimiter.length());

	if (options.size() > 0) {
		cout << "Invalid input for room number" << endl;
		return;
	}

	unsigned int room_number = Utils::validate_room_number(room_nr, hotel);
	if (room_number == 0) {
		cout << "Invalid input for room number" << endl;
		return;
	}
	hotel->check_out(room_number);
}

// parse make_reservation command with parameters - options
void Parser::parse_make_reservation(string options, Hotel* hotel)
{
	string room_nr = options.substr(0, options.find(space_delimiter));
	options.erase(0, room_nr.size() + space_delimiter.length());

	if (options.size() == 0) {
		cout << "Invalid input for client name" << endl;
		return;
	}

	unsigned int room_number = Utils::validate_room_number(room_nr, hotel);
	if (room_number == 0) {
		cout << "Invalid input for room number" << endl;
		return;
	}

	Person *person = Utils::validate_client_name(options);
	if (person == NULL) {
		cout << "Invalid input for client name" << endl;
		return;
	}

	hotel->make_reservation(room_number, person);
}

// parse cancel_reservation command with parameters - options
void Parser::parse_cancel_reservation(string options, Hotel* hotel)
{
	string room_nr = options.substr(0, options.find(space_delimiter));
	options.erase(0, room_nr.size() + space_delimiter.length());

	if (options.size() > 0) {
		cout << "Invalid input for room number" << endl;
		return;
	}

	unsigned int room_number = Utils::validate_room_number(room_nr, hotel);
	if (room_number == 0) {
		cout << "Invalid input for room number" << endl;
		return;
	}

	hotel->cancel_reservation(room_number);
}

// parse search_guest command with parameters - options
void Parser::parse_search_guest(string options, Hotel* hotel)
{
	Person *person = Utils::validate_client_name(options);
	if (person == NULL) {
		cout << "Invalid input for guest name" << endl;
		return;
	}

	hotel->search_guest(person);
}

// parse search_reservation command with parameters - options
void Parser::parse_search_reservation(string options, Hotel* hotel)
{
	Person *person = Utils::validate_client_name(options);
	if (person == NULL) {
		cout << "Invalid input for guest name" << endl;
		return;
	}

	hotel->search_reservation(person);
}

// parse list_rooms command with parameters - options
void Parser::parse_list_rooms(string options, Hotel* hotel)
{
	size_t pos = 0;

	vector<Room_state> state_filter;
	vector<Room_type> type_filter;

	while (options.size() > 0) {
		size_t pos = options.find(space_delimiter);

		string token = options.substr(0, pos);

		options.erase(0, token.size() + space_delimiter.length());

		if (token.compare("available") == 0) {
			state_filter.push_back(Available);
		} else if (token.compare("reserved") == 0) {
			state_filter.push_back(Reserved);
		} else if (token.compare("taken") == 0) {
			state_filter.push_back(Taken);
		} else if (token.compare("used") == 0) {
			state_filter.push_back(Used);
		} else
			if (token.compare("single") == 0) {
				type_filter.push_back(Single);
			} else if (token.compare("double") == 0) {
				type_filter.push_back(Double);
			} else if (token.compare("suite") == 0) {
				type_filter.push_back(Suite);
			} 
				else {
					cout << "Wrong " << token << " option for room type or state" << endl;
					return;
				}
	}

	hotel->list_rooms(state_filter, type_filter);
}