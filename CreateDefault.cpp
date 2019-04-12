//
// Created by hp on 26.11.2018.
//

#include "CreateDefault.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void CreateDefault::runCommand() {
   CTable::cTableVektor.push_back(new CTable());
   /* if(numberOfObjects<=ileMaksObiektow){
        tabela[numberOfObjects] = new CTable();
        numberOfObjects++;
        main::cTableVektor
    }
    else{
        cout << "Przekroczono maksymalna liczbe obiektow" << endl;
    }*/

}

