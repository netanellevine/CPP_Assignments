//
// Created by Netanel Levine on 25/04/2022.
//

#include "Game.hpp"
using namespace std;
#include <string>
using namespace coup;

void Game::setPlayer(const string& player_name){
    this->_players.push_back(player_name);
}

//returns the name of the player to play next
string Game::turn() { return this->_player_turn;}
// return who is the winner of the game.
// if the game is still in progress, then throw exception.
string Game::winner() {
    vector<string> str = this->_players;
    return str.at(0);
}
// returns a vector of strings which contains the names of the players in the game
vector<string> & Game::players() {
    return this->_players;
}