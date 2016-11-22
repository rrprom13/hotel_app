#include <stdio.h>
#include <vector>

#include "room.h"

using namespace std;

class Floor {

		unsigned int nr_rooms;
		vector<Room*> rooms;
		unsigned int number;

	public:

		Floor(unsigned int number, unsigned int nr_rooms, vector<Room*> rooms);
		vector<Room*> getRooms();
		unsigned int getNumber();
		void check_in(unsigned int nr_room, Person* client, vector<Person*> guests);
		void check_out(unsigned int nr_room);
		void make_reservation(unsigned int nr_room, Person* person);
		void cancel_reservation(unsigned int nr_room);
		void list_rooms(vector<Room_state> states, vector<Room_type> types);
		bool search_guest(Person* person);
		bool search_reservation(Person* person);
};
