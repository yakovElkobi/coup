#include "Captain.hpp"

using namespace std;

namespace coup{

    Captain::~Captain(){}

    void Captain::block(Player &p){
        this->isInGame();
        if(p.getActions() != Actions::steal_1 || p.getActions() != Actions::steal_2){
            throw runtime_error("This is not the last action:");
        }
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
        void Captain::steal(Player &p){
            this->isMyTurn();
            this->isInGame();
            p.isInGame();
            if(p.coins() == 1){
                this->setAction(Actions::steal_1);
                this->setCoins(this->coins()+1);
                p.setCoins(p.coins()-1);
            }
            else{
                this->setAction(Actions::steal_2);
                this->setCoins(this->coins()+2);
                p.setCoins(p.coins()-2);
            }
            _target = &p;
            this->getCurrentGame()->moveTurn();
        }
        string Captain::role(){ return "Captain";}
}