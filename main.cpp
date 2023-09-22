#include <iostream>
#include "Deck.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "PokerHandProbabilityCalculator.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Poker Hands Counter");

    sf::Font font;
    if (!font.loadFromFile("/Users/shantzargarian/Downloads/CS3A_Spring23_SFMLCard/OpenSans-Bold.ttf")) {
        return EXIT_FAILURE;
    }

    std::map<Scores, int> handCounts;
    std::map<Scores, sf::Text> handTexts;
    std::map<Scores, CardHand> exampleHands;

    int y_offset = 0;
    for (Scores score : PokerScore::getAllScores()) {
        handCounts[score] = 0;

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);

        if (static_cast<int>(score) < static_cast<int>(Scores::FLUSH)) {
            text.setPosition(10, y_offset);
        } else {
            text.setPosition(600, y_offset - 5 * 60);
        }
        y_offset += 60;

        handTexts[score] = text;
    }



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        Deck deck;
        deck.shuffle();

        CardHand playerHand;
        for (int i = 0; i < 5; i++) {
            playerHand.addCard(deck.drawCard());
        }

        CardHandScorer scorer;
        PokerScore score = scorer.analyzeHand(playerHand);

        for (const auto& s : PokerScore::getAllScores()) {
            if (score.containsScore(s)) {
                handCounts[s]++;
                if (exampleHands.find(s) == exampleHands.end()) {
                    exampleHands[s] = playerHand;
                }
            }
        }

        for (const auto& entry : handCounts) {
            handTexts[entry.first].setString(PokerScore::scoreToString(entry.first) + ": " + std::to_string(entry.second));
        }

        window.clear();

        y_offset = 0;
        int column = 0;
        for (const auto& entry : handTexts) {
            window.draw(entry.second);
            handTexts[entry.first].setString(PokerScore::scoreToString(entry.first) + ": " + std::to_string(handCounts[entry.first]));

            if (y_offset >= 1000) {
                y_offset = 0;
                column++;
            }

            handTexts[entry.first].setPosition(670 * column + 575, y_offset);
            y_offset += 225;
        }


        Card RF1(ACE, HEARTS);
        Card RF2(KING, HEARTS);
        Card RF3(QUEEN, HEARTS);
        Card RF4(JACK, HEARTS);
        Card RF5(TEN, HEARTS);

        RF1.setPosition({100,0});
        RF1.draw(window, sf::RenderStates());

        RF2.setPosition({175,0});
        RF2.draw(window, sf::RenderStates());

        RF3.setPosition({250,0});
        RF3.draw(window, sf::RenderStates());

        RF4.setPosition({325,0});
        RF4.draw(window, sf::RenderStates());

        RF5.setPosition({400,0});
        RF5.draw(window, sf::RenderStates());

        Card SF1(NINE, DIAMONDS);
        Card SF2(EIGHT, DIAMONDS);
        Card SF3(SEVEN, DIAMONDS);
        Card SF4(SIX, DIAMONDS);
        Card SF5(FIVE, DIAMONDS);

        SF1.setPosition({100, 225});
        SF1.draw(window, sf::RenderStates());
        SF2.setPosition({175, 225});
        SF2.draw(window, sf::RenderStates());
        SF3.setPosition({250, 225});
        SF3.draw(window, sf::RenderStates());
        SF4.setPosition({325, 225});
        SF4.draw(window, sf::RenderStates());
        SF5.setPosition({400, 225});
        SF5.draw(window, sf::RenderStates());

        // Four of a Kind
        Card F1(FOUR, HEARTS);
        Card F2(FOUR, SPADES);
        Card F3(FOUR, DIAMONDS);
        Card F4(FOUR, CLUBS);
        Card F5(THREE, HEARTS);

        F1.setPosition({100, 450});
        F1.draw(window, sf::RenderStates());
        F2.setPosition({175, 450});
        F2.draw(window, sf::RenderStates());
        F3.setPosition({250, 450});
        F3.draw(window, sf::RenderStates());
        F4.setPosition({325, 450});
        F4.draw(window, sf::RenderStates());
        F5.setPosition({400, 450});
        F5.draw(window, sf::RenderStates());

        // Full House
        Card FH1(THREE, SPADES);
        Card FH2(THREE, DIAMONDS);
        Card FH3(THREE, CLUBS);
        Card FH4(TWO, HEARTS);
        Card FH5(TWO, SPADES);

        FH1.setPosition({100, 675});
        FH1.draw(window, sf::RenderStates());
        FH2.setPosition({175, 675});
        FH2.draw(window, sf::RenderStates());
        FH3.setPosition({250, 675});
        FH3.draw(window, sf::RenderStates());
        FH4.setPosition({325, 675});
        FH4.draw(window, sf::RenderStates());
        FH5.setPosition({400, 675});
        FH5.draw(window, sf::RenderStates());

        // Flush
        Card FL1(KING, CLUBS);
        Card FL2(TEN, CLUBS);
        Card FL3(EIGHT, CLUBS);
        Card FL4(SIX, CLUBS);
        Card FL5(THREE, CLUBS);

        FL1.setPosition({100, 900});
        FL1.draw(window, sf::RenderStates());
        FL2.setPosition({175, 900});
        FL2.draw(window, sf::RenderStates());
        FL3.setPosition({250, 900});
        FL3.draw(window, sf::RenderStates());
        FL4.setPosition({325, 900});
        FL4.draw(window, sf::RenderStates());
        FL5.setPosition({400, 900});
        FL5.draw(window, sf::RenderStates());

        // Straight
        Card S1(QUEEN, CLUBS);
        Card S2(JACK, HEARTS);
        Card S3(TEN, DIAMONDS);
        Card S4(NINE, SPADES);
        Card S5(EIGHT, CLUBS);

        S1.setPosition({800, 0});
        S1.draw(window, sf::RenderStates());
        S2.setPosition({875, 0});
        S2.draw(window, sf::RenderStates());
        S3.setPosition({950, 0});
        S3.draw(window, sf::RenderStates());
        S4.setPosition({1025, 0});
        S4.draw(window, sf::RenderStates());
        S5.setPosition({1100, 0});
        S5.draw(window, sf::RenderStates());

        // Three of a Kind
        Card T1(NINE, CLUBS);
        Card T2(NINE, HEARTS);
        Card T3(NINE, DIAMONDS);
        Card T4(KING, SPADES);
        Card T5(FOUR, CLUBS);

        T1.setPosition({800, 225});
        T1.draw(window, sf::RenderStates());
        T2.setPosition({875, 225});
        T2.draw(window, sf::RenderStates());
        T3.setPosition({950, 225});
        T3.draw(window, sf::RenderStates());
        T4.setPosition({1025, 225});
        T4.draw(window, sf::RenderStates());
        T5.setPosition({1100, 225});
        T5.draw(window, sf::RenderStates());

        // Two Pair
        Card TP1(JACK, CLUBS);
        Card TP2(JACK, DIAMONDS);
        Card TP3(EIGHT, HEARTS);
        Card TP4(EIGHT, SPADES);
        Card TP5(THREE, DIAMONDS);

        TP1.setPosition({800, 450});
        TP1.draw(window, sf::RenderStates());
        TP2.setPosition({875, 450});
        TP2.draw(window, sf::RenderStates());
        TP3.setPosition({950, 450});
        TP3.draw(window, sf::RenderStates());
        TP4.setPosition({1025, 450});
        TP4.draw(window, sf::RenderStates());
        TP5.setPosition({1100, 450});
        TP5.draw(window, sf::RenderStates());

        // One Pair
        Card OP1(QUEEN, SPADES);
        Card OP2(QUEEN, DIAMONDS);
        Card OP3(TEN, CLUBS);
        Card OP4(NINE, HEARTS);
        Card OP5(TWO, SPADES);

        OP1.setPosition({800, 675});
        OP1.draw(window, sf::RenderStates());
        OP2.setPosition({875, 675});
        OP2.draw(window, sf::RenderStates());
        OP3.setPosition({950, 675});
        OP3.draw(window, sf::RenderStates());
        OP4.setPosition({1025, 675});
        OP4.draw(window, sf::RenderStates());
        OP5.setPosition({1100, 675});
        OP5.draw(window, sf::RenderStates());

        // High Card
        Card HC1(ACE, DIAMONDS);
        Card HC2(KING, HEARTS);
        Card HC3(QUEEN, CLUBS);
        Card HC4(EIGHT, SPADES);
        Card HC5(SIX, DIAMONDS);

        HC1.setPosition({800, 900});
        HC1.draw(window, sf::RenderStates());
        HC2.setPosition({875, 900});
        HC2.draw(window, sf::RenderStates());
        HC3.setPosition({950, 900});
        HC3.draw(window, sf::RenderStates());
        HC4.setPosition({1025, 900});
        HC4.draw(window, sf::RenderStates());
        HC5.setPosition({1100, 900});
        HC5.draw(window, sf::RenderStates());


        window.display();
        window.clear();
    }

    return 0;
}



