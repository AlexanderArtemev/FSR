#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Solver {
private:
    pair<double, double>* arr;
    int Points;
    double ans(int* path);
    double distance(const pair<double, double>& a, const pair<double, double>& b);
public:
    explicit Solver(pair<double, double>* arr, int Points);
    void solve_ans();
};

#endif
