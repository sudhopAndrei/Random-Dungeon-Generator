#include <SFML/Graphics.hpp>
#include <algorithm>
#include <chrono>
#include <time.h>

#include "GameManager.h"

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

}

//game initializer
void GameManager::initializeEntities() {

	srand(time(NULL));

	//random number of rooms between 10 and 20
	for (int i = 0; i < 10; i++) {
		Room::initializeRoom();
	}

	Room::linkRooms();

	for (int i = 0; i < Room::rooms.size(); i++) {
		std::cout << std::endl;
		std::cout << "room" << i << std::endl;
		std::cout << std::endl;
		std::cout << "left door" << Room::rooms[i]->getLeftDoor() << std::endl;
		std::cout << std::endl;
		std::cout << "up door" << Room::rooms[i]->getUpDoor() << std::endl;
		std::cout << std::endl;
		std::cout << "right door" << Room::rooms[i]->getRightDoor() << std::endl;
		std::cout << std::endl;
		std::cout << "down door" << Room::rooms[i]->getDownDoor() << std::endl;
		std::cout << std::endl;
	}

	for (int i = 0; i < Room::rooms.size(); i++) {

		if (i != 0) {
			//initialize the entities in the room
			for (int j = 0; j < rand() % 5 + 7; j++) {
				Room::rooms[i]->roomEntities.push_back(MovingEntities::initializeEnemy());
			}
		}
		Room::rooms[i]->roomEntities.push_back(MovingEntities::initializePlayer()); //initialize the player

	}
}

//initialize steady clock
std::chrono::steady_clock::time_point GameManager::lastTime = std::chrono::steady_clock::now();

void GameManager::handleGame() {
	//handle the movement of the entities
	for (auto& entity : GameManager::activeRoom->roomEntities) {
		EntityType type = entity->getEntityType();
		if (type == EntityType::Player || type == EntityType::Enemy) {
			entity->handleMovement();
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

		//player-door collision handling
		for (int i = 0; i < GameManager::activeRoom->roomEntities.size(); i++) {
			if (GameManager::activeRoom->roomEntities[i]->getEntityType() == EntityType::Player) {

				for (int j = 0; j < GameManager::activeRoom->roomEntities.size(); j++) {

					if (GameManager::activeRoom->roomEntities[j]->getEntityType() == EntityType::Door) {

						if (managerInstance.isColliding(GameManager::activeRoom->roomEntities[i]->getSprite(), GameManager::activeRoom->roomEntities[j]->getSprite())) {

							if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().x < 100.f) {
								GameManager::activeRoom->roomEntities[i]->blockMovementLeft();
								GameManager::activeRoom = GameManager::activeRoom->getLeftDoor(); //left room
								std::cout << "new active room: " << GameManager::activeRoom << std::endl;
							}

							else if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().y < 100.f) {
								GameManager::activeRoom->roomEntities[i]->blockMovementUp();
								GameManager::activeRoom = GameManager::activeRoom->getUpDoor(); //up room
								std::cout << "new active room: " << GameManager::activeRoom << std::endl;

							}

							else if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().x > 1690.f) {
								GameManager::activeRoom->roomEntities[i]->blockMovementRight();
								GameManager::activeRoom = GameManager::activeRoom->getRightDoor(); //right room	
								std::cout << "new active room: " << GameManager::activeRoom << std::endl;

							}

							else if (GameManager::activeRoom->roomEntities[j]->getSprite().getPosition().y < 850.f) {
								GameManager::activeRoom->roomEntities[i]->blockMovementDown();
								GameManager::activeRoom = GameManager::activeRoom->getDownDoor(); //down room
								std::cout << "new active room: " << GameManager::activeRoom << std::endl;

							}
						}
					}
				}				
			}
		}
	}
}

//getter
Room* GameManager::getActiveRoom() {
	return GameManager::activeRoom;
}

