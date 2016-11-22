#include <string>

#include "room.h"

using namespace std;

Room::Room(unsigned int number, Room_type type, Room_state state)
{
    this->number = number;
    this->type = type;
    this->state = state;
}

unsigned int Room::getNumber()
{
	return number;
}

Room_type Room::getType()
{
    return type;
}

Room_state Room::getState()
{
    return state;
}

void Room::setPersonReserved(Person* person)
{
	this->client = person;
}

Person* Room::getPersonReserved()
{
	return client;
}

void Room::check_in(Person* client, vector<Person*> guests)
{
	if (state == Taken) {
		cout << "Sorry, room " << number << " is already checked-in" << endl;
		return;
	}
	if (state == Reserved && !client->equals(this->client)) {
		cout << "Sorry, room " << number << " could not be checked-in since it is already booked by somebody else" << endl;
		return;
	}
	perform_maintenance();
	state = Taken;
	this->client = client;
	this->guests = guests;
	cout << "Congrats, room " << number << " has been successfully checked-in" << endl;
}

void Room::check_out()
{
	if (state == Taken) {
		state = Used;
		client = NULL;
		guests.clear();
		cout << "Congrats, room " << number << " has been successfully checked-out" << endl;
	}
	else {
		cout << "Room " << number << " is not checked-in" << endl;
	}
}

void Room::perform_maintenance()
{
	if (state == Used) {
		state = Available;
		cout << "Room " << number << " has been successfully cleaned" << endl;
	}
	else {
		cout << "There is no need for cleaning up room " << number << endl;
	}
}

void Room::make_reservation(Person* person)
{
	if (state == Used) {
		perform_maintenance();
	}
	if (state == Available) {
		state = Reserved;
		client = person;
		cout << "Congrats, room " << number << " has been successfully booked" << endl;
	} else if (state == Reserved) {
		cout << "Sorry, room " << number << " is already booked" << endl;
	} else if (state == Taken) {
		cout << "Sorry, room " << number << " is checked-in" << endl;
	}
}

void Room::cancel_reservation()
{
	if (state == Reserved) {
		state = Available;
		client = NULL;
		guests.clear();
		cout << "Room " << number << " has been successfully unbooked" << endl;
	}
	else {
		cout << "Room " << number << " is not booked" << endl;
	}
}

bool Room::search_guest(Person* person)
{
	if (state != Taken) {
		return false;
	}
	if (person->equals(client)) {
		cout << "Guest " << person->getFirstName() << " " << person->getLastName() << " has been found in room " << number << endl;
		return true;
	}
	for (unsigned int i = 0; i < guests.size(); i++) {
		if (guests[i]->equals(person)) {
			cout << "Guest " << person->getFirstName() << " " << person->getLastName() << " has been found in room " << number << endl;
			return true;
		}
	}
	return false;
}

bool Room::search_reservation(Person* person)
{
	if (state != Reserved) {
		return false;
	}
	if (person->equals(client)) {
		cout << "Reservation for " << person->getFirstName() << " " << person->getLastName() << " has been found in room " << number << endl;
		return true;
	}
	return false;
}

string Room::getStateString()
{
	switch (state) {
		case Available:
						return string("available");
		case Taken:
						return string("taken");
		case Used:
						return string("used");
		case Reserved:
						return string("reserved");
	}
}

string Room::getTypeString()
{
	switch (type) {
		case Single:
						return string("single");
		case Double:
						return string("double");
		case Suite:
						return string("suite");
	}
}