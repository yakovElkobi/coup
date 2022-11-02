/**
 * Duke file for the exercise
 *
 * @author yakov elkobi
 * @since 2022-04
 * 
 */
#pragma once
#include "Game.hpp"
#include "Player.hpp"
#include <string>


namespace coup{
    class Duke : public Player{
    private:
        
    public:
        Duke(/* args */);
        Duke(Game &game, std::string name): Player(game, name){}
        ~Duke();

        void tax();
        void block(Player &p);
        std::string role()override;
    };
}