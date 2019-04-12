#include "CTable.h"
#include "iostream"
#include "string"

using namespace std;

const string CTable::defaultNAME = "domyslne";
const int CTable::defaultLENGTH = 7;
const int CTable::defaultVALUE = -1;
vector<CTable*> CTable::cTableVektor;
CTable::CTable(){
    sName = defaultNAME;
    tabLength = defaultLENGTH;
    piTable = new int[tabLength];
    fill_n(piTable,tabLength,defaultVALUE);
    cout << "bezp: " << sName << endl;
}
CTable::CTable(string sName2,int tabLength2){
    sName = sName2;
    tabLength = tabLength2;
    piTable = new int[tabLength];
    fill_n(piTable,tabLength,defaultVALUE);
    cout << "parametr: " << sName << endl;
}
CTable::CTable(CTable &pcOther){
    sName = pcOther.getName() + "_copy";
    tabLength = pcOther.tabLength;
    piTable = new int[tabLength];
    for(int i=0; i<tabLength;i++){
        piTable[i] = pcOther.piTable[i];
    };
    cout << "kopiuj: " << sName << endl;
}
CTable::CTable(CTable* pcOther[],int s){
    tabLength = 0;

    for(int i=0; i<s; i++){
        tabLength = tabLength + (*pcOther[i]).getTabLength();
    }
    piTable = new int[tabLength];
    int nextValue = 0;
    for(int i=0; i<s; i++){
        for(int j=0; j<(*pcOther[i]).getTabLength(); j++){
            piTable[nextValue] = (*pcOther[i]).getValue2(j);
            nextValue++;
        }
    }
    cout << getInfo() << endl;
}
CTable::~CTable()
{
    cout << "usunieto obiekt: " << sName << endl;
    delete piTable;
}
string CTable::getName(){
    return sName;
}
void CTable::setName(string sName){
    this->sName = sName;
}
int CTable::getTabLength(){
    return tabLength;
}
void CTable::setTabLength(int tabLength)
{
    int *piNewTable = new int[tabLength];
    fill_n(piNewTable, tabLength, defaultVALUE);
    for(int i=0; i<tabLength;i++){
        piNewTable[i] = piTable[i];
    };
    delete piTable;
    piTable = piNewTable;
    this->tabLength = tabLength;
}
bool CTable::getValue(int index)
{
    if (index >= tabLength || index < 0)
        return false;
    else
    {
        return true;
    }//else
}
int CTable::getValue2(int index)
{
    if(getValue(index)==true){
        return piTable[index];
    }
    else{return -1;}
}
bool CTable::setValue(int index, int value)
{
    if (index >= tabLength || index < 0)
        return false;
    else
    {
        piTable[index] = value;
        return true;
    }//else
}
string CTable::getInfo()
{
    string tabValues;

    for (int i = 0; i < tabLength; i++)
    {
        tabValues += to_string(piTable[i]);
        if(i!=tabLength-1){
            tabValues += ",";
        }
    }
    return sName + " len: " + to_string(tabLength) + " " + "values: " + tabValues;
}