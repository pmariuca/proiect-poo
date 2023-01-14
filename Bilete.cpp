#include "Locatie.h"
#include "Eveniment.h"
#include "Bilete.h"
#include <iostream>
#include <string>
using namespace std;

int Bilete::id = 0;

Bilete::Bilete() :oras("Bucuresti")
{
	nume = new char[2];
	strcpy_s(nume, 1, "");
}

Bilete::Bilete(char* nume) :oras(oras)
{
	if (nume != nullptr)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	else
	{
		this->nume = nullptr;
	}
}

Bilete::Bilete(const Bilete& bil):oras(bil.oras)
{
	if (bil.nume != nullptr)
	{
		nume = new char[strlen(bil.nume) + 1];
		strcpy_s(nume, strlen(bil.nume) + 1, bil.nume);
	}
	else
	{
		nume = nullptr;
	}
}

Bilete& Bilete::operator=(const Bilete& bil)
{
	if (this != &bil)
	{
		if (bil.nume != nullptr)
		{
			nume = new char[strlen(bil.nume) + 1];
			strcpy_s(nume, strlen(bil.nume) + 1, bil.nume);
		}
		else
		{
			nume = nullptr;
		}
	}
	return *this;
}

char* Bilete::getNume()
{
	if (nume == nullptr)
	{
		return NULL;
	}
	char* copie = new char[strlen(nume) + 1];
	strcpy_s(copie, strlen(nume) + 1, nume);
	return copie;
}

void Bilete::setNume(char* nume)
{
	if (nume != nullptr)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	else
	{
		nume = nullptr;
	}
}

int Bilete::getId()
{
	return Bilete::id;
}

void Bilete::setId(int id)
{
	if (id != NULL)
	{
		Bilete::id = id;
	}
	else id = NULL;
}
	

void Bilete::incrementeazaId()
{
	Bilete::id++;
}

bool Bilete::idCorect(Locatie locatie)
{
	return (Bilete::id > 0 && Bilete::id >= locatie.nrLocuri - locatie.nrLocuriDisponibile);
		
}

bool Bilete::operator!()
{
	return nume != nullptr;
}

Bilete::operator char* ()
{
	return nume;
}

void Bilete::afisare_succes()
{
	cout << "Inregistrarea biletului a reusit!";
}

void Bilete::afisare_erori()
{
	cout << "Inregistrarea biletului nu a reusit!";
}

Bilete::~Bilete()
{
	if (nume != nullptr)
	{
		delete[] nume;
		nume = nullptr;
	}
}

ostream& operator<<(ostream& out, Bilete bil)
{
	out << "Oras: " << bil.oras;
	out << "Nume: " << bil.nume;
	out << "Id: " << bil.id;
	return out;
}

istream& operator>>(istream& in, Bilete& bil)
{
	char sir[100];
	in >> sir;
	if (bil.nume != nullptr)
	{
		delete[] bil.nume;
		bil.nume = nullptr;
	}
	bil.nume = new char[strlen(sir) + 1];
	strcpy_s(bil.nume, strlen(sir) + 1, sir);
	return in;
}



BileteVIP::BileteVIP() :Bilete()
{
	oraBufet = "";
	meniuCopii = 1;
}

BileteVIP::BileteVIP(string oraBufet, bool meniuCopii) :Bilete()
{
	this->oraBufet = oraBufet;
	this->meniuCopii = meniuCopii;
}

BileteVIP::BileteVIP(const BileteVIP& bil) :Bilete()
{
	if (bil.oraBufet != "")
	{
		this->oraBufet = oraBufet;
	}
	else
	{
		this->oraBufet = "";
	}
	if (bil.meniuCopii != NULL)
	{
		this->meniuCopii = meniuCopii;
	}
	else
	{
		this->meniuCopii = 1;
	}
}

BileteVIP& BileteVIP::operator=(const BileteVIP& bil)
{
	if (this != &bil)
	{
		if (bil.oraBufet != "")
		{
			this->oraBufet = oraBufet;
		}
		else
		{
			this->oraBufet = "";
		}
		if (bil.meniuCopii != NULL)
		{
			this->meniuCopii = meniuCopii;
		}
		else
		{
			this->meniuCopii = 1;
		}
	}
	return *this;
}

string BileteVIP::getOraBufet()
{
	return oraBufet;
}

void BileteVIP::setOraBufet(string oraBufet)
{
	this->oraBufet = oraBufet;
}

bool BileteVIP::getMeniuCopii()
{
	return meniuCopii;
}

void BileteVIP::setMeniuCopii(bool meniuCopii)
{
	this->meniuCopii = meniuCopii;
}

void BileteVIP::afisare_succes_VIP()
{
	cout << "Inregistrarea biletului VIP a reusit!";
}

void BileteVIP::afisare_erori_VIP()
{
	cout << "Inregistrarea biletului VIP nu a reusit!";
}

ostream& operator<<(ostream& out, BileteVIP bil)
{
	out << "Ora bufet: " << bil.oraBufet;
	if (bil.meniuCopii == 1)
	{
		out << "Meniul de copii nu este disponibil.";
	}
	else 
		out << "Meniul de copii este disponibil.";
	return out;
}

istream& operator>>(istream& in, BileteVIP& bil)
{
	in >> bil.oraBufet;
	in >> bil.meniuCopii;
	return in;
}