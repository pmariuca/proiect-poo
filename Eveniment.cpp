#include "Eveniment.h"
#include <iostream>
#include <string>
using namespace std;

Eveniment::Eveniment()
{
	tipEveniment = new char[12];
	strcpy_s(tipEveniment, 12, "Necunoscut");
	numeEveniment = new char[12];
	strcpy_s(numeEveniment, 12, "Necunoscut");
	data = new char[13];
	strcpy_s(data, 13, "Necunoscuta");
	ora = new char[13];
	strcpy_s(ora, 13, "Necunoscuta");
	bileteDisponibile = 0;
}

Eveniment::Eveniment(char* tipEveniment, char* numeEveniment, char* data, char* ora, int bileteDisponibile, Locatie locatie)
{
	if (tipEveniment != nullptr) {
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy_s(this->tipEveniment, strlen(tipEveniment) + 1, tipEveniment);
	}
	else
	{
		this->tipEveniment = nullptr;
	}
	if (numeEveniment != nullptr) {
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(numeEveniment) + 1, numeEveniment);
	}
	else
	{
		this->numeEveniment = nullptr;
	}
	if (data != nullptr) {
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	else
	{
		this->data = nullptr;
	}
	if (ora != nullptr) {
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora, strlen(ora) + 1, ora);
	}
	else
	{
		this->ora = nullptr;
	}
	if (bileteDisponibile >= 0) {
		this->bileteDisponibile = bileteDisponibile;
	}
	else
	{
		this->bileteDisponibile = 0;
	}
	this->locatie = locatie;
}

Eveniment::Eveniment(const Eveniment& ev)
{
	if (ev.tipEveniment != nullptr)
	{
		tipEveniment = new char[strlen(ev.tipEveniment) + 1];
		strcpy_s(tipEveniment, strlen(ev.tipEveniment) + 1, ev.tipEveniment);
	}
	else
	{
		tipEveniment = nullptr;
	}
	if (ev.numeEveniment != nullptr)
	{
		numeEveniment = new char[strlen(ev.numeEveniment) + 1];
		strcpy_s(numeEveniment, strlen(ev.numeEveniment) + 1, ev.numeEveniment);
	}
	else
	{
		numeEveniment = nullptr;
	}
	if (ev.data != nullptr)
	{
		data = new char[strlen(ev.data) + 1];
		strcpy_s(data, strlen(ev.data) + 1, ev.data);
	}
	else
	{
		data = nullptr;
	}
	if (ev.ora != nullptr)
	{
		ora = new char[strlen(ev.ora) + 1];
		strcpy_s(ora, strlen(ev.ora) + 1, ev.ora);
	}
	else
	{
		ora = nullptr;
	}
	if (ev.bileteDisponibile >= 0) {
		bileteDisponibile = ev.bileteDisponibile;
	}
	else
	{
		bileteDisponibile = 0;
	}
}

Eveniment& Eveniment::operator=(const Eveniment& ev)
{
	if (this != &ev)
	{
		if(ev.tipEveniment != nullptr)
	{
		tipEveniment = new char[strlen(ev.tipEveniment) + 1];
		strcpy_s(tipEveniment, strlen(ev.tipEveniment) + 1, ev.tipEveniment);
	}
	else
	{
		tipEveniment = nullptr;
	}
	if (ev.numeEveniment != nullptr)
	{
		numeEveniment = new char[strlen(ev.numeEveniment) + 1];
		strcpy_s(numeEveniment, strlen(ev.numeEveniment) + 1, ev.numeEveniment);
	}
	else
	{
		numeEveniment = nullptr;
	}
	if (ev.data != nullptr)
	{
		data = new char[strlen(ev.data) + 1];
		strcpy_s(data, strlen(ev.data) + 1, ev.data);
	}
	else
	{
		data = nullptr;
	}
	if (ev.ora != nullptr)
	{
		ora = new char[strlen(ev.ora) + 1];
		strcpy_s(ora, strlen(ev.ora) + 1, ev.ora);
	}
	else
	{
		ora = nullptr;
	}
	if (ev.bileteDisponibile >= 0) {
		bileteDisponibile = ev.bileteDisponibile;
	}
	else
	{
		bileteDisponibile = 0;
	}
	}
	return *this;
}

char* Eveniment::getTipEveniment()
{
	if (tipEveniment != nullptr)
	{
		return tipEveniment;
	}
	else
		return NULL;
}

void Eveniment::setTipEveniment(char* tip)
{
	if (tip != nullptr)
	{
		tipEveniment = new char[strlen(tip) + 1];
		strcpy_s(tipEveniment, strlen(tip) + 1, tip);
	}
	else
	{
		tipEveniment = nullptr;
	}
}

