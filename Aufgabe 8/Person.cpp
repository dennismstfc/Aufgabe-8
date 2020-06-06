#include "Person.h"

Person::Person()
{

}

void Person::erstelleKunde()
{
	std::cout << "Bitte geben Sie den Namen des Kundes ein: ";
	std::cin >> m_name;
	std::cout << std::endl;
}

void Person::werdeKunde()
{
	m_istKunde = true;
}


