//
// Created by Shant Zargarian on 4/1/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_CARDHANDSCORER_H
#define CS3A_SPRING23_SFMLCARD_CARDHANDSCORER_H
#include <iostream>
#include "Scores.h"
#include "CardHand.h"
#include "PokerScore.h"


class CardHandScorer {

private:
    int highestScore;
    std::string highestScoreDescription;
    static bool isRoyalFlush(const CardHand& hand);
    static bool isStraightFlush(const CardHand& hand);
    static bool isFourOfAKind(const CardHand& hand);
    static bool isFullHouse(const CardHand& hand);
    static bool isFlush(const CardHand& hand);
    static bool isStraight(const CardHand& hand);
    static bool isThreeOfAKind(const CardHand& hand);
    static bool isTwoPair(const CardHand& hand);
    static bool isOnePair(const CardHand& hand);
    static bool isHighCard(const CardHand& hand);
    static bool isConsecutive(const std::vector<Card>& cards);

public:
    CardHandScorer();

    void addScore(int score, const std::string &description);

    int getHighestScore() const;

    std::string getHighestScoreDescription() const;

    PokerScore analyzeHand(const CardHand &hand);

};


#endif //CS3A_SPRING23_SFMLCARD_CARDHANDSCORER_H
