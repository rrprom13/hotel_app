#include <stdio.h>
#include <vector>
#include <iostream>

#include "floor.h"

using namespace std;

class Hotel {

		unsigned int nr_floors;
		unsigned int nr_floor_rooms;
		vector<Floor*> floors;

	public:

		Hotel(unsigned int nr_floors, unsigned int nr_floor_rooms);
		void init();
		vector<Floor*> getFloors();
		void setFloors(vector<Floor*> floor);
		void check_in(unsigned int nr_room, Person* client, vector<Person*> guests);
		void check_out(unsigned int nr_room);
		void make_reservation(unsigned int nr_room, Person* person);
		void cancel_reservation(unsigned int nr_room);
		void list_rooms(vector<Room_state> states, vector<Room_type> types);
		void search_guest(Person* person);
		void search_reservation(Person* person);
		bool is_valid_room_number(unsigned int room_number);
};
