#ifndef _NAIVE_H
#define _NAIVE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#include "../../include/Guesser.hpp"

using freq_matrix = std::vector<std::pair<std::string, int> >;

class Naive : public Guesser
{
public:
    Naive() = default;

    ~Naive() = default;

    std::string guess(std::vector<Guess>& history) override;

    void fill_freq_matrix(freq_matrix& vec, std::string filepath);

    void sort_freq_matrix(freq_matrix& map);

    freq_matrix m_freq_matrix;
    std::array<Correctness, 5> m_mask;
};


#endif
