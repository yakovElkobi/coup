/**
 * Duke.hpp file for the exercise
 *
 * @author yakov elkobi
 * @since 2022-04
 * 
 */
#pragma once
#include <vector>
#include<string>
#include <iostream>
#include <stdexcept>

#include "Player.hpp"

namespace coup{
    class Player;
    class Game{

    private:
        std::vector<Player*> _players;
        unsigned int _turn;
        bool _startGame;
    public:
        // constructor
        Game();
        ~Game();

        // getters
        std::string turn()const;
        std::vector <std::string> players()const;
        std::vector<Player*> getPlayers()const{return this->_players;}
        std::string winner()const;

        void addPlayer(Player *p);
        void moveTurn();
        bool isMyTurn(const std::string name)const;
        
    };
}