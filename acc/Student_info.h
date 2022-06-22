#ifndef ACCCPP_STUDENT_INFO_H
#define ACCCPP_STUDENT_INFO_H

#include <string>
#include <vector>

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);

    double grade() const;
    std::istream &read(std::istream &);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info &x, const Student_info &y) {
    return x.name() < y.name();
}

#endif //ACCCPP_STUDENT_INFO_H
