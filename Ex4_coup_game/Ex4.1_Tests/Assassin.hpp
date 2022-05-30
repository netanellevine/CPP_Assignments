//
// Created by Netanel Levine on 25/04/2022.
//

//#ifndef EX4_1_CPP_ASSASSIN_HPP
//#define EX4_1_CPP_ASSASSIN_HPP

#include "Player.hpp"
#include "Game.hpp"
using namespace std;
#include <string>

namespace coup {
    class Assassin : public Player {
    public:
        Assassin(Game & game, string name);
        string role() override{return "Assassin";}
        void block(const Player& p);
    };
}


//#endif //EX4_1_CPP_ASSASSIN_HPP
