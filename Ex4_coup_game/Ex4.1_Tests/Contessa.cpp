//
// Created by Netanel Levine on 25/04/2022.
//

#include "Contessa.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

Contessa::Contessa(Game & game, std::string name) : Player(game, name, "Contessa"){}
void Contessa::block(const Player& p) {}

