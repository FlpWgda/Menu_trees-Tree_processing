//
// Created by hp on 27.11.2018.
//

#include "CreateCustom.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void CreateCustom::runCommand() {
    int correctNumber2=-1;
    cout << "Podaj nazwe obiektu: " << endl;
    string sName;
    cin >> sName;
    cout << "Podaj dlugosc tablicy: "<< endl;
    while(!(cin >> correctNumber2)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nieprawidlowa liczba. Sprobuj ponownie: ";
    }
    CTable::cTableVektor.push_back(new CTable(sName, correctNumber2));
}