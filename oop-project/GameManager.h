#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Collision.h"
#include "MovingEntities.h"
#include "Room.h"

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

enum DoorPosition {
	Left,
	Up,
	Right,
	Down
};

class GameManager : public Collision {
private:
	static sf::Clock clock;

	static std::chrono::steady_clock::time_point lastTime;
	static GameManager managerInstance;
	static Room* activeRoom; //the room in which the player is currently in

	static void initializeEntities();

	static void changePlayerRoom(GameEntity* player, Room* oldRoom, Room* newRoom, DoorPosition position);

	GameManager() {};
	~GameManager() {};

public:
	static void startGame();
	static void handleGame();
	static void collisionManager();

	static Room* getActiveRoom();
};

#endif