#include <string>

#include "utils.h"

using namespace std;

class Parser {

	public:

		static void parse_check_in(string options, Hotel* hotel);
		static void parse_check_out(string options, Hotel* hotel);
		static void parse_make_reservation(string options, Hotel* hotel);
		static void parse_cancel_reservation(string options, Hotel* hotel);
		static void parse_search_guest(string options, Hotel* hotel);
		static void parse_search_reservation(string options, Hotel* hotel);
		static void parse_list_rooms(string options, Hotel* hotel);
};
