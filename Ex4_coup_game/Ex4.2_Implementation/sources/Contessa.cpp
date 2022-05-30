//
// Created by Netanel Levine on 25/04/2022.
//

#include "Contessa.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

Contessa::Contessa(Game & game, const string& name) : Player(game, name, "Contessa"){
    // game.turns.push(*this);
}

void Contessa::block(Assassin& a) {
    if (a.wasKilled == NULL) {
        throw std::invalid_argument("You can't block " + a.player_name + " because he didn't kill anyone!");
    }
    if (a.wasKilled->alive) {
        throw std::invalid_argument("You can't block because " + a.wasKilled->player_name + " is alive!");
    }
    if (a.last_action != "assassin_coup"){
        throw std::invalid_argument("You can block only the assassin_coup action!");
    }
    a.wasKilled->alive = true;
    this->game->players_list.insert(this->game->players_list.begin() + a.wasKilled->id, a.wasKilled->player_name);
    revive(a.wasKilled->playedBeforeMe, a.wasKilled->player_name);
    this->last_action = "contessa_block";
}

void Contessa::block(Player& p) {
    if (p.player_role != "Assassin"){
        throw std::invalid_argument("You can block only the Assassin role!");
    }
    Assassin assassin(*p.game, p.player_name);
    block(assassin);
}

