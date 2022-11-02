/**
 * Player.hpp program for Coup exercise
 *
 * @author: yakov elkobi
 * @since: 2022-04
 */
#pragma once
#include "Game.hpp"


namespace coup{
    enum Actions{
        init, income, foreign_aid, coup, assassin_coup, block, tex, transfer, steal_1, steal_2
    };
    class Game;
    class Player{

    protected:
        std::string _name;
        Actions _lastAction;
        int _coins;
        Game* _game;
        bool _alive;
        Player* _target;
    public:
        // constructor
        Player(/* args */);
        Player(Game &game, const std::string &name);
        ~Player();

        // getters
        std::string getName()const{return this->_name;}
        Game* getCurrentGame()const{return _game;}
        bool isAlive()const{return this->_alive;}
        Actions getActions()const{return this->_lastAction;}
        int coins()const{return this->_coins;}
        Player* getPlayer(const std::string &name)const;
        Player* getTarget()const{return this->_target;}

        // setters
        void setAlive(bool alive){this->_alive = alive;}
        void setAction(Actions action){ this->_lastAction = action;}
        void setCoins(int coins){ this->_coins = coins;}

        // methods
        void income();
        void foreign_aid();
        void isInGame()const;
        void isMyTurn()const;
        void isLastAction(Actions action)const;
        void maxCoins()const;
        virtual void coup(Player &p);
        virtual std::string role();
    };
}