#include "Rotor.hpp"

Rotor::Rotor(Rotors type, int tickno) {
    rotorNo = type;
    this->setTick(tickno);

    rotorsData = {{ 
                    {E, S, O, Letter(V), P, Z, J, A, Y, Q, U, Letter(I), R, H, X, L, N, F, T, G, K, D, C, M, W, B}, // Rotor I
                    {Letter(V), Z, B, R, G, Letter(I), T, Y, U, P, S, D, N, H, L, X, A, W, M, J, Q, O, F, E, C, K}, // Rotor II
                    {J, P, G, Letter(V), O, U, M, F, Y, Q, B, E, N, H, Z, R, D, K, A, S, X, L, Letter(I), C, T, W}, // Rotor III
                    {N, Z, J, H, G, R, C, X, M, Y, S, W, B, O, U, F, A, Letter(I), Letter(V), L, P, E, K, Q, D, T}, // Rotor IV
                    {F, K, Q, H, T, L, X, O, C, B, J, S, P, D, Z, R, A, M, E, W, N, Letter(I), U, Y, G, Letter(V)}  // Rotor V
    }};
}

bool Rotor::setTick(int tickno) {

    if (tickno > 0 && tickno < 27) {
        tick = tickno;
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

Letter Rotor::run(Letter input) {

    Letter rv = rotorsData[rotorNo][accessEncryptedLetter(input)];
    return rv;
}

int Rotor::accessEncryptedLetter(Letter input) {
    
    // Ensures the indices loop back around
    if (input + tick - 1 > 26) {return input + tick - 27;}
    return input + tick - 1;
}