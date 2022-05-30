//
// Created by Netanel Levine on 25/04/2022.
//

#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

Ambassador::Ambassador(Game & game, std::string name) : Player(game, name, "Ambassador"){}
void Ambassador::transfer(Player& p_from, Player& p_to){}

