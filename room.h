#include <stdio.h>
#include <vector>
#include <iostream>


#include "person.h"

using namespace std;

enum Room_type {Single, Double, Suite};
enum Room_state {Available, Taken, Used, Reserved};

class Room {

        unsigned int number;
        Room_type type;
        Room_state state;
		Person* client;
		vector<Person*> guests;

	public:

		Room(unsigned int number, Room_type type, Room_state state);
		unsigned int getNumber();
        Room_type getType();
        Room_state getState();
		void setPersonReserved(Person* person);
		Person* getPersonReserved();
		void check_in(Person* client, vector<Person*> guests);
		void check_out();
		void perform_maintenance();
		void make_reservation(Person* person);
		void cancel_reservation();
		bool search_guest(Person* person);
		bool search_reservation(Person* person);
		string getTypeString();
		string getStateString();
};
