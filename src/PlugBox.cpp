#include "PlugBox.hpp"
#include <algorithm>

PlugBox::PlugBox(std::vector<Plug> & plugData) {
    
    // Reserving 10 elements for run-time efficiency, when connecting more elements
    plugs.reserve(10);
    plugs = plugData;
}

bool PlugBox::disconnect(Plug remove) {
    
    // Find element in vector
    std::vector<Plug>::iterator toErase = std::find(plugs.begin, plugs.end, remove);

    // Remove if found
    if (toErase != plugs.end) {
        plugs.erase(toErase);
        return true;
    }
    return false;
}

bool PlugBox::connect(Plug attach) {
    
    // If full no more connnections (elements) are possible, until disconnections occur (elements are removed)
    if (plugs.size() == 10) {
        return false;
    }

    // Adding new connections (element)
    plugs.push_back(attach);
    return true;
}