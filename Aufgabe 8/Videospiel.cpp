#include "Videospiel.h"

Videospiel::Videospiel(int ID)
{
	m_ID = ID;
	generiereDaten();
}

void Videospiel::generiereDaten()
{
	generiereTitel();
	m_speichergroeﬂe = rand() % 100 + 1;
	m_anzahlVerfuegbareVideospiele = rand() % 4 + 1;
	m_erscheinungsjahr = rand() % 30 + 1990;
}

std::string Videospiel::generiereTitel()
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

void Videospiel::gebeDatenAus()
{
	std::cout << typeid(this).name() << " Titel: " << m_titel << "\t ID: " << m_ID << "\t Speicherplatz: " << m_speichergroeﬂe << "\t Erscheinungsjahr: " << m_erscheinungsjahr  << "\tAnzahl: " << m_anzahlVerfuegbareVideospiele << std::endl;
}

bool Videospiel::istVerfuegbar()
{
	if (m_anzahlVerfuegbareVideospiele == 0) {
		m_verfuegbar = false;
	}
	else {
		m_verfuegbar = true;
	}
	return m_verfuegbar;
}

void Videospiel::verringereStueckzahl()
{
	m_anzahlVerfuegbareVideospiele--;
}

std::string Videospiel::getTitel()
{
	return m_titel;
}

int Videospiel::getID()
{
	return m_ID;
}

int Videospiel::getErscheinungsjahr()
{
	return m_erscheinungsjahr;
}
