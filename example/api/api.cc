#include <iostream>
#include <unistd.h>
#include "network_manager.h"

int main(int argc, char** argv){
    // create NetworkManager first
    NetworkManager *nm;
    nm=new NetworkManager();

    // Method 1: using create_* API
    // create h1, h2
    Host *h1 = nm->create_host(std::string("h1"));
    Host *h2 = nm->create_host(std::string("h2"));
    // create s0
    Switch *s1 = nm->create_switch();
    // then create link (also add nodes into network manager)
    nm->linkup(s1, h1);
    nm->linkup(s1, h2); // because linkup will add each node pass through the parameters, so this method will cause a warning message, but won't effect the correctness
    // reset
    nm->clear();

    // Method 2: using add_* API
    nm->add_host(std::string("h1"));
    nm->add_host(std::string("h2"));
    nm->add_switch();
    nm->connect(std::string("s0"), std::string("h1"));
    nm->connect(std::string("s0"), std::string("h2"));
    // reset
    nm->clear();

    return 0;
}