//
// Created by Netanel Levine on 25/04/2022.
//

//#ifndef EX4_1_CPP_ASSASSIN_HPP
//#define EX4_1_CPP_ASSASSIN_HPP
#pragma once
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
#include <string>

namespace coup {
    class Assassin : public Player {
    public:
        Player *wasKilled = NULL;
        Assassin(Game & game, const string& name);
        ~Assassin(){}
        string role() override{return "Assassin";}
        void coup(Player& p);
    };
}


//#endif //EX4_1_CPP_ASSASSIN_HPP
