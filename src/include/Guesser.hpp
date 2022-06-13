#ifndef _GUESSER_H
#define _GUESSER_H

#include <string>
#include <vector>

#include "Guess.hpp"

class Guesser
{
public:
    virtual std::string guess(std::vector<Guess>& history) = 0;
};

#endif
