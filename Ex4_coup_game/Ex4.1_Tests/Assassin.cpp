//
// Created by Netanel Levine on 25/04/2022.
//

#include "Assassin.hpp"
#include "Player.hpp"
#include "Game.hpp"
using namespace coup;
Assassin::Assassin(Game & game, std::string name) : Player(game, name, "Assassin"){}
void Assassin::block(const Player& p){}

