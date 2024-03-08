#include "database.h"
#include "Parser.h"

std::pair<double, double>& database::operator[](int index) {
    return data[index];
}


void database::print_data() {
for (int i = 0; i < Points; i++) {
	std::cout << "(" << std::data[i].first << ", " << std::data[i].second << ")" << std::endl;
}
}

void database::load_data(const std::string& filename) {
    Parser parser;
    data = parser.read_file(filename, Points);
}

std::pair<double, double>* database::get_base() {
    return &data;
}

int database::get_points() {
    return Points;
}
