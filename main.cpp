#include <iostream>
#include "database.h"
#include "Solver.h"

int main() {
    database database;
    database.load_data("input.txt");
    std:: pair<double, double>* arr = database.get_base();
    int NPoints = database.get_points();
    if (arr == nullptr || NPoints == 0) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    Solver solver(arr, NPoints);
    solver.solve_ans();
    delete[] arr;
    return 0;
}
