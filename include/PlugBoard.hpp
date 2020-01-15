#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <array>
#include "helper/enums.hpp"

class PlugBoard {
    private:

        std::array<Letter, 26> plugData; // Index - Letter A, element at Index - encrypted Letter A using plug
        int totalPlugs = 0; // Only 10 Plugs are available

    public:
        PlugBoard(const std::array<Letter, 26> & _plugData);

        virtual ~PlugBoard() = default;

        PlugBoard(const PlugBoard & src) = default;

        virtual Letter run(Letter _input);

        bool disconnect(Letter _A, Letter _B);

        bool connect(Letter _A, Letter _B);
};
#endif