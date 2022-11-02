#include "Captain.hpp"

using namespace std;

namespace coup{

    Captain::~Captain(){}

    void Captain::block(Player p){
        cout << "block" << endl;
    }
        void Captain::steal(Player p){
            cout << "steal" << endl;
        }
}