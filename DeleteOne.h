//
// Created by hp on 27.11.2018.
//

#ifndef UNTITLED_DELETEONE_H
#define UNTITLED_DELETEONE_H
#include "CTable.h"
#include "iostream"
#include "CCommand.h"
using namespace std;

class DeleteOne:public CCommand {
    virtual void runCommand();
};

#endif //UNTITLED_DELETEONE_H
