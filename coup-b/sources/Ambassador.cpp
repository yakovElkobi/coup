#include "Ambassador.hpp"

using namespace std;

namespace coup{

    Ambassador::~Ambassador(){}

    void Ambassador::block(Player &p){
        this->isInGame();
        if(p.getActions() == Actions::steal_1){
            p.setCoins(p.coins()-1);
            p.getTarget()->setCoins(p.getTarget()->coins()+1);
        }
        else{
            p.setCoins(p.coins()-2);
            p.getTarget()->setCoins(p.getTarget()->coins()+2);
        }
        
        this->setAction(Actions::block);
    }
    void Ambassador::transfer(Player &p1, Player &p2){
        if(p1.coins() == 0){
            throw runtime_error("Player dont have coins to transfer:");
        }
        this->isMyTurn();
        p1.isInGame();
        p2.isInGame();
        this->setAction(Actions::transfer);
        p1.setCoins(p1.coins()-1);
        p2.setCoins(p2.coins()+1);
        this->getCurrentGame()->moveTurn();
    }
    string Ambassador::role(){return "Ambassador";}
}