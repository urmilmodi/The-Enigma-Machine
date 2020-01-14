#ifndef PLUGBOX_H
#define PLUGBOX_H

#include <vector>
#include "Plugs.hpp"
#include "helper/enums.hpp"

class PlugBox {
    private:

        std::vector<Plug> data;

    public:
        PlugBox(std::vector<Plug> data);

        bool disconnect(Plug remove);

        bool connect(Plug connect);
};


#endif