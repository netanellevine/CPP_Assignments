//
// Created by netan on 27/04/2022.
//

#include "doctest.h"
#include "Game.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"

using namespace std;
using namespace coup;

Game game_1{};

Duke duke{game_1, "Mor"};
Assassin assassin{game_1, "Haim"};
Ambassador ambassador{game_1, "Evgeniy"};
Captain captain{game_1, "Tal"};
Contessa contessa{game_1, "Nofar"};

TEST_CASE("Basic Tests"){
    CHECK(game_1.players().size() == 5);
    CHECK(game_1.turn()=="Mor");
    for(int i = 1; i < 5; i++){
        assassin.foreign_aid();
        CHECK(assassin.coins() == i * 2);
        duke.foreign_aid();
        CHECK(duke.coins() == i * 2);
        ambassador.foreign_aid();
        CHECK(ambassador.coins() == i * 2);
        captain.foreign_aid();
        CHECK(captain.coins() == i * 2);
        contessa.foreign_aid();
        CHECK(contessa.coins() == i * 2);
    }
    CHECK_THROWS(duke.coup(assassin));
    CHECK_NOTHROW(duke.block(ambassador));
    CHECK_NOTHROW(assassin.coup(duke));
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(assassin.coup(captain));
    CHECK_THROWS(ambassador.foreign_aid());
    CHECK_THROWS(captain.steal(assassin));
    CHECK_THROWS(contessa.foreign_aid());
}
