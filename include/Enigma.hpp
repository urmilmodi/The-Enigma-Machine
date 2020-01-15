#ifndef ENIGMA_H
#define ENIGMA_H

#include "PlugBoard.hpp"
#include "RotorController.hpp"

class Enigma : public RotorController, PlugBoard {

    private:
        

    public:
        Enigma();

        /* Inherit from plugboard and RotorController
        bool changeRotor(RotorsPosition pos, Rotors newRotor);

        bool changeRotorTick(RotorsPosition pos, int tickno);

        bool removePlug(Plug disconnect);

        bool addPlug(Plug connect);

        */
        virtual Letter run();
};
#endif