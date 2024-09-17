#include <iostream>
using namespace std;
class Vektor
{
	int meret;
	int *tomb = new int;
public:
	Vektor(int _meret);
	~Vektor();	
	Vektor(const Vektor& c);
	int getErtek(unsigned int index) const { return tomb[index]; }
	void setErtek(unsigned int index, int ertek) { tomb[index] = ertek; }
	unsigned int getMeret() const { return meret; }

	
	int operator[](unsigned int index) const { return tomb[index]; }
	int& operator[](unsigned int index) { return tomb[index]; }
	friend std::ostream& operator<<(std::ostream& s, const Vektor& v);
};

Vektor::Vektor(int _meret )
{
	meret = _meret;
	tomb = new int[meret];
	for (size_t i = 0; i < meret; i++)
	{
		tomb[i] = i;
	}

}

Vektor::~Vektor()
{
	delete tomb;
}

Vektor::Vektor(const Vektor& c)
{
	meret = c.meret;
	tomb = new int[meret];
	for (size_t i = 0; i < meret; i++)
	{
		tomb[i] = c.tomb[i];
	}
}

int main() {
	Vektor v1(4);
	for (int i = 0; i < v1.getMeret(); i++)
	{
		v1[i] = i;
	}
	std::cout << v1 << std::endl;
	
}

ostream& operator<<(ostream& s, const Vektor& v) {
	for (int i = 0; i < v.getMeret(); i++)
		s << v.tomb[i] << " ";
	return s;
}