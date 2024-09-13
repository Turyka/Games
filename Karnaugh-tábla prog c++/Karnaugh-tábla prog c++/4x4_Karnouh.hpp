#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int Dec_to_Binary(int num) {
    int binary = 0;
    int place = 1;
    while (num > 0) {
        binary += (num % 2) * place;
        num /= 2;
        place *= 10;
    }
    return binary;
}

int Binary_to_Dec(int num) {
    int decimal = 0;
    int base = 1;
    while (num > 0) {
        decimal += (num % 10) * base;
        num /= 10;
        base *= 2;
    }
    return decimal;
}

int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num % 10;
        num /= 10;
    }
    return count;
}
bool Megegyezik_e_a_vektor_ertekei(int value, const tuple<int, int, int, int>& tpl) {
    return (value == get<0>(tpl) || value == get<1>(tpl) || value == get<2>(tpl) || value == get<3>(tpl));
}

void Karnouh_4x4_matrix(int tabla[4][4], const vector<int>& Karnouh_indexek, int szamlalo)
{
    for (size_t k = 0; k < szamlalo; k++)
    {
        switch (Karnouh_indexek[k]) {
        case 0:
            tabla[0][0] = 1;
            break;
        case 1:
            tabla[0][1] = 1;
            break;
        case 2:
            tabla[0][3] = 1;
            break;
        case 3:
            tabla[0][2] = 1;
            break;
        case 4:
            tabla[1][0] = 1;
            break;
        case 5:
            tabla[1][1] = 1;
            break;
        case 6:
            tabla[1][3] = 1;
            break;
        case 7:
            tabla[1][2] = 1;
            break;
        case 8:
            tabla[3][0] = 1;
            break;
        case 9:
            tabla[3][1] = 1;
            break;
        case 10:
            tabla[3][3] = 1;
            break;
        case 11:
            tabla[3][2] = 1;
            break;
        case 12:
            tabla[2][0] = 1;
            break;
        case 13:
            tabla[2][1] = 1;
            break;
        case 14:
            tabla[2][3] = 1;
            break;
        case 15:
            tabla[2][2] = 1;
            break;
        }
    }
    cout << endl;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << '\t' << tabla[i][j];
        }
        cout << endl;
    }
    cout << endl;

    vector<int> Karnouh_indexek_binary;
    for (size_t i = 0; i < szamlalo; i++)
    {
        Karnouh_indexek_binary.push_back(Dec_to_Binary(Karnouh_indexek[i]));
    }
    //Minterm Binary
    vector<int> Suly0_Binary;
    vector<int> Suly1_Binary;
    vector<int> Suly2_Binary;
    vector<int> Suly3_Binary;
    vector<int> Suly4_Binary;

    //Minterm Dec
    vector<int> Suly0_Dec;
    vector<int> Suly1_Dec;
    vector<int> Suly2_Dec;
    vector<int> Suly3_Dec;
    vector<int> Suly4_Dec;
    cout << endl;

    cout << "Indexek binarisan: ";
    cout << endl;
    for (size_t i = 0; i < szamlalo; i++)
    {
        cout << Karnouh_indexek_binary[i] << " ";
        if (countSetBits(Karnouh_indexek_binary[i]) == 0)
        {
            Suly0_Binary.push_back(Dec_to_Binary(Karnouh_indexek[i]));
            Suly0_Dec.push_back(Karnouh_indexek[i]);
        }
        if (countSetBits(Karnouh_indexek_binary[i]) == 1)
        {
            Suly1_Binary.push_back(Dec_to_Binary(Karnouh_indexek[i]));
            Suly1_Dec.push_back(Karnouh_indexek[i]);
        }
        if (countSetBits(Karnouh_indexek_binary[i]) == 2)
        {
            Suly2_Binary.push_back(Dec_to_Binary(Karnouh_indexek[i]));
            Suly2_Dec.push_back(Karnouh_indexek[i]);
        }
        if (countSetBits(Karnouh_indexek_binary[i]) == 3)
        {
            Suly3_Binary.push_back(Dec_to_Binary(Karnouh_indexek[i]));
            Suly3_Dec.push_back(Karnouh_indexek[i]);
        }
        if (countSetBits(Karnouh_indexek_binary[i]) == 4)
        {
            Suly4_Binary.push_back(Dec_to_Binary(Karnouh_indexek[i]));
            Suly4_Dec.push_back(Karnouh_indexek[i]);
        }
    }
    cout << endl;
    cout << endl;

    cout << "0-es Suly szama: " << Suly0_Binary.size() << endl;
    for (size_t i = 0; i < Suly0_Binary.size(); i++)
    {
        cout << Suly0_Binary[i] << endl;
    }

    cout << endl;

    cout << "1-es Suly szama: " << Suly1_Binary.size() << endl;
    for (size_t i = 0; i < Suly1_Binary.size(); i++)
    {
        cout << "Bin: " << Suly1_Binary[i] << " Dec: " << Suly1_Dec[i] << endl;
    }

    cout << endl;

    cout << "2-es Suly szama: " << Suly2_Binary.size() << endl;
    for (size_t i = 0; i < Suly2_Binary.size(); i++)
    {
        cout << "Bin: " << Suly2_Binary[i] << " Dec: " << Suly2_Dec[i] << endl;
    }
    cout << endl;

    cout << "3-es Suly szama: " << Suly3_Binary.size() << endl;
    for (size_t i = 0; i < Suly3_Binary.size(); i++)
    {
        cout << "Bin: " << Suly3_Binary[i] << " Dec: " << Suly3_Dec[i] << endl;
    }
    cout << endl;

    cout << "4-es Suly szama: " << Suly4_Binary.size() << endl;
    for (size_t i = 0; i < Suly4_Binary.size(); i++)
    {
        cout << "Bin: " << Suly4_Binary[i] << " Dec: " << Suly4_Dec[i] << endl;
    }
    vector<pair<int, int>> Kulumbseg1;
    vector<pair<int, int>> Kulumbseg2;
    vector<pair<int, int>> Kulumbseg4;
    vector<pair<int, int>> Kulumbseg8;

    //Suly0-bol megnezni az osszes Suly1-et
    if (Suly0_Dec.size() > 0 && Suly1_Dec.size() > 0)
    {
        for (size_t i = 0; i < Suly1_Dec.size(); i++)
        {
            if (abs(Suly0_Dec[0] - Suly1_Dec[i]) == 1)
            {
                if (Suly0_Dec[0] < Suly1_Dec[i])
                {
                    Kulumbseg1.push_back(make_pair(Suly0_Dec[0], Suly1_Dec[i]));
                }
            }
            else if (abs(Suly0_Dec[0] - Suly1_Dec[i]) == 2)
            {
                if (Suly0_Dec[0] < Suly1_Dec[i])
                {
                    Kulumbseg2.push_back(make_pair(Suly0_Dec[0], Suly1_Dec[i]));
                }
            }
            else if (abs(Suly0_Dec[0] - Suly1_Dec[i]) == 4)
            {
                if (Suly0_Dec[0] < Suly1_Dec[i])
                {
                    Kulumbseg4.push_back(make_pair(Suly0_Dec[0], Suly1_Dec[i]));
                }
            }
            else if (abs(Suly0_Dec[0] - Suly1_Dec[i]) == 8)
            {
                if (Suly0_Dec[0] < Suly1_Dec[i])
                {
                    Kulumbseg8.push_back(make_pair(Suly0_Dec[0], Suly1_Dec[i]));
                }
            }
        }
    }
    //Suly1-bol megnezi az osszes Suly2-et
    if (Suly1_Dec.size() > 0 && Suly2_Dec.size() > 0)
    {
        for (size_t i = 0; i < Suly1_Dec.size(); i++)
        {
            for (size_t j = 0; j < Suly2_Dec.size(); j++)
            {
                if (abs(Suly1_Dec[i] - Suly2_Dec[j]) == 1)
                {
                    if (Suly1_Dec[i] < Suly2_Dec[j])
                    {
                        Kulumbseg1.push_back(make_pair(Suly1_Dec[i], Suly2_Dec[j]));
                    }
                }
                else if (abs(Suly1_Dec[i] - Suly2_Dec[j]) == 2)
                {
                    if (Suly1_Dec[i] < Suly2_Dec[j])
                    {
                        Kulumbseg2.push_back(make_pair(Suly1_Dec[i], Suly2_Dec[j]));
                    }
                }
                else if (abs(Suly1_Dec[i] - Suly2_Dec[j]) == 4)
                {
                    if (Suly1_Dec[i] < Suly2_Dec[j])
                    {
                        Kulumbseg4.push_back(make_pair(Suly1_Dec[i], Suly2_Dec[j]));
                    }
                }
                else if (abs(Suly1_Dec[i] - Suly2_Dec[j]) == 8)
                {
                    if (Suly1_Dec[i] < Suly2_Dec[j])
                    {
                        Kulumbseg8.push_back(make_pair(Suly1_Dec[i], Suly2_Dec[j]));
                    }
                }
            }
        }
    }
    //Suly2-bol megnezi az osszes Suly3-at
    if (Suly2_Dec.size() > 0 && Suly3_Dec.size() > 0)
    {
        for (size_t i = 0; i < Suly2_Dec.size(); i++)
        {
            for (size_t j = 0; j < Suly3_Dec.size(); j++)
            {
                if (abs(Suly2_Dec[i] - Suly3_Dec[j]) == 1)
                {
                    if (Suly2_Dec[i] < Suly3_Dec[j])
                    {
                        Kulumbseg1.push_back(make_pair(Suly2_Dec[i], Suly3_Dec[j]));
                    }
                }
                else if (abs(Suly2_Dec[i] - Suly3_Dec[j]) == 2)
                {
                    if (Suly2_Dec[i] < Suly3_Dec[j])
                    {
                        Kulumbseg2.push_back(make_pair(Suly2_Dec[i], Suly3_Dec[j]));
                    }
                }
                else if (abs(Suly2_Dec[i] - Suly3_Dec[j]) == 4)
                {
                    if (Suly2_Dec[i] < Suly3_Dec[j])
                    {
                        Kulumbseg4.push_back(make_pair(Suly2_Dec[i], Suly3_Dec[j]));
                    }
                }
                else if (abs(Suly2_Dec[i] - Suly3_Dec[j]) == 8)
                {
                    if (Suly2_Dec[i] < Suly3_Dec[j])
                    {
                        Kulumbseg8.push_back(make_pair(Suly2_Dec[i], Suly3_Dec[j]));
                    }
                }
            }
        }
    }
    //Suly3-bol megnezi az osszes Suly4-et
    if (Suly3_Dec.size() > 0 && Suly4_Dec.size() > 0)
    {
        for (size_t i = 0; i < Suly3_Dec.size(); i++)
        {
            for (size_t j = 0; j < Suly4_Dec.size(); j++)
            {
                if (abs(Suly3_Dec[i] - Suly4_Dec[j]) == 1)
                {
                    if (Suly3_Dec[i] < Suly4_Dec[j])
                    {
                        Kulumbseg1.push_back(make_pair(Suly3_Dec[i], Suly4_Dec[j]));
                    }
                }
                else if (abs(Suly3_Dec[i] - Suly4_Dec[j]) == 2)
                {
                    if (Suly3_Dec[i] < Suly4_Dec[j])
                    {
                        Kulumbseg2.push_back(make_pair(Suly3_Dec[i], Suly4_Dec[j]));
                    }
                }
                else if (abs(Suly3_Dec[i] - Suly4_Dec[j]) == 4)
                {
                    if (Suly3_Dec[i] < Suly4_Dec[j])
                    {
                        Kulumbseg4.push_back(make_pair(Suly3_Dec[i], Suly4_Dec[j]));
                    }
                }
                else if (abs(Suly3_Dec[i] - Suly4_Dec[j]) == 8)
                {
                    if (Suly3_Dec[i] < Suly4_Dec[j])
                    {
                        Kulumbseg8.push_back(make_pair(Suly3_Dec[i], Suly4_Dec[j]));
                    }
                }
            }
        }
    }

    cout << endl;
    cout << "1 Kulombseg:" << endl;
    for (size_t i = 0; i < Kulumbseg1.size(); i++)
    {
        cout << "(" << Kulumbseg1[i].first << ", " << Kulumbseg1[i].second << ")" << endl;
    }
    cout << endl;
    cout << "2 Kulombseg:" << endl;
    for (size_t i = 0; i < Kulumbseg2.size(); i++)
    {
        cout << "(" << Kulumbseg2[i].first << ", " << Kulumbseg2[i].second << ")" << endl;
    }
    cout << endl;
    cout << "4 Kulombseg:" << endl;
    for (size_t i = 0; i < Kulumbseg4.size(); i++)
    {
        cout << "(" << Kulumbseg4[i].first << ", " << Kulumbseg4[i].second << ")" << endl;
    }
    cout << endl;
    cout << "8 Kulombseg:" << endl;
    for (size_t i = 0; i < Kulumbseg8.size(); i++)
    {
        cout << "(" << Kulumbseg8[i].first << ", " << Kulumbseg8[i].second << ")" << endl;
    }


    // 1. Kulombseg
    vector<tuple<int, int, int, int>> Kulumbseg1_2;
    vector<tuple<int, int, int, int>> Kulumbseg1_4;
    vector<tuple<int, int, int, int>> Kulumbseg1_8;
    vector<tuple<int, int, int, int>> Kulumbseg1_16;
    for (size_t i = 0; i < Kulumbseg1.size(); i++)
    {
        for (size_t j = 0; j < Kulumbseg1.size(); j++)
        {
            // 1. Kulombseg közötti kivonas 2-bol
            if (abs(Kulumbseg1[i].first - Kulumbseg1[j].first) == 2 && abs(Kulumbseg1[i].second - Kulumbseg1[j].second) == 2)
            {
                if (Kulumbseg1[i].first < Kulumbseg1[j].first)
                {
                    Kulumbseg1_2.push_back(make_tuple(Kulumbseg1[i].first, Kulumbseg1[i].second, Kulumbseg1[j].first, Kulumbseg1[j].second));
                }
                
            }
            // 1. Kulombseg közötti kivonas 4-bol
            else if (abs(Kulumbseg1[i].first - Kulumbseg1[j].first) == 4 && abs(Kulumbseg1[i].second - Kulumbseg1[j].second) == 4)
            {
                if (Kulumbseg1[i].first < Kulumbseg1[j].first)
                {
                    Kulumbseg1_4.push_back(make_tuple(Kulumbseg1[i].first, Kulumbseg1[i].second, Kulumbseg1[j].first, Kulumbseg1[j].second));
                }
                
            }
            // 1. Kulombseg közötti kivonas 8-bol
            else if (abs(Kulumbseg1[i].first - Kulumbseg1[j].first) == 8 && abs(Kulumbseg1[i].second - Kulumbseg1[j].second) == 8)
            {
                if (Kulumbseg1[i].first < Kulumbseg1[j].first)
                {
                    Kulumbseg1_8.push_back(make_tuple(Kulumbseg1[i].first, Kulumbseg1[i].second, Kulumbseg1[j].first, Kulumbseg1[j].second));
                }

            }
            // 1. Kulombseg közötti kivonas 16-bol
            else if (abs(Kulumbseg1[i].first - Kulumbseg1[j].first) == 16 && abs(Kulumbseg1[i].second - Kulumbseg1[j].second) == 16)
            {
                if (Kulumbseg1[i].first < Kulumbseg1[j].first)
                {
                    Kulumbseg1_16.push_back(make_tuple(Kulumbseg1[i].first, Kulumbseg1[i].second, Kulumbseg1[j].first, Kulumbseg1[j].second));
                }
            }
        }
    }
    
    if (Kulumbseg1_2.size() > 0)
    {
        cout << endl;
        cout << "Kulombseg (1,2): " << endl;
        for (size_t i = 0; i < Kulumbseg1_2.size(); i++)
        {
            cout << "(" << get<0>(Kulumbseg1_2[i]) << ", " << get<1>(Kulumbseg1_2[i]) << ", " << get<2>(Kulumbseg1_2[i]) << ", " << get<3>(Kulumbseg1_2[i]) << ")" << endl;
        }
    }
    if (Kulumbseg1_4.size() > 0)
    {
        cout << endl;
        cout << "Kulombseg (1,4): " << endl;
        for (size_t i = 0; i < Kulumbseg1_4.size(); i++)
        {
            cout << "(" << get<0>(Kulumbseg1_4[i]) << ", " << get<1>(Kulumbseg1_4[i]) << ", " << get<2>(Kulumbseg1_4[i]) << ", " << get<3>(Kulumbseg1_4[i]) << ")" << endl;
        }
    }
    if (Kulumbseg1_8.size() > 0)
    {
        cout << endl;
        cout << "Kulombseg (1,8): " << endl;
        for (size_t i = 0; i < Kulumbseg1_8.size(); i++)
        {
            cout << "(" << get<0>(Kulumbseg1_8[i]) << ", " << get<1>(Kulumbseg1_8[i]) << ", " << get<2>(Kulumbseg1_8[i]) << ", " << get<3>(Kulumbseg1_8[i]) << ")" << endl;
        }
    }
    //2.Kulonbseg 
    vector<tuple<int, int, int, int>> Kulumbseg2_4;
    vector<tuple<int, int, int, int>> Kulumbseg2_8;
    for (size_t i = 0; i < Kulumbseg2.size(); i++)
    {
        for (size_t j = 0; j < Kulumbseg2.size(); j++)
        {

            if (abs(Kulumbseg2[i].first - Kulumbseg2[j].first) == 4 && abs(Kulumbseg2[i].second - Kulumbseg2[j].second) == 4)
            {
               if (Kulumbseg2[i].first < Kulumbseg2[j].first)
               {
                Kulumbseg2_4.push_back(make_tuple(Kulumbseg2[i].first, Kulumbseg2[i].second, Kulumbseg2[j].first, Kulumbseg2[j].second));
                }
            }
    // 1. Kulombseg közötti kivonas 8-bol
            else if (abs(Kulumbseg2[i].first - Kulumbseg2[j].first) == 8 && abs(Kulumbseg2[i].second - Kulumbseg2[j].second) == 8)
            {
                if (Kulumbseg2[i].first < Kulumbseg2[j].first)
                {
                    Kulumbseg2_8.push_back(make_tuple(Kulumbseg2[i].first, Kulumbseg2[i].second, Kulumbseg2[j].first, Kulumbseg2[j].second));
                }
            }
        }
    }

    if (Kulumbseg2_4.size() > 0)
    {
        cout << endl;
        cout << "Kulombseg (2,4): " << endl;
        for (size_t i = 0; i < Kulumbseg2_4.size(); i++)
        {
            cout << "(" << get<0>(Kulumbseg2_4[i]) << ", " << get<1>(Kulumbseg2_4[i]) << ", " << get<2>(Kulumbseg2_4[i]) << ", " << get<3>(Kulumbseg2_4[i]) << ")" << endl;
        }
    }
    if (Kulumbseg2_8.size() > 0)
    {
        cout << endl;
        cout << "Kulombseg (2,8): " << endl;
        for (size_t i = 0; i < Kulumbseg2_8.size(); i++)
        {
            cout << "(" << get<0>(Kulumbseg2_8[i]) << ", " << get<1>(Kulumbseg2_8[i]) << ", " << get<2>(Kulumbseg2_8[i]) << ", " << get<3>(Kulumbseg2_8[i]) << ")" << endl;
        }
    }
    //4.Kulombseg
    vector<tuple<int, int, int, int>> Kulumbseg4_8;
    for (size_t i = 0; i < Kulumbseg4.size(); i++)
    {
        for (size_t j = 0; j < Kulumbseg4.size(); j++)
        {

            if (abs(Kulumbseg4[i].first - Kulumbseg4[j].first) == 4 && abs(Kulumbseg4[i].second - Kulumbseg4[j].second) == 4)
            {
                if (Kulumbseg4[i].first < Kulumbseg4[j].first)
                {
                    Kulumbseg4_8.push_back(make_tuple(Kulumbseg4[i].first, Kulumbseg4[i].second, Kulumbseg4[j].first, Kulumbseg4[j].second));
                }
            }
        }
    }

    if (Kulumbseg4_8.size() > 0)
    {
        cout << endl;
        cout << "Kulonbseg (4,8): " << endl;
        for (size_t i = 0; i < Kulumbseg4_8.size(); i++)
        {
            cout << "(" << get<0>(Kulumbseg4_8[i]) << ", " << get<1>(Kulumbseg4_8[i]) << ", " << get<2>(Kulumbseg4_8[i]) << ", " << get<3>(Kulumbseg4_8[i]) << ")" << endl;
        }
    }
    /*
    for (size_t i = 0; i < 15; i++) {
        int value = Karnouh_indexek[i];
        cout << "Karough index erteke: " << value << endl;
        cout << "Kulumbsegek: " << get<0>(Kulumbseg1_2[i]);
        
        bool found = Megegyezik_e_a_vektor_ertekei(value, Kulumbseg1_2[i]) ||
            Megegyezik_e_a_vektor_ertekei(value, Kulumbseg1_4[i]) ||
            Megegyezik_e_a_vektor_ertekei(value, Kulumbseg1_8[i]) ||
            Megegyezik_e_a_vektor_ertekei(value, Kulumbseg2_4[i]) ||
            Megegyezik_e_a_vektor_ertekei(value, Kulumbseg2_8[i]);

        if (!found) {
            cout << "Value " << value << " at index " << i << " in Karnouh_indexek is not present in any corresponding tuple." << endl;
        }
        
    }
    */
}