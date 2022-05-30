//
// Created by Netanel Levine on 25/04/2022.
//

#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

Captain::Captain(Game & game, const string& name) : Player(game, name, "Captain"){
    // game.turns.push(*this);
}

void Captain::steal(Player &p) {
    checkEnoughPlayers();
    checkTurn();
    check10Coins();
    if (!p.alive) {
        throw std::invalid_argument("You can't steal from " + p.player_name + " because he is dead!");
    }
    this->game->gameIsActive = true;
    this->stolen = p.current_money < max_steal ? p.current_money : 2;
    this->current_money += stolen;
    this->last_action = "steal";
    p.current_money -= stolen;
    this->stolenFrom = &p;
    moveTurnToLast();
}

void Captain::block(Captain& c) {
    if (!c.alive) {
        throw std::invalid_argument("You can't block " + c.player_name + " because he is dead!");
    }
    if (c.stolenFrom == NULL) {
        throw std::invalid_argument("You can't block " + c.player_name + " because he didn't still from anyone!");
    }
    if (c.last_action != "steal"){
        throw std::invalid_argument("You can block only the steal action!");
    }
    this->last_action = "block";
    c.stolenFrom->current_money += c.stolen;
    c.current_money -= c.stolen;
}

void Captain::block(Player& p) {
    if (p.player_role != "Captain"){
        throw std::invalid_argument("You can block only the Captain role!");
    }
//    Captain* cap = (Captain)*(p);
    Captain* cap = dynamic_cast<Captain*>(&p);
    block(*cap);
}

