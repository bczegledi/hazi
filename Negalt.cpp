#include "Negalt.h"
#include "Kapu.h"

void Negalt:: print(const Negalt &a) const
{
    cout<<"    ___"<<endl;
    cout<<"   |   |"<<endl;
    cout<<a.masodik<<"--| 1 |D--"<<operator- (a)<<endl;
    cout<<"   |___|"<<endl;
}
bool Negalt:: operator- (const Negalt &a)const
{
    if (a.masodik==false)
        return true;
    return false;
}
Negalt::Negalt(bool b):Kapu(0,b){}

