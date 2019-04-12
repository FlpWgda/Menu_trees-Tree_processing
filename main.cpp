#include <iostream>
#include <algorithm>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "CTable.h"
#include "string"
#include "CreateDefault.h"
#include "CreateCustom.h"
#include "CreateCopy.h"
#include "DeleteOne.h"
#include "DeleteAll.h"
#include "ChangeName.h"
#include "ChangeCell.h"
#include "ShowInfo.h"
#include "stack"
CMenuCommand *readTreeCommand(string stringTree);
CMenuCommand* readTreeCommand2(string stringTree);
using namespace std;
int stringIndex=-1;
string helper="";
CMenu* readTree(string stringTree){
    if (stringTree.substr(0,1)=="("){
        helper = stringTree.substr(2);

        string subString2 = stringTree.substr(2);
        string name = subString2.substr(0,subString2.find("'"));
        cout<<name<<endl;
        string subString3 = subString2.substr(name.length()+3);
        string command = subString3.substr(0,subString3.find("'"));
        cout<<command<<endl;
        string subString4 = subString3.substr(command.length()+1);
        CMenu* cMenuRoot = new CMenu(name,command);
        helper = subString4;
        while(helper.substr(0,1)==","){
            helper = helper.substr(1);
            if(helper.substr(0,1)=="("){
                cMenuRoot->addMenu2(readTree (helper));
            }
            else if(helper.substr(0,1)=="["){
                cMenuRoot->addCommand2(readTreeCommand (helper));
            }
        }
        cout<<helper.substr(0,1)<<endl;

        if(helper.substr(0,1)==")"){
            helper = helper.substr(1);
        }
        else if(helper.substr(0,1)=="]"){
            helper = helper.substr(1);
        }
        else{
            cout<<"Blad w zapisie drzewa- brak '(' lub '[' "<<endl;
        }
        return cMenuRoot;
        /*return new CMenu(subString1.substr(0,subString1.find("'")),(subString1.substr(0,subString1.find("'"))).substr(3,((subString1.substr(0,subString1.find("'"))).find("'"))-3));*/
    }
    else{
        cout<<"2Blad w zapisie drzewa- brak '(' lub '[' "<<endl;
        return nullptr;
    }
}
CMenuCommand* readTreeCommand(string stringTree) {
    if (stringTree.substr(0,1)=="["){
        string subString2 = stringTree.substr(2);
        string name = subString2.substr(0,subString2.find("'"));
        cout<<name<<endl;
        string subString3 = subString2.substr(name.length()+3);
        string command = subString3.substr(0,subString3.find("'"));
        cout<<command<<endl;
        string subString4 = subString3.substr(command.length()+3);
        string helpText= subString4.substr(0,subString4.find("'"));
        cout<<helpText<<endl;
        string subString5 = subString4.substr(helpText.length()+1);
        CMenuCommand* cMenuCommand = new CMenuCommand(name,command,new CCommand,helpText);
        if(subString5.substr(0,1)=="]"){
            helper = subString5.substr(1);
            return cMenuCommand;
        }
        else{
            cout<<"Blad w zapisie drzewa- brak ']' "<<endl;
            cout<<subString5.substr(0,7)<<endl;
            return cMenuCommand;
        }
        /*return new CMenu(subString1.substr(0,subString1.find("'")),(subString1.substr(0,subString1.find("'"))).substr(3,((subString1.substr(0,subString1.find("'"))).find("'"))-3));*/
    }
    else{
        cout<<"Blad w zapisie drzewa- brak '(' "<<endl;
        return nullptr;
    }
}
CMenu* readTree2(string stringTree){
    if (stringTree.substr(0,1)=="{"){
        helper = stringTree.substr(2);

        string subString2 = stringTree.substr(2);
        string name = subString2.substr(0,subString2.find("'"));
        cout<<name<<endl;
        string subString3 = subString2.substr(name.length()+3);
        string command = subString3.substr(0,subString3.find("'"));
        cout<<command<<endl;
        string subString4 = subString3.substr(command.length()+1);
        CMenu* cMenuRoot = new CMenu(name,command);
        helper = subString4;
        while(helper.substr(0,1)=="="){
            helper = helper.substr(1);
            string checkSubstr = helper.substr(0,helper.find("}"));
            size_t n = count(checkSubstr.begin(), checkSubstr.end(), '=');
            if(n>2){
                cMenuRoot->addMenu2(readTree2 (helper));
            }
            else {
                cMenuRoot->addCommand2(readTreeCommand2 (helper));
            }
        }
        cout<<helper.substr(0,1)<<endl;

        if(helper.substr(0,1)=="}"){
            helper = helper.substr(1);
        }
        else{
            cout<<"Blad w zapisie drzewa- brak '{' "<<endl;
        }
        return cMenuRoot;
        /*return new CMenu(subString1.substr(0,subString1.find("'")),(subString1.substr(0,subString1.find("'"))).substr(3,((subString1.substr(0,subString1.find("'"))).find("'"))-3));*/
    }
    else{
        cout<<"2Blad w zapisie drzewa- brak '{' "<<endl;
        return nullptr;
    }
}
CMenuCommand* readTreeCommand2(string stringTree) {
    if (stringTree.substr(0,1)=="{"){
        string subString2 = stringTree.substr(2);
        string name = subString2.substr(0,subString2.find("'"));
        cout<<name<<endl;
        string subString3 = subString2.substr(name.length()+3);
        string command = subString3.substr(0,subString3.find("'"));
        cout<<command<<endl;
        string subString4 = subString3.substr(command.length()+3);
        string helpText= subString4.substr(0,subString4.find("'"));
        cout<<helpText<<endl;
        string subString5 = subString4.substr(helpText.length()+1);
        CMenuCommand* cMenuCommand = new CMenuCommand(name,command,new CCommand,helpText);
        if(subString5.substr(0,1)=="}"){
            helper = subString5.substr(1);
            return cMenuCommand;
        }
        else{
            cout<<"Blad w zapisie drzewa- brak '}' "<<endl;
            cout<<subString5.substr(0,7)<<endl;
            return cMenuCommand;
        }
        /*return new CMenu(subString1.substr(0,subString1.find("'")),(subString1.substr(0,subString1.find("'"))).substr(3,((subString1.substr(0,subString1.find("'"))).find("'"))-3));*/
    }
    else{
        cout<<"Blad w zapisie drzewa- brak '{' "<<endl;
        return nullptr;
    }
}
/*void readTree2(string tree){
    stack<string> stos;
    for(int i=0;i<tree.length();i++){

    }
    if (stos.top()== "("){

    }

}
string stringParser(string tree){
    int pos = tree.find("(");
    return tree;

}*/
int main() {

    CMenu *cmenu1 = new CMenu("Menu glowne","menu");
    CMenu *podmenu1_1 = cmenu1->addMenu("Utworz obiekt","menu1");
    CMenu *podmenu1_2 = cmenu1->addMenu("Skasuj obiekt","menu2");
    CMenu *podmenu1_3 = cmenu1->addMenu("Zmien dane obiektu","menu3");
    CMenuCommand *podmenu1_4 = cmenu1->addCommand("Informacje o danym obiekcie", "showInfo", (new ShowInfo), "helpText");

    CCommand *ccommand = new CCommand();
    podmenu1_1->addCommand("O wartosciach domyslnych", "default", (new CreateDefault),"helpText");
    podmenu1_1->addCommand("Podaj nazwe i dlugosc tabeli", "custom",(new CreateCustom),"helpText");
    podmenu1_1->addCommand("Skopiuj dane innego obiektu", "copy", (new CreateCopy),"helpText");
    podmenu1_2->addCommand("Skasuj wybrany obiekt", "deleteOne", (new DeleteOne),"helpText");
    podmenu1_2->addCommand("Skasuj wszystkie obiekty", "deleteAll", (new DeleteAll),"helpText");
    podmenu1_3->addCommand("Zmien nazwe obiektu", "changeName", (new ChangeName),"helpText");
    podmenu1_3->addCommand("Zmien wartosc komorki w tabeli", "changeCell", (new ChangeCell),"helpText");
    podmenu1_3->addCommand("Zmien wartosc komorki w tabeli", "showInfo", (new ChangeCell),"helpText");
    podmenu1_3->addCommand("def", "default", (new ChangeCell),"helpText");
    cout<<cmenu1->createNode()<<endl;
    cout<<" "<<endl;
    /*cmenu1->run();*/
    string tree1 = "('Menu glowne','menu',('Utworz obiekt','menu1',['O wartosciach domyslnych','default','helpText'],['Podaj nazwe i dlugosc\n"
                   " tabeli','custom','helpText'],['Skopiuj dane innego obiektu','copy','helpText']),('Skasuj obiekt','menu2',['Skasuj wybra\n"
                   "ny obiekt','deleteOne','helpText'],['Skasuj wszystkie obiekty','deleteAll','helpText']),('Zmien dane obiektu','menu3',['\n"
                   "Zmien nazwe obiektu','changeName','helpText'],['Zmien wartosc komorki w tabeli','changeCell','helpText'],['Zmien wartosc\n"
                   " komorki w tabeli','showInfo','helpText']),['Informacje o danym obiekcie','showInfo','helpText'])";
    string tree2 = "{'Menu glowne'='menu'={'Utworz obiekt'='menu1'={'O wart. domyslnych'='default'='helpText'}={'"
                   "Podaj nazwe i dlugosc tabeli'='custom'='helpText'}={'Skopiuj dane innego obiektu'='copy'='helpText'}}={'"
                   "Skasuj obiekt'='menu2'={'Skasuj wybrany obiekt'='deleteOne'='helpText'}={'Skasuj wszystkie obiekty'='"
                   "deleteAll'='helpText'}}={'Zmien dane obiektu'='menu3'={'Zmien nazwe obiektu'='changeName'='helpText'}={'"
                   "Zmien wartosc komorki w tabeli'='changeCell'='helpText'}={'Zmien wartosc komorki w tabeli'='showInfo'='"
                   "helpText'}={'def'='default'='helpText'}}={'Informacje o danym obiekcie'='showInfo'='helpText'}}";
    CMenu* cmenu2 = readTree2(tree2);
    cmenu2->run();
    cmenu1->run();

    return 0;
}