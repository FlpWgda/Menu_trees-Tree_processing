//
// Created by hp on 27.11.2018.
//

#include "CreateCopy.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void CreateCopy::runCommand() {
    int correctNumber3=-1;
    cout << "Podaj indeks obiektu do skopiowania: " << endl;
    if(!(cin >> correctNumber3)||CTable::cTableVektor.size()<=correctNumber3||CTable::cTableVektor[correctNumber3]==NULL){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nie ma takiego indeksu. Sprobuj ponownie:\n ";

    }
    CTable::cTableVektor.push_back(new CTable(*(CTable::cTableVektor[correctNumber3])));
}