#include "vektor.h"

//vektor::vektor() {
//	meret = 0;
//	tomb = nullptr;
//}

vektor::vektor(unsigned int _meret) {
	meret = _meret;
	tomb = new int[meret];
	for (unsigned int i = 0; i < meret; i++)
		tomb[i] = 0;
}

vektor::vektor(const vektor& v) {
	meret = v.meret;
	tomb = new int[meret];
	for (unsigned int i = 0; i < meret; i++)
		tomb[i] = v.tomb[i];
}

vektor::~vektor() {
	if (tomb != nullptr)
		delete tomb;
}

vektor vektor::operator+(const vektor& v) const {
	vektor eredmeny;
	eredmeny.meret = meret > v.meret ? meret : v.meret;
	eredmeny.tomb = new int[eredmeny.meret];
	for (unsigned int i = 0; i < eredmeny.meret; i++)
		eredmeny.tomb[i] = 0;
	for (unsigned int i = 0; i < meret; i++)
		eredmeny.tomb[i] += tomb[i];
	for (unsigned int i = 0; i < v.meret; i++)
		eredmeny.tomb[i] += v.tomb[i];
	return eredmeny;
}

vektor& vektor::operator=(const vektor& v) {
	meret = v.meret;
	if (tomb != nullptr)
		delete tomb;
	tomb = new int[meret];
	for (unsigned int i = 0; i < meret; i++)
		tomb[i] = v.tomb[i];
	return *this;
}

vektor vektor::operator*(int szorzo) const {
	vektor eredmeny;
	eredmeny.meret = meret;
	eredmeny.tomb = new int[meret];
	for (unsigned int i = 0; i < meret; i++)
		eredmeny[i] = tomb[i] * szorzo;
	return eredmeny;
}

std::ostream& operator<<(std::ostream& s, const vektor& v) {
	for (unsigned int i = 0; i < v.getMeret(); i++)
		s << v.tomb[i] << " ";
	return s;
}

vektor operator*(int szorzo, const vektor& v) {
	return v * szorzo;
}
