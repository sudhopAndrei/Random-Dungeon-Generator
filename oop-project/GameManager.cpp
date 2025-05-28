#include <SFML/Graphics.hpp>
#include <algorithm>
#include <chrono>
#include <time.h>

#include "GameManager.h"

//manager clock initializer
sf::Clock GameManager::clock;

//singleton instance of GameManager (private constructor)
GameManager GameManager::managerInstance;

Room* GameManager::activeRoom = nullptr;

//function called in main.cpp
void GameManager::startGame() {
	initializeEntities();

	for (int i = 0; i < Room::rooms.size(); i++) {
		GameManager::activeRoom = Room::rooms[0]; //set the active room to the first room
		break;
	}

	Player* player = MovingEntities::initializePlayer(); //initialize the player
	GameManager::activeRoom->roomEntities.push_back(player); //add the player to the active room
}

//game initializer
void GameManager::initializeEntities() {

	srand(time(NULL));

	//random number of rooms between 10 and 20
	for (int i = 0; i < rand() % 10 + 10; i++) {
		Room::initializeRoom();
	}

	Room::linkRooms();

	for (int i = 0; i < Room::rooms.size(); i++) {

		if (i != 0) {
			//initialize the entities in the room
			for (int j = 0; j < rand() % 5 + 7; j++) {
				Room::rooms[i]->roomEntities.push_back(MovingEntities::initializeEnemy());
			}
		}
	}
}

//initialize steady clock
std::chrono::steady_clock::time_point GameManager::lastTime = std::chrono::steady_clock::now();

void GameManager::handleGame() {
	
	float deltaTime = GameManager::clock.restart().asSeconds();

	//handle the movement of the entities
	for (auto& entity : GameManager::activeRoom->roomEntities) {
		EntityType type = entity->getEntityType();
		if (type == EntityType::Player || type == EntityType::Enemy) {
			entity->handleMovement(deltaTime);
		}
	}

	//change the direction of the enemies every 3 seconds
    auto currentTime = std::chrono::steady_clock::now();
    const std::chrono::seconds changeInterval(3);

    if (currentTime - lastTime >= changeInterval) {
		for (auto& entity : GameManager::activeRoom->roomEntities) {
			EntityType type = entity->getEntityType();
			if (type == EntityType::Enemy) {
				entity->changeDirection();
			}
		}
        lastTime = currentTime;
    }

	//handle the collision between entities
	collisionManager();
}

