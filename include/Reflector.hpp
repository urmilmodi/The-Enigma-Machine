#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <array>
#include "helper/enums.hpp"

class Reflector {

    private:
        
        static std::array<std::array<Letter, 26>,  3> reflectorData;
        
        Reflectors reflector;

    public:

        Reflector(Reflectors _type);

        void setReflector(Reflectors _newType);

        Reflectors getReflector();

        Letter run(Letter _input);
};
#endif