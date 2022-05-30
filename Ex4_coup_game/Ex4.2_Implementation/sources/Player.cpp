//
// Created by Netanel Levine on 25/04/2022.
//
// #pragma once 

#include "Player.hpp"

#include <utility>
using namespace std;
 namespace coup{

    Player::Player(Game& g, const string& player_name, const string& player_role){
        if (g.players_list.size() >= MAX_PLAYERS){
            throw invalid_argument("The game has the maximum players allowed, cant add more!");
        }
        this->game = &g;
        if (!this->game->turns.empty()){
            this->playedBeforeMe = this->game->turns.back();
        }
        g.addPlayer(player_name);
        this->player_role = player_role;
        this->player_name = player_name;
        this->id = (int)(this->game->players_list.size() - 1);
        this->alive = true;
        // cout << this->id << endl;
    }

    void Player::income() {
        checkEnoughPlayers();
        checkTurn();
        check10Coins();
        this->game->gameIsActive = true;
        this->current_money += 1;
        this->last_action = "income";
        moveTurnToLast();
    }

    void Player::foreign_aid() {
        checkEnoughPlayers();
        checkTurn();
        check10Coins();
        this->game->gameIsActive = true;
        this->current_money += 2;
        this->last_action = "foreign_aid";
        moveTurnToLast();
    }

    void Player::coup(Player& p) {
        checkEnoughPlayers();
        checkTurn();
        if (!p.alive) {
            throw std::invalid_argument(p.player_name + " is already dead!");
        }
        if (this->current_money < coup_cost){
            throw std::invalid_argument("You don't have enough coins for this action!");
        }
        this->game->gameIsActive = true;
        this->game->players_list.erase(this->game->players_list.begin() + p.id);
        p.alive = false;
        this->last_action = "coup";
        this->current_money -= coup_cost;
        kill(p.player_name);
        moveTurnToLast();
    }

    int Player::coins() const {
        return this->current_money;
    }

    void Player::check10Coins() const{
        if (this->current_money >= max_without_coup){
            throw invalid_argument("You can perform the coup action only!!");
        }
    }

    void Player::checkTurn() const{
        if (this->game->turns.front() != this->player_name){
            throw invalid_argument("It's not your turn!");
        }
    }

    void Player::moveTurnToLast() const{
        this->game->turns.push(this->game->turns.front());
        this->game->turns.pop();
    }

     void Player::revive(const string& name_before, const string& name_after) const{
         int c = 0;
        string curr_turn = this->game->turns.front();
        while (this->game->turns.front() != name_before && c < MAX_PLAYERS){
            this->game->turns.push(this->game->turns.front());
            this->game->turns.pop();
            c++;
        }
         this->game->turns.push(this->game->turns.front());
         this->game->turns.pop();
         this->game->turns.push(name_after);
        c = 0;
         while (this->game->turns.front() != curr_turn && c < MAX_PLAYERS){
             this->game->turns.push(this->game->turns.front());
             this->game->turns.pop();
             c++;
         }
    }

    void Player::kill(const string& name_after) const{
        string curr_turn = this->game->turns.front();
        int c = 0;
        while (this->game->turns.front() != name_after && c < MAX_PLAYERS){
            this->game->turns.push(this->game->turns.front());
            this->game->turns.pop();
            c++;
        }
        this->game->turns.pop();
        c = 0;
        while (this->game->turns.front() != curr_turn && c < MAX_PLAYERS){
             this->game->turns.push(this->game->turns.front());
             this->game->turns.pop();
             c++;
         }
    }

     void Player::checkEnoughPlayers() const{
        if (this->game->players_list.size() < 2){
            throw runtime_error("Min amount of players is 2! can't start the game!");
        }
    }
 }
