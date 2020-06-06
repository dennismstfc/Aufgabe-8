#include <fstream>
#include "System.h"
#include <iomanip>


int main() {

	srand(time(NULL));

	//std::ofstream protokolldatei;
	//protokolldatei.open("Protokolldatei.txt");

	auto t = std::time(nullptr);
	auto tm = *localtime_s(&t);
	std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;

	


	//protokolldatei.close();

	System bibliothek;
	bibliothek.run();


	return 0;
}