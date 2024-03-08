#ifndef PARSER_H
#define PARSER_H

#include <string>

class MParcer {
public:
    virtual std::pair<double, double>* read_file(const std::string& filename, int& numPoints) = 0;
};

class Parser : public MParcer {
public:
    std::pair<double, double>* read_file(const std::string& filename, int& Points);
};

#endif
