//
// Created by hp on 27.11.2018.
//

#ifndef UNTITLED_CHANGECELL_H
#define UNTITLED_CHANGECELL_H
#include "CTable.h"
#include "iostream"
#include "CCommand.h"
using namespace std;

class ChangeCell:public CCommand {
    virtual void runCommand();
};



#endif //UNTITLED_CHANGECELL_H
