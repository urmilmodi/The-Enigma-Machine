#ifndef PLUG_H
#define PLUG_H

#include <iostream>
#include "helper/enums.hpp"

class Plug {

    private:

        std::pair<Letter, Letter> data;
    
    public:

        Plug(Letter _First, Letter _Second);
        
        ~Plug() = default;
        
        Plug(const Plug & _src) = default;

        bool operator==(const Plug & _src) const;

        Plug & operator=(const Plug & _src) = default;

        Letter getFirst() const;

        Letter getSecond() const;

        bool setFirst(const Letter _First);

        bool setSecond(const Letter _Second);
};
#endif