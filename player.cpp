#include "player.h"
#include <iostream>

Player::Player(std::string name){
    this->_name = name;
}

void Player::addCard(Card card){
    this->_hand.push_back(card); 
}

// get current max point in hand
int Player::getHandValue() const {
    int sum = 0;
    int point, credit = 0;
    for(int i = 0; i < this->_hand.size(); ++i){
        point = pip_value_map[this->_hand[i].pip];
        if(point == 1) credit++;
        sum += point;
    }

    // if already busted, return -1 immediately
    if(sum > 21)return -1;

    // add point depends on how many Aces we have
    for(int i = 0; i < credit; ++i){
        if(sum + 10 <= 21){
            sum += 10;
        }
        else break;
    }

    return sum;
}

void Player::printHand(bool showAll) const{
    std::cout << "[" << this->_name << "] 目前的牌: ";
    if(showAll){
        for(auto& card : this->_hand){
            std::cout << card << " ";
        }
    }
    else{
        std::cout << this->_hand[0];
    
        for(int i = 1; i < this->_hand.size(); ++i){
            std::cout << " **";
        }
    }
    std::cout << std::endl;
}

std::string Player::getName() const{
    return this->_name;
}

