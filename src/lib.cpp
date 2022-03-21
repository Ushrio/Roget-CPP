#include <string>
#include <vector>
#include <array>

#include "lib.hpp"
#include "lib/algorithms/naive.cpp"

Guess::Guess(std::string word, std::array<Correctness, 5> mask) : word{ word }, mask{ mask } {};

std::array<Correctness, 5> check(std::string answer, std::string guess)
{
    // TODO
}

size_t play(std::string answer, Guesser G)
{
    std::vector<Guess> history;
    for (size_t i = 1;;)
    {
        std::string guess = G.guess(history);

        if (guess == answer)
        {
            return i;
        }

        std::array<Correctness, 5> correctness = check(answer, guess);
        history.push_back(Guess(guess, correctness));
    }
}
