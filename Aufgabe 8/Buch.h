#pragma once
#include "Artikel.h"


class Buch :public Artikel
{
public:

	Buch(int ID);
	~Buch() = default;

	void generiereDaten();
	std::string generiereTitel();
	void gebeDatenAus();
	bool istVerfuegbar();
	void verringereStueckzahl();
	int getID();
	std::string getTitel();

private:
	int m_ID = 0;
	std::string m_titel;
	int m_seitenanzahl = 0;
	int m_anzahlVerfuegbareBuecher = 0;
	int m_verfuegbar = false;
	int m_erscheinungsjahr = 0;
};

