//
// Created by Netanel Levine on 25/04/2022.
//

//#ifndef EX4_1_CPP_AMBASSADOR_HPP
//#define EX4_1_CPP_AMBASSADOR_HPP

#include "Player.hpp"
#include "Game.hpp"
using namespace std;
#include <string>

namespace coup {
    class Ambassador : public Player {
    public:
        Ambassador(Game & game, string name);
        string role() override{return "Ambassador";}
        void transfer(Player& p_from, Player& p_to);


    };
}


//#endif //EX4_1_CPP_AMBASSADOR_HPP
