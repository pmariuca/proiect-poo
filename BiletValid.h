#pragma once
#include <iostream>
using namespace std;

class BiletValid
{
private:
	bool valid;
public:
	virtual bool validare(BiletValid* b) = 0;

	virtual void afisare_valid();

	virtual void afisare_invalid();
};

class BiletIntrodus : public BiletValid
{
public:
	bool validare(int);
};