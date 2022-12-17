#include "Locatie.h"
#include <iostream>
#include <string>
using namespace std;

Locatie::Locatie()
{
	numeLocatie = new char[12];
	strcpy_s(numeLocatie, 12, "Necunoscuta");
	nrLocuri = 0;
	nrRanduri = 0;
	nrLocuriPeRand = 0;
	sala = nullptr;
	nrLocuriDisponibile = 0;
	numeZona = "Necunoscuta";
	zone = 0;
	pret = nullptr;
}

Locatie::Locatie(char* numeLocatie, int nrLocuri, int nrRanduri, int nrLocuriPeRand, int** sala, int nrLocuriDisponibile,string numeZona, int zone, float* pret)
{
	this->numeLocatie = new char[strlen(numeLocatie) + 1];
	strcpy_s(this->numeLocatie, strlen(numeLocatie) + 1, numeLocatie);
	this->nrLocuri = nrLocuri;
	if (sala != nullptr && nrRanduri > 0 && nrLocuriPeRand > 0)
	{
		this->nrRanduri = nrRanduri;
		this->nrLocuriPeRand = nrLocuriPeRand;
		this->sala = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
			this->sala[i] = new int[nrLocuriPeRand];

		for (int i = 0; i < nrRanduri; i++)
		{
			for (int j = 0; j < nrLocuriPeRand; j++)
			{
				this->sala[i][j] = sala[i][j];
			}
		}

	}
	else
	{
		this->nrRanduri = 0;
		this->nrLocuriPeRand = 0;
		this->sala = nullptr;
	}
	this->nrLocuriDisponibile = nrLocuriDisponibile;
	this->numeZona = numeZona;
	if (pret != nullptr && zone > 0)
	{
		this->zone = zone;
		this->pret = new float[zone];
		for (int i = 0; i < zone; i++)
		{
			this->pret[i] = pret[i];
		}
	}
	else
	{
		this->zone = 0;
		this->pret = nullptr;
	}
}

Locatie::Locatie(const Locatie& locatie)
{
	numeLocatie = new char[strlen(locatie.numeLocatie) + 1];
	strcpy_s(numeLocatie, strlen(locatie.numeLocatie) + 1, locatie.numeLocatie);
	nrLocuri = locatie.nrLocuri;
	if (locatie.sala != nullptr && locatie.nrRanduri > 0 && locatie.nrLocuriPeRand > 0)
	{
		nrRanduri = locatie.nrRanduri;
		nrLocuriPeRand = locatie.nrLocuriPeRand;
		sala = new int* [locatie.nrRanduri];
		for (int i = 0; i < locatie.nrRanduri; i++)
			sala[i] = new int[locatie.nrLocuriPeRand];
		for (int i = 0; i < locatie.nrRanduri; i++)
		{
			for (int j = 0; j < nrLocuriPeRand; j++)
			{
				sala[i][j] = locatie.sala[i][j];
			}
		}
	}
	else
	{
		nrRanduri = 0;
		nrLocuriPeRand = 0;
		sala = nullptr;
	}
	nrLocuriDisponibile = locatie.nrLocuriDisponibile;
	numeZona = locatie.numeZona;
	if (locatie.pret != nullptr && locatie.zone > 0)
	{
		zone = locatie.zone;
		pret = new float[locatie.zone];
		for (int i = 0; i < locatie.zone; i++)
		{
			pret[i] = locatie.pret[i];
		}
	}
	else
	{
		zone = 0;
		pret = nullptr;
	}
}

Locatie& Locatie::operator=(const Locatie& locatie)
{
	if (this != &locatie)
	{
		numeLocatie = new char[strlen(locatie.numeLocatie) + 1];
		strcpy_s(numeLocatie, strlen(locatie.numeLocatie) + 1, locatie.numeLocatie);
		nrLocuri = locatie.nrLocuri;
		if (sala != nullptr)
		{
			delete[] sala;
			sala = nullptr;
		}
		if (locatie.sala != nullptr && locatie.nrRanduri > 0 && locatie.nrLocuriPeRand > 0)
		{
			nrRanduri = locatie.nrRanduri;
			nrLocuriPeRand = locatie.nrLocuriPeRand;
			sala = new int* [locatie.nrRanduri];
			for (int i = 0; i < locatie.nrRanduri; i++)
				sala[i] = new int[locatie.nrLocuriPeRand];
			for (int i = 0; i < locatie.nrRanduri; i++)
			{
				for (int j = 0; j < nrLocuriPeRand; j++)
				{
					sala[i][j] = locatie.sala[i][j];
				}
			}
		}
		else
		{
			nrRanduri = 0;
			nrLocuriPeRand = 0;
			sala = nullptr;
		}
		nrLocuriDisponibile = locatie.nrLocuriDisponibile;
		numeZona = locatie.numeZona;
		if (locatie.pret != nullptr && locatie.zone > 0)
		{
			zone = locatie.zone;
			pret = new float[locatie.zone];
			for (int i = 0; i < locatie.zone; i++)
			{
				pret[i] = locatie.pret[i];
			}
		}
		else
		{
			zone = 0;
			pret = nullptr;
		}
	}

	return *this;
}

char* Locatie::getNumeLocatie()
{
	return numeLocatie;
}

void Locatie::setNumeLocatie(char* nume)
{
	numeLocatie = new char[strlen(nume) + 1];
	strcpy_s(numeLocatie, strlen(nume) + 1, nume);
}

int Locatie::getNrLocuri()
{
	return nrLocuri;
}
void Locatie::setNrLocuri(int nr)
{
	nrLocuri = nr;
}

