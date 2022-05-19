#include "Nand.h"
#include "Kapu.h"
#include "Es.h"
#include "Negalt.h"

void Nand:: print(const Nand &a) const
{
    cout<<"    ___"<<endl;
    cout<<a.Es::elso<<"--|   |"<<endl;
    cout<<a.Es::masodik<<"--| & |D--"<<operator& (a)<<endl;
    cout<<"   |___|"<<endl;
}
bool Nand:: operator& (const Nand &a)const
{
    if (a.Es::elso==1 && a.Es::masodik==1)
        return false;
    return true;
}
Nand::Nand(bool c, bool b):Negalt(b),Es(c, b){}
