//
// Created by Netanel Levine on 25/04/2022.
//

#include "Assassin.hpp"
#include "Player.hpp"
#include "Game.hpp"
using namespace coup;
Assassin::Assassin(Game & game, const string& name) : Player(game, name, "Assassin"){}

void Assassin::coup(Player& p) {
    checkEnoughPlayers();
    checkTurn();
    if (!p.alive) {
        throw std::invalid_argument(p.player_name + " is already dead!");
    }
    if (this->current_money < assassin_coup){
        throw std::invalid_argument("You don't have enough coins for this action!");
    }
    this->game->gameIsActive = true;
    if (this->current_money < coup_cost){
        p.alive = false;
        this->last_action = "assassin_coup";
        this->current_money -= assassin_coup;
        this->wasKilled = &p;
    }
    else {
        p.alive = false;
        this->last_action = "coup";
        this->current_money -= coup_cost;
    }
    kill(p.player_name);
    this->game->players_list.erase(this->game->players_list.begin() + p.id);
    moveTurnToLast();
}

