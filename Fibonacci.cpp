// Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int Fib3(int N);

int main()
{
    int N = 5;
    cout << Fib3(N)<<"\n";
}

int Fib3(int N) {
    vector<int> v(3);
    v[0] = 1;
    v[1] = 1;
    for (int j = 0; j <= N - 2; ++j) {
        v[(j + 2) % 3] = v[(j + 1) % 3] + v[(j) % 3];
    };
    return v[N % 3];

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
