#include "Vagy.h"
#include "Kapu.h"

void Vagy:: print(const Vagy &a) const
{
    cout<<"    ___"<<endl;
    cout<<a.elso<<"--| > |"<<endl;
    cout<<a.masodik<<"--| =1|--"<<operator+ (a)<<endl;
    cout<<"   |___|"<<endl;
}
bool Vagy:: operator+ (const Vagy &a)const
{
    if (a.elso==false && a.masodik==false)
        return false;
    return true;
}
Vagy::Vagy(bool c, bool b):Kapu(c, b){}
