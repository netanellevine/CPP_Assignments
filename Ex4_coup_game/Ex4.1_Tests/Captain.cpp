//
// Created by Netanel Levine on 25/04/2022.
//

#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;

Captain::Captain(Game & game, std::string name) : Player(game, name, "Captain"){}
void Captain::steal(Player &p) {}
void Captain::block(const Player& p){}

