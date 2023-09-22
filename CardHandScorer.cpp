//
// Created by Shant Zargarian on 4/1/23.
//

#include "CardHandScorer.h"

CardHandScorer::CardHandScorer() : highestScore(0), highestScoreDescription("No score") {
}

void CardHandScorer::addScore(int score, const std::string &description) {
    if (score > highestScore) {
        highestScore = score;
        highestScoreDescription = description;
    }
}

int CardHandScorer::getHighestScore() const {
    return highestScore;
}

std::string CardHandScorer::getHighestScoreDescription() const {
    return highestScoreDescription;
}

PokerScore CardHandScorer::analyzeHand(const CardHand& hand) {
    PokerScore score;

    if (isRoyalFlush(hand)) {
        score.addScore(Scores::ROYAL_FLUSH);
    } else if (isStraightFlush(hand)) {
        score.addScore(Scores::STRAIGHT_FLUSH);
    } else if (isFourOfAKind(hand)) {
        score.addScore(Scores::FOUR_OF_A_KIND);
    } else if (isFullHouse(hand)) {
        score.addScore(Scores::FULL_HOUSE);
    } else if (isFlush(hand)) {
        score.addScore(Scores::FLUSH);
    } else if (isStraight(hand)) {
        score.addScore(Scores::STRAIGHT);
    } else if (isThreeOfAKind(hand)) {
        score.addScore(Scores::THREE_OK_A_KIND);
    } else if (isTwoPair(hand)) {
        score.addScore(Scores::TWO_PAIR);
    } else if (isOnePair(hand)) {
        score.addScore(Scores::ONE_PAIR);
    } else {
        score.addScore(Scores::HIGH_CARD);
    }

    return score;
}



bool CardHandScorer::isConsecutive(const std::vector<Card>& cards) {
    for (size_t i = 1; i < cards.size(); ++i) {
        if (static_cast<int>(cards[i].getRank()) - static_cast<int>(cards[i - 1].getRank()) != 1) {
            return false;
        }
    }
    return true;
}


bool CardHandScorer::isRoyalFlush(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::sort(cards.begin(), cards.end(), [](const Card& a, const Card& b) { return a.getRank() < b.getRank(); });

    if (cards[0].getRank() != Ranks::TEN) {
        return false;
    }

    if (!isConsecutive(cards)) {
        return false;
    }

    Suits suit = cards[0].getSuit();
    for (const Card& card : cards) {
        if (card.getSuit() != suit) {
            return false;
        }
    }

    return true;
}

bool CardHandScorer::isStraightFlush(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::sort(cards.begin(), cards.end(), [](const Card& a, const Card& b) { return a.getRank() < b.getRank(); });

    if (!isConsecutive(cards)) {
        return false;
    }

    Suits suit = cards[0].getSuit();
    for (const Card& card : cards) {
        if (card.getSuit() != suit) {
            return false;
        }
    }

    return true;
}

bool CardHandScorer::isFourOfAKind(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::map<Ranks, int> rankCount;

    for (const Card& card : cards) {
        rankCount[card.getRank()]++;
    }

    for (const auto& entry : rankCount) {
        if (entry.second == 4) {
            return true;
        }
    }

    return false;
}

bool CardHandScorer::isFullHouse(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::map<Ranks, int> rankCount;

    for (const Card& card : cards) {
        rankCount[card.getRank()]++;
    }

    bool hasThree = false, hasTwo = false;
    for (const auto& entry : rankCount) {
        if (entry.second == 3) {
            hasThree = true;
        } else if (entry.second == 2) {
            hasTwo = true;
        }
    }

    return hasThree && hasTwo;
}

bool CardHandScorer::isFlush(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    Suits suit = cards[0].getSuit();

    for (const Card& card : cards) {
        if (card.getSuit() != suit) {
            return false;
        }
    }

    return true;
}

bool CardHandScorer::isStraight(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::sort(cards.begin(), cards.end(), [](const Card& a, const Card& b) { return a.getRank() < b.getRank(); });

    return isConsecutive(cards);
}

bool CardHandScorer::isThreeOfAKind(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::map<Ranks, int> rankCount;

    for (const Card& card : cards) {
        rankCount[card.getRank()]++;
    }

    for (const auto& entry : rankCount) {
        if (entry.second == 3) {
            return true;
        }
    }

    return false;
}

bool CardHandScorer::isTwoPair(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::map<Ranks, int> rankCount;

    for (const Card& card : cards) {
        rankCount[card.getRank()]++;
    }

    int pairCount = 0;
    for (const auto& entry : rankCount) {
        if (entry.second == 2) {
            pairCount++;
        }
    }

    return pairCount == 2;
}

bool CardHandScorer::isOnePair(const CardHand& hand) {
    std::vector<Card> cards = hand.getCards();
    std::map<Ranks, int> rankCount;

    for (const Card& card : cards) {
        rankCount[card.getRank()]++;
    }

    for (const auto& entry : rankCount) {
        if (entry.second == 2) {
            return true;
        }
    }

    return false;
}

bool CardHandScorer::isHighCard(const CardHand& hand) {
    return true;
}


