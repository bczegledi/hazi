#include "Es.h"
#include "Kapu.h"

void Es:: print(const Es &a)const
{
    cout<<"    ___"<<endl;
    cout<<a.elso<<"--|   |"<<endl;
    cout<<a.masodik<<"--| & |--"<<operator* (a)<<endl;
    cout<<"   |___|"<<endl;
}
bool Es:: operator* (const Es &a)const
{
    if (a.elso && a.masodik)
        return true;
    return false;
}
Es::Es(bool c, bool b):Kapu(c, b){};