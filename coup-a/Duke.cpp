#include "Duke.hpp"

using namespace std;

namespace coup{

    Duke::~Duke(){}

    void Duke::tax(){
        cout << "tax" << endl;
    }
    void Duke::block(Player p){
        cout << "block" << endl;
    }
}