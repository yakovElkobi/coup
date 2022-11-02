/**
 * Contessa.hpp program for Coup exercise
 *
 * @author: yakov elkobi
 * @since: 2022-04
 */
#pragma once
#include "Player.hpp"

namespace coup{
    class Contessa : public Player{
    private:
        /* data */
    public:
        //Contessa(/* args */);
        Contessa(Game &game, const std::string name) : Player(game, name){}

        void block(Player &p);
        std::string role()override;
        ~Contessa();
    };
    
}
