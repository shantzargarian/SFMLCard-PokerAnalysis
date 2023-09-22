//
// Created by Shant Zargarian on 4/1/23.
//

#include "PokerScore.h"

PokerScore::PokerScore() = default;

void PokerScore::addScore(const Scores& score) {
    scores.push_back(score);
}

bool PokerScore::contains(Scores score) const {
    return std::find(scores.begin(), scores.end(), score) != scores.end();
}

int PokerScore::size() const {
    return scores.size();
}

Scores PokerScore::operator[](unsigned int index) {
    if (index < scores.size()) {
        return scores[index];
    }
    throw std::out_of_range("Invalid index");
}

bool operator==(const PokerScore& p, Scores score) {
    return p.contains(score);
}

Scores PokerScore::getHighestScore() const {
    Scores highest = Scores::HIGH_CARD;
    int maxCount = 0;

    for (const auto &entry : scoreCounts) {
        if (entry.second > maxCount) {
            highest = entry.first;
            maxCount = entry.second;
        }
    }

    return highest;
}

std::string PokerScore::scoreToString(Scores score) {
    switch (score) {
        case Scores::ROYAL_FLUSH: return "Royal Flush";
        case Scores::STRAIGHT_FLUSH: return "Straight Flush";
        case Scores::FOUR_OF_A_KIND: return "Four of a Kind";
        case Scores::FULL_HOUSE: return "Full House";
        case Scores::FLUSH: return "Flush";
        case Scores::STRAIGHT: return "Straight";
        case Scores::THREE_OK_A_KIND: return "Three of a Kind";
        case Scores::TWO_PAIR: return "Two Pair";
        case Scores::ONE_PAIR: return "One Pair";
        case Scores::HIGH_CARD: return "High Card";
        default: return "Unknown";
    }
}

PokerScore &PokerScore::operator+=(const Scores &score) {
    if (std::find(scores.begin(), scores.end(), score) == scores.end()) {
        scores.push_back(score);
    }

    return *this;
}

bool PokerScore::containsScore(const Scores& score) const {
    return std::find(scores.begin(), scores.end(), score) != scores.end();
}

void PokerScore::displayScores(const std::map<Scores, int>& scoreCounts) const {
    std::vector<Scores> allScores = {
            Scores::ROYAL_FLUSH, Scores::STRAIGHT_FLUSH, Scores::FOUR_OF_A_KIND, Scores::FULL_HOUSE,
            Scores::FLUSH, Scores::STRAIGHT, Scores::THREE_OK_A_KIND, Scores::TWO_PAIR,
            Scores::ONE_PAIR, Scores::HIGH_CARD
    };

    for (const auto &score : allScores) {
        std::cout << scoreToString(score) << ": " << scoreCounts.at(score) << std::endl;
    }
}

std::vector<Scores> PokerScore::getAllScores() {
    return std::vector<Scores>{
            Scores::ROYAL_FLUSH,
            Scores::STRAIGHT_FLUSH,
            Scores::FOUR_OF_A_KIND,
            Scores::FULL_HOUSE,
            Scores::FLUSH,
            Scores::STRAIGHT,
            Scores::THREE_OK_A_KIND,
            Scores::TWO_PAIR,
            Scores::ONE_PAIR,
            Scores::HIGH_CARD
    };
}

