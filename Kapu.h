#ifndef HAZI_HAZI_H
#define HAZI_HAZI_H
#include <iostream>

using namespace std;

class Kapu
{
protected:
    bool elso;
    bool masodik;
protected:
    Kapu(bool a, bool b);
    void print(const Kapu &a);
};

#endif //HAZI_HAZI_H