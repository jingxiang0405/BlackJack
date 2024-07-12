#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>
#include <string>

enum GameResult{
    WIN, LOSE, TIE
};

class Game{
    public:
        Game(std::string);

        void init();

        // determine dealer's card
        void dealerDraw();

        // handling user input
        bool oneMoreCard();

        void terminate();

        // called after each draw by user
        void displayRound() const;

        bool isEnd() const;

        // called at the end of the game
        GameResult judgeWinner() const;
        
    private:
        bool _end;

        std::vector<Card> _deck;
        Player _user, _dealer;

};

#endif
