#include "Parser.h"
#include <fstream>

std::pair<double, double>* Parser::read_file(const std::string& filename, int& Points) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        Points = 0;
        return nullptr;
    }
    file >> Points;
    std::pair<double, double>* data = new std::pair<double, double>[Points];
    for (int i = 0; i < Points; i++) {
        file >> data[i].first >> data[i].second;
    }
    file.close();
    return data;
}
