#ifndef PLUG_H
#define PLUG_H

#include <iostream>
#include "helper/enums.hpp"

class Plug {

    private:

        std::pair<Letter, Letter> data;
    
    public:

        Plug(Letter First, Letter Second);

        Letter getFirst();

        Letter getSecond();

        void setFirst(Letter First);

        void setSecond(Letter Second);

        bool operator==(const Plug & src);
};
#endif