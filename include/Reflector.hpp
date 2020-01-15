#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <array>
#include "helper/enums.hpp"

class Reflector {

    private:
        
        std::array<std::array<Letter, 26>,  5> reflectorData;
        
        Reflectors reflector;

    public:

        Reflector(Reflectors _type);

        Letter run(Letter _input);

        void changeReflector(Reflectors _type);
};
#endif