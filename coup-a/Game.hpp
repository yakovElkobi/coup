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

namespace coup{
   class Player;
    class Game{

    private:
        std::vector<std::string> _players;
        unsigned int _turn;
    public:
        
        Game();
        ~Game();
        void addPlayer(std::string name);
        std::string turn();
        std::vector <std::string> players();
        std::string winner();
    };
}