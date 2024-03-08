#include "solver.hpp"

Solver::Solver(pair<double, double>* arr, int Points) : arr(arr), Points(Points) {}

double Solver::ans(int* path) {
    double dist = 0;
    for (int i = 0; i < Points - 1; i++) {
        dist += distance(arr[path[i]], arr[path[i + 1]]);
    }
    dist += distance(arr[path[Points - 1]], arr[path[0]]);
    return dist;
}

double Solver::distance(const pair<double, double>& a, const pair<double, double>& b) {
    return hypot(a.first - b.first, a.second - b.second);
}

void Solver::solve_ans() {
    // Реализация метода solve_ans()
}
