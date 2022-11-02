/**
 * Ambassador.hpp program for Coup exercise
 *
 * @author: yakov elkobi
 * @since: 2022-03
 */
#pragma once
#include "Player.hpp"

namespace coup{
    class Ambassador : public Player{
    private:
        /* data */
    public:
        Ambassador(/* args */);
        Ambassador(Game &game, std::string name) : Player(game, name){}
        ~Ambassador();

        void transfer(Player &p1, Player &p2);
        void block(Player &p);
        std::string role()override;
    };
}
