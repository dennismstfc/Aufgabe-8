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


private:
	int m_speichergroeﬂe = 0;
	int m_ID = 0;
	std::string m_titel;
	bool m_verfuegbar = false;
	int m_anzahlVerfuegbareVideospiele = 0;
};

