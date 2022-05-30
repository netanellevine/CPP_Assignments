//
// Created by Netanel Levine on 25/04/2022.
//
// #pragma once 

#include "Player.hpp"

#include <utility>
using namespace std;
 namespace coup{

    Player::Player(Game & game, string player_name, const string& player_role){
        this->game = game;
        this->game.setPlayer(player_role);
        this->player_role = player_role;
        this->player_name = move(player_name);
    }

    void Player::income() {
       this->current_money += 1;
    }

    void Player::foreign_aid() {
       this->current_money += 2;
    }

    void Player::coup(const Player& p) {
        int i = 0;
    }

    int Player::coins() const {
        return this->current_money;
    }

 }
