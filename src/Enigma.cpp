#include "../include/Enigma.hpp"

Enigma::Enigma() : RotorController(a, ROYAL, FLAGS, WAVE), PlugBoard() {}

Letter Enigma::run(Letter _input) {

    Letter tempOutput = PlugBoard::run(_input);

    tempOutput = RotorController::run(tempOutput);

    tempOutput = PlugBoard::run(tempOutput);
    
    return tempOutput;
}