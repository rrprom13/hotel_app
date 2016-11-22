#include "floor.h"

using namespace std;

Floor::Floor(unsigned int number, unsigned int nr_rooms, vector<Room*> rooms)
{
    this->number = number;
    this->rooms = rooms;
	this->nr_rooms = nr_rooms;
}

vector<Room*> Floor::getRooms()
{
	return rooms;
}

unsigned int Floor::getNumber()
{
	return number;
}

void Floor::check_in(unsigned int nr_room, Person* client, vector<Person*> guests)
{
	unsigned int room = nr_room - number * 100;
	rooms[room - 1]->check_in(client, guests);
}

void Floor::check_out(unsigned int nr_room)
{
	int room = nr_room - number * 100;
	rooms[room - 1]->check_out();
}

void Floor::make_reservation(unsigned int nr_room, Person* person)
{
	int room = nr_room - number * 100;
	rooms[room - 1]->make_reservation(person);
}

void Floor::cancel_reservation(unsigned int nr_room)
{
	int room = nr_room - number * 100;
	rooms[room - 1]->cancel_reservation();
}

void Floor::list_rooms(vector<Room_state> states, vector<Room_type> types)
{
	for (unsigned int i = 0; i < rooms.size(); i++) {
		bool found_state = false;
		for (vector<Room_state>::iterator state_it = states.begin(); state_it != states.end(); ++state_it) {
    		if (rooms[i]->getState() == *state_it) {
    			found_state = true;
    			break;
    		}
		}
		if (states.size() > 0 && !found_state) {
			continue;
		}
		bool found_type = false;
		for (vector<Room_type>::iterator type_it = types.begin(); type_it != types.end(); ++type_it) {
    		if (rooms[i]->getType() == *type_it) {
    			found_type = true;
    			break;
    		}
		}
		if (types.size() > 0 && !found_type) {
			continue;
		}
		cout << rooms[i]->getNumber() << " " << rooms[i]->getTypeString() << " " << rooms[i]->getStateString() << endl;
	}
}

bool Floor::search_guest(Person* person)
{
	for (unsigned int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->search_guest(person)) {
			return true;
		}
	}
	return false;
}

bool Floor::search_reservation(Person* person)
{
	for (unsigned int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->search_reservation(person)) {
			return true;
		}
	}
	return false;
}
