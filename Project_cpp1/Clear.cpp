#include <iostream>
#include "projetcpp.h"

void Projetcpp::Clear()
{
    std::cout << "\x1B[2J\x1B[H";
}