/**
 * Duke.hpp file for the exercise
 *
 * @author yakov elkobi
 * @since 2022-04
 * 
 */
#pragma once
#include "Player.hpp"

namespace coup{
    class Assassin : public Player{
    private:
    public:
        //Assassin(/* args */);
        Assassin(Game &game, std::string name) : Player(game, name){}
        void coup(Player &p) override;
        ~Assassin();
        std::string role()override;

    };
}