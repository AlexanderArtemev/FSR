#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class MParcer {
public:
    virtual pair<double, double>* read_file(const string& filename, int& numPoints) = 0;
};

class Parser : public MParcer {
public:
    pair<double, double>* read_file(const string& filename, int& Points) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file" << endl;
            Points = 0;
            return nullptr;
        }
        file >> Points;
        pair<double, double>* data = new pair<double, double>[Points];
        for (int i = 0; i < Points; i++) {
            file >> data[i].first >> data[i].second;
        }
        file.close();
        return data;
    }
};

class Base {
public:
    virtual void load_data(const string& filename) = 0;
    virtual void print_data() = 0;
    virtual pair<double, double>* get_base() = 0;
    virtual int get_points() = 0;
};

class database : public Base {
public:
    int Points = 0;
    pair<double, double>* data;
    void print_data() {
        for (int i = 0; i < Points; i++) {
            cout << "(" << data[i].first << ", " << data[i].second << ")" << endl;
        }
    }
    void load_data(const string& filename) {
        Parser parser;
        data = parser.read_file(filename, Points);
    }
    pair<double, double>* get_base() {
        return data;
    }
    int get_points() {
        return Points;
    }
};

class Solver {
    private:
    pair<double, double>* arr;
    int Points;
    double ans(int* path) {
        double dist = 0;
        for (int i = 0; i < Points - 1; i++) {
            dist += distance(arr[path[i]], arr[path[i + 1]]);
        }
        dist += distance(arr[path[Points - 1]], arr[path[0]]);
        return dist;
    }

    double distance(const pair<double, double>& a, const pair<double, double>& b) {
        return hypot(a.first - b.first, a.second - b.second);//The Euclidean metric
    }
    public:
    explicit Solver(pair<double, double>* arr, int Points) : arr(arr), Points(Points) {}
    void solve_ans() {
        int* vertex = new int[Points];
        for (int i = 0; i < Points; i++) {
            vertex[i] = i;
        }
        double min_dist = ans(vertex);
        double dist = 0;
        int* min_path = new int[Points];
        copy(vertex, vertex + Points, min_path);
        int flag = 1;
        while (flag) {
            flag = 0;
            for (int k = 0; k < Points; k++) {
                for (int j = k + 1; j < Points; j++) {
                    swap(vertex[k], vertex[j]);
                    dist = ans(vertex);
                    if (dist < min_dist) {
                        min_dist = dist;
                        copy(vertex, vertex + Points, min_path);
                        flag = 1;
                    } else {
                        swap(vertex[k], vertex[j]);
                    }
                }
            }
        }
        cout << "path: ";
        for (int i = 0; i < Points; i++) {
            cout << min_path[i] << "   ";
        }
        cout << min_path[0] << endl;
        cout << "distance: " << min_dist << endl;
        delete[] vertex;
        delete[] min_path;
    }
};

int main() {
    database database;
    database.load_data("input.txt");
    //database.print_data();
    pair<double, double>* arr = database.get_base();
    int NPoints = database.get_points();
    if (arr == nullptr || NPoints == 0) {
        cout << "Error" << endl;
        return 1;
    }
    Solver solver(arr, NPoints);
    solver.solve_ans();
    delete[] arr;
    return 0;
}