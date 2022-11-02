/**
 * Player.hpp program for Coup exercise
 *
 * @author: yakov elkobi
 * @since: 2022-04
 */
#pragma once
#include "Game.hpp"

namespace coup{
    class Player{

    private:
        std::string _name;
        int _coins;
        Game * _game;
    public:
        Player(/* args */);
        Player(Game &game, const std::string name);
        ~Player();

        void income();
        void foreign_aid();
        void coup(Player p);
        int coins();
    };
}