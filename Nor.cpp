#include "Nor.h"
#include "Kapu.h"

void Nor:: print(const Nor &a) const
{
    cout<<"    ___"<<endl;
    cout<<a.Vagy::elso<<"--| > |"<<endl;
    cout<<a.Vagy::masodik<<"--| =1|D--"<<operator| (a)<<endl;
    cout<<"   |___|"<<endl;
}
bool Nor:: operator| (const Nor &a)const
{
    if (a.Vagy::elso==0 && a.Vagy::masodik==0)
        return true;
    return false;
}
Nor::Nor(bool c, bool b):Negalt(b), Vagy(c, b){}
