#include "../include/RotorController.hpp"

RotorController::RotorController(Reflectors _Reflector, Rotors _Left, Rotors _Middle, Rotors _Right) : reflector(_Reflector), left(_Left, 1), middle(_Middle, 1), right(_Right, 1) {}

Letter RotorController::run(Letter _input) {
    
    // Inital Run through rotors
    Letter tempOutput = right.run(_input);
    right.tickUp();

    tempOutput = middle.run(tempOutput);
    if (right.getTick() == 1) {middle.tickUp();} // If the previous rotator completes a rotation TickUp

    tempOutput = left.run(tempOutput);
    if (middle.getTick() == 1) {left.tickUp();} // If the previous rotator completes a rotation TickUp

    // Reflection back into rotors in reverse direction
    tempOutput = reflector.run(tempOutput);

    // Final Run through rotors
    tempOutput = left.run(tempOutput);
    left.tickUp();

    tempOutput = middle.run(tempOutput);
    if (left.getTick() == 1) {middle.tickUp();} // If the previous rotator completes a rotation TickUp

    tempOutput = right.run(tempOutput);
    if (middle.getTick() == 1) {right.tickUp();} // If the previous rotator completes a rotation TickUp

    return tempOutput;
}

bool RotorController::setTicks(int _leftTickno, int _middleTickno, int _rightTickno) {

    // If any rotor fails, the controller fails and returns false
    // Upon success of all rotors, the controller returns truex
    return left.setTick(_leftTickno) && middle.setTick(_middleTickno) && right.setTick(_rightTickno);
}

void RotorController::changeRotor(RotorsPosition _pos, Rotors _newRotor) {

    switch(_pos) {
        LEFT: left.setRotor(_newRotor);
        break;

        MIDDLE: middle.setRotor(_newRotor);
        break;

        RIGHT: right.setRotor(_newRotor);
        break;
    }
}