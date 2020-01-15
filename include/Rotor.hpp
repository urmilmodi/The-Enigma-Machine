#ifndef ROTOR_H
#define ROTOR_H

#include <array>
#include "helper/enums.hpp"

class Rotor {

    private:

        std::array<std::array<Letter, 26>,  5> rotorsData;
        int tick = 1;
        Rotors rotor;

        int accessEncryptedLetter(Letter _input);

    public:

        Rotor(Rotors _type, int _tickno);

        void setRotor(Rotors _type);
        
        Rotors getRotor();

        bool setTick(int _tickno);

        int getTick();

        void tickUp();

        Letter run(Letter _input);
};
#endif