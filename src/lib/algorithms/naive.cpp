#include <algorithm>
#include <cmath>

#include "naive.hpp"
#include "../../lib.hpp"

std::string Naive::guess(std::vector<Guess>& history)
{
    // First guess - choose a word in the top 10% of the the dictionary for frequency
    if (history.empty())
    {
        int choice = rand() % (m_freq_hash_map.size() / 10);
        return history.at(choice).word;
    }

    Guess g = history.back();
    history.pop_back();
    for (int i = 0; i < g.mask.size(); i++)
    {
        if (g.mask.at(i) == Correctness::Correct)
        {

        }
        else if (g.mask.at(i) == Correctness::Misplaced)
        {

        }
        else if (g.mask.at(i) == Correctness::Wrong)
        {

        }
    }
}
