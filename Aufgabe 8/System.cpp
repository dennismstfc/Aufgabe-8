#include "System.h"

  
void System::fuegeKundeDemVerzeichnisZu(Person* kunde, int kundenID)
{
	m_kundenverzeichnis[kunde] = kundenID;
}

void System::erstelleNeuenKunde(std::vector<Person*>& neuerKunde)
{
	neuerKunde[m_index] = new Person;
	neuerKunde[m_index]->erstelleKunde();
	fuegeKundeDemVerzeichnisZu(neuerKunde[m_index], m_index);
	m_index++;
}

void System::gebeAlleKundenAus(std::map <Person*, int> kundenverzeichnis)
{
	std::cout << std::endl;
	for (const auto& val : kundenverzeichnis) {
		std::cout << "Name: "<< val.first->m_name << "\t ID:" << val.second << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void System::ausgelieheneArtikelAnsehen(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde) {
	if (kunde->m_anzahlAusgelieheneArtikel == 0) {
		std::cout << "Der Kunde: " << kunde->m_name << " hat noch keine Artikel ausgeliehen." << std::endl;
		std::cout << "Wollen Sie einen Artikel ausleihen? (Ja/Nein) " << std::endl;

		std::string antwort;
		std::cin >> antwort;

		if (antwort == "ja" || antwort == "Ja" || antwort == "JA" || antwort == "j" || antwort == "jA") {
			leiheArtikelAus(gewuenschterArtikel, kunde);
		}
		else {
			return;
		}
	}
	else {
		for (size_t i = 0; i < kunde->m_anzahlAusgelieheneArtikel; i++) {
			std::cout << i << "#";
			kunde->m_ausgelieheneArtikel[i]->gebeDatenAus();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

void System::gebeArtikelZurueck(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde) {
	ausgelieheneArtikelAnsehen(gewuenschterArtikel, kunde);
	std::cout << std::endl;
	std::cout << "Welchen Artikel wollen Sie zurueckgeben? " << std::endl;

	int indexArtikelZurueck;
	std::cin >> indexArtikelZurueck;
	if (kunde->m_anzahlAusgelieheneArtikel == 1 && indexArtikelZurueck == 1) {
		return;
	}

	if (kunde->m_anzahlAusgelieheneArtikel == 2) {
		if (indexArtikelZurueck == 0) {
			kunde->m_ausgelieheneArtikel[0] = kunde->m_ausgelieheneArtikel[1];
			kunde->m_ausgelieheneArtikel[1] = NULL;
			kunde->m_anzahlAusgelieheneArtikel--;
		}
		else if (indexArtikelZurueck == 1) {
			kunde->m_ausgelieheneArtikel[1] = NULL;
			kunde->m_anzahlAusgelieheneArtikel--;
		}
	}
	else {
		kunde->m_ausgelieheneArtikel[0] = NULL;
		kunde->m_anzahlAusgelieheneArtikel--;
	}

	if (indexArtikelZurueck != 0 && indexArtikelZurueck != 1) {
		std::cout << "Dieser Artikel existiert nicht!" << std::endl;
		return;
	}
	std::cout << "Der Kunde: " << kunde->m_name << " gab " << kunde->m_ausgelieheneArtikel[indexArtikelZurueck]->getTitel() << " zur�ck." << std::endl;
}

void System::alleArtikelAnsehen() {
	 
	for (const auto& var : m_alleArtikelSortiertNachErscheinungsjahr) {
		std::cout  << "Titel: " << var.second << "\tErscheinungsjahr: " << var.first << std::endl;
	}

	std::cout << std::endl << std::endl;
}


void System::schreibeInProtkollDatei(Person* kunde, Artikel* ausgeliehenerArtikel) {
	
	std::ofstream protokoll("Protokolldatei.txt", std::ios::app);

	if (protokoll.fail()) {
		std::cout << "Datei konnte nicht ge�ffnet werden!" << std::endl;
	}
	else {
		protokoll << "Der Kunde: " << kunde->m_name << " hat sich " << ausgeliehenerArtikel->getTitel() << " ausgeliehen." << std::endl;
	}

	if (protokoll.is_open()) {
		protokoll.close();
	}
}

void System::leiheArtikelAus(std::vector<Artikel*>& gewuenschterArtikel, Person* kunde) {

	if (kunde->m_istKunde == true) {
		std::cout << "Bitte geben Sie die ID des Produktes ein, um es auszuleihen: ";
		int gesuchterArtikel;
		std::cin >> gesuchterArtikel;
		std::cout << std::endl;

		for (size_t i = 0; i < 100; i++) {
			if (gewuenschterArtikel[i]->getID() == gesuchterArtikel) {
				if (kunde->m_anzahlAusgelieheneArtikel < 2 ) {
					if (gewuenschterArtikel[i]->istVerfuegbar() == true) {
						kunde->m_ausgelieheneArtikel[kunde->m_anzahlAusgelieheneArtikel] = gewuenschterArtikel[i];
						gewuenschterArtikel[i]->verringereStueckzahl();
						kunde->m_anzahlAusgelieheneArtikel++;
						std::cout << "Glueckwunsch Sie haben " << gewuenschterArtikel[i]->getTitel() << " ausgeliehen!" << std::endl;
						std::cout << std::endl;
						schreibeInProtkollDatei(kunde, gewuenschterArtikel[i]);
						break;
					}
				}
				else {
					std::cout << "Sie k�nnen nicht mehr als zwei Artikel gleichzeitig ausleihen!" << std::endl;
					break;
				}
			}
		}
	}
	else {
		std::cout << "Sie k�nnen nur einen Artikel ausleihen, wenn Sie Kunde sind." << std::endl;
		std::cout << "Wollen Sie Kunde werden, um einen Artikel auszuleihen? (Ja/Nein) ";
		std::string antwort;
		std::cin >> antwort;
		if (antwort == "ja" || antwort == "Ja" || antwort == "JA" || antwort == "j" || antwort == "jA") {
			std::cout << std::endl;
			kunde->werdeKunde();
			leiheArtikelAus(gewuenschterArtikel, kunde);
		}
		else {
			std::cout << std::endl;
			std::cout << "Dann bis zum n�chsten mal!" << std::endl;
		}
	}
}

int System::waehleKundeAus() {
	
	int i;
	gebeAlleKundenAus(m_kundenverzeichnis);
	std::cout << "Welchen Kunden m�chten Sie bearbeiten?  " << std::endl;
	std::cin >> i;
	std::cout << std::endl;

	if (i > m_index || i < 0) {
		std::cout << "Invalide Eingabe!" << std::endl;
		return 0;
	}
	
	return i;
}

void System::sucheArtikelNachTitel(std::vector<Artikel*>& gewuenschterArtikel)
{
	std::cout << "Suchen Sie bitte einen Titel aus: ";
	std::string gesuchterArtikel;
	std::cin >> gesuchterArtikel;
	std::cout << std::endl;
	std::cout << "Hier sind ihre folgende Ergebnisse: " << std::endl;

	for (size_t i = 0; i < 100; i++) {
		if (gewuenschterArtikel[i]->getTitel() == gesuchterArtikel) {
			gewuenschterArtikel[i]->gebeDatenAus();
		}
	}
	std::cout << std::endl;
}

void System::sucheArtikelNachID(std::vector<Artikel*>& gewuenschterArtikel) {
	std::cout << "Geben Sie eine ID ein um zu suchen:";
	int gesuchterArtikel;
	std::cin >> gesuchterArtikel;
	std::cout << std::endl;
	std::cout << "Hier sind ihre folgende Ergebnisse: " << std::endl;

	for (size_t i = 0; i < 100; i++) {
		if (gewuenschterArtikel[i]->getID() == gesuchterArtikel) {
			gewuenschterArtikel[i]->gebeDatenAus();
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void System::sucheArtikel(std::vector<Artikel*>& gewuenschterArtikel) {
	std::cout << "1: suche Artikel nach Titel" << std::endl;
	std::cout << "2: suche Artikel nach ID" << std::endl;

	int wahl;
	std::cin >> wahl;

	switch (wahl) {
	case 1: sucheArtikelNachTitel(gewuenschterArtikel); break;
	case 2: sucheArtikelNachID(gewuenschterArtikel); break;
	default: std::cout << "Invalide Eingabe!" << std::endl;
	}
}


void System::run()
{
	 
	
	std::vector<Artikel*> m_alleArtikel(100);

	for (size_t i = 0; i < 100; i++) {
		if (i < 30) {
			m_alleArtikel[i] = new Videospiel(i);
		}
		else if (i > 30 && i < 60) {
			m_alleArtikel[i] = new Buch(i);
		}
		else {
			m_alleArtikel[i] = new Hoerbuch(i);
		}

		std::string tmpTitel = m_alleArtikel[i]->getTitel();
		int tmpErscheinungsjahr = m_alleArtikel[i]->getErscheinungsjahr();

		std::pair<int, std::string> pair(tmpErscheinungsjahr, tmpTitel);
		m_alleArtikelSortiertNachErscheinungsjahr.insert(pair);
	}
		

	std::vector<Person*> neuerKunde(100);
	erstelleNeuenKunde(neuerKunde);
	int indexKunde = 0;
 
	int input;

	do {
		std::cout << "1: Alle Artikel ansehen   2: Ausgeliehene Artikel ansehen" << std::endl;
		std::cout << "3: Artikel ausleihen      4: Artikel zurueckgeben" << std::endl;
		std::cout << "5: Artikel suchen         6: Erstelle Kunde" << std::endl;
		std::cout << "7: Kunde auswaehlen       8: Alle Kunden einsehen" << std::endl;
		std::cout << "9: Menue schliessen" << std::endl;
				
		std::cout << std::endl << "Eingabe: ";
		std::cin >> input;
		std::cout << std::endl;
				
		switch (input) {
		case 1: alleArtikelAnsehen(); break;
		case 2: ausgelieheneArtikelAnsehen(m_alleArtikel, neuerKunde[indexKunde]); break;
		case 3: leiheArtikelAus(m_alleArtikel, neuerKunde[indexKunde]); break;
		case 4: gebeArtikelZurueck(m_alleArtikel, neuerKunde[indexKunde]); break;
		case 5: sucheArtikel(m_alleArtikel); break;
		case 6: erstelleNeuenKunde(neuerKunde); break;
		case 7: indexKunde = waehleKundeAus(); break;
		case 8: gebeAlleKundenAus(m_kundenverzeichnis); break;
		case 9: break;
		default: std::cout << "Invalide Eingabe! " << std::endl; break;
		}

	} while (input != 9);
}
