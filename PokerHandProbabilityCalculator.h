//
// Created by Shant Zargarian on 4/1/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_POKERHANDPROBABILITYCALCULATOR_H
#define CS3A_SPRING23_SFMLCARD_POKERHANDPROBABILITYCALCULATOR_H

#include <iostream>
#include <vector>
#include <map>
#include "Deck.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include "PokerScore.h"

class PokerHandProbabilityCalculator {
private:
    std::map<Scores, double> handProbabilities;



public:
    void calculateProbabilities();
    PokerHandProbabilityCalculator();
    void displayProbabilities();
};



#endif //CS3A_SPRING23_SFMLCARD_POKERHANDPROBABILITYCALCULATOR_H
