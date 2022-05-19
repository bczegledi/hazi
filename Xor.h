#ifndef HAZI_CPP_XOR_H
#define HAZI_CPP_XOR_H
#include "Kapu.h"

class Xor : public Kapu {
public:
    void print(const Xor &a) const;
    bool operator^ (const Xor &a)const;
    Xor(bool elso, bool masodik);
};

#endif //HAZI_CPP_XOR_H