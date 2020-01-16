#ifndef ROTOR_H
#define ROTOR_H

#include <array>
#include "helper/enums.hpp"

class Rotor {

    private:

        static std::array<std::array<Letter, 26>,  5> rotorsData;

        int offset = 1;
        Rotors rotor;

        int shiftedIndex(Letter _input);

    public:

        Rotor(Rotors _type, int _offset);

        void setRotor(Rotors _type);
        
        Rotors getRotor();

        bool setOffset(int _offset);

        int getOffset();

        void offsetUpdate();

        Letter run(Letter _input);
};
#endif