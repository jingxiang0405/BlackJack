#include "game.h"
#include "card.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

// [#]initialization list can be replaced by setter
Game::Game(std::string playerName) : _user(playerName), _dealer("Dealer"){}

void Game::init(){
    srand(time(nullptr));

    this->_end = false;
    this->_deck.clear();

    // fill in deck with 52 cards
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 13; ++j){
            Card c;

            // mapping with the table in card.cpp
            // [#]You can omit the mapping procedure, and
            // fill in the data directly.
            c.suit = suit_table[i];
            c.pip = pip_table[j];
            this->_deck.push_back(std::move(c));
        }
    }

    // shuffle the deck 
    // [#]search "how to shuffle a vector"
    // [#]lambda can be replaced by a complete defined function
    std::random_shuffle(this->_deck.begin(), this->_deck.end(),
            [](int i){return rand()%i; });


}

// keep drawing until sum > 17
void Game::dealerDraw(){
    int target = 17;
    int value;
    while(true){
        value = this->_dealer.getHandValue();
        if(value == -1 || value > target)break;
        this->_dealer.addCard(this->_deck.back());
        this->_deck.pop_back();
    }
}

//return true to terminate the game(sum > 21)
bool Game::oneMoreCard(){
    this->_user.addCard(this->_deck.back());
    this->_deck.pop_back();
    return this->_user.getHandValue() == -1;
}

void Game::terminate(){
    _end = true;
}


void Game::displayRound() const {
    this->_dealer.printHand(this->_end);
    this->_user.printHand(true);

}

bool Game::isEnd() const{
    return this->_end;
}

GameResult Game::judgeWinner() const {
    int user = this->_user.getHandValue();
    int dealer = this->_dealer.getHandValue();
    
    if(user > dealer){
        return GameResult::WIN;
    } else if(user == dealer){
        return GameResult::TIE;
    } else {
        return GameResult::LOSE;
    } 
}

