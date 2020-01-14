#ifndef ROTORCONTROLLER_H
#define ROTORCONTROLLER_H

#include "Rotor.hpp"
#include "helper/enums.hpp"

class RotorController {

    private:
        Rotor left, middle, right;

    public:

        RotorController(Rotors Left, Rotors Middle, Rotors Right);

        Letter run(Letter input);

        bool setTicks(int leftTickno, int middleTickno, int rightTickno);
};

#endif