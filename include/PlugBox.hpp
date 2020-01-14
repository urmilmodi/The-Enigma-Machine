#ifndef PLUGBOX_H
#define PLUGBOX_H

#include <vector>
#include "Plug.hpp"
#include "helper/enums.hpp"

class PlugBox {
    private:

        std::vector<Plug> plugs;

    public:
        PlugBox(std::vector<Plug> & plugData);

        bool disconnect(Plug remove);

        bool connect(Plug attach);
};
#endif