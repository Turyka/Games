#include <iostream>
#include "vektor.h"

int main() {
	vektor<int> v1, v4(5);
	vektor<int>* v2, * v3;
	v2 = new vektor<int>(3);
	v3 = new vektor<int>[3];

	vektor<int> v5;
	for (unsigned int i = 0; i < v4.getMeret(); i++)
		v4[i] = i;
	//v4.setErtek(i, i);
//for(unsigned int i = 0; i < v4.getMeret(); i++)
//	std::cout << v4[i] << " ";
	//std::cout << v4.getErtek(i) << " ";
	std::cout << v4 << std::endl;

	v5 = v1 + v4;
	v4 = v4 * 12;
	std::cout << v4 << std::endl;
	v4 = 3 * v4;
	std::cout << v4 << std::endl;

	try {
		v4[6] = 5;
	}
	catch (std::string s) {
		std::cout << s << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	delete[] v3;
	delete v2;

	vektor<double> v7(6);
	for (unsigned int i = 0; i < v7.getMeret(); i++)
		v7[i] = (double)i / (i + 1);
	std::cout << v7 << std::endl;

	unsigned int N = 3, M = 5;
	vektor<vektor<int>> matrix(N);
	for (unsigned int i = 0; i < N; i++) {
		matrix[i].meretez(M);
		for (unsigned int j = 0; j < M; j++)
			matrix[i][j] = i * j;
	}
	std::cout << matrix << std::endl;
}