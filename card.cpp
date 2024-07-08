#include "card.h"
#include <string>

// listing all the possible suits and pips
Suit suit_table[] = {SPADE,HEART,DIAMOND,CLUB};
char pip_table[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};   

std::unordered_map<char, int> pip_value_map = {
    {'A', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    // T stands for 10
    {'T', 10},
    {'J', 10},
    {'Q', 10},
    {'K', 10}
};

std::unordered_map<Suit, std::string> suit_name_map = {
    {SPADE, "♠"},
    {HEART, "♥"},
    {DIAMOND, "♦"},
    {CLUB, "♣"}
};

std::ostream& operator<<(std::ostream& out, const Card& card){
    out << suit_name_map[card.suit] << card.pip;
    return out;
}
