//
// Created by Netanel Levine on 25/04/2022.
//
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>

namespace coup {
    class Game {
        private:
            // list of names of the playing characters
            std::vector<std::string> _players;
            // the name of the current player's turn
            std::string _player_turn;
        public:

            Game()= default;

            //returns the name of the player to play next
            std::string turn();
            // returns who is the winner of the game.
            // if the game is still in progress, then throw exception.
            std::string winner();
            // returns a vector of strings which contains the names of the players in the game
            std::vector<std::string> & players();

            void setPlayer(const string& player_name);


    };
}


