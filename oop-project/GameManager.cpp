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
	Room::initializeTiles();
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

	//Change the direction of the enemies every 3 seconds
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
	handleCollision();
}

//handle the actor collision with the collidable instances
void GameManager::handleCollision() {

	for (int i = 0; i < GameEntity::entities.size(); i++) {
		if (GameEntity::entities[i]->getEntityType() == EntityType::Player || GameEntity::entities[i]->getEntityType() == EntityType::Enemy) {

			for (int j = 0; j < GameEntity::entities.size(); j++) {
				if (GameEntity::entities[j]->getEntityType() == EntityType::Wall) {

					//if there is collision, set the collision type for the wall
					if (managerInstance.isColliding(GameEntity::entities[i]->getSprite(), GameEntity::entities[j]->getSprite())) {

						//calculates if the player is above or below the wall
						if (managerInstance.isHorizontalCollision(GameEntity::entities[i]->getSprite(), GameEntity::entities[j]->getSprite()) == false) {
							if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.y > GameEntity::entities[j]->getSprite().getGlobalBounds().position.y) {
								GameEntity::entities[i]->blockMovementUp();
							}
							else if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.y < GameEntity::entities[j]->getSprite().getGlobalBounds().position.y) {
								GameEntity::entities[i]->blockMovementDown();
							}
						}

						//calculates if the player is left or right of the wall
						if (managerInstance.isHorizontalCollision(GameEntity::entities[i]->getSprite(), GameEntity::entities[j]->getSprite()) == true) {
							if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.x < GameEntity::entities[j]->getSprite().getGlobalBounds().position.x) {
								GameEntity::entities[i]->blockMovementRight();
							}
							else if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.x > GameEntity::entities[j]->getSprite().getGlobalBounds().position.x) {
								GameEntity::entities[i]->blockMovementLeft();
							}
						}
					}
				}
			}
		}
	}
}