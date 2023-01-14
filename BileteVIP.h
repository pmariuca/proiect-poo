#pragma once
#include "Bilete.h"
#include <iostream>
#include <string>
using namespace std;

class BileteVIP : virtual public Bilete
{
private:
	string oraBufet;
	bool meniuCopii;

	BileteVIP();

	BileteVIP(string, bool);

	BileteVIP(const BileteVIP&);

	BileteVIP& operator=(const BileteVIP&);

	string getOraBufet();

	void setOraBufet(string);

	bool getMeniuCopii();

	void setMeniuCopii(bool);

};

