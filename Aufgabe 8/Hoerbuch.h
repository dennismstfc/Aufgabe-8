#pragma once
#include "Artikel.h"
class Hoerbuch :
	public Artikel
{
public:
	Hoerbuch(int ID);
	~Hoerbuch() = default;

	void generiereDaten();
	std::string generiereTitel();
	void gebeDatenAus();
	bool istVerfuegbar();
	void verringereStueckzahl();
	std::string getTitel();
	int getID();
	int getErscheinungsjahr();

private:
	int m_dauer = 0;
	int m_ID = 0;
	std::string m_titel;
	int m_anzahlVerfuegbareHoerbuecher = 0;
	bool m_verfuegbar = false;
	int m_erscheinungsjahr = 0;
};

