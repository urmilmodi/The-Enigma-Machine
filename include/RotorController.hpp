#ifndef ROTORCONTROLLER_H
#define ROTORCONTROLLER_H

#include <vector>
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "helper/enums.hpp"

class RotorController {

    private:
        
        Rotor left, middle, right;
        Reflector reflector;

    public:

        RotorController(Reflectors _Reflector, Rotors _Left, Rotors _Middle, Rotors _Right);

        void setRotor(RotorPosition _pos, Rotors _newRotor);

        std::vector<Rotor> getRotors();

        void setReflector(Reflectors _newReflector);

        Reflector getReflector();
        
        bool setOffset(RotorPosition _pos, int _offset);

        std::vector<int> getOffsets();

        virtual Letter run(Letter _input);
};
#endif