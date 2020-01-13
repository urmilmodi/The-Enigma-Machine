#ifndef PLUGS_H
#define PLUGS_H

#include <iostream>
#include "helper/enums.hpp"

class Plugs {
    private:

    std::pair <Letter, Letter> data;

    public:

        Plugs(Letter First, Letter Second);

        Letter getFirst();

        Letter getSecond();
};


#endif