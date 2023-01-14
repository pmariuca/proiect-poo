#pragma once
#include <iostream>
#include <string>
using namespace std;

class Locatie
{
private:
	char* numeLocatie;
	int nrLocuri;
	int nrRanduri;
	int nrLocuriPeRand;
	int** sala;
	int nrLocuriDisponibile;
	string numeZona;
	int zone;
	float* pret;

public:
	Locatie();

	Locatie(char*, int, int, int, int**, int, string, int, float*);

	Locatie(const Locatie&);

	Locatie& operator=(const Locatie&);

	char* getNumeLocatie();
	void setNumeLocatie(char*);

	int getNrLocuri();
	void setNrLocuri(int);

	int getNrRanduri();
	
	int getNrLocuriPeRand();

	int** getSala();
	void setSala(int**, int, int);

	int getZone();

	float* getPret();
	void setPret(float*, int);

	string getNumeZona();
	void setNumeZona(string);

	void locuriDisponibile(int);
	bool nrCorectLocuri();

	void operator*(int);
	float operator[](int);

	virtual void afisare_succes();
	virtual void afisare_erori();

	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);
	friend class Eveniment;
	friend class Bilete;

	~Locatie();
};