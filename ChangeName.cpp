//
// Created by hp on 27.11.2018.
//

#include "ChangeName.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void ChangeName::runCommand() {
    cout << "Podaj indeks obiektu: " << endl;
    int correctNumber3=-1;
    if(!(cin >> correctNumber3)||correctNumber3<0||correctNumber3>CTable::cTableVektor.size()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nie ma takiego indeksu. Sprobuj ponownie:\n";
    }
    else if(CTable::cTableVektor[correctNumber3]==NULL){
        cout<<"Ten indeks jest pusty"<< endl;

    }
    else{
        cout << "Podaj nowa nazwe obiektu" << endl;
        string sName;
        cin >> sName;
        (*CTable::cTableVektor[correctNumber3]).setName(sName);}
}