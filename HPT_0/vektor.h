//#ifndef __VEKTOR__
//#define __VEKTOR__

#pragma once

#include <iostream>

class vektor {
	int* tomb;
	unsigned int meret;
	// privát oszály érték
public:
	//vektor();
	vektor(unsigned int _meret = 0);
	vektor(const vektor&);
	~vektor();
	// meret behuzasa
	unsigned int getMeret() const { return meret; }
	// Eterek behuzas
	int getErtek(unsigned int index) const { return tomb[index]; }
	// Ertek alitas
	void setErtek(unsigned int index, int ertek) { tomb[index] = ertek; }

	vektor operator+(const vektor& v) const;
	vektor& operator=(const vektor& v);
	int operator[](unsigned int index) const{ return tomb[index]; }
	int& operator[](unsigned int index) { return tomb[index]; }
	vektor operator*(int) const;

	friend std::ostream& operator<<(std::ostream& s, const vektor& v);
	friend vektor operator*(int, const vektor&);
};




//#endif // !__VEKTOR__
