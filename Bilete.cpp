#include "Bilete.h"
#include <iostream>
#include <string>
using namespace std;

Bilete::Bilete() :oras("Bucuresti")
{
	Bilete::id++;
	nume = new char[2];
	strcpy_s(nume, 1, "");
}

Bilete::Bilete(char* nume) :oras(oras)
{
	Bilete::id++;
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
	Bilete::id = id;
}

void Bilete::incrementeazaId()
{
	Bilete::id++;
}

bool Bilete::idCorect(Locatie locatie)
{
	return id > locatie.nrLocuri - locatie.nrLocuriDisponibile;
}

bool Bilete::operator!()
{
	return nume != nullptr;
}

Bilete::operator char* ()
{
	return nume;
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