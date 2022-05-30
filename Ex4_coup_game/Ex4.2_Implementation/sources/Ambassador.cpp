//
// Created by Netanel Levine on 25/04/2022.
//

#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

Ambassador::Ambassador(Game & game, const string& name) : Player(game, name, "Ambassador"){
    // game.turns.push(*this);
}

void Ambassador::transfer(Player& p_from, Player& p_to){
    checkEnoughPlayers();
    checkTurn();
    check10Coins();
    if (!p_from.alive or !p_to.alive){
        throw std::invalid_argument("You can't commit actions on dead players!");
    }
    if (p_from.current_money == 0){
        throw std::invalid_argument(p_from.player_name + " doesn't have enough money to transfer!");
    }
    this->game->gameIsActive = true;
    p_from.current_money -= 1;
    p_to.current_money += 1;
    this->took_from = &p_from;
    this->gave_to = &p_to;
    this->last_action = "transfer";
    moveTurnToLast();
}

void Ambassador::block(Captain& c){
    if (!c.alive) {
        throw std::invalid_argument("You can't block " + c.player_name + " because he is dead!");
    }
    if (c.stolenFrom == NULL) {
        throw std::invalid_argument("You can't block " + c.player_name + " because he didn't steal from anyone!");
    }
    if (c.last_action != "steal"){
        throw std::invalid_argument("You can block only the steal action!");
    }
    c.stolenFrom->current_money += c.stolen;
    c.current_money -= c.stolen;
    this->last_action = "block";
}

