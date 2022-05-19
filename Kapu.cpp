#include <iostream>
#include "Kapu.h"

Kapu::Kapu(bool a, bool b):elso(a), masodik(b){}

void Kapu::print(const Kapu &a)
{
    cout<<"    ___"<<endl;
    cout<<a.elso<<"--|   |"<<endl;
    cout<<a.masodik<<"--|   |--"<<endl;
    cout<<"   |___|"<<endl;
}
