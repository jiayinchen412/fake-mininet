#ifndef __SWITCH__
#define __SWITCH__

#include "vertex.h"

class Switch: public Vertex{
public: 
    Switch();
    Switch(std::string name);
    ~Switch();
    void set_name(std::string name);
    std::string get_name();
};

#endif