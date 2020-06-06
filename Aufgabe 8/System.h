#pragma once
#include "Buch.h"
#include "Videospiel.h"
#include "Hoerbuch.h"
#include "Artikel.h"
#include "Person.h"
#include <map>

class System
{
public:
	void fuegeKundeDemVerzeichnisZu(Person* kunde, int kundenID);
	void erstelleNeuenKunde(std::vector<Person*>& neuerKunde);
	void ausgelieheneArtikelAnsehen(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde);
	void gebeArtikelZurueck(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde);
	void alleArtikelAnsehen(std::vector<Artikel*>& gewuenschterArtikel);
	void leiheArtikelAus(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde);
	int waehleKundeAus();
	void sucheArtikelNachTitel(std::vector<Artikel*>& gewuenschterArtikel);
	void sucheArtikelNachID(std::vector<Artikel*>& gewuenschterArtikel);
	void sucheArtikel(std::vector<Artikel*>& gewuenschterArtikel);
	void run();

private:
	std::map <Person*, int> m_kundenverzeichnis;

};

