#include "Assassin.hpp"

using namespace std;

namespace coup{

    Assassin::~Assassin(){}

    void Assassin::coup(Player &p) {
        this->isMyTurn();
        this->isInGame();
        p.isInGame();
        const int minCoup = 3;
        if(this->coins() < minCoup){
            throw runtime_error("dont have enough coins:");
        }
        const int coupPrice = 7;
        if(this->coins() >= coupPrice){
            Player::coup(p);
        }
        else {
            this->setCoins(this->coins()-minCoup);
            this->setAction(Actions::assassin_coup);
            _target = &p;
            p.setAlive(false);
            this->getCurrentGame()->moveTurn();
        }
    }
    string Assassin::role(){return "Assassin";}
}