#include "../include/Rotor.hpp"

Rotor::Rotor(Rotors _type, int _tickno) {
    
    this->setRotor(_type);
    this->setTick(_tickno);

    rotorsData = {{ 
                    {E, S, O, V, P, Z, J, A, Y, Q, U, I, R, H, X, L, N, F, T, G, K, D, C, M, W, B}, // Rotor I
                    {V, Z, B, R, G, I, T, Y, U, P, S, D, N, H, L, X, A, W, M, J, Q, O, F, E, C, K}, // Rotor II
                    {J, P, G, V, O, U, M, F, Y, Q, B, E, N, H, Z, R, D, K, A, S, X, L, I, C, T, W}, // Rotor III
                    {N, Z, J, H, G, R, C, X, M, Y, S, W, B, O, U, F, A, I, V, L, P, E, K, Q, D, T}, // Rotor IV
                    {F, K, Q, H, T, L, X, O, C, B, J, S, P, D, Z, R, A, M, E, W, N, I, U, Y, G, V}  // Rotor V
    }};
}

Rotors Rotor::getRotor() {
    return rotor;
}

void Rotor::setRotor(Rotors _type) {
    rotor = _type;
}

bool Rotor::setTick(int _tickno) {

    if (_tickno > 0 && _tickno < 27) {
        tick = _tickno;
        return true;
    }
    return false;
}

int Rotor::getTick() {
    return tick;
}

void Rotor::tickUp() {
    tick++;
    if (tick == 27) {tick = 1;}
}

Letter Rotor::run(Letter _input) {

    return rotorsData[rotor][accessEncryptedLetter(_input)];
}

int Rotor::accessEncryptedLetter(Letter _input) {
    
    // Ensures the indices loop back around
    if (_input + tick - 1 > 26) {return _input + tick - 27;}
    return _input + tick - 1;
}