#include "Buch.h"

Buch::Buch(int ID)
{
	m_ID = ID;
	generiereDaten();

}

void Buch::generiereDaten()
{
	generiereTitel();
	m_seitenanzahl = rand() % 1985 + 15;
	m_anzahlVerfuegbareBuecher = rand() % 4 + 1;
	m_erscheinungsjahr = rand() % 130 + 1900;
}

std::string Buch::generiereTitel()
{
	static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	static const std::string beginn = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
	static std::default_random_engine rng(std::time(nullptr));
	static std::uniform_int_distribution<std::size_t> distribution(0, alphabet.size() - 1);

	int length = rand() % 7 + 2;
	int anfangsBuchstabe = rand() % 26;
	m_titel = beginn[anfangsBuchstabe];

	while (m_titel.size() < length) m_titel += alphabet[distribution(rng)];
	return m_titel;
}

void Buch::gebeDatenAus()
{
	std::cout << typeid(this).name() << " Titel: " << m_titel << "\t ID: " << m_ID << "\t Seitenanzahl: " << m_seitenanzahl << "\t Erscheinungsjahr: " << m_erscheinungsjahr << "\tAnzahl: " << m_anzahlVerfuegbareBuecher << std::endl;
}

bool Buch::istVerfuegbar()
{
	if (m_anzahlVerfuegbareBuecher == 0) {
		m_verfuegbar = false;

	}
	else {
		m_verfuegbar = true;
	}
	return m_verfuegbar;
}

void Buch::verringereStueckzahl()
{
	m_anzahlVerfuegbareBuecher--;
}

int Buch::getID()
{
	return m_ID;
}

std::string Buch::getTitel()
{
	return m_titel;
}

int Buch::getErscheinungsjahr()
{
	return m_erscheinungsjahr;
}
