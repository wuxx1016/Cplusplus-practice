//
//
//
//                          DoubleDigital.h
//
//                              

#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H

#include <PayOff2.h>

class PayOffDoubleDigital : public PayOff
{
public: 
    PayOffDoubleDigital(double LowerLeveL_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}
private:
    double LowerLevel;
    double UpperLevel;

};

#endif 
