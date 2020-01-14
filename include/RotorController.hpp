#ifndef ROTORCONTROLLER_H
#define ROTORCONTROLLER_H

#include "Rotor.hpp"
#include "helper/enums.hpp"

class RotorController {

    private:
        Rotor reflector, left, middle, right;

    public:

        RotorController(Rotors reflector, Rotors Left, Rotors Middle, Rotors Right);

        Letter run(Letter input);

        bool setTicks(int reflectorTickno, int leftTickno, int middleTickno, int rightTickno);
};
#endif