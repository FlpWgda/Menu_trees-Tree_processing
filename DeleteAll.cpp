//
// Created by hp on 27.11.2018.
//

#include "DeleteAll.h"
#include "CTable.h"
#include "iostream"
#include "vector"
using namespace std;

void DeleteAll::runCommand() {
    for(int i=0;i<CTable::cTableVektor.size();i++){
        delete CTable::cTableVektor[i];
        CTable::cTableVektor[i] = NULL;
    }
}