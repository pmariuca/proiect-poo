#include "BiletValid.h"
#include "Bilete.h"
#include <iostream>
#include <vector>
using namespace std;

bool BiletValid::getValid()
{
	return valid;
}

void BiletValid::afisare_valid()
{
	cout << "Biletul este valid!";
}

void BiletValid::afisare_invalid()
{
	cout << "Biletul nu este valid!";
}

bool BiletIntrodus::validare(int id, Bilete bilet)
{
	for (unsigned i = 0; i < bilet.vector_id.size(); i++)
	{
		if (id == bilet.vector_id[i]) 
			valid = true;
		else 
			valid = false;
	}
	return valid;
}