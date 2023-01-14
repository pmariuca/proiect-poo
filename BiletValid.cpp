#include "BiletValid.h"
#include "Bilete.h"
#include <iostream>
using namespace std;

void BiletValid::afisare_valid()
{
	valid = 0;
}

void BiletValid::afisare_invalid()
{
	valid = 1;
}

bool BiletIntrodus::validare(int id)
{
	return (id > 0);
}