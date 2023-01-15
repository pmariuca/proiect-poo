#pragma once
#include "Bilete.h"
#include <iostream>
#include <vector>
using namespace std;

class BiletValid
{
private:
	bool valid;
public:
	virtual bool validare(BiletValid* b) = 0;

	bool getValid();

	virtual void afisare_valid();

	virtual void afisare_invalid();

	friend class BiletIntrodus;
};

class BiletIntrodus : virtual public BiletValid
{
public:
	bool validare(int, Bilete);
};