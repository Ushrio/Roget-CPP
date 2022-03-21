#ifndef _LIB_HPP_
#define _LIB_HPP_

#include <string>
#include <vector>
#include <array>

enum Correctness { Correct, Misplaced, Wrong };

class Guess
{
public:
    Guess(std::string word, std::array<Correctness, 5> mask);

    std::string word;
    std::array<Correctness, 5> mask;
};

class Guesser
{
public:
    std::string guess(std::vector<Guess>& history);
};

std::array<Correctness, 5> check(std::string answer, std::string guess);

size_t play(std::string answer, Guesser G);

#endif
