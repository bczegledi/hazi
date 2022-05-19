#ifndef HAZI_CPP_ES_H
#define HAZI_CPP_ES_H
#include "Kapu.h"


class Es : public Kapu{
public:
    void print(const Es &a)const;
    bool operator* (const Es &a)const;
    Es(bool elso, bool masodik);
};

#endif //HAZI_CPP_ES_H