//
// Created by Shant Zargarian on 4/1/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_CARDHAND_H
#define CS3A_SPRING23_SFMLCARD_CARDHAND_H
#include <vector>
#include "Card.h"

class CardHand {

private:
    std::vector<Card> hand;

public:
    CardHand();
    void addCard(const Card &card);
    Card getCard(int index) const;
    int getCardCount() const;
    int size() const;
    const std::vector<Card>& getCards() const;
};


#endif //CS3A_SPRING23_SFMLCARD_CARDHAND_H
