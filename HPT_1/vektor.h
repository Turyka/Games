//#ifndef __VEKTOR__
//#define __VEKTOR__

#pragma once

#include <iostream>
#include <string>
#include "myexcept.h"

template <class Tipus>
class vektor {
	Tipus* tomb;
	unsigned int meret;
public:
	//vektor();
	vektor(unsigned int _meret = 0) : meret(_meret) {
		tomb = new Tipus[meret];
		for (unsigned int i = 0; i < meret; i++)
			tomb[i] = Tipus();
	}

	vektor(const vektor& v) : meret(v.meret) {
		tomb = new Tipus[meret];
		for (unsigned int i = 0; i < meret; i++)
			tomb[i] = v.tomb[i];
	}
	~vektor() {
		if (tomb != nullptr)
			delete[] tomb;
	}

	unsigned int getMeret() const { return meret; }
	Tipus getErtek(unsigned int index) const { return tomb[index]; }
	void setErtek(unsigned int index, Tipus ertek) { tomb[index] = ertek; }

	vektor operator+(const vektor& v) const {
		vektor eredmeny;
		eredmeny.meret = meret > v.meret ? meret : v.meret;
		eredmeny.tomb = new Tipus[eredmeny.meret];
		for (unsigned int i = 0; i < eredmeny.meret; i++)
			eredmeny.tomb[i] = 0;
		for (unsigned int i = 0; i < meret; i++)
			eredmeny.tomb[i] += tomb[i];
		for (unsigned int i = 0; i < v.meret; i++)
			eredmeny.tomb[i] += v.tomb[i];
		return eredmeny;
	}

	vektor& operator=(const vektor& v) {
		meret = v.meret;
		if (tomb != nullptr)
			delete[] tomb;
		tomb = new Tipus[meret];
		for (unsigned int i = 0; i < meret; i++)
			tomb[i] = v.tomb[i];
		return *this;
	}

	Tipus operator[](unsigned int index) const { return tomb[index]; }
	Tipus& operator[](unsigned int index) {
		if (index >= meret)
			throw tulcimzesException((std::string("Tulcimzes! Meret: ") + std::to_string(meret) + " Index: " + std::to_string(index)));
		//throw std::string("Tulcimzes! Meret: ") + std::to_string(meret) + " Index: " + std::to_string(index);
		return tomb[index];
	}

	void meretez(unsigned int ujmeret) {
		delete[] tomb;
		tomb = new Tipus[ujmeret];
		meret = ujmeret;
		for (unsigned int i = 0; i < meret; i++)
			tomb[i] = Tipus();
	}

	vektor operator*(int szorzo) const {
		vektor eredmeny;
		eredmeny.meret = meret;
		eredmeny.tomb = new Tipus[meret];
		for (unsigned int i = 0; i < meret; i++)
			eredmeny[i] = tomb[i] * szorzo;
		return eredmeny;
	}

	friend std::ostream& operator<<(std::ostream& s, const vektor& v) {
		for (unsigned int i = 0; i < v.getMeret(); i++)
			s << v.tomb[i] << " ";
		return s;
	}

	friend vektor operator*(int szorzo, const vektor& v) {
		return v * szorzo;
	}

};




//#endif // !__VEKTOR__
