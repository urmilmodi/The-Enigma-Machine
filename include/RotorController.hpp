#ifndef ROTORCONTROLLER_H
#define ROTORCONTROLLER_H

#include "Rotor.hpp"
#include "Reflector.hpp"
#include "helper/enums.hpp"

class RotorController {

    private:
        Rotor left, middle, right;
        Reflector reflector;

    public:

        RotorController(Reflectors _Reflector, Rotors _Left, Rotors _Middle, Rotors _Right);

        virtual ~RotorController() = default;

        RotorController(const RotorController & src) = default;

        virtual Letter run(Letter _input);

        bool setTicks(int _leftTickno, int _middleTickno, int _rightTickno);

        void changeRotor(RotorsPosition _pos, Rotors _newRotor);
};
#endif