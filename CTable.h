#ifndef CTABLE_H
#define CTABLE_H
#include <string>
#include <vector>
using namespace std;
class CTable
{
public:
    static const string defaultNAME;
    static const int defaultLENGTH;
    static const int defaultVALUE;
    int ITableLen;
    CTable();
    CTable(string sName, int tabLength);
    CTable(CTable &pcOther);
    CTable(CTable* pcOther[], int s);
    virtual ~CTable();
    string getName();
    void setName(string sName);
    void setTabLength(int tabLength);
    int getTabLength();
    bool setValue(int index,int value);
    bool getValue(int index);
    int getValue2(int index);
    string getInfo();

    static vector<CTable*> cTableVektor;
protected:

private:
    string sName;
    int tabLength;
    int *piTable;
};

#endif // CTABLE_H