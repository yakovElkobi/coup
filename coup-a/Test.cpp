/**
 * Test program for Coup exercise
 *
 * @author: yakov elkobi
 * @since: 2022-04
 */

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "doctest.h"

#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;
using namespace coup;

TEST_CASE("Test game"){
    Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

    // round 1
    CHECK_EQ(game_1.players().size(), 5);
    CHECK_EQ(game_1.turn(), "Moshe");
    CHECK_EQ(duke.coins(), 0);
    duke.income(); // duke coins 1
    CHECK_EQ(duke.coins(), 1); 
    CHECK_EQ(game_1.turn(), "Yossi");
    assassin.foreign_aid(); // assassin coins 2
    CHECK_EQ(assassin.coins(), 2); 
    CHECK_THROWS(assassin.coup(duke)); // assassin coins 2, need 3 coins for coup
    duke.block(assassin); // assassin coins 0
    CHECK_EQ(assassin.coins(), 0); 
    CHECK_EQ(game_1.turn(), "Meirav");
    ambassador.income(); // ambassador coins 1
    CHECK_EQ(ambassador.coins(), 1);
    captain.income(); // captain coins 1
    contessa.foreign_aid(); // contessa coins 2
    // round 2
    CHECK_EQ(game_1.turn(), "Moshe");
    duke.tax(); // duke coins 4
    CHECK_EQ(duke.coins(), 4);
    assassin.income(); // assassin coins 1
    CHECK_EQ(assassin.coins(), 1);
    ambassador.foreign_aid(); // ambassador coins 3
    captain.steal(duke); // captain coins 3
    CHECK_EQ(captain.coins(), 3);
    CHECK_EQ(duke.coins(), 2);
    contessa.income(); // conessa coins 3
    // round 3
    duke.tax(); // duke coins 5
    assassin.income(); // assassin coins 2
    ambassador.transfer(duke, assassin); // transfer 1 coins from duke to assissin
    CHECK_EQ(duke.coins(), 4); // duke coins 4
    CHECK_EQ(assassin.coins(), 3); // assassin coins 3
    captain.steal(assassin); // captain coins 5
    CHECK_EQ(assassin.coins(), 1);
    CHECK_EQ(captain.coins(), 5);
    ambassador.block(captain); // prevent from captin steal
    CHECK_EQ(assassin.coins(), 3); // assassin coins 3
    CHECK_EQ(captain.coins(), 3);  // captain coins 3
    contessa.income(); // contessa coins 5
    // round 4
    duke.tax(); // duke coins 7
    assassin.coup(duke);
    CHECK_EQ(game_1.players().size(), 4);
    CHECK_EQ(assassin.coins(), 0); 
    contessa.block(assassin);
    CHECK_EQ(game_1.players().size(), 5);
    ambassador.income(); // ambassdor coins 4
    captain.steal(ambassador); // captin coins 5
    CHECK_EQ(ambassador.coins(), 2); // ambassdor coins 4
    contessa.income(); // contessa coins 6
    // round 5
    duke.coup(assassin); // duke coins 0
    CHECK_EQ(game_1.players().size(), 4);
    CHECK_EQ(duke.coins(), 0);
    CHECK_EQ(game_1.turn(), "Meirav");
    ambassador.income(); // ambassdor coins 4
    captain.income(); // captin coins 6
    CHECK_THROWS(contessa.coup(duke));
    contessa.income(); // contessa coins 7
    // round 6
    duke.tax(); // duke coins 3
    ambassador.foreign_aid(); // ambassdor coins 6
    captain.income(); // captin coins 7
    contessa.coup(duke); // contessa coins 0
    CHECK_EQ(game_1.players().size(), 3);
    CHECK_EQ(game_1.turn(), "Meirav");
    // round 7
    ambassador.foreign_aid(); // ambassdor coins 8
    CHECK_THROWS(captain.steal(contessa)); // conteasa coins is 0
    captain.steal(ambassador); //  captain coins 9
    contessa.foreign_aid(); // contessa coins 2
    // round 8
    ambassador.transfer(captain, contessa);
    captain.coup(ambassador); //  captain coins 2
    CHECK_EQ(game_1.players().size(), 2);
    contessa.foreign_aid(); // contessa coins 4
    // round 9
    captain.foreign_aid(); //  captain coins 4
    contessa.foreign_aid(); // contessa coins 6
    // round 10
    CHECK_THROWS(game_1.winner()); // the game is not finish
    captain.foreign_aid(); //  captain coins 6
    contessa.foreign_aid(); // contessa coins 8
    // round 11
    captain.foreign_aid(); //  captain coins 8
    contessa.income(); // contessa coins 9
    // round 12
    CHECK_THROWS(captain.foreign_aid()); // most coup 
    captain.coup(contessa);
    CHECK_EQ(game_1.winner(), "Reut");
    cout << "the winner is:" << game_1.winner() << endl;
    cout << "end of game_1" << endl;


























}
