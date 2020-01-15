#include "../include/Reflector.hpp"

Reflector::Reflector(Reflectors _type) {
    
    this->changeReflector(_type);

    reflectorData = {{
                        {},
                        {},
                        {},
                        {}
    }};
}

Letter Reflector::run(Letter _input) {
    return reflectorData[reflector][_input];
}

void Reflector::changeReflector(Reflectors _type) {
    reflector = _type;
}