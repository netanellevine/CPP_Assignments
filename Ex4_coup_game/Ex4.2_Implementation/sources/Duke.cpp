//
// Created by Netanel Levine on 25/04/2022.
//

#include "Duke.hpp"

#include <utility>
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

using namespace coup;
Duke::Duke(Game & game, const string& name) : Player(game, name, "Duke"){
    // game.turns.push(*this);
}

void Duke::tax() {
    checkEnoughPlayers();
    checkTurn();
    check10Coins();
    this->game->gameIsActive = true;
    this->current_money += 3;
    this->last_action = "tax";
    moveTurnToLast();
}

void Duke::block(Player &p) {
    if (p.last_action == "foreign_aid") {
        p.current_money -= 2;
        this->current_money = this->current_money;
    }
    else {
        throw invalid_argument(p.player_name + "'s last action wasn't foreign_aid!");
    }
}