#include "Bilete.h"
#include "Eveniment.h"
#include "Locatie.h"
#include "BiletValid.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int mod_utilizator;
	string parola_corecta = "admin";
	string parola;
	int parola_incorecta;
	int tip_bilet;

	int tip_eveniment;

	char* numePersoana;
	int tip_ev_ales;
	int ev_ales;
	int loc_ales;
	int rand_ales;
	string zona_aleasa;
	float pret_zona{};

	int** matrice_locuri_film = new int* [10];
	for (int i = 0; i < 10; i++)
		matrice_locuri_film[i] = new int[10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrice_locuri_film[i][j] = 0;
		}
	}
	vector<string> zone_film;
	zone_film.push_back("Close");
	zone_film.push_back("Middle");
	zone_film.push_back("VIP");
	float* pret_film = new float[3];
	pret_film[0] = 30;
	pret_film[1] = 40;
	pret_film[2] = 70;
	char* locatie_film = new char[14];
	strcpy_s(locatie_film, 14, "Cinematograf");
	Locatie film(locatie_film, 100, 10, 10, matrice_locuri_film, 100, 3, zone_film, pret_film);

	char* tipF = new char[5];
	strcpy_s(tipF, 5, "Film");
	char* numeFilm = new char[7];
	strcpy_s(numeFilm, 7, "Avatar");
	char* dataFilm = new char[11];
	strcpy_s(dataFilm, 11, "11.02.2023");
	char* oraFilm = new char[6];
	strcpy_s(oraFilm, 6, "19:20");
	int bileteDisponibileFilm;
	bileteDisponibileFilm = 100;
	Eveniment avatar(tipF, numeFilm, dataFilm, oraFilm, bileteDisponibileFilm, film);

	char* numeFilm2 = new char[7];
	strcpy_s(numeFilm2, 6, "Megan");
	char* dataFilm2 = new char[11];
	strcpy_s(dataFilm2, 11, "24.01.2023");
	char* oraFilm2 = new char[6];
	strcpy_s(oraFilm2, 6, "20:00");
	Eveniment megan(tipF, numeFilm2, dataFilm2, oraFilm2, bileteDisponibileFilm, film);

	int** matrice_locuri_meci = new int* [10];
	for (int i = 0; i < 10; i++)
		matrice_locuri_meci[i] = new int[10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrice_locuri_meci[i][j] = 0;
		}
	}
	vector<string> zone_meci;
	zone_meci.push_back("Tribuna1");
	zone_meci.push_back("Tribuna2");
	zone_meci.push_back("Peluza");
	float* pret_meci = new float[3];
	pret_meci[0] = 40;
	pret_meci[1] = 60;
	pret_meci[2] = 100;
	char* locatie_meci = new char[8];
	strcpy_s(locatie_meci, 8, "Stadion");
	Locatie meci(locatie_meci, 100, 10, 10, matrice_locuri_meci, 100, 3, zone_meci, pret_meci);

	char* tipM = new char[5];
	strcpy_s(tipM, 5, "Meci");
	char* numeMeci = new char[4];
	strcpy_s(numeMeci, 4, "FCB");
	char* dataMeci = new char[11];
	strcpy_s(dataMeci, 11, "25.02.2023");
	char* oraMeci = new char[6];
	strcpy_s(oraMeci, 6, "21:00");
	int bileteDisponibileMeci;
	bileteDisponibileMeci = 100;
	Eveniment fcb(tipM, numeMeci, dataMeci, oraMeci, bileteDisponibileMeci, meci);

	char* numeMeci2 = new char[4];
	strcpy_s(numeMeci2, 4, "RMD");
	char* dataMeci2 = new char[11];
	strcpy_s(dataMeci2, 11, "14.02.2023");
	char* oraMeci2 = new char[6];
	strcpy_s(oraMeci2, 6, "21:00");
	int bileteDisponibileMeci2;
	bileteDisponibileMeci2 = 100;
	Eveniment rmd(tipM, numeMeci2, dataMeci2, oraMeci2, bileteDisponibileMeci2, meci);

	int** matrice_locuri_teatru = new int* [10];
	for (int i = 0; i < 10; i++)
		matrice_locuri_teatru[i] = new int[10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrice_locuri_teatru[i][j] = 0;
		}
	}
	vector<string> zone_teatru;
	zone_teatru.push_back("Categoria1");
	zone_teatru.push_back("Categoria2");
	zone_teatru.push_back("Loja");
	float* pret_teatru = new float[3];
	pret_teatru[0] = 40;
	pret_teatru[1] = 60;
	pret_teatru[2] = 120;
	char* locatie_teatru = new char[7];
	strcpy_s(locatie_teatru, 7, "Teatru");
	Locatie sceneta(locatie_teatru, 100, 10, 10, matrice_locuri_teatru, 100, 3, zone_teatru, pret_teatru);

	char* tipS = new char[8];
	strcpy_s(tipS, 8, "Sceneta");
	char* numeSceneta = new char[19];
	strcpy_s(numeSceneta, 19, "Capra cu trei iezi");
	char* dataSceneta = new char[11];
	strcpy_s(dataSceneta, 11, "15.03.2023");
	char* oraSceneta = new char[6];
	strcpy_s(oraSceneta, 6, "19:00");
	int bileteDisponibileSceneta;
	bileteDisponibileSceneta = 100;
	Eveniment capra3(tipS, numeSceneta, dataSceneta, oraSceneta, bileteDisponibileSceneta, sceneta);

	char* numeSceneta2 = new char[8];
	strcpy_s(numeSceneta2, 8, "Ranitii");
	char* dataSceneta2 = new char[11];
	strcpy_s(dataSceneta2, 11, "30.03.2023");
	char* oraSceneta2 = new char[6];
	strcpy_s(oraSceneta2, 6, "19:00");
	int bileteDisponibileSceneta2;
	bileteDisponibileSceneta2 = 100;
	Eveniment ranitii(tipS, numeSceneta2, dataSceneta2, oraSceneta2, bileteDisponibileSceneta2, sceneta);

	cout << "Selectati modul in care doriti sa folositi aplicatia:" << endl;
	cout << "1. Utilizator normal" << endl;
	cout << "2. Admin" << endl;
	cin >> mod_utilizator;

	if (mod_utilizator == 2)
	{
		cout << "Introduceti parola: " << endl;
		cin >> parola;
		if (parola == parola_corecta)
		{
			cout << endl;
			cout << "Bine ati venit!" << endl;
			cout << "Pentru ce tip de eveniment ati dori sa introduceti date?" << endl;
			cout << "1. Film" << endl;
			cout << "2. Meci de fotbal" << endl;
			cout << "3. Sceneta de teatru" << endl;
			cin >> tip_eveniment;
			cout << endl;

			if (tip_eveniment == 1)
			{
				Locatie film;
				cin >> film;
				Eveniment filmEv;
				cin >> filmEv;

				ofstream f;
				f.open("film.txt", ios::out | ios::trunc);
				f << filmEv;
				f << film;
				f.close();
			}
			else if (tip_eveniment == 2)
			{
				Locatie meci;
				cin >> meci;
				Eveniment meciEv;
				cin >> meciEv;

				ofstream f;
				f.open("meci.txt", ios::out | ios::trunc);
				f << meciEv;
				f << meci;
				f.close();
			}
			else if (tip_eveniment == 3)
			{
				Locatie sceneta;
				cin >> sceneta;
				Eveniment scenetaEv;
				cin >> scenetaEv;

				ofstream f;
				f.open("sceneta.txt", ios::out | ios::trunc);
				f << scenetaEv;
				f << sceneta;
				f.close();
			}
			cout << "Evenimentul a fost creat cu succes! Puteti inchide fereastra.";
		}
		else
		{
			cout << "Parola pe care ati introdus-o este gresita! Ne pare rau, veti putea folosi aplicatia doar in modul utilizator normal." << endl;
			cout << endl;
			mod_utilizator = 1;
		}
	}

	if (mod_utilizator == 1)
	{
			char sir_nume[100];
			cout << "Introduceti-va numele de familie: " << endl;
			cin >> sir_nume;
			numePersoana = new char[strlen(sir_nume) + 1];
			strcpy_s(numePersoana, strlen(sir_nume) + 1, sir_nume);
			cout << "La ce tip de eveniment doriti sa mergeti?" << endl;
			cout << "1. Film" << endl;
			cout << "2. Meci de fotbal" << endl;
			cout << "3. Sceneta de teatru" << endl;
			cin >> tip_ev_ales;
			if (tip_ev_ales == 1)
			{
				cout << "Alegeti unul din filmele disponibile: " << endl;
				cout << "1. " << avatar.getNumeEveniment() << endl;
				cout << "2. " << megan.getNumeEveniment() << endl;
				cin >> ev_ales;
				if (ev_ales == 1)
				{
					cout << "Acestea sunt detaliile locatiei: " << endl;
					cout << avatar.getLocatie();
					cout << "Alegeti o zona: " << endl;
					cin >> zona_aleasa;
					if (zona_aleasa == "Close" || zona_aleasa== "close")
					{
						pret_zona = 30;
					}
					else if (zona_aleasa == "Middle" || zona_aleasa == "middle")
					{
						pret_zona = 40;
					}
					else if (zona_aleasa == "VIP" || zona_aleasa == "vip")
					{
						pret_zona = 70;
					}
					cout << "Alegeti un loc disponibil si un rand: " << endl;
					cin >> loc_ales;
					cin >> rand_ales;
					film.ocupareLoc(loc_ales, rand_ales);
					cout << "Biletul se va creea imediat!" << endl;
					cout << endl;

					Bilete bil(numePersoana, avatar);
					cout << bil;
					ofstream f;
					f.open("biletAVATAR.txt", ios::out | ios::trunc);
					f << bil;
					f << "Locatie:" << film.getNumeLocatie() << endl;
					f <<"Nume film: "<< avatar.getNumeEveniment() << endl;
					f <<"Data film: "<< avatar.getData() << endl;
					f <<"Ora film: " << avatar.getOra() << endl;
					cout <<"Locatie: " << film.getNumeLocatie() << endl;
					cout <<"Nume film: " << avatar.getNumeEveniment() << endl;
					cout <<"Data film: "<< avatar.getData() << endl;
					cout <<"Ora film: " << avatar.getOra() << endl;
					cout << "Pret: " << pret_zona << endl;
					f << "Loc: " << loc_ales << endl;
					f << "Rand: " << rand_ales << endl;
					f << "Zona: " << zona_aleasa << endl;
					f << "Pret: " << pret_zona << endl;
					f.close();
				}
				else if (ev_ales == 2)
				{
					cout << "Acestea sunt detaliile locatiei: " << endl;
					cout << megan.getLocatie();
					cout << "Alegeti o zona: " << endl;
					cin >> zona_aleasa;
					if (zona_aleasa == "Close" || zona_aleasa == "close")
					{
						pret_zona = 30;
					}
					else if (zona_aleasa == "Middle" || zona_aleasa == "middle")
					{
						pret_zona = 40;
					}
					else if (zona_aleasa == "VIP" || zona_aleasa == "vip")
					{
						pret_zona = 70;
					}
					cout << "Alegeti un loc disponibil si un rand: " << endl;
					cin >> loc_ales;
					cin >> rand_ales;
					film.ocupareLoc(loc_ales, rand_ales);
					cout << "Biletul se va creea imediat!" << endl;
					cout << endl;
					Bilete bil(numePersoana, megan);
					cout << bil;
					ofstream f;
					f.open("biletMEGAN.txt", ios::out | ios::trunc);
					f << bil;
					f << "Locatie:" << film.getNumeLocatie() << endl;
					f << "Nume film: " << megan.getNumeEveniment() << endl;
					f << "Data film: " << megan.getData() << endl;
					f << "Ora film: " << megan.getOra() << endl;
					cout << "Locatie: " << film.getNumeLocatie() << endl;
					cout << "Nume film: " << megan.getNumeEveniment() << endl;
					cout << "Data film: " << megan.getData() << endl;
					cout << "Ora film: " << megan.getOra() << endl;
					cout << "Pret: " << pret_zona << endl;
					f << "Loc: " << loc_ales << endl;
					f << "Rand: " << rand_ales << endl;
					f << "Zona: " << zona_aleasa << endl;
					f << "Pret: " << pret_zona << endl;
					f.close();
				}

			}
			else if (tip_ev_ales == 2)
			{
				cout << "Alegeti unul din meciurile disponibile: " << endl;
				cout << "1. " << fcb.getNumeEveniment() << endl;
				cout << "2. " << rmd.getNumeEveniment() << endl;
				cin >> ev_ales;
				if (ev_ales == 1)
				{
					cout << "Acestea sunt detaliile locatiei: " << endl;
					cout << fcb.getLocatie();
					cout << "Alegeti o zona: " << endl;
					cin >> zona_aleasa;
					if (zona_aleasa == "Tribuna1" || zona_aleasa=="tribuna1")
					{
						pret_zona = 40;
					}
					else if (zona_aleasa == "Tribuna2" || zona_aleasa == "tribuna2")
					{
						pret_zona = 60;
					}
					else if (zona_aleasa == "Peluza" || zona_aleasa == "peluza")
					{
						pret_zona = 100;
					}
					cout << "Alegeti un loc disponibil si un rand: " << endl;
					cin >> loc_ales;
					cin >> rand_ales;
					meci.ocupareLoc(loc_ales, rand_ales);
					cout << "Biletul se va creea imediat!" << endl;
					cout << endl;

					Bilete bil(numePersoana, fcb);
					cout << bil;
					ofstream f;
					f.open("biletFCB.txt", ios::out | ios::trunc);
					f << bil;
					f << "Locatie:" << meci.getNumeLocatie() << endl;
					f << "Nume meci: " << fcb.getNumeEveniment() << endl;
					f << "Data meci: " << fcb.getData() << endl;
					f << "Ora meci: " << fcb.getOra() << endl;
					cout << "Locatie: " << meci.getNumeLocatie() << endl;
					cout << "Nume meci: " << fcb.getNumeEveniment() << endl;
					cout << "Data meci: " << fcb.getData() << endl;
					cout << "Ora meci: " << fcb.getOra() << endl;
					cout << "Pret: " << pret_zona<<endl;
					f << "Loc: " << loc_ales << endl;
					f << "Rand: " << rand_ales << endl;
					f << "Zona: " << zona_aleasa << endl;
					f << "Pret: " << pret_zona << endl;
					f.close();
				}
				else if (ev_ales == 2)
				{
					cout << "Acestea sunt detaliile locatiei: " << endl;
					cout << rmd.getLocatie();
					cout << "Alegeti o zona: " << endl;
					cin >> zona_aleasa;
					if (zona_aleasa == "Tribuna1" || zona_aleasa == "tribuna1")
					{
						pret_zona = 40;
					}
					else if (zona_aleasa == "Tribuna2" || zona_aleasa == "tribuna2")
					{
						pret_zona = 60;
					}
					else if (zona_aleasa == "Peluza" || zona_aleasa == "peluza")
					{
						pret_zona = 100;
					}
					cout << "Alegeti un loc disponibil si un rand: " << endl;
					cin >> loc_ales;
					cin >> rand_ales;
					meci.ocupareLoc(loc_ales, rand_ales);
					cout << "Biletul se va creea imediat!" << endl;
					cout << endl;

					Bilete bil(numePersoana, rmd);
					cout << bil;
					ofstream f;
					f.open("biletRMD.txt", ios::out | ios::trunc);
					f << bil;
					f << "Locatie:" << meci.getNumeLocatie() << endl;
					f << "Nume meci: " << rmd.getNumeEveniment() << endl;
					f << "Data meci: " << rmd.getData() << endl;
					f << "Ora meci: " << rmd.getOra() << endl;
					cout << "Locatie: " << meci.getNumeLocatie() << endl;
					cout << "Nume meci: " << rmd.getNumeEveniment() << endl;
					cout << "Data meci: " << rmd.getData() << endl;
					cout << "Ora meci: " << rmd.getOra() << endl;
					cout << "Pret: " << pret_zona<<endl;
					f << "Loc: " << loc_ales << endl;
					f << "Rand: " << rand_ales << endl;
					f << "Zona: " << zona_aleasa << endl;
					f << "Pret: " << pret_zona << endl;
					f.close();
				}
			}
			else if (tip_ev_ales == 3)
			{
				cout << "Alegeti una din scenetele disponibile: " << endl;
				cout << "1. " << capra3.getNumeEveniment() << endl;
				cout << "2. " << ranitii.getNumeEveniment() << endl;
				cin >> ev_ales;
				if (ev_ales == 1)
				{
					cout << "Acestea sunt detaliile locatiei: " << endl;
					cout << capra3.getLocatie();
					cout << "Alegeti o zona: " << endl;
					cin >> zona_aleasa;
					if (zona_aleasa == "Categoria1" || zona_aleasa == "categoria1")
					{
						pret_zona = 40;
					}
					else if (zona_aleasa == "Categoria2" || zona_aleasa == "categoria2")
					{
						pret_zona = 60;
					}
					else if (zona_aleasa == "Loja" || zona_aleasa == "loja")
					{
						pret_zona = 120;
					}
					cout << "Alegeti un loc disponibil si un rand: " << endl;
					cin >> loc_ales;
					cin >> rand_ales;
					film.ocupareLoc(loc_ales, rand_ales);
					cout << "Biletul se va creea imediat!" << endl;
					cout << endl;

					Bilete bil(numePersoana, capra3);
					cout << bil;
					ofstream f;
					f.open("biletCAPRA.txt", ios::out | ios::trunc);
					f << bil;
					f << "Locatie:" << sceneta.getNumeLocatie() << endl;
					f << "Nume sceneta: " << capra3.getNumeEveniment() << endl;
					f << "Data sceneta: " << capra3.getData() << endl;
					f << "Ora sceneta: " << capra3.getOra() << endl;
					cout << "Locatie: " << sceneta.getNumeLocatie() << endl;
					cout << "Nume sceneta: " << capra3.getNumeEveniment() << endl;
					cout << "Data sceneta: " << capra3.getData() << endl;
					cout << "Ora sceneta: " << capra3.getOra() << endl;
					cout << "Pret: " << pret_zona << endl;
					f << "Loc: " << loc_ales << endl;
					f << "Rand: " << rand_ales << endl;
					f << "Zona: " << zona_aleasa << endl;
					f << "Pret: " << pret_zona << endl;
					f.close();
				}
				else if (ev_ales == 2)
				{
					cout << "Acestea sunt detaliile locatiei: " << endl;
					cout << ranitii.getLocatie();
					cout << "Alegeti o zona: " << endl;
					cin >> zona_aleasa;
					if (zona_aleasa == "Categoria1" || zona_aleasa == "categoria1")
					{
						pret_zona = 40;
					}
					else if (zona_aleasa == "Categoria2" || zona_aleasa == "categoria2")
					{
						pret_zona = 60;
					}
					else if (zona_aleasa == "Loja" || zona_aleasa == "loja")
					{
						pret_zona = 120;
					}
					cout << "Alegeti un loc disponibil si un rand: " << endl;
					cin >> loc_ales;
					cin >> rand_ales;
					film.ocupareLoc(loc_ales, rand_ales);
					cout << "Biletul se va creea imediat!" << endl;
					cout << endl;

					Bilete bil(numePersoana, ranitii);
					cout << bil;
					ofstream f;
					f.open("biletRANITII.txt", ios::out | ios::trunc);
					f << bil;
					f << "Locatie:" << sceneta.getNumeLocatie() << endl;
					f << "Nume sceneta: " << ranitii.getNumeEveniment() << endl;
					f << "Data sceneta: " << ranitii.getData() << endl;
					f << "Ora sceneta: " << ranitii.getOra() << endl;
					cout << "Locatie: " << sceneta.getNumeLocatie() << endl;
					cout << "Nume sceneta: " << ranitii.getNumeEveniment() << endl;
					cout << "Data sceneta: " << ranitii.getData() << endl;
					cout << "Ora sceneta: " << ranitii.getOra() << endl;
					cout << "Pret: " << pret_zona<<endl;
					f << "Loc: " << loc_ales << endl;
					f << "Rand: " << rand_ales << endl;
					f << "Zona: " << zona_aleasa << endl;
					f << "Pret: " << pret_zona << endl;
					f.close();
				}
			}
	}
	return 0;
}