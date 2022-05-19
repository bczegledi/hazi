#ifndef HAZI_CPP_NOR_H
#define HAZI_CPP_NOR_H
#include "Kapu.h"
#include "Negalt.h"
#include "Vagy.h"

class Nor : public Negalt, public Vagy{
public:
    void print(const Nor &a) const;
    bool operator| (const Nor &a)const;
    Nor(bool elso, bool masodik);
};


#endif //HAZI_CPP_NOR_H
