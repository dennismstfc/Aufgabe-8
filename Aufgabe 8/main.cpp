#include <fstream>
#include "System.h"


int main() {

	srand(time(NULL));

	//std::ofstream protokolldatei;
	//protokolldatei.open("Protokolldatei.txt");
	//protokolldatei.close();

	System bibliothek;
	bibliothek.run();


	return 0;
}