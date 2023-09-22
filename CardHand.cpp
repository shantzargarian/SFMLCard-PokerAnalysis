//
// Created by Shant Zargarian on 4/1/23.
//

#include "CardHand.h"
CardHand::CardHand() {
}

void CardHand::addCard(const Card &card) {
    hand.push_back(card);
}

Card CardHand::getCard(int index) const {
    if (index >= 0 && index < hand.size()) {
        return hand[index];
    }
    throw std::out_of_range("Invalid card index");
}

int CardHand::getCardCount() const {
    return hand.size();
}

int CardHand::size() const {
    return hand.size();
}

const std::vector<Card>& CardHand::getCards() const {
    return hand;
}