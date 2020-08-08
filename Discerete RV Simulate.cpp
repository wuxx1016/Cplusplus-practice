// Discerete RV Simulate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <random>
#include <vector>
double Simulate(const vector<double> & p, const vector<double>& v, double u);
default_random_engine generator;
uniform_real_distribution<double> distribution(0.0, 1.0);
int main()
{
	const vector<double> p = { 0.1, 0.2, 0.3, 0.4 };
	const vector<double> v = { 1,2,3,4 };
	for (int i = 0; i < 10; ++i) 
	{
		double u = distribution(generator);
		cout << Simulate(p, v, u)<<endl;
	}
	
}
double Simulate(const vector<double> &p, const vector<double>&v, double u)
{
	int i = 0;
	while (u > p[i])
	{
		u -= p[i];
		++i;
	}
	return v[i];

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