int Locatie::getNrRanduri()
{
	return nrRanduri;
}

int Locatie::getNrLocuriPeRand()
{
	return nrLocuriPeRand;
}

int** Locatie::getSala()
{
	if (sala == nullptr || nrRanduri < 0 || nrLocuriPeRand < 0)
		return NULL;
	int** copie = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++)
		copie[i] = new int[nrLocuriPeRand];
	for (int i = 0; i < nrRanduri; i++)
	{
		for (int j = 0; j < nrLocuriPeRand; j++)
		{
			copie[i][j] = sala[i][j];
		}
	}
	return copie;
}

void Locatie::setSala(int** sala, int randuri, int locuri)
{
	if (sala != nullptr && randuri > 0 && locuri > 0)
	{
		nrRanduri = randuri;
		nrLocuriPeRand = locuri;
		this->sala = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
			this->sala[i] = new int[nrLocuriPeRand];

		for (int i = 0; i < nrRanduri; i++)
		{
			for (int j = 0; j < nrLocuriPeRand; j++)
			{
				this->sala[i][j] = sala[i][j];
			}
		}
	}
	else
	{
		nrRanduri = 0;
		nrLocuriPeRand = 0;
		this->sala = nullptr;
	}
}

int Locatie::getZone()
{
	return zone;
}

float* Locatie::getPret()
{
	if (pret == nullptr || zone <= 0)
		return NULL;
	float* copie = new float[zone];
	for (int i = 0; i < zone; i++)
		copie[i] = pret[i];
	return copie;
}

void Locatie::setPret(float* pret, int zone)
{
	if (pret != nullptr && zone > 0)
	{
		this->zone = zone;
		this->pret = new float[zone];
		for (int i = 0; i < zone; i++)
		{
			this->pret[i] = pret[i];
		}
	}
	else
	{
		this->zone = 0;
		this->pret = nullptr;
	}
}

string Locatie::getNumeZona()
{
	return numeZona;
}

void Locatie::setNumeZona(string numeZona)
{
	this->numeZona = numeZona;
}

void Locatie::locuriDisponibile(int nrLocuriOcupate)
{
	nrLocuriDisponibile = nrLocuri - nrLocuriOcupate;
}

bool Locatie::nrCorectLocuri()
{
	return nrLocuriDisponibile < nrLocuri;
}

void Locatie::operator*(int nrLocuri)
{
	nrLocuri = nrRanduri * nrLocuriPeRand;
}

float Locatie::operator[](int index)
{
	if (index >= 0 && index <= zone)
	{
		return pret[index];
	}
	else
		return -1;
}

Locatie::~Locatie()
{
	if (sala != nullptr)
	{
		delete[] sala;
		sala = nullptr;
	}
	if (pret != nullptr)
	{
		delete[] pret;
		pret = nullptr;
	}
}

ostream& operator<<(ostream& out, Locatie locatie)
{
	out << "Nume locatie: "<<locatie.numeLocatie << endl;
	out << "Nr locuri: "<<locatie.nrLocuri << endl;
	out << "Nr randuri: "<<locatie.nrRanduri << endl;
	out << "Nr locuri pe rand: "<<locatie.nrLocuriPeRand << endl;
	out << "Sala: ";
	if (locatie.sala == nullptr)
	{
		out << NULL << endl;;
	}
	else
	{
		for (int i = 0; i < locatie.nrRanduri; i++)
		{
			for (int j = 0; j < locatie.nrLocuriPeRand; j++)
			{
				out << locatie.sala[i][j]<< " ";
			}
			cout << endl;
		}
	}
	out << "Nr locuri disponibile: " << locatie.nrLocuriDisponibile << endl;
	out << "Zona: " << locatie.numeZona;
	out << "Nr zone: " << locatie.zone << endl;
	out << "Preturi: ";
	if (locatie.pret == nullptr)
	{
		out << NULL << endl;
	}
	else
	{
		for (int i = 0; i < locatie.zone; i++)
		{
			out << locatie.pret[i] << " ";
		}
	}
	return out;
}

istream& operator>>(istream& in, Locatie& locatie)
{
	char sir[100];
	in >> sir;
	if (locatie.numeLocatie != nullptr)
	{
		delete[] locatie.numeLocatie;
		locatie.numeLocatie = nullptr;
	}
	locatie.numeLocatie = new char[strlen(sir)];
	strcpy_s(locatie.numeLocatie, strlen(sir) + 1, sir);
	in >> locatie.nrLocuri;
	in >> locatie.nrRanduri;
	in >> locatie.nrLocuriPeRand;
	if (locatie.sala != nullptr)
	{
		delete[] locatie.sala;
		locatie.sala = nullptr;
	}
	locatie.sala = new int* [locatie.nrRanduri];
	for (int i = 0; i < locatie.nrRanduri; i++)
		locatie.sala[i] = new int[locatie.nrLocuriPeRand];
	for (int i = 0; i < locatie.nrRanduri; i++)
	{
		for (int j = 0; j < locatie.nrLocuriPeRand; j++)
		{
			in >> locatie.sala[i][j];
		}
	}
	in >> locatie.nrLocuriDisponibile;
	in >> locatie.numeZona;
	in >> locatie.zone;
	if (locatie.pret != nullptr)
	{
		delete[] locatie.pret;
		locatie.pret = nullptr;
	}
	locatie.pret = new float[locatie.zone];
	for (int i = 0; i < locatie.zone; i++)
	{
		in >> locatie.pret[i];
	}
	return in;
}