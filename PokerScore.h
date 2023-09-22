//
// Created by Shant Zargarian on 4/1/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_POKERSCORE_H
#define CS3A_SPRING23_SFMLCARD_POKERSCORE_H
#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>
#include "Scores.h"

class PokerScore {

private:
    std::vector<Scores> scores;
    std::map<Scores, int> scoreCounts;
public:
    PokerScore();

    void addScore(const Scores& score);

    bool contains(Scores score) const;

    int size() const;

    Scores operator[](unsigned int index);

    friend bool operator==(const PokerScore& p, Scores score);

    static std::string scoreToString(Scores score);

    Scores getHighestScore() const;

    bool containsScore(const Scores& score) const;

    void displayScores(const std::map<Scores, int>& scoreCounts) const;

    PokerScore &operator+=(const Scores &score);

    static std::vector<Scores> getAllScores();

};

#endif //CS3A_SPRING23_SFMLCARD_POKERSCORE_H
