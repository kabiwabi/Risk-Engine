#include "LoggingObserverDriver.h"

/**
 * @brief Test function for logging observer functionality.
 *
 * This function tests the logging observer by creating a game engine, players, loading a map,
 * creating orders, attaching observers, and testing various game state changes and order execution.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of command line argument strings.
 */
void testLoggingObserver(int argc, char** argv){

  auto gameEngine = new GameEngine(argc, argv);
  auto player1 = new Player(gameEngine, new Hand(), "Player1");
  auto player2 = new Player(gameEngine, new Hand(), "Player2");

  gameEngine->loadMap("../res/TestMap1_valid.map");

  player2->addTerritory(*gameEngine->getMap()->getTerritories()->at(0));

  // Create order and attach observer
  auto order = new Bomb(gameEngine, player2->getTerritories()->at(0), player1);

  // Get orderList and attach observer
  auto orderList = player1->getOrdersListObject();

  // Create commandProcessor and attach observer
  auto processor = new CommandProcessor(gameEngine, argc, argv);

  // TEST GAME STATE CHANGE
  gameEngine->setCurrentState(GE_Map_Loaded);

  // TEST ADDITION OF ORDER TO ORDER LIST
  orderList->add(order);

  // TEST ORDER EXECUTION
  order->execute();

  // TEST EFFECT SAVED and COMMAND SAVED
  processor->getCommand();

}