#ifndef _NAIVE_H
#define _NAIVE_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

#include "../../include/Guesser.hpp"

class Naive : public Guesser
{
public:
    Naive() = default;

    ~Naive() = default;

    std::string guess(std::vector<Guess>& history) override;

    void make_hash_map(std::unordered_map<std::string, int>& map, std::string filepath);

    std::unordered_map<std::string, int> sort_map(std::unordered_map<std::string, int>& map);

    std::unordered_map<std::string, int> m_freq_hash_map;
    std::array<Correctness, 5> m_mask;
};


#endif
