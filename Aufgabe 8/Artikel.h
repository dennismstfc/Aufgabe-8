#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>


class Artikel
{
public:

	Artikel() = default;
	virtual ~Artikel() = default;
	virtual void generiereDaten() = 0;
	virtual std::string generiereTitel() = 0;
	virtual void gebeDatenAus() = 0;
	virtual bool istVerfuegbar() = 0;
	virtual void verringereStueckzahl() = 0;
	virtual std::string getTitel() = 0;
	virtual int getID() = 0;


};

