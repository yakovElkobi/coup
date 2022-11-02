/**
 * Captain.hpp program for Coup exercise
 *
 * @author: yakov elkobi
 * @since: 2022-04
 */
#pragma once
#include "Player.hpp"

namespace coup{
    class Captain : public Player{
    private:
        /* data */
    public:
        Captain(/* args */);
        Captain(Game &game, std::string name) : Player(game, name){}
        ~Captain();


        void block(Player &p);
        void steal(Player &p);
        std::string role()override;
    };
    
}
