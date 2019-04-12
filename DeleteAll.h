//
// Created by hp on 27.11.2018.
//

#ifndef UNTITLED_DELETEALL_H
#define UNTITLED_DELETEALL_H
#include "CTable.h"
#include "iostream"
#include "CCommand.h"
using namespace std;

class DeleteAll:public CCommand {
    virtual void runCommand();
};


#endif //UNTITLED_DELETEALL_H
