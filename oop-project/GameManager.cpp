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

//get the collision type (vertical or horizontal) between an actor and a collidable object
void GameManager::setCollisionType(GameEntity* actor, GameEntity* wall) {
	float horizontalCollision;
	float verticalCollision;

	//calculates the lenght for vertical collisions (x-axis movement)
	verticalCollision = std::min(
		actor->getSprite().getGlobalBounds().position.x + actor->getSprite().getGlobalBounds().size.x,
		wall->getSprite().getGlobalBounds().position.x + wall->getSprite().getGlobalBounds().size.x
	) - std::max(
		actor->getSprite().getGlobalBounds().position.x,
		wall->getSprite().getGlobalBounds().position.x
	);

	//calculates the lenght for horizontal collisions (y-axis movement)
	horizontalCollision = std::min(
		actor->getSprite().getGlobalBounds().position.y + actor->getSprite().getGlobalBounds().size.y,
		wall->getSprite().getGlobalBounds().position.y + wall->getSprite().getGlobalBounds().size.y
	) - std::max(
		actor->getSprite().getGlobalBounds().position.y,
		wall->getSprite().getGlobalBounds().position.y
	);

	//the longer collision is picked (one of them will always tend to 0)
	if (horizontalCollision > verticalCollision) {
		actor->setIsHorizontalCollision(true);
	}

	if (horizontalCollision < verticalCollision) {
		actor->setIsVerticalCollision(true);
	}
}

//handle the actor collision with the collidable instances
void GameManager::handleCollision() {

	for (int i = 0; i < GameEntity::entities.size(); i++) {
		if (GameEntity::entities[i]->getEntityType() == EntityType::Player || GameEntity::entities[i]->getEntityType() == EntityType::Enemy) {

			bool collisionDetected = false;

			for (int j = 0; j < GameEntity::entities.size(); j++) {
				if (GameEntity::entities[j]->getEntityType() == EntityType::Wall) {

					//if there is collision, set the collision type for the wall
					if (managerInstance.isColliding(GameEntity::entities[i]->getSprite(), GameEntity::entities[j]->getSprite())) {
						GameManager::setCollisionType(GameEntity::entities[i], GameEntity::entities[j]);

						//calculates if the player is above or below the wall
						if (GameEntity::entities[i]->getIsVerticalCollision() == true) {
							if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.y > GameEntity::entities[j]->getSprite().getGlobalBounds().position.y) {
								GameEntity::entities[i]->blockMovementUp();
							}
							else if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.y < GameEntity::entities[j]->getSprite().getGlobalBounds().position.y) {
								GameEntity::entities[i]->blockMovementDown();
							}
						}

						//calculates if the player is left or right of the wall
						if (GameEntity::entities[i]->getIsHorizontalCollision() == true) {
							if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.x < GameEntity::entities[j]->getSprite().getGlobalBounds().position.x) {
								GameEntity::entities[i]->blockMovementRight();
							}
							else if (GameEntity::entities[i]->getSprite().getGlobalBounds().position.x > GameEntity::entities[j]->getSprite().getGlobalBounds().position.x) {
								GameEntity::entities[i]->blockMovementLeft();
							}
						}
						collisionDetected = true;
					}
				}
			}

			//if no collision is detected, reset the movement flags
			if (collisionDetected == false) {
				GameEntity::entities[i]->setIsVerticalCollision(false);
				GameEntity::entities[i]->setIsHorizontalCollision(false);
				GameEntity::entities[i]->resetMovementFlags();
			}
		}
	}
}