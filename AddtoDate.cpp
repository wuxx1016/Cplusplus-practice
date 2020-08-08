// AddtoDate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
bool IsLeapDayNext(int y, int m, int d);
void AddOneToDate(int& y, int& m, int& d);
void AddToDate(int& y, int& m, int& d, int N);
int main()
{
    int y = 2020;
    int m = 2;
    int d = 29;
    int N = 40;
    AddToDate(y, m, d, N);
    cout << "year: "<<y<<" month: " <<m <<" day: "<<d<<endl;
}

bool IsLeapDayNext(int y, int m, int d) {
    if (m != 2)
        return false;
    if (d != 28)
        return false;
    if (y % 4 > 0)
        return false;
    if (y % 100 > 0)
        return true;
    if (y % 400 == 0)
        return true;
    return false;
}

void AddOneToDate(int& y, int& m, int& d) {
    static double length[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (d < length[m - 1]) { ++d; return; }
    if (IsLeapDayNext(y, m, d)) {
        ++d;
        return;
    }
    d = 1;
    ++m;
    y = y + (m / 12);
    m = m % 12;
}

void AddToDate(int& y, int& m, int& d, int N) {
    for (int i = 0; i < N; i++)
        AddOneToDate(y, m, d);
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
