#include <string>

#include "hotel.h"

using namespace std;

extern string space_delimiter;
extern string hyphen_delimiter;

class Utils {
		
		static string validate_name(string name, bool first_name);

	public:

		static unsigned int validate_number(string string_number);
		static unsigned int validate_room_number(string string_number, Hotel* hotel);
		static Person* validate_client_name(string client_name);
		static string trim(string input);
		static void print_file(string filename);
};
