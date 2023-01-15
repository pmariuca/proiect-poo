#pragma once
#include <iostream>
#include <string>
#include <vector>
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
	int zone;
	vector <string> numeZone;
	float* pret;

public:
	Locatie();

	Locatie(char*, int, int, int, int**, int, int, vector <string>, float*);

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

	vector<string> getNumeZone();
	void setNumeZone(vector<string>, int);

	float* getPret();
	void setPret(float*, int);

	int getNrLocuriDisponibile();
	void setNrLocuriDisponibile(int);

	void locuriDisponibile(int);
	void ocupareLoc(int, int);
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