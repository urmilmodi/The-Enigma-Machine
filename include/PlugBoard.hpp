#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <list>
#include "Plug.hpp"
#include "helper/enums.hpp"

class PlugBoard {
    private:

        std::list<Plug> plugs;

    public:
        PlugBoard() = default;

        PlugBoard(const std::list<Plug> & _plugData);

        virtual Letter run(Letter _input);

        bool disconnect(Plug _remove);

        bool connect(Plug _attach);
};
#endif