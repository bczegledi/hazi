#ifndef HAZI_CPP_NAND_H
#define HAZI_CPP_NAND_H
#include "Kapu.h"
#include "Negalt.h"
#include "Es.h"

class Nand: public Negalt, public Es{
public:
    void print(const Nand &a) const;
    bool operator& (const Nand &a)const;
    Nand(bool elso, bool masodik);
};

#endif //HAZI_CPP_NAND_H
