//
// Created by Netanel Levine on 25/04/2022.
//

// #ifndef EX4_1_CPP_CAPTAIN_HPP
// #define EX4_1_CPP_CAPTAIN_HPP

#include "Player.hpp"
#include "Game.hpp"
using namespace std;
#include <string>

namespace coup {
    class Captain : public Player {
    public:
        Captain(Game & game, string name);
        string role() override{return "Captain";}
        void block(const Player& p);
        void steal(Player& p);
    };
}



// #endif //EX4_1_CPP_CAPTAIN_HPP
