//
// Created by shkla on 2022-06-13.
//

#ifndef ACCCPP_CORE_H
#define ACCCPP_CORE_H

#include <istream>
#include <vector>

class Core {
public:
    Core();
    Core(std::istream &);
    std::string name() const;
    std::istream &read(std::istream &);
    double grade() const;
protected:
    std::istream &read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
private:
    std::string n;
};

#endif //ACCCPP_CORE_H
