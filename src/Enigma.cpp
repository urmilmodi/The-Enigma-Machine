#include "../include/Enigma.hpp"

// Inherit from plugboard and rotor controller

Enigma::Enigma() : StageA(Ih, II, III, IV), StageB() {}
/*
bool Enigma::changeRotor(RotorsPosition pos, Rotors newRotor) {}

bool Enigma::changeRotorTick(RotorsPosition pos, int tickno) {}

bool Enigma::removePlug(Plug disconnect) {}

bool Enigma::addPlug(Plug connect) {}
*/