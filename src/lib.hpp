#ifndef _LIB_HPP_
#define _LIB_HPP_

#include <unordered_map>
#include <string>

#include "include/Guesser.hpp"
#include "include/Correctness.hpp"

std::array<Correctness, 5> check(std::string answer, std::string guess);

size_t play(std::string answer, Guesser* G);

void make_hash_map_from_dictionary(std::unordered_map<std::string, int>& map, std::string filepath);

void sort_map_by_frequency(std::unordered_map<std::string, int>& map);

#endif
