#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "CollisionDetection.h"
#include "MovingEntities.h"
#include "Room.h"

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager : public CollisionDetection {
private:
	static std::chrono::steady_clock::time_point lastTime;
	static GameManager managerInstance;

	static void initializeEntities();

	GameManager() {};
	~GameManager() {};

public:
	static void startGame();
	static void handleGame();
	static void callCollisions();
};

#endif