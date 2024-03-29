#include "Orders.h"
#include "OrdersDriver.h"
#include "GameEngine/GameEngine.h"

using namespace std;

/**
 * @brief Test function for order execution in the game.
 *
 * This function simulates the execution of various orders in the game, including reinforcement,
 * airlift, diplomacy, blockade, and bomb orders. It initializes a game engine with players and territories,
 * sets up a deck with different types of cards, and then executes orders through the main game loop.
 */
void testOrderExecution()
{
  // arrange
  // mocking argc and argv
  int argc = 1;
  char *argv[] = {(char *)"-console"};
  // create a game engine
  auto gameEngine = GameEngine(argc, argv);

  // add cards to the gameEngine deck
  auto deck = gameEngine.getDeck();
  deck->addCardToDeck(new Card(CardType::CT_Reinforcement, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Reinforcement, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Reinforcement, &gameEngine));

  deck->addCardToDeck(new Card(CardType::CT_Airlift, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Airlift, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Airlift, &gameEngine));

  deck->addCardToDeck(new Card(CardType::CT_Diplomacy, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Diplomacy, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Diplomacy, &gameEngine));

  deck->addCardToDeck(new Card(CardType::CT_Bomb, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Bomb, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Bomb, &gameEngine));

  deck->addCardToDeck(new Card(CardType::CT_Blockade, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Blockade, &gameEngine));
  deck->addCardToDeck(new Card(CardType::CT_Blockade, &gameEngine));

  // load a map before the game starts
  gameEngine.loadMap("../res/TestMap1_valid.map");

  // create players
  auto player1 = new Player(&gameEngine, new Hand(), "Rick Astley", "Aggressive");
  auto player2 = new Player(&gameEngine, new Hand(), "Bob Ross", "Aggressive");
  auto player3 = new Player(&gameEngine, new Hand(), "Felix Kjellberg", "Aggressive");

  // adding sets of territories just for testing
  auto map = gameEngine.getMap();
  auto continents = map->getContinents();

  for (auto t : *continents->at(0)->getTerritories())
  {
    player1->addTerritory(*t);
  }

  for (auto t : *continents->at(1)->getTerritories())
  {
    player2->addTerritory(*t);
  }

  for (auto t : *continents->at(2)->getTerritories())
  {
    player3->addTerritory(*t);
  }

  player1->getHand()->addToHand(new Card(CardType::CT_Reinforcement, &gameEngine));
  player1->getHand()->addToHand(new Card(CardType::CT_Blockade, &gameEngine));
  player1->getHand()->addToHand(new Card(CardType::CT_Bomb, &gameEngine));
  player1->getHand()->addToHand(new Card(CardType::CT_Diplomacy, &gameEngine));
  player1->getHand()->addToHand(new Card(CardType::CT_Airlift, &gameEngine));

  // act
  gameEngine.mainGameLoop();
}