#ifndef ROTOR_H
#define ROTOR_H

#include <vector>
#include "helper/enums.hpp"

class Rotor {

    private:

        static std::vector<std::vector<Letter, Letter>> rotorsData;
        int tick = 1;
        Rotors no;

        int accessEncryptedLetter();

    public:

        Rotor(Rotors type);

        bool setTick(int tickno);

        bool tick();

        Letter getLetter(Letter input);
};

#endif