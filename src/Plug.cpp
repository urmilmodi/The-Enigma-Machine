#include "Plug.hpp"

Plug::Plug(Letter First, Letter Second) {

    this->setFirst(First);
    this->setSecond(Second);
}

Letter Plug::getFirst() {
    return data.first;
}

Letter Plug::getSecond() {
    return data.second;
}

void Plug::setFirst(Letter First) {
    data.first = First;
}

void Plug::setSecond(Letter Second) {
    data.second = Second;
}

bool Plug::operator==(const Plug & src) {

    return src.data.first == data.first && src.data.second == data.second;
}