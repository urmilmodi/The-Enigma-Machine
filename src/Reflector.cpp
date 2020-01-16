#include "../include/Reflector.hpp"

Reflector::Reflector(Reflectors _type) {
    
    this->setReflector(_type);

    reflectorData = {{
                        {E, J, M, Z, A, L, Y, X, V, B, W, F, C, R, Q, U, O, N, T, S, P, I, K, H, G, D}, // Reflector A
                        {Y, R, U, H, Q, S, L, D, P, X, N, G, O, K, M, I, E, B, F, Z, C, W, V, J, A, T}, // Reflector B
                        {F, V, P, J, I, A, O, Y, E, D, R, Z, X, W, G, C, T, K, U, Q, S, B, N, M, H, L}  // Reflector C
    }};
}

void Reflector::setReflector(Reflectors _newType) {
    
    reflector = _newType;
}

Reflectors Reflector::getReflector() {

    return reflector;
}

Letter Reflector::run(Letter _input) {

    return reflectorData[reflector][_input];
}