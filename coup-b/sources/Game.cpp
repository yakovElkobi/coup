#include "Game.hpp"

using namespace std;

namespace coup{

    Game::~Game(){}

    Game::Game(){
        _turn = 0;
        _startGame = false;
    }
    void Game::addPlayer(Player *p){
        const int maxPlayers = 6;
        if(this->_players.size() == maxPlayers){
            throw runtime_error("The maximom players is six:");
        }
        if(_startGame){
            throw runtime_error("The game is already start:");
        }
        this->_players.push_back(p);
    }
    vector <string> Game::players()const{
        vector <string> ans;
        if(this->_players.empty()){
            throw runtime_error("dont have players in the game:");
        }
        for(size_t i = 0; i < _players.size(); ++i){
            if(this->_players.at(i)->isAlive()) {
                ans.push_back(this->_players.at(i)->getName());
            }
        }
        return ans;
    }
    string Game::turn()const{
        return this->_players.at(this->_turn)->getName();
    }
    void Game::moveTurn(){
        if(this->_players.size() > 1){
            _startGame = true;
        }
        if(!_startGame){
            throw runtime_error("2");
        }
        do {
            this->_turn = (++this->_turn)%this->_players.size();
        } while (!this->_players.at(this->_turn)->isAlive());
    }
    string Game::winner()const{
        if(this->players().size() != 1 || !_startGame){
            throw runtime_error("The game is not over:");
        }
        return this->players().at(0);
    }
}