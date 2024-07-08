#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "card.h"

class Player{

public:
    Player(std::string);


    int getHandValue() const;
        
    void addCard(Card);

    // getter
    std::string getName() const;

    void printHand(bool) const;

private:
    std::string _name;
        
    std::vector<Card> _hand;
};

#endif
