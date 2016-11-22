#include <string>

using namespace std;

class Person {

		string first_name;
		string last_name;

	public:

		Person(string first_name, string last_name);

		bool equals(Person* person);

		string getFirstName();

		string getLastName();
};
