//
// Created by Shant Zargarian on 4/1/23.
//
#include <algorithm>
#include <ctime>
#include "Deck.h"

Deck::Deck() {
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) { // Change the loop to start from 1
            Suits suit = static_cast<Suits>(i);
            Ranks rank = static_cast<Ranks>(j);
            deck.push_back(Card(rank, suit));
        }
    }
}


void Deck::shuffle() {
    std::srand(static_cast<unsigned>(std::time(0)));
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard() {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

Card Deck::getCard(int index) const {
    if (index >= 0 && index < 52) {
        return deck[index];
    }
    throw std::out_of_range("Invalid card index");
}
