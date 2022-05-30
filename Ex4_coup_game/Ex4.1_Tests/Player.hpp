//
// Created by Netanel Levine on 25/04/2022.
//
//#ifndef EX4_1_CPP_PLAYER_HPP
//#define EX4_1_CPP_PLAYER_HPP
#pragma once 

#include "Game.hpp"
using namespace std;

namespace coup {
    class Player {
        protected:
            Game game;
            string player_name;
            string player_role;
            int current_money = 0;

        public:
            Player()= default;
            Player(Game & game, string player_name, const string& player_role);
            void income();
            void foreign_aid();
            void coup(const Player& p);
            int coins() const;
            virtual string role() = 0;
    };
}

//#endif //EX4_1_CPP_PLAYER_HPP
