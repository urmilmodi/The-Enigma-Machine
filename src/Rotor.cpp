#include "../include/Rotor.hpp"

Rotor::Rotor(Rotors _type, int _offset) {
    
    this->setRotor(_type);
    this->setOffset(_offset);

    rotorsData = {{ 
                    {E, S, O, V, P, Z, J, A, Y, Q, U, I, R, H, X, L, N, F, T, G, K, D, C, M, W, B}, // Rotor I
                    {V, Z, B, R, G, I, T, Y, U, P, S, D, N, H, L, X, A, W, M, J, Q, O, F, E, C, K}, // Rotor II
                    {J, P, G, V, O, U, M, F, Y, Q, B, E, N, H, Z, R, D, K, A, S, X, L, I, C, T, W}, // Rotor III
                    {N, Z, J, H, G, R, C, X, M, Y, S, W, B, O, U, F, A, I, V, L, P, E, K, Q, D, T}, // Rotor IV
                    {F, K, Q, H, T, L, X, O, C, B, J, S, P, D, Z, R, A, M, E, W, N, I, U, Y, G, V}  // Rotor V
    }};
}

void Rotor::setRotor(Rotors _type) {

    rotor = _type;
}

Rotors Rotor::getRotor() {

    return rotor;
}

bool Rotor::setOffset(int _offset) {

    if (_offset > 0 && _offset < 27) {
        offset = _offset;
        return true;
    }
    return false;
}

int Rotor::getOffset() {
    return offset;
}

void Rotor::offsetUpdate() {
    
    offset++;
    if (offset == 27) {offset = 1;}
}

Letter Rotor::run(Letter _input) {

    return rotorsData[rotor][shiftedIndex(_input)];
}

int Rotor::shiftedIndex(Letter _input) {
    
    // Ensures the indices loop back around
    if (_input + offset - 1 > 26) {return _input + offset - 27;}
    return _input + offset - 1;
}