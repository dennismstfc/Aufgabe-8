#pragma once
#include <string>
#include <iostream>
#include "Artikel.h"
#include <array>

class Person
{
public:

	Person();
	~Person() = default;

	void erstelleKunde();
	void werdeKunde();

	bool m_istKunde = false;
	std::array<Artikel*, 2> m_ausgelieheneArtikel;
	int m_anzahlAusgelieheneArtikel = 0;
	std::string m_name;


};

