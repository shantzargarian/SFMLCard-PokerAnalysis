//
// Created by Shant Zargarian on 4/1/23.
//

#include "PokerHandProbabilityCalculator.h"

PokerHandProbabilityCalculator::PokerHandProbabilityCalculator() {
    calculateProbabilities();
}

void PokerHandProbabilityCalculator::displayProbabilities() {
    std::cout << "Poker Hand Probabilities:\n";
    for (const auto &entry : handProbabilities) {
        std::cout << PokerScore::scoreToString(entry.first) << ": " << entry.second * 100 << "%" << std::endl;
    }
}

void PokerHandProbabilityCalculator::calculateProbabilities() {
    Deck deck;
    std::map<Scores, int> handCounts;

    for (int i = 0; i < 52; i++) {
        for (int j = i + 1; j < 52; j++) {
            for (int k = j + 1; k < 52; k++) {
                for (int l = k + 1; l < 52; l++) {
                    for (int m = l + 1; m < 52; m++) {
                        CardHand hand;
                        hand.addCard(deck.getCard(i));
                        hand.addCard(deck.getCard(j));
                        hand.addCard(deck.getCard(k));
                        hand.addCard(deck.getCard(l));
                        hand.addCard(deck.getCard(m));

                        CardHandScorer scorer;
                        PokerScore score = scorer.analyzeHand(hand);
                        for (int n = 0; n < score.size(); n++) {
                            handCounts[score[n]]++;
                        }
                    }
                }
            }
        }
    }

    int totalHands = 2598960; // Total possible 5-card hands (C(52, 5))
    for (const auto &entry : handCounts) {
        handProbabilities[entry.first] = static_cast<double>(entry.second) / totalHands;
    }
}