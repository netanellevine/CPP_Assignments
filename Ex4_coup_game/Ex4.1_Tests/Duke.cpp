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
Duke::Duke(Game & game, string name) : Player(game, move(name), "Duke"){}
void Duke::tax() {}
void Duke::block(Player &p) {}