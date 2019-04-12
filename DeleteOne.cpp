//
// Created by hp on 27.11.2018.
//

#include "DeleteOne.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void DeleteOne::runCommand() {
    int correctNumber4 = -1;
    cout << "Podaj indeks obiektu do usuniecia: " << endl;
    if(!(cin >> correctNumber4)||correctNumber4<0||correctNumber4>CTable::cTableVektor.size()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nie ma takiego indeksu. Sprobuj ponownie:\n ";

    }
    else if(CTable::cTableVektor[correctNumber4]==NULL){
        cout<<"Ten indeks jest pusty"<< endl;

    }
    else{delete CTable::cTableVektor[correctNumber4];
        CTable::cTableVektor[correctNumber4]= NULL;}
}