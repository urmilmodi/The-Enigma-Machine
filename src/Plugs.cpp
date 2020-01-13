#include "../include/Plugs.hpp"

Plugs::Plugs(Letter First, Letter Second) {

    data.first = First;
    data.second = Second;
}

Letter Plugs::getFirst() {
    return data.first;
}

Letter Plugs::getSecond() {
    return data.second;
}