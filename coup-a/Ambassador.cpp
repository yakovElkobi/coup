#include "Ambassador.hpp"

using namespace std;

namespace coup{

    Ambassador::~Ambassador(){}

    void Ambassador::block(Player p){
        cout << "block" << endl;
    }
    void Ambassador::transfer(Player p1, Player p2){
        cout << "transger" << endl;
    }
}