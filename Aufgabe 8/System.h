#pragma once
#include "Buch.h"
#include "Videospiel.h"
#include "Hoerbuch.h"
#include "Artikel.h"
#include "Person.h"
#include <map>
#include <set>
#include <fstream>

class System
{
public:
	
	void fuegeKundeDemVerzeichnisZu(Person* kunde, int kundenID);
	void erstelleNeuenKunde(std::vector<Person*>& neuerKunde);
	void gebeAlleKundenAus(std::map <Person*, int> kundenverzeichnis);
	void ausgelieheneArtikelAnsehen(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde);
	void gebeArtikelZurueck(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde);
	void alleArtikelAnsehen();
	void schreibeInProtkollDatei(Person* kunde, Artikel* ausgeliehenerArtikel);
	void leiheArtikelAus(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde);
	int waehleKundeAus();
	void sucheArtikelNachTitel(std::vector<Artikel*>& gewuenschterArtikel);
	void sucheArtikelNachID(std::vector<Artikel*>& gewuenschterArtikel);
	void sucheArtikel(std::vector<Artikel*>& gewuenschterArtikel);
	void run();

private:

	std::map <Person*, int> m_kundenverzeichnis;
	std::multiset<std::pair<int, std::string>>  m_alleArtikelSortiertNachErscheinungsjahr;
	int m_index = 0;
};

