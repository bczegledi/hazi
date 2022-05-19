#ifndef HAZI_CPP_NEGALT_H
#define HAZI_CPP_NEGALT_H
#include "Kapu.h"


class Negalt : public Kapu{
public:
    void print(const Negalt &a) const;
    bool operator- (const Negalt &a)const;
    Negalt(bool masodik);
};


#endif //HAZI_CPP_NEGALT_H