char* Eveniment::getNumeEveniment()
{
	if (numeEveniment != nullptr)
	{
		return numeEveniment;
	}
	else
		return NULL;
}

void Eveniment::setNumeEveniment(char* nume)
{
	if (nume != nullptr)
	{
		numeEveniment = new char[strlen(nume) + 1];
		strcpy_s(numeEveniment, strlen(nume) + 1, nume);
	}
	else
	{
		numeEveniment = nullptr;
	}
}

char* Eveniment::getData()
{
	if (data != nullptr)
	{
		return data;
	}
	else
		return NULL;
}

void Eveniment::setData(char* data)
{
	if (data != nullptr)
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	else
	{
		this->data = nullptr;
	}
}

char* Eveniment::getOra()
{
	if (ora != nullptr)
	{
		return ora;
	}
	else
		return NULL;
}

void Eveniment::setOra(char* ora)
{
	if (ora != nullptr)
	{
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora, strlen(ora) + 1, ora);
	}
	else
	{
		this->ora = nullptr;
	}
}

int Eveniment::getBileteDisponibile()
{
	return bileteDisponibile;
}

void Eveniment::setBileteDisponibile(int bileteDisponibile)
{
	if (bileteDisponibile >= 0)
	{
		this->bileteDisponibile = bileteDisponibile;
	}
	else
	{
		this->bileteDisponibile = 0;
	}
}

Locatie Eveniment::getLocatie()
{
	return this->locatie;
}

void Eveniment::getNrBilete(Locatie locatie)
{
	bileteDisponibile = locatie.nrLocuriDisponibile;
}

void Eveniment::literaMare(char* tipEveniment)
{
	if (tipEveniment != nullptr)
	{
		if (!isupper(tipEveniment[0]))
		{
			tipEveniment[0] -= 32;
		}
	}
}

bool Eveniment::operator>(Locatie locatie)
{
	return bileteDisponibile > locatie.nrLocuriDisponibile;
}

bool Eveniment::operator<(Locatie locatie)
{
	return bileteDisponibile < locatie.nrLocuriDisponibile;
}

Eveniment::~Eveniment()
{
	if (tipEveniment != nullptr)
	{
		delete[] tipEveniment;
		tipEveniment = nullptr;
	}
	if (numeEveniment != nullptr)
	{
		delete[] numeEveniment;
		numeEveniment = nullptr;
	}
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	if (ora != nullptr)
	{
		delete[] ora;
		ora = nullptr;
	}
}

void Eveniment::afisare_succes()
{
	cout << "Inregistrarea evenimentului a reusit!";
}

void Eveniment::afisare_erori()
{
	cout << "Inregistrarea evenimentului nu a reusit!";
}

ostream& operator<<(ostream& out, Eveniment ev)
{
	out << "Tip eveniment: " << ev.tipEveniment << endl;;
	out << "Nume eveniment: " << ev.numeEveniment << endl;
	out << "Data: " << ev.data << endl;
	out << "Ora: " << ev.ora << endl;
	return out;
}

istream& operator>>(istream& in, Eveniment& ev)
{
	cout << "Introduceti tipul evenimetului: " << endl;
	char sir[100];
	in >> sir;
	if (ev.tipEveniment != nullptr)
	{
		delete[] ev.tipEveniment;
		ev.tipEveniment = nullptr;
	}
	ev.tipEveniment = new char[strlen(sir) + 1];
	strcpy_s(ev.tipEveniment, strlen(sir) + 1, sir);

	cout << "Introduceti numele evenimetului: " << endl;
	char sir2[100];
	in >> sir2;
	if (ev.numeEveniment != nullptr)
	{
		delete[] ev.numeEveniment;
		ev.numeEveniment = nullptr;
	}
	ev.numeEveniment = new char[strlen(sir2) + 1];
	strcpy_s(ev.numeEveniment, strlen(sir2) + 1, sir2);

	cout << "Introduceti data evenimetului: " << endl;
	char sir3[100];
	in >> sir3;
	if (ev.data != nullptr)
	{
		delete[] ev.data;
		ev.data = nullptr;
	}
	ev.data = new char[strlen(sir3) + 1];
	strcpy_s(ev.data, strlen(sir3) + 1, sir3);

	cout << "Introduceti ora evenimetului: " << endl;
	char sir4[100];
	in >> sir4;
	if (ev.ora != nullptr)
	{
		delete[] ev.ora;
		ev.ora = nullptr;
	}
	ev.ora = new char[strlen(sir4) + 1];
	strcpy_s(ev.ora, strlen(sir4) + 1, sir4);
	cout << "Introduceti numarul de bilete disponibile: " << endl;
	in >> ev.bileteDisponibile;
	return in;
}