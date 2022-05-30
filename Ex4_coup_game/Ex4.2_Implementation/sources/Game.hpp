//
// Created by Netanel Levine on 25/04/2022.
//
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
//#include "Player.hpp"
const int max_steal = 2;
const size_t assassin_coup = 3;
const size_t coup_cost = 7;
const size_t max_without_coup = 10;
const size_t MAX_PLAYERS = 6;
const size_t MIN_PLAYERS = 2;

namespace coup {
//    class Player;
    class Game {
        public:
            // list of names of the playing characters
            vector <string> players_list;
            queue <string> turns;
            // the name of the current player's turn
            string curr_turn;
            bool gameIsActive = false;
        public:

            Game()= default;
            ~Game(){}

            //returns the name of the player to play next
            string turn();
            // returns who is the winner of the game.
            // if the game is still in progress, then throw exception.
            string winner();
            // returns a vector of strings which contains the names of the players in the game
            vector<string> & players();

            void addPlayer(const string& player_name);


    };
}


