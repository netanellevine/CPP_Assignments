//
// Created by Netanel Levine on 25/04/2022.
//

//#ifndef EX4_1_CPP_AMBASSADOR_HPP
//#define EX4_1_CPP_AMBASSADOR_HPP
#pragma once
#include "Player.hpp"
#include "Captain.hpp"
#include "Game.hpp"
using namespace std;
//using namespace coup;
#include <string>

namespace coup {
    class Ambassador : public Player {
    public:
        Player *took_from = NULL;
        Player *gave_to = NULL;
        Ambassador(Game & game, const string& name);
        ~Ambassador(){}
        string role() override{return "Ambassador";}
        void transfer(Player& p_from, Player& p_to);
        void block(Captain& c);


    };
}


//#endif //EX4_1_CPP_AMBASSADOR_HPP
