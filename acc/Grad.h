//
// Created by shkla on 2022-06-13.
//

#ifndef ACCCPP_GRAD_H
#define ACCCPP_GRAD_H

#include <istream>
#include "Core.h"

class Grad : public Core {
public:
    Grad();
    Grad(std::istream &);
    double grad() const;
    std::istream &read(std::istream &);
private:
    double thesis;
};

#endif //ACCCPP_GRAD_H
