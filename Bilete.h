#pragma once
#include "Eveniment.h"
#include "BiletValid.h"
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

	virtual void afisare_succes();
	virtual void afisare_erori();

	friend ostream& operator<<(ostream&, Bilete);
	friend istream& operator>>(istream&, Bilete&);
	friend class Eveniment;

	~Bilete();
};


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

	virtual void afisare_succes_VIP();
	virtual void afisare_erori_VIP();

	friend ostream& operator<<(ostream&, BileteVIP);
	friend istream& operator>>(istream&, BileteVIP&);

};