//
// Created by Netanel Levine on 25/04/2022.
//

// #ifndef EX4_1_CPP_CONTESSA_HPP
// #define EX4_1_CPP_CONTESSA_HPP
#pragma once
#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
using namespace std;
//using namespace coup;
#include <string>

namespace coup {
    class Contessa : public Player {
    public:
        Contessa(Game & game, const string& name);
        ~Contessa(){}
        string role() override{return "Contessa";}
        void block(Assassin& a);
        void block(Player& p);


    };
}



// #endif //EX4_1_CPP_CONTESSA_HPP
