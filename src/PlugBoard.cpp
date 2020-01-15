#include "../include/PlugBoard.hpp"
#include <algorithm>

PlugBoard::PlugBoard(const std::list<Plug> & _plugData) {
    
    plugs = _plugData;
    plugs.sort();
    plugs.unique();
}

Letter PlugBoard::run(Letter _input) {

    // Find element in list
    for (auto i = plugs.begin(); i != plugs.end(); ++i) {
        if (i->getFirst() == _input) {
            return i->getSecond();
        }
    }

    // Return the original element, if no input plug exists
    return _input;
}

bool PlugBoard::disconnect(Plug _remove) {
    
    // Find element in list
    std::list<Plug>::iterator toErase = std::find(plugs.begin(), plugs.end(), _remove);

    // Remove if found
    if (toErase != plugs.end()) {
        plugs.erase(toErase);
        return true;
    }
    return false;
}

bool PlugBoard::connect(Plug _attach) {
    
    // Find element in list
    std::list<Plug>::iterator toErase = std::find(plugs.begin(), plugs.end(), _attach);
    if (toErase != plugs.end()) {return false;}

    // If full no more connnections (elements) are possible, until disconnections occur (elements are removed)
    if (plugs.size() == 10) {
        return false;
    }

    // Adding new connections (element)
    plugs.push_back(_attach);
    return true;
}