#include <fstream>
#include "System.h"
#include <map>

int main() {

	srand(time(NULL));

	//std::ofstream protokolldatei;
	//protokolldatei.open("Protokolldatei.txt");

	std::map <Person*, int> kundenverzeichnis;
	


	//protokolldatei.close();

	System bibliothek;
	bibliothek.run();


	return 0;
}