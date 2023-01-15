#pragma once
#include "Locatie.h"
#include <iostream>
#include <string>
using namespace std;

class Eveniment
{
private:
	char* tipEveniment;
	char* numeEveniment;
	char* data;
	char* ora;
	int bileteDisponibile;
	Locatie locatie;

public:
	Eveniment();

	Eveniment(char*, char*, char*, char*, int, Locatie locatie);

	Eveniment(const Eveniment&);

	Eveniment& operator=(const Eveniment&);

	char* getTipEveniment();
	void setTipEveniment(char*);

	char* getNumeEveniment();
	void setNumeEveniment(char*);

	char* getData();
	void setData(char*);

	char* getOra();
	void setOra(char*);

	int getBileteDisponibile();
	void setBileteDisponibile(int);

	Locatie getLocatie();

	void getNrBilete(Locatie);
	void literaMare(char*);

	bool operator>(Locatie);
	bool operator<(Locatie);

	virtual void afisare_succes();
	virtual void afisare_erori();

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
	friend class Bilete;

	~Eveniment();
};