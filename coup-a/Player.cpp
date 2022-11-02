#include "Player.hpp"
#include <stdexcept>
#include <vector>

using namespace std;

namespace coup{

    Player::Player(Game &game, const string name){
        this->_name = name;
        this->_coins = 0;
        this->_game = &game;
        this->_game->addPlayer(this->_name);
    }
    Player::~Player(){}

    void Player::income(){
        this->_coins++;
    }
    void Player::foreign_aid(){
        this->_coins += 2;
    }
    void Player::coup(Player p){
    }
    int Player::coins(){
        return this->_coins;
    }
}