#include "../include/Plug.hpp"

Plug::Plug(Letter __First, Letter _Second) {

    this->setFirst(__First);
    this->setSecond(_Second);
}

Letter Plug::getFirst() const {
    return data.first;
}

Letter Plug::getSecond() const {
    return data.second;
}

bool Plug::setFirst(const Letter _First) {
    if (data.second != _First) {
        data.first = _First;
        return true;
    }
    return false;
}

bool Plug::setSecond(const Letter _Second) {
    if (data.first != _Second) {
        data.second = _Second;
        return true;
    }
    return false;
}

bool Plug::operator==(const Plug & _src) const {

    return _src.data.first == data.first && _src.data.second == data.second;
}