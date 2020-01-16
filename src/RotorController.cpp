#include "../include/RotorController.hpp"

RotorController::RotorController(Reflectors _Reflector, Rotors _Left, Rotors _Middle, Rotors _Right) : reflector(_Reflector), left(_Left, 1), middle(_Middle, 1), right(_Right, 1) {}

void RotorController::setRotor(RotorsPosition _pos, Rotors _newRotor) {

    if (_pos == LEFT) {left.setRotor(_newRotor);}
    if (_pos == MIDDLE) {middle.setRotor(_newRotor);}
    if (_pos == RIGHT) {right.setRotor(_newRotor);}
}

std::vector<Rotor> RotorController::getRotors() {

    return {left, middle, right};
}

void RotorController::setReflector(Reflectors _newReflector) {

    reflector.setReflector(_newReflector);
}

Reflector RotorController::getReflector() {
    
    return reflector;
}

bool RotorController::setOffset(RotorsPosition _pos, int _offset) {

    // Store success or failure of setOffset
    bool success = false;

    if (_pos == LEFT) {success = left.setOffset(_offset);}
    if (_pos == MIDDLE) {success = middle.setOffset(_offset);}
    if (_pos == RIGHT) {success = right.setOffset(_offset);}
    
    // return success or failure
    return success;
}

std::vector<int> RotorController::getOffsets() {

    return {left.getOffset(), middle.getOffset(), right.getOffset()};
}

Letter RotorController::run(Letter _input) {
    
    // Inital Run through rotors
    Letter tempOutput = right.run(_input);
    right.offsetUpdate();

    tempOutput = middle.run(tempOutput);
    if (right.getOffset() == 1) {middle.offsetUpdate();} // If the previous rotator completes a rotation offsetUpdate

    tempOutput = left.run(tempOutput);
    if (middle.getOffset() == 1) {left.offsetUpdate();} // If the previous rotator completes a rotation offsetUpdate

    // Reflection back into rotors in reverse direction
    tempOutput = reflector.run(tempOutput);

    // Final Run through rotors
    tempOutput = left.run(tempOutput);
    left.offsetUpdate();

    tempOutput = middle.run(tempOutput);
    if (left.getOffset() == 1) {middle.offsetUpdate();} // If the previous rotator completes a rotation offsetUpdate

    tempOutput = right.run(tempOutput);
    if (middle.getOffset() == 1) {right.offsetUpdate();} // If the previous rotator completes a rotation offsetUpdate

    return tempOutput;
}