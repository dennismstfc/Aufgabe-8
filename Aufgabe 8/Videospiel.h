#pragma once
#include "Artikel.h"
class Videospiel : public Artikel
{
public:
	Videospiel(int ID);
	~Videospiel() = default;

	void generiereDaten();
	std::string generiereTitel();
	void gebeDatenAus();
	bool istVerfuegbar();
	void verringereStueckzahl();
	std::string getTitel();
	int getID();
	int getErscheinungsjahr();


private:
	int m_speichergroeße = 0;
	int m_ID = 0;
	std::string m_titel;
	bool m_verfuegbar = false;
	int m_anzahlVerfuegbareVideospiele = 0;
	int m_erscheinungsjahr = 0;
};

