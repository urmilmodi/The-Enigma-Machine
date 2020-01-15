#include "../include/PlugBoard.hpp"

PlugBoard::PlugBoard(const std::array<Letter, 26> & _plugData) {
    
    plugData = _plugData;
}

Letter PlugBoard::run(Letter _input) {

    // Return associated input
    return plugData[_input];
}

bool PlugBoard::disconnect(Letter _A, Letter _B) {

    if (!(plugData[_A] == _B && plugData[_B] == _A)) {return false;}
    
    // Change associated letter to itself - Plug is disconnected
    // Must do for both, A and B as how the plugData is arranged
    plugData[_A] = _A;
    plugData[_B] = _B;
    
    // Decrement count
    totalPlugs--;
    return true;
}

bool PlugBoard::connect(Letter _A, Letter _B) {

    if (totalPlugs == 10) {return false;}

    // Change associated letter to itself - Plug is connected
    // Must do for both, A and B as how the plugData is arranged
    plugData[_A] = _B;
    plugData[_B] = _A;

    // Increment count
    totalPlugs++;
    return true;
}