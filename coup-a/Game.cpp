#include "Game.hpp"

using namespace std;

namespace coup{

    Game::~Game(){}

    Game::Game(){
        vector<string> _players;
        _turn = 0;
    }
    void Game::addPlayer(string name){
        this->_players.push_back(name);
    }

    vector <string> Game::players(){
        return this->_players;
    }
    string Game::turn(){
        return this->_players.at(this->_turn);
    }
    string Game::winner(){
        return "winner";
    }
}