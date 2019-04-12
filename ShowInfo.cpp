//
// Created by hp on 27.11.2018.
//

#include "ShowInfo.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void ShowInfo::runCommand() {
    int correctNumber3=-1;
    cout << "Podaj indeks obiektu do wyswietlenia informacji: " << endl;
    if(!(cin >> correctNumber3)||correctNumber3<0||correctNumber3>CTable::cTableVektor.size()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nie ma takiego indeksu. Sprobuj ponownie:\n ";

    }
    else if(CTable::cTableVektor[correctNumber3]==NULL){
        cout<<"Ten indeks jest pusty"<< endl;

    }
    else {cout << (*CTable::cTableVektor[correctNumber3]).getInfo() << endl;}
}