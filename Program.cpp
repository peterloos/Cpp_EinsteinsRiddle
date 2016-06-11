#include <windows.h>

#include <iostream>
using namespace std;

#include "House.h"
#include "EinsteinRiddleSolver.h"

void main()
{
    long ticks = ::GetTickCount();

    EinsteinRiddleSolver solver;

    // solver.Solve_BruteForce_01();  // runs too loooong

    solver.Solve_BruteForce_02();
    ticks = ::GetTickCount() - ticks;
    cout << "[" <<  ticks << " msecs]" << endl;

    ticks = ::GetTickCount();
    solver.Solve_BruteForce_03();
    ticks = ::GetTickCount() - ticks;
    cout << "[" <<  ticks << " msecs]" << endl;

	getchar();
}