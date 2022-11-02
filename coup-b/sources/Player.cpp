#include "Player.hpp"

using namespace std;

namespace coup{

    Player::Player(Game &game, const string &name){
        this->_name = name;
        _coins = 0;
        _alive = true;
        this->_game = &game;
        this->_lastAction = init;
        this->_target = nullptr;
        this->_game->addPlayer(this);
    }
    Player::~Player(){}

    void Player::income(){
        this->isInGame();
        this->isMyTurn();
        this->maxCoins();
        this->setAction(Actions::income);
        this->setCoins(this->coins()+1);
        this->_game->moveTurn();
    }
    void Player::foreign_aid(){
        this->isInGame();
        this->isMyTurn();
        this->maxCoins();
        this->setCoins(this->coins()+2);
        this->setAction(Actions::foreign_aid);
        this->_game->moveTurn();
    }
    void Player::coup(Player &p){
        this->isInGame();
        p.isInGame();
        this->isMyTurn();
        const int coupPrice = 7;
        if(this->_coins < coupPrice){
            throw runtime_error("dont have enough coins:");
        }
        this->setAction(Actions::coup);
        p.setAlive(false);
        this->setCoins(this->coins()-coupPrice);
        this->_game->moveTurn();
    }
    void Player::isInGame() const {
        if(!this->isAlive()){
            throw runtime_error("The player is not in the game:");
        }
    }
    void Player::isMyTurn() const {
        int b = this->getName().compare(this->_game->turn());
        if(b!=0){
            throw runtime_error("This is not your turn:");
        }
    }
    void Player::isLastAction(Actions action) const {
        if(this->getActions() != action){
            throw runtime_error("This is not the last action:");
        }
    }
    void Player::maxCoins()const{
        const int max = 10;
        if(this->coins() >= max){
            throw runtime_error("Maximom coins is 9 you most coup:");
        }
    }
    string Player::role(){ return "virtual";}
}