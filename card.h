#ifndef CARD_H
#define CARD_H

#include <unordered_map>
#include <iostream>


enum Suit{
    SPADE,HEART,DIAMOND,CLUB
};

struct Card{
    Suit suit;
    char pip;
};

// for easier cout usage
std::ostream& operator<<(std::ostream&, const Card&);

// for initialization
extern Suit suit_table[]; 
extern char pip_table[];   

// for pip&value mapping
extern std::unordered_map<char, int> pip_value_map;

#endif

