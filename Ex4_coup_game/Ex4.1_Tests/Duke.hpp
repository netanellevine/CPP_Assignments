//
// Created by Netanel Levine on 25/04/2022.
//
//#ifndef EX4_1_CPP_DUKE_HPP
//#define EX4_1_CPP_DUKE_HPP

#include "Player.hpp"
#include "Game.hpp"
using namespace std;
#include <string>

namespace coup {
    class Duke : public Player{
        public:
            Duke(Game & game, string name);
            string role() override{return "Duke";}
            void block(Player & p);
            void tax();


    };
}
//#endif //EX4_1_CPP_DUKE_HPP
