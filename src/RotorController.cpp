#include "RotorController.hpp"

RotorController::RotorController(Rotors Reflector, Rotors Left, Rotors Middle, Rotors Right) : reflector(Reflector, 1), left(Left, 1), middle(Middle, 1), right(Right, 1) {}

Letter RotorController::run(Letter input) {
    
    // Inital Run through rotors
    Letter tempOutput = right.run(input);
    right.tickUp();

    tempOutput = middle.run(tempOutput);
    if (right.getTick() == 1) {middle.tickUp();} // If the previous rotator completes a rotation TickUp

    tempOutput = left.run(tempOutput);
    if (middle.getTick() == 1) {left.tickUp();} // If the previous rotator completes a rotation TickUp

    // Reflection back into rotors in reverse direction
    tempOutput = reflector.run(tempOutput);
    if (left.getTick() == 1) {reflector.tickUp();} // If the previous rotator completes a rotation TickUp

    // Final Run through rotors
    tempOutput = left.run(tempOutput);
    left.tickUp();

    tempOutput = middle.run(tempOutput);
    if (left.getTick() == 1) {middle.tickUp();} // If the previous rotator completes a rotation TickUp

    tempOutput = right.run(tempOutput);
    if (middle.getTick() == 1) {right.tickUp();} // If the previous rotator completes a rotation TickUp

    return tempOutput;
}

bool RotorController::setTicks(int reflectorTickno, int leftTickno, int middleTickno, int rightTickno) {

    // If any rotor fails, the controller fails and returns false
    // Upon success of all rotors, the controller returns true
    return reflector.setTick(reflectorTickno) && left.setTick(leftTickno) && middle.setTick(middleTickno) && right.setTick(rightTickno);
}