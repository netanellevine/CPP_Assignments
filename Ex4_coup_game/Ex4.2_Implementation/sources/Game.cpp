//
// Created by Netanel Levine on 25/04/2022.
//

#include "Game.hpp"
using namespace std;
#include <string>
#include <algorithm>
using namespace coup;

void Game::addPlayer(const string& player_name){
    if (this->gameIsActive){
        throw invalid_argument("The game has started! can't add new players!");
    }
    if (!binary_search(this->players_list.begin(), this->players_list.end(), player_name)){
        this->players_list.push_back(player_name);
        this->turns.push(player_name);
    }
//    this->_players.push_back(player_name);
}

//returns the name of the player to play next
string Game::turn() { return this->turns.front();}
// return who is the winner of the game.
// if the game is still in progress, then throw exception.
string Game::winner() {
    if (this->players_list.size() == 1 && this->gameIsActive){
        return this->players_list.at(0);
    }
    throw invalid_argument("The game is still running!! there is not a winner for now.");
}

// returns a vector of strings which contains the names of the players in the game
vector<string> & Game::players() {
    return this->players_list;
}