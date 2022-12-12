#pragma once
#include <iostream>
#include <string>
using namespace std;

class Zona
{
	string denumire;
	int numarLocuriPeRand;
	int nrLocuri;
	int nrRanduri;
	int* locOcupat; //se marcheaza cu 1-ocupat si 0-liber
public:
	Zona() {
		denumire = "necunoscuta";
		nrLocuri = 1;
		nrRanduri = 1;
		locOcupat = new int[1]{ 1 };
	}
	Zona(string denumire, int nrL, int nrR, int* nrLoc) {
		this->denumire = denumire;
		nrLocuri = nrL;
		nrRanduri = nrR;
		if (locOcupat != nullptr)
			delete[] locOcupat;
		locOcupat = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			locOcupat[i] = nrLoc[i];
		}
		numarLocuriPeRand = getNumarLocuri_peRand();
	}
	
	~Zona() { delete[] locOcupat;}

	void setDenumire(string denumire) { this->denumire = denumire; }
	void setNrLocuri(int x) { this->nrLocuri = x; }
	void setNrRanduri(int x) { this->nrRanduri = x; }
	void setNrLocuri_peRand(int x) { this->numarLocuriPeRand = x; }
	void setNumarLoc(int* x) {
		if (locOcupat != nullptr)
			delete[] locOcupat;
		if (x != nullptr && nrRanduri > 0) {
			locOcupat = new int[nrRanduri];
			for (int i = 0; i < nrRanduri; i++) {
				locOcupat[i] = x[i];
			}
		}
	}

	string getDenumire() { return denumire; }
	int getNrL() { return nrLocuri; }
	int getNrR() { return nrRanduri; }
	int getNumarLocuri_peRand() {
		numarLocuriPeRand = nrLocuri / nrRanduri;
		return numarLocuriPeRand;
	}
	int* getLocOcupat() { return locOcupat; }

	friend istream& operator>>(istream& in, Zona& x) {
		cout << "Denumire zona: ";
		in.get();
		getline(in, x.denumire);
		cout << "Numar locuri: ";
		in >> x.nrLocuri;
		cout << "Numar randuri: ";
		in >> x.nrRanduri;
		x.numarLocuriPeRand = x.getNumarLocuri_peRand();
		return in;
	}

	friend ostream& operator<<(ostream& out, Zona x) {
		out << "Denumire zona: " << x.denumire << endl;
		out << "Numar locuri: " << x.nrLocuri << endl;
		out << "Numar randuri: " << x.nrRanduri << endl;
		out << "Numar locuri pe rand: " << x.getNumarLocuri_peRand() << endl;
		return out;
	}

	Zona(const Zona& x) {
		denumire = x.denumire;
		nrLocuri = x.nrLocuri;
		nrRanduri = x.nrRanduri;
	}

	Zona operator=(const Zona& i) {
		Zona& x = *this;
		x.denumire = i.denumire;
		x.numarLocuriPeRand = i.numarLocuriPeRand;
		x.nrLocuri = i.nrLocuri;
		x.nrRanduri = i.nrRanduri;
		return x;
	}
};