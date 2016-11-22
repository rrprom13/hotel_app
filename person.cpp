#include "person.h"

using namespace std;

Person::Person(string first_name, string last_name)
{
	this->first_name = string(first_name);
	this->last_name = string(last_name);
}

string Person::getFirstName()
{
	return first_name;
}

string Person::getLastName()
{
	return last_name;
}

bool Person::equals(Person* person)
{
	if (this == NULL || person == NULL) {
		return false;
	}
	if (this->first_name.compare(person->getFirstName()) == 0 &&
		this->last_name.compare(person->getLastName()) == 0) {
			return true;
	}
	return false;
}
