#include "Contessa.hpp"

using namespace std;

namespace coup{

    Contessa::~Contessa(){}

    void Contessa::block(Player &p){
        this->isInGame();
        p.isLastAction(Actions::assassin_coup);
        p.getTarget()->setAlive(true);
    }
    string Contessa::role(){ return "Contessa";}
}