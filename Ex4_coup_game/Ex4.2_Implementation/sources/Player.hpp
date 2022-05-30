//
// Created by Netanel Levine on 25/04/2022.
//
//#ifndef EX4_1_CPP_PLAYER_HPP
//#define EX4_1_CPP_PLAYER_HPP
#pragma once

#include "Game.hpp"
using namespace std;
static int number = 1;
//using namespace coup;
namespace coup {
//    class Game;
    class Player {
        public:
            Game *game;
            string player_name;
            string player_role;
            int current_money = 0;
            string last_action = "";
            bool alive = false;
            bool action_performed = false;
            // int id = number++;
            int id;
            string playedBeforeMe;

        public:
            Player()=default;
            ~Player(){}
            Player(Game& g, const string& player_name, const string& player_role);
            void income();
            void foreign_aid();
            void coup(Player& p);
            int coins() const;
            virtual string role() = 0;
            void check10Coins() const;
            void checkTurn() const;
            void setCoins(int num);
            void setLastAction(string action);
            void moveTurnToLast() const;
            string getLastAction();
            void revive(const string& name_before, const string& name_after) const;
            void kill(const string& name_after) const;
            void checkEnoughPlayers() const;
    };
}

//#endif //EX4_1_CPP_PLAYER_HPP
