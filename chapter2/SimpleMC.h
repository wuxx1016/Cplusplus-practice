#pragma once
#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include <PayOff1.h>

double SimpleMonteCarlo2(const PayOff& thePayoff,
	double Expiry, double Spot, double Vol, double r, unsigned long NumverOfPaths);

#endif
