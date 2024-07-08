#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include "player.h"
#include "game.h"

// for standard I/O input value.
enum Command{
    ONE_MORE_CARD = 1,
    ENOUGH,
};

int main(){
    srand(time(nullptr));
    int command;
    std::string name;
    std::cout << "請輸入玩家名稱 > ";
    std::cin >> name;
    Game game(name);
    game.init();
    std::cout << "遊戲開始！" << std::endl;
    // determine dealer's point
    game.dealerDraw();
    // draw two cards for user
    game.oneMoreCard();
    game.oneMoreCard();

    game.displayRound();
    // game loop
    while(!game.isEnd()){
        
        std::cout << "(1) 拿牌 (2) 停止拿牌 > ";
        std::cin >> command;
        switch((Command)command){
            case ONE_MORE_CARD:
                
                // user's hand value > 21
                if (game.oneMoreCard()){
                    game.terminate();
                }
                break;
            case ENOUGH:
                game.terminate();
                break;
        }

        game.displayRound();
    }
    
    switch(game.judgeWinner()){
        case WIN:
            std::cout << "你贏了！" << std::endl;
            break;
        case LOSE:
            std::cout << "你輸了！" << std::endl;
            break;
        case TIE:
            std::cout << "平手！" << std::endl;
            break;
    }
}
