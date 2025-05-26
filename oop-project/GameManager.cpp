#include <SFML/Graphics.hpp>
#include <algorithm>
#include <chrono>

#include "GameManager.h"

//singleton instance of GameManager (private constructor)
GameManager GameManager::managerInstance;

//function called in main.cpp
void GameManager::startGame() {
	initializeEntities();
}

//game initializer
void GameManager::initializeEntities() {

	//random number of rooms between 10 and 20
	for (int i = 0; i < rand() % 10 + 10; i++) {
		Room::initializeRoom();
	}

	//Room::generateRooms();

	MovingEntities::initializeActors();
}

//initialize steady clock
std::chrono::steady_clock::time_point GameManager::lastTime = std::chrono::steady_clock::now();

void GameManager::handleGame() {
	//handle the movement of the entities
	for (auto& entity : GameEntity::entities) {
		EntityType type = entity->getEntityType();
		if (type == EntityType::Player || type == EntityType::Enemy) {
			entity->handleMovement();
		}
	}

	//change the direction of the enemies every 3 seconds
    auto currentTime = std::chrono::steady_clock::now();
    const std::chrono::seconds changeInterval(3);

    if (currentTime - lastTime >= changeInterval) {
		for (auto& entity : GameEntity::entities) {
			EntityType type = entity->getEntityType();
			if (type == EntityType::Enemy) {
				entity->changeDirection();
			}
		}
        lastTime = currentTime;
    }

	//handle the collision between entities
	callCollisions();
}

//handle the actor collision with the collidable instances
void GameManager::callCollisions() {

	//actor-wall collision handling -> calls actor handling method
	for (int i = 0; i < GameEntity::entities.size(); i++) {
		if (GameEntity::entities[i]->getEntityType() == EntityType::Player || GameEntity::entities[i]->getEntityType() == EntityType::Enemy) {

			for (int j = 0; j < GameEntity::entities.size(); j++) {
				if (GameEntity::entities[j]->getEntityType() == EntityType::Wall) {

					//if there is collision, set the collision type for the wall
					if (managerInstance.isColliding(GameEntity::entities[i]->getSprite(), GameEntity::entities[j]->getSprite())) {
						GameEntity::entities[i]->handleCollision(GameEntity::entities[i], GameEntity::entities[j]);
					}
				}
			}
		}
	}
}