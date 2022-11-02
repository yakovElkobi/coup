#include "Duke.hpp"

using namespace std;

namespace coup{

    Duke::~Duke(){}

    void Duke::tax(){
        this->isMyTurn();
        this->isInGame();
        this->setCoins(this->coins()+3);
        this->setAction(Actions::tex);
        this->getCurrentGame()->moveTurn();
    }
    void Duke::block(Player &p){
        this->isInGame();
        p.isLastAction(Actions::foreign_aid);
        p.setCoins(p.coins()-2);
        this->setAction(Actions::block);
    }
    string Duke::role(){ return "Duke";}
}