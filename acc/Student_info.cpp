#include <bits/stdc++.h>
#include "Student_info.h"

using namespace std;

istream &read_hw(istream &, vector<double>);

double median(vector<double>);

double grade(double, double, double);

double grade(double, double, const vector<double> &);

Student_info::Student_info() : midterm(0), final(0) {}

Student_info::Student_info(std::istream &is) { read(is); }

istream &Student_info::read(istream &in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

istream &read_hw(istream &in, vector<double> &hw) {
    if (in) {
        hw.clear();

        double x;

        while (in >> x) {
            hw.push_back(x);
        }

        in.clear();
    }

    return in;
}

double median(vector<double> vec) {
    vector<double>::size_type size = vec.size();

    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(vec.begin(), vec.end());
    return size % 2 ? (vec[size / 2] + vec[size / 2 + 1]) / 2 : vec[size / 2];
}

double grade(double m, double f, double hw) {
    return 0.2 * m + 0.4 * f + 0.4 * hw;
}

double grade(double m, double f, const vector<double> &hw) {
    if (hw.empty()) {
        throw domain_error("student has done no homework");
    }

    return grade(m, f, median(hw));
}
