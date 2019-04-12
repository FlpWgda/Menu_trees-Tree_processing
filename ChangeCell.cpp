//
// Created by hp on 27.11.2018.
//

#include "ChangeCell.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void ChangeCell::runCommand() {
    int correctNumber3=-1;
    cout << "Podaj indeks obiektu: " << endl;
    if(!(cin >> correctNumber3)||correctNumber3<0||correctNumber3>CTable::cTableVektor.size()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nie ma takiego indeksu. Sprobuj ponownie:\n ";

    }
    else if(CTable::cTableVektor[correctNumber3]==NULL){
        cout<<"Ten indeks jest pusty"<< endl;

    }
    else {
        int correctNumber4 = -1;
        cout << "Podaj nowa wartosc komorki: " << endl;
        while (!(cin >> correctNumber4)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nieprawidlowa liczba. Sprobuj ponownie: ";
        }
        int correctNumber5 = -1;
        cout << "Podaj indeks tabeli do zmiany: " << endl;
        while (!(cin >> correctNumber5) || (*CTable::cTableVektor[correctNumber3]).getValue(correctNumber5) == false) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nie ma takiego indeksu. Sprobuj ponownie: ";
            break;
        }
        (*CTable::cTableVektor[correctNumber3]).setValue(correctNumber5, correctNumber4);
    }
}