/*
requires 
	PayOff1.cpp
	Random1.cpp
	SimpleMC.cpp
*/
#include<SimpleMC.h>
#include<iostream>
using namespace std;
int main() 
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\n Enter expiry\n";
	cin >> Expiry;

	cout << "\n Enter strike\n";
	cin >> Strike;

	cout << "\n Enter spot\n";
	cin >> Spot;

	cout << "\n Enter vol\n";
	cin >> Vol;

	cout << "\n Enter r\n";
	cin >> r;

	cout << "\n Enter number of paths\n";
	cin >> NumberOfPaths;

	PayOff callPayOff(Strike, PayOff::call);//Payoff Object 
	PayOff putPayOff(Strike, PayOff::put);
	PayOff digitalcallPayoff(Strike, PayOff::digitalcall);

	double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultDigitalCall = SimpleMonteCarlo2(digitalcallPayoff, Expiry, Spot, Vol, r, NumberOfPaths);

	cout << "the price are " << resultCall << " for the call and " << resultPut << " for the put, and " <<resultDigitalCall<< " for the digital call\n";


	double call_parity = resultCall + Strike * exp(-r * Expiry);
	double put_parity = resultPut + Spot;

	cout << "\ntest Put-call Parity:\n";
	cout << "Call + K*B(r,t) == " << call_parity << "\n" << "Put + S(t) == " << put_parity << "\n";

	double temp;
	cin >> temp;
	return 0;


}