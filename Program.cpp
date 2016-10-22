#include <windows.h>

#include <iostream>
using namespace std;

#include "House.h"
#include "EinsteinRiddleSolver.h"

void main()
{
    EinsteinRiddleSolver solver;
    cout << "Einstein Riddle:" << endl;

    // solver.Solve_BruteForce_01();  // runs too loooong

    long ticks = ::GetTickCount();
    solver.Solve_BruteForce_02();
    ticks = ::GetTickCount() - ticks;
    cout << "[" <<  ticks << " msecs]" << endl;

    ticks = ::GetTickCount();
    solver.Solve_BruteForce_03();
    ticks = ::GetTickCount() - ticks;
    cout << "[" <<  ticks << " msecs]" << endl;

	getchar();
}
