#pragma once
#ifndef PAYOFF_H
#define PAYOFF_H
class PayOff
{
public:
	enum OptionType {call,put,digitalcall};//the constructor 
	PayOff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const; // main mthod -given a value of a spot, return the value of the payoff
	//use function objects or functors here
	//define operator() as const, this method would not modify the object
private:
	double Strike;
	OptionType TheOptionsType;

};
#endif
