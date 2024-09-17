#include <iostream>
#include "vektor.h"
using namespace std;

int main() {
	vektor v1, v4(8);
	//pointer
	vektor *v2, *v3;
	v2 = new vektor(3);
	v3 = new vektor[3];
	
	vektor v5;
	
	vektor v6;
	std::cout << "Getertek: "  << v6.getMeret() << std::endl;
	for (unsigned int i = 0; i < v4.getMeret(); i++)
	{
		v4[i] = i;
	}
	//v4.setErtek(i, i);
//for(unsigned int i = 0; i < v4.getMeret(); i++)
//	std::cout << v4[i] << " ";
	//std::cout << v4.getErtek(i) << " ";
	cout << "iurhgruihg:" <<v4 << std::endl;

	v5 = v1 + v4;
	v4 = v4 * 12;
	std::cout << "v5 ereket:" << v5 << std::endl;
	v4 = 3 * v4;
	std::cout << v4 << std::endl;

	delete[] v3;
	delete v2;
}