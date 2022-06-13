#ifndef _GUESS_H
#define _GUESS_H

#include <array>
#include <string>

#include "Correctness.hpp"

class Guess
{
public:
    Guess(std::string word, std::array<Correctness, 5> mask);

    std::string word;
    std::array<Correctness, 5> mask;
};

#endif
