#ifndef HAZI_CPP_VAGY_H
#define HAZI_CPP_VAGY_H
#include "Kapu.h"


class Vagy : public Kapu{
public:
    void print(const Vagy &a) const;
    bool operator+ (const Vagy &a)const;
    Vagy(bool elso, bool masodik);
};

#endif //HAZI_CPP_VAGY_H
