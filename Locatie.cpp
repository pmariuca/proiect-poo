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
	zone = 0;
	for (unsigned i = 0; i < zone; i++)
	{
		numeZone[i] = "";
	}
	pret = nullptr;
}

Locatie::Locatie(char* numeLocatie, int nrLocuri, int nrRanduri, int nrLocuriPeRand, int** sala, int nrLocuriDisponibile, int zone, vector <string> numeZone, float* pret)
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
	if (zone > 0)
	{
		for (unsigned i = 0; i < zone; i++)
		{
			this->numeZone.push_back(numeZone[i]);

		}
	}
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
	if (locatie.zone > 0)
	{
		for (unsigned i = 0; i < locatie.zone; i++)
		{
			numeZone.push_back(locatie.numeZone[i]);

		}
	}
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
		if (locatie.zone > 0)
		{
			for (unsigned i = 0; i < locatie.zone; i++)
			{
				numeZone.push_back(locatie.numeZone[i]);

			}
		}
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
	if (numeLocatie == nullptr)
		return NULL;
	char* copie = new char[strlen(numeLocatie) + 1];
	strcpy_s(copie, strlen(numeLocatie) + 1, numeLocatie);
	return copie;
}

void Locatie::setNumeLocatie(char* nume)
{
	if (nume != nullptr)
	{
		numeLocatie = new char[strlen(nume) + 1];
		strcpy_s(numeLocatie, strlen(nume) + 1, nume);
	}
	else numeLocatie=nullptr;
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

vector<string>  Locatie::getNumeZone()
{
	return numeZone;
}

void Locatie::setNumeZone(vector<string>, int zone)
{
	if (zone > 0)
	{
		for (unsigned i = 0; i < zone; i++)
		{
			this->numeZone.push_back(numeZone[i]);

		}
	}
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

int Locatie::getNrLocuriDisponibile()
{
	return nrLocuriDisponibile;
}

void Locatie::setNrLocuriDisponibile(int nrLocuriDisponibile)
{
	this->nrLocuriDisponibile = nrLocuriDisponibile;
}

void Locatie::locuriDisponibile(int nrLocuriOcupate)
{
	nrLocuriDisponibile = nrLocuri - nrLocuriOcupate;
}

void Locatie::ocupareLoc(int loc, int rand)
{
	if (sala[loc][rand] == 0)
	{
		sala[loc][rand] = 1;
		cout << "Locul este disponibil!" << endl;
	}
	else if (sala[loc][rand] == 1)
	{
		cout << "Locul este deja ocupat!" << endl;
	}
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

void Locatie::afisare_succes()
{
	cout << "Inregistrarea locatiei a reusit!";
}

void Locatie::afisare_erori()
{
	cout << "Inregistrarea locatiei nu a reusit!";
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
	out << "Sala: " << endl;
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
	out << "Nr zone: " << locatie.zone << endl;
	out << "Nume zone: " << endl;
	for (unsigned i = 0; i < locatie.numeZone.size(); i++)
	{
		out << locatie.numeZone[i]<<" ";
	} 
	out << endl;
	out << "Preturi: " << endl;
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
	out << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& locatie)
{
	char sir[100];
	cout << "Introduceti numele locatiei: " << endl;
	in >> sir;
	if (locatie.numeLocatie != nullptr)
	{
		delete[] locatie.numeLocatie;
		locatie.numeLocatie = nullptr;
	}
	locatie.numeLocatie = new char[strlen(sir)];
	strcpy_s(locatie.numeLocatie, strlen(sir) + 1, sir);
	cout << "Introduceti numarul de locuri: " << endl;
	in >> locatie.nrLocuri;
	cout << "Introduceti numarul de randuri: " << endl;
	in >> locatie.nrRanduri;
	cout << "Introduceti numarul de locuri pe rand: " << endl;
	in >> locatie.nrLocuriPeRand;
	if (locatie.sala != nullptr)
	{
		delete[] locatie.sala;
		locatie.sala = nullptr;
	}
	cout << "Introduceti organizarea salii:" << endl;
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
	cout << "Introduceti numarul de locuri disponibile: " << endl;
	in >> locatie.nrLocuriDisponibile;
	cout << "Introduceti numarul de zone: " << endl;
	in >> locatie.zone;
	cout << "Introduceti numele zonelor: " << endl;
	string nume_z;
	for (unsigned i = 0; i < locatie.zone; i++)
	{
		in >> nume_z;
		locatie.numeZone.push_back(nume_z);
	}
	if (locatie.pret != nullptr)
	{
		delete[] locatie.pret;
		locatie.pret = nullptr;
	}
	cout << "Introduceti preturile: " << endl;
	locatie.pret = new float[locatie.zone];
	for (int i = 0; i < locatie.zone; i++)
	{
		in >> locatie.pret[i];
	}
	return in;
}