//handle the actor collision with the collidable instances
void GameManager::collisionManager() {

	//actor-wall collision handling
	for (int i = 0; i < GameManager::activeRoom->roomEntities.size(); i++) {
		if (GameManager::activeRoom->roomEntities[i]->getEntityType() == EntityType::Player || GameManager::activeRoom->roomEntities[i]->getEntityType() == EntityType::Enemy) {

			for (int j = 0; j < GameManager::activeRoom->roomEntities.size(); j++) {
				if (GameManager::activeRoom->roomEntities[j]->getEntityType() == EntityType::Wall) {

					//if there is collision, set the collision type for the wall
					if (managerInstance.isColliding(GameManager::activeRoom->roomEntities[i]->getSprite(), GameManager::activeRoom->roomEntities[j]->getSprite())) {
						//calculates if the player is above or below the wall
						if (Collision::isHorizontalCollision(GameManager::activeRoom->roomEntities[i]->getSprite(), GameManager::activeRoom->roomEntities[j]->getSprite()) == false) {
							if (GameManager::activeRoom->roomEntities[i]->getSprite().getGlobalBounds().position.y > GameManager::activeRoom->roomEntities[j]->getSprite().getGlobalBounds().position.y) {
								GameManager::activeRoom->roomEntities[i]->blockMovementUp();
							}
							else if (GameManager::activeRoom->roomEntities[i]->getSprite().getGlobalBounds().position.y < GameManager::activeRoom->roomEntities[j]->getSprite().getGlobalBounds().position.y) {
								GameManager::activeRoom->roomEntities[i]->blockMovementDown();
							}
						}

						//calculates if the player is left or right of the wall
						if (Collision::isHorizontalCollision(GameManager::activeRoom->roomEntities[i]->getSprite(), GameManager::activeRoom->roomEntities[j]->getSprite()) == true) {
							if (GameManager::activeRoom->roomEntities[i]->getSprite().getGlobalBounds().position.x < GameManager::activeRoom->roomEntities[j]->getSprite().getGlobalBounds().position.x) {
								GameManager::activeRoom->roomEntities[i]->blockMovementRight();
							}
							else if (GameManager::activeRoom->roomEntities[i]->getSprite().getGlobalBounds().position.x > GameManager::activeRoom->roomEntities[j]->getSprite().getGlobalBounds().position.x) {
								GameManager::activeRoom->roomEntities[i]->blockMovementLeft();
							}
						}
					}
				}
			}
		}
	}

	Room* oldRoom = nullptr;
	GameEntity* player = nullptr;

	//player-door collision handling
	for (int i = 0; i < GameManager::activeRoom->roomEntities.size(); i++) {
		if (GameManager::activeRoom->roomEntities[i]->getEntityType() == EntityType::Player) {

			player = GameManager::activeRoom->roomEntities[i];

			for (int j = 0; j < GameManager::activeRoom->roomEntities.size(); j++) {

				if (GameManager::activeRoom->roomEntities[j]->getEntityType() == EntityType::Door) {

					if (managerInstance.isColliding(GameManager::activeRoom->roomEntities[i]->getSprite(), GameManager::activeRoom->roomEntities[j]->getSprite())) {

						if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().x < 100.f) {
							oldRoom = GameManager::activeRoom; 
							oldRoom->roomEntities.erase(std::remove(oldRoom->roomEntities.begin(), oldRoom->roomEntities.end(), player), oldRoom->roomEntities.end());

							GameManager::activeRoom = GameManager::activeRoom->getLeftDoor(); //left room
							GameManager::activeRoom->roomEntities.push_back(player);
							player->getSpriteRef().setPosition({ 1770.f, 540.f });


							break;
						}

						else if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().y < 100.f) {
							oldRoom = GameManager::activeRoom;
							oldRoom->roomEntities.erase(std::remove(oldRoom->roomEntities.begin(), oldRoom->roomEntities.end(), player), oldRoom->roomEntities.end());

							GameManager::activeRoom = GameManager::activeRoom->getUpDoor(); //up room
							GameManager::activeRoom->roomEntities.push_back(player);
							player->getSpriteRef().setPosition({ 960.f, 930.f });


							break;
						}

						else if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().x > 1690.f) {
							oldRoom = GameManager::activeRoom;
							oldRoom->roomEntities.erase(std::remove(oldRoom->roomEntities.begin(), oldRoom->roomEntities.end(), player), oldRoom->roomEntities.end());

							GameManager::activeRoom = GameManager::activeRoom->getRightDoor(); //right room
							GameManager::activeRoom->roomEntities.push_back(player);
							player->getSpriteRef().setPosition({ 150.f, 540.f });


							break;
						}

						else if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().y > 850.f) {
							oldRoom = GameManager::activeRoom;
							oldRoom->roomEntities.erase(std::remove(oldRoom->roomEntities.begin(), oldRoom->roomEntities.end(), player), oldRoom->roomEntities.end());

							GameManager::activeRoom = GameManager::activeRoom->getDownDoor(); //down room
							GameManager::activeRoom->roomEntities.push_back(player);
							player->getSpriteRef().setPosition({ 960.f, 150.f });

							break;
						}
					}
				}
			}

			break;
		}
	}
}

//getter
Room* GameManager::getActiveRoom() {
	return GameManager::activeRoom;
}

