#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include "4x4_Karnouh.hpp"
using namespace std;
int main()
{
    int szamlalo = 0;
    vector<int> Karnouh_indexek;
    int input;
    
    while (szamlalo < 16) {
        cout << "Kerek be Indexeket (Karnouh): ";
        cin >> input;

        if (input == 111) {
            break;
        }
        else if (input >= 0 && input < 16) {

            Karnouh_indexek.push_back(input);
            szamlalo++;
        }
        else {
            cout << "Csak 0-15 kozott lehet az index." << endl;
        }
    }

    int tabla[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    Karnouh_4x4_matrix(tabla, Karnouh_indexek, szamlalo);
}