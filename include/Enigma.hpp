#ifndef ENIGMA_H
#define ENIGMA_H

#include "PlugBoard.hpp"
#include "RotorController.hpp"

class Enigma : public RotorController, PlugBoard {
    
    public:

        Enigma();

        virtual Letter run(Letter _input);
};
#endif