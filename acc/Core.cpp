//
// Created by shkla on 2022-06-13.
//
#include "Core.h"

using namespace std;

double grade(double, double, const vector<double> &);

std::string Core::name() const {
    return n;
}
std::istream &Core::read(std::istream &in) {
    read_common(in);
    read_hw(in, homework);
    return in;
}

double Core::grade() const {
    return ::grade(midterm, final, homework);
}
std::istream &Core::read_common(std::istream& in) {
    in >> n >> midterm >> final;
    return in;
}

double grade(double m, double f, const vector<double> &hw) {
    if (hw.empty()) {
        throw domain_error("student has done no homework");
    }

    return grade(m, f, median(hw));
}
