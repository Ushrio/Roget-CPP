/**
 * Wordle player developed in C++. Heavily inspired by Jon
 * Gjengset's Wordle solver implemented in Rust. The dictionary
 * is created from Google Books' Ngram dataset.
 *
 * @author Greg Heiman
 * @since 2022-03-20
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iterator>

#include "lib.hpp"
#include "lib/algorithms/naive.cpp"
#include "lib/algorithms/naive.hpp"

#define NUM_OF_WORDS_TO_LOAD 32

std::vector<std::string> open_answers(std::string filepath, int words_to_load)
{
    std::ifstream file;
    file.open(filepath);

    if (!file.is_open())
    {
        std::cerr << "Could not open file located at " << filepath << " exiting." << std::endl;
        EXIT_FAILURE;
    }

    // Retrieve a random set of words from the answers text file
    unsigned int line_count = std::count(std::istreambuf_iterator<char>(file),
                                         std::istreambuf_iterator<char>(), '\n');
    std::srand(std::time(nullptr));
    std::vector<std::string> words;
    for (int i = 0; i < words_to_load; i++)
    {
        int rand = std::rand() % line_count;
        std::string word;
        int dump;

        // Return to the beginning of the file
        file.seekg(std::ios::beg);
        for (int j = 0; j < rand; j++)
        {
            file >> word >> dump;
        }
        words.push_back(word);
    }

    return words;
}

int main()
{

    std::vector<std::string> words;
    words = open_answers("answers.txt", NUM_OF_WORDS_TO_LOAD);

    Naive *G = new Naive();
    make_hash_map_from_dictionary(G->m_freq_hash_map, "dictionary.txt");
    sort_map_by_frequency(G->m_freq_hash_map);

    for (std::string s : words)
    {
        size_t guesses = play(s, G);
        std::cout << guesses << std::endl;
    }
    return 0;
}
