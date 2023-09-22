//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_FONT_H
#define CS3A_SPRING23_SFMLCARD_FONT_H
#include <SFML/Graphics.hpp>

class Font
{
private:
    static sf::Font font;
    static void loadFont();

public:
    static sf::Font& getFont();
};


#endif //CS3A_SPRING23_SFMLCARD_FONT_H
