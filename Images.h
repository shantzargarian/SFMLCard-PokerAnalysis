//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_IMAGES_H
#define CS3A_SPRING23_SFMLCARD_IMAGES_H
#include <vector>
#include "Suits.h"
#include <SFML/Graphics.hpp>
#include <string>

class Images
{
private:
    static std::vector<sf::Texture> images;
    static std::string getPath(Suits suit);
    static void loadFile(Suits suit);
public:
    static sf::Texture& getImage(Suits suit);
};


#endif //CS3A_SPRING23_SFMLCARD_IMAGES_H
