//
// Created by Netanel Levine on 25/04/2022.
//

// #ifndef EX4_1_CPP_CONTESSA_HPP
// #define EX4_1_CPP_CONTESSA_HPP

#include "Player.hpp"
#include "Game.hpp"
using namespace std;
#include <string>

namespace coup {
    class Contessa : public Player {
    public:
        Contessa(Game & game, string name);
        string role() override{return "Contessa";}
        void block(const Player& p);


    };
}



// #endif //EX4_1_CPP_CONTESSA_HPP
