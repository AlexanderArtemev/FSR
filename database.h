#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>

class Base {
public:
	virtual void load_data(const std::string& filename) = 0;
	virtual void print_data() = 0;
	virtual std::pair <double, double>* get_base() = 0;
	virtual int get_points() = 0;
	std::pair<double, double>& operator[](int index);
};

class database: public Base {
public:
    int Points = 0;
    std::pair <double, double> data;
    void print_data();
    void load_data(const std::string& filename);
    std::pair <double, double>* get_base();
    int get_points();
};

#endif
