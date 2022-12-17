#pragma once
#include "Eveniment.h"
#include <iostream>
#include <string>
using namespace std;

class Bilete
{
private:
	const string oras = "Bucuresti";
	static int id;
	char* nume;
	Eveniment eveniment;

public:
	Bilete();

	Bilete(char*);

	Bilete(const Bilete&);

	Bilete& operator=(const Bilete&);

	char* getNume();

	void setNume(char*);

	static int getId();
	static void setId(int id);

	static void incrementeazaId();
	bool idCorect(Locatie);

	bool operator!();
	operator char* ();

	friend ostream& operator<<(ostream&, Bilete);
	friend istream& operator>>(istream&, Bilete&);
	friend class Eveniment;

	~Bilete();
};
int Bilete::id = 1;