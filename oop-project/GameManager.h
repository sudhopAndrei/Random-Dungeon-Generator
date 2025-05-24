#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Collision.h"
#include "MovingEntities.h"
#include "Room.h"

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager : public Collision {
private:
	static std::chrono::steady_clock::time_point lastTime;
	static GameManager managerInstance;

	static void setCollisionType(GameEntity* actor, GameEntity* wall);
	static void initializeEntities();

	GameManager() {};
	~GameManager() {};

public:
	static void startGame();
	static void handleGame();
	static void handleCollision();

};

#endif