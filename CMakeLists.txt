cmake_minimum_required(VERSION 3.17)
project(CS3A_Spring23_SFMLCard)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS3A_Spring23_SFMLCard main.cpp Background.cpp Background.h Suit.cpp Suit.h Rank.cpp Rank.h Card.cpp Card.h Font.cpp Font.h Images.cpp Images.h Suits.h Ranks.h Position.cpp Position.h Deck.cpp Deck.h CardHand.cpp CardHand.h PokerScore.cpp PokerScore.h CardHandScorer.cpp CardHandScorer.h PokerHandProbabilityCalculator.cpp PokerHandProbabilityCalculator.h Scores.h)
target_link_libraries(CS3A_Spring23_SFMLCard sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)