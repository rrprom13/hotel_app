#include "hotel.h"

using namespace std;

Hotel::Hotel(unsigned int nr_floors, unsigned int nr_floor_rooms)
{
	this->nr_floors = nr_floors;
	this->nr_floor_rooms = nr_floor_rooms;
}

void Hotel::init()
{
	for (unsigned int floor_index = 1 ; floor_index <= nr_floors ; floor_index++) {
		vector<Room*> rooms;
		for (unsigned int room_index = 1 ; room_index <= nr_floor_rooms; room_index++) {
			unsigned int room_number = floor_index * 100 + room_index;
			Room_type type;
			if (room_number % 3 == 0) {
				type = Single;
			} else if (room_number % 3 == 1) {
				type = Double;
			} else {
				type = Suite;
			}
			Room* room = new Room(floor_index * 100 + room_index, type, Available);
			rooms.push_back(room);
		}
		Floor* floor = new Floor(floor_index, nr_floor_rooms, rooms);
		floors.push_back(floor);
	}
}

vector<Floor*> Hotel::getFloors()
{
	return floors;
}

void Hotel::setFloors(vector<Floor*> floors)
{
	this->floors = floors;
}

void Hotel::check_in(unsigned int nr_room, Person* client, vector<Person*> guests)
{
	unsigned int floor = nr_room / 100;
	floors[floor - 1]->check_in(nr_room, client, guests);
}

void Hotel::check_out(unsigned int nr_room)
{
	unsigned int floor = nr_room / 100;
	floors[floor - 1]->check_out(nr_room);
}

void Hotel::make_reservation(unsigned int nr_room, Person* person)
{
	unsigned int floor = nr_room / 100;
	floors[floor - 1]->make_reservation(nr_room, person);
}

void Hotel::cancel_reservation(unsigned int nr_room)
{
	unsigned int floor = nr_room / 100;
	floors[floor - 1]->cancel_reservation(nr_room);
}

void Hotel::list_rooms(vector<Room_state> states, vector<Room_type> types)
{
	for (unsigned int i = 0; i < floors.size(); i++) {
		floors[i]->list_rooms(states, types);
	}
}

void Hotel::search_guest(Person* person)
{
	for (unsigned int i = 0; i < floors.size(); i++) {
		if (floors[i]->search_guest(person)) {
			return;
		}
	}
	cout << "Guest " << person->getFirstName() << " " << person->getLastName() << " has not been found" << endl;
}

void Hotel::search_reservation(Person* person)
{
	for (unsigned int i = 0; i < floors.size(); i++) {
		if (floors[i]->search_reservation(person)) {
			return;
		}
	}
	cout << "Reservation for " << person->getFirstName() << " " << person->getLastName() << " has not been found" << endl;
}

bool Hotel::is_valid_room_number(unsigned int room_number)
{
	if (room_number < 100) {
		return false;
	}
	if (room_number / 100 > nr_floors) {
		return false;
	}
	if (room_number % 100 == 0) {
		return false;
	}
	if (room_number - room_number / 100 * 100 > nr_floor_rooms) {
		return false;
	}
	return true;
}