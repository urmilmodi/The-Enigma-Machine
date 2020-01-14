#ifndef ROTOR_H
#define ROTOR_H

#include <array>
#include "helper/enums.hpp"

class Rotor {

    private:

        static std::array<std::array<Letter, 26>,  5> rotorsData;
        int tick = 1;
        Rotors rotorNo;

        int accessEncryptedLetter(Letter input);

    public:

        Rotor(Rotors type, int tickno);

        bool setTick(int tickno);

        int getTick();

        void tickUp();

        Letter run(Letter input);
};
#endif