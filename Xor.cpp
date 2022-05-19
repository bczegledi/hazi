#include "Xor.h"
#include "Kapu.h"

void Xor:: print(const Xor &a) const
{
    cout<<"    ___"<<endl;
    cout<<a.elso<<"--|   |"<<endl;
    cout<<a.masodik<<"--| =1|--"<<operator^ (a)<<endl;
    cout<<"   |___|"<<endl;
}
bool Xor:: operator^ (const Xor &a)const
{
    if (a.elso==false && a.masodik==true)
        return true;
    if (a.elso==true && a.masodik==false)
        return true;
    return false;
}

Xor::Xor(bool c, bool b):Kapu(c, b){}

