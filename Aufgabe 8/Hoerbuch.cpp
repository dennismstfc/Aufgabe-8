#include "Hoerbuch.h"

Hoerbuch::Hoerbuch(int ID)
{
	m_ID = ID;
	generiereDaten();
}

void Hoerbuch::generiereDaten()
{
	generiereTitel();
	m_dauer = rand() % 100;
	m_anzahlVerfuegbareHoerbuecher = rand() % 4 + 1;
}

std::string Hoerbuch::generiereTitel()
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

void Hoerbuch::gebeDatenAus()
{
	std::cout << typeid(this).name() << " Titel: " << m_titel << "\t ID: " << m_ID << "\t Dauer: " << m_dauer << "\tAnzahl: " << m_anzahlVerfuegbareHoerbuecher << std::endl;
}

bool Hoerbuch::istVerfuegbar()
{
	if (m_anzahlVerfuegbareHoerbuecher == 0) {
		m_verfuegbar = false;
	}
	else {
		m_verfuegbar = true;
	}
	return m_verfuegbar;
}

void Hoerbuch::verringereStueckzahl()
{
	m_anzahlVerfuegbareHoerbuecher--;
}

std::string Hoerbuch::getTitel()
{
	return m_titel;
}

int Hoerbuch::getID()
{
	return m_ID;
}


