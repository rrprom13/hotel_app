#include <iostream>

#include "parser.h"

using namespace std;

string space_delimiter = " ";
string hyphen_delimiter = "-";

int main(int args, char** argv)
{
	cout << "For general information regarding the hotel, type 'info'." << endl;
	cout << "To display the available commands and their input, type 'commands'." << endl;
	cout << "Providing you already know this intel, type 'input' in order to init the hotel's parameters." << endl;
	cout << "In order to exit the application, type 'exit' whenever you wish." << endl;

	string input, command;

	// loop until command is different from  "input"
	do {
		cout << endl;
		cout << "Insert new command: ";
		getline(cin, input);
		input = Utils::trim(input);
		if (input.compare("exit") == 0) {
			return 0;
		} else if (input.compare("info") == 0) {
			Utils::print_file("info.txt");
		} else if (input.compare("commands") == 0) {
			Utils::print_file("commands.txt");
		} else if (input.compare("input") == 0) {
			break;
		} else {
			cout << endl << "Invalid command. Available commands are 'info', 'commands', 'input', 'exit'." << endl;
		}
	} while (true);

	unsigned int nr_floors;
	unsigned int nr_floor_rooms;

	// loop until user does not insert a valid number of floors
	do {
		cout << endl;
		cout << "Insert number of floors: ";
		getline(cin, input);
		input = Utils::trim(input);
		if (input.compare("exit") == 0) {
			return 0;
		}
		nr_floors = Utils::validate_number(input);
		if (nr_floors == 0) {
			cout << endl << "Invalid number of floors" << endl;
		}
	} while (nr_floors == 0);

	// loop until user does not insert a valid number of rooms per floor
	do {
		cout << endl;
		cout << "Insert number of rooms per floor: ";
		getline(cin, input);
		input = Utils::trim(input);
		if (input.compare("exit") == 0) {
			return 0;
		}
		nr_floor_rooms = Utils::validate_number(input);
		if (nr_floor_rooms == 0) {
			cout << endl << "Invalid number of rooms per floor" << endl;
		}
	} while (nr_floor_rooms == 0);

	Hotel* hotel = new Hotel(nr_floors, nr_floor_rooms);
	hotel->init();

	// loop while command is different from "exit"
	while (true) {
		cout << endl;
		cout << "Insert new command: ";
		getline(cin, input);
		input = Utils::trim(input);
		if (input.compare("exit") == 0) {
			break;
		}
		cout << endl;
		command = input.substr(0, input.find(space_delimiter));
		input.erase(0, command.size() + space_delimiter.length());
		if (command.compare("check_in") == 0) {
			Parser::parse_check_in(input, hotel);
		} else if (command.compare("check_out") == 0) {
			Parser::parse_check_out(input, hotel);
		} else if (command.compare("make_reservation") == 0) {
			Parser::parse_make_reservation(input, hotel);
		} else if (command.compare("cancel_reservation") == 0) {
			Parser::parse_cancel_reservation(input, hotel);
		} else if (command.compare("search_guest") == 0) {
			Parser::parse_search_guest(input, hotel);
		} else if (command.compare("search_reservation") == 0) {
			Parser::parse_search_reservation(input, hotel);
		} else if (command.compare("list_rooms") == 0) {
			Parser::parse_list_rooms(input, hotel);
		} else if (command.compare("info") == 0 && input.size() == 0) {
			Utils::print_file("info.txt");
		} else if (command.compare("commands") == 0 && input.size() == 0) {
			Utils::print_file("commands.txt");
		} else if (command.compare("input") == 0 && input.size() == 0) {
			cout << "Hotel's parameters have already been specified." << endl;
		} else {
			cout << "Invalid command" << endl;
		}
	}

    return 0;
}
