//
// Created by Netanel Levine on 25/04/2022.
//

// #ifndef EX4_1_CPP_CAPTAIN_HPP
// #define EX4_1_CPP_CAPTAIN_HPP
#pragma once
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
#include <string>

namespace coup {
    class Captain : public Player {
    public:
        Player *stolenFrom = NULL;
        int stolen = 0;
        Captain(Game & game, const string& name);
        ~Captain(){}
        string role() override{return "Captain";}
        void block(Player& p);
        void block(Captain& c);
        void steal(Player& p);
    };
}



// #endif //EX4_1_CPP_CAPTAIN_HPP
