#include <algorithm>
#include <cmath>

#include "naive.hpp"
#include "../../lib.hpp"

std::string Naive::guess(std::vector<Guess>& history)
{
    int top_ten_percent = m_freq_matrix.size() * 0.10;
    int choice = std::rand() % top_ten_percent;

    // First guess - choose a word in the top 10% of the dictionary for frequency
    if (history.empty())
    {
        return m_freq_matrix[choice].first;
    }

    Guess g = history.back();
    history.pop_back();
    for (int i = 0; i < g.mask.size(); i++)
    {
        if (g.mask.at(i) == Correctness::Correct)
        {
            // Remove values from map that do not have the same letter in the same position
            m_freq_matrix.erase(std::remove_if(m_freq_matrix.begin(), m_freq_matrix.end(), [&i, &g](auto p){ return p.first[i] != g.word[i]; }));
        }
        else if (g.mask.at(i) == Correctness::Misplaced)
        {
            // Remove values from map that do not have the correct letter
            m_freq_matrix.erase(std::remove_if(m_freq_matrix.begin(), m_freq_matrix.end(), [&i, &g](auto p){ return p.first.find(g.word[i]) == std::string::npos; }));
        }
        else if (g.mask.at(i) == Correctness::Wrong)
        {
            // Remove values from map that do have the incorrect letter
            m_freq_matrix.erase(std::remove_if(m_freq_matrix.begin(), m_freq_matrix.end(), [&i, &g](auto p){ return p.first.find(g.word[i]) != std::string::npos; }));
        }
    }

    return m_freq_matrix[choice].first;
}

bool sort_pair_by_second(const std::pair<std::string, int>& a,
                         const std::pair<std::string, int>& b)
{
    return (a.second < b.second);
}

void Naive::fill_freq_matrix(freq_matrix& freq_matrix, std::string filepath)
{
    std::ifstream file;
    file.open(filepath);
    if (!file.is_open())
    {
        std::cerr << "Could not open file located at " << filepath << " exiting program" << std::endl;
    }

    std::string word;
    int frequency;
    while (file >> word >> frequency)
    {
        freq_matrix.push_back(std::make_pair(word, frequency));
    }

    std::sort(freq_matrix.begin(), freq_matrix.end(), sort_pair_by_second);
}
