//
// Created by Shant Zargarian on 4/1/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_DECK_H
#define CS3A_SPRING23_SFMLCARD_DECK_H
#include <vector>
#include "Card.h"

class Deck {
    std::vector<Card> deck;

public:
    Deck();
    void shuffle();
    Card drawCard();
    Card getCard(int index) const;

};

#endif // DECK_H

