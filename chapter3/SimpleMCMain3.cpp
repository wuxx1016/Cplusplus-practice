// VirtualFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
* requires 
* PayOff2.cpp
* Random1.cpp
* SimpleMC2.cpp
*/

#include<SimpleMC2.h>
#include <iostream>
using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nEnter strike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffCall callPayOff(Strike);
    PayOffPut putPayoff(Strike);

    double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayoff, Expiry, Spot, Vol, r, NumberOfPaths);

    cout << "the prices are " << resultCall << " for the call and " << resultPut << " for the put\n";

    double call_parity = resultCall + Strike * exp(-r * Expiry);
    double put_parity = resultPut + Spot;

    cout << "\ntest Put-call Parity:\n";
    cout << "Call + K*B(r,t) == " << call_parity << "\n" << "Put + S(t) == " << put_parity << "\n";

    double temp;
    cin >> temp;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